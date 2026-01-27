#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>
/*Global Arrays (indexed by file descriptor):
• ids[65536] - Stores unique client IDs
• msgs[65536] - Buffers incomplete messages per client

File Descriptor Sets:
• afds - All active file descriptors (master set)
• rfds - Ready for reading (copy for select)
• wfds - Ready for writing (copy for select)

Other Globals:
• count - Next client ID to assign
• max_fd - Highest file descriptor number */


int		count = 0, max_fd = 0;
int		ids[65536];
char	*msgs[65536];

fd_set	rfds, wfds, afds;
char	buf_read[1001], buf_write[42];


// START COPY-PASTE FROM GIVEN MAIN

int extract_message(char **buf, char **msg)
{
	char	*newbuf;
	int	i;

	*msg = 0;
	if (*buf == 0)
		return (0);
	i = 0;
	while ((*buf)[i])
	{
		if ((*buf)[i] == '\n')
		{
			newbuf = calloc(1, sizeof(*newbuf) * (strlen(*buf + i + 1) + 1));
			if (newbuf == 0)
				return (-1);
			strcpy(newbuf, *buf + i + 1);
			*msg = *buf;
			(*msg)[i + 1] = 0;
			*buf = newbuf;
			return (1);
		}
		i++;
	}
	return (0);
}

char *str_join(char *buf, char *add)
{
	char	*newbuf;
	int		len;

	if (buf == 0)
		len = 0;
	else
		len = strlen(buf);
	newbuf = malloc(sizeof(*newbuf) * (len + strlen(add) + 1));
	if (newbuf == 0)
		return (0);
	newbuf[0] = 0;
	if (buf != 0)
		strcat(newbuf, buf);
	free(buf);
	strcat(newbuf, add);
	return (newbuf);
}

// END COPY-PASTE


void	fatal_error()
{
	write(2, "Fatal error\n", 12);
	exit(1);
}

void	notify_other(int author, char *str)
{
	for (int fd = 0; fd <= max_fd; fd++)
	{
		if (FD_ISSET(fd, &wfds) && fd != author)
			send(fd, str, strlen(str), 0);
	}
}

void	register_client(int fd)
{
	max_fd = fd > max_fd ? fd : max_fd;
	ids[fd] = count++;
	msgs[fd] = NULL;
	FD_SET(fd, &afds);
	sprintf(buf_write, "server: client %d just arrived\n", ids[fd]);
	notify_other(fd, buf_write);
}

void	remove_client(int fd)
{
	sprintf(buf_write, "server: client %d just left\n", ids[fd]);
	notify_other(fd, buf_write);
	free(msgs[fd]);
	FD_CLR(fd, &afds);
	close(fd);
}

void	send_msg(int fd)
{
	char *msg;

	while (extract_message(&(msgs[fd]), &msg))
	{
		sprintf(buf_write, "client %d: ", ids[fd]);
		notify_other(fd, buf_write);
		notify_other(fd, msg);
		free(msg);
	}
}

int		create_socket()
{
	max_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (max_fd < 0)
		fatal_error();
	FD_SET(max_fd, &afds);
	return max_fd;
}

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		exit(1);
	}

	FD_ZERO(&afds);
	/*Creates the server socket and adds it to the active file descriptor set */
	int sockfd = create_socket();

	// START COPY-PASTE FROM MAIN

	/*Binds to localhost and specified port, starts listening for connections */
	struct sockaddr_in servaddr;
	bzero(&servaddr, sizeof(servaddr));

	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433);
	servaddr.sin_port = htons(atoi(av[1])); // replace 8080

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)))
		fatal_error();
	if (listen(sockfd, SOMAXCONN)) // the main uses 10, SOMAXCONN is 180 on my machine
		fatal_error();

	// END COPY-PASTE
	/*select() blocks until one or more file descriptors are ready for I/O */
	while (1)
	{
		rfds = wfds = afds;

		/*Detailed Explanation:
select(max_fd + 1, &rfds, &wfds, NULL, NULL)
Argument 1: max_fd + 1 (nfds)

Tells select() how many file descriptors to check
It checks from fd=0 to fd=max_fd (inclusive)
You must pass max_fd + 1 because it's the count, not the highest fd
Example: If max_fd = 5, select checks fds: 0, 1, 2, 3, 4, 5 (that's 6 fds total)

Argument 2: &rfds (readfds) ✅ MONITORED

File descriptors to monitor for READING
Select will wake up when:

Server socket: New client wants to connect
Client socket: Client sent data to read
Client socket: Client disconnected (recv returns 0)



Argument 3: &wfds (writefds) ✅ MONITORED

File descriptors to monitor for WRITING
Select will wake up when:

Socket is ready to accept data (send buffer has space)


In your code, this is used to check which clients are ready to receive broadcasts */

		if (select(max_fd + 1, &rfds, &wfds, NULL, NULL) < 0)
			fatal_error();
		/*
		## Visual Timeline:
```
Step 1: Copy master set
afds:  0001111000  (fds 3,4,5,6 are active)
rfds:  0001111000  (copy for select)

Step 2: select() called - blocks...
       (waiting for any of fds 3,4,5,6 to have data)

Step 3: Client fd=5 sends "Hello"

Step 4: select() returns and MODIFIES rfds
rfds:  0000100000  (only fd 5 is ready!)
       ││││││││││
       │││││└───── bit 5 stayed 1 (fd 5 ready!)
       ││││└────── bit 4 changed 1→0 (fd 4 not ready)
       │││└─────── bit 3 changed 1→0 (fd 3 not ready)
       ││└──────── bit 6 changed 1→0 (fd 6 not ready)
       ...

Step 5: Check with FD_ISSET
FD_ISSET(3, &rfds) → bit 3 is 0 → FALSE
FD_ISSET(4, &rfds) → bit 4 is 0 → FALSE
FD_ISSET(5, &rfds) → bit 5 is 1 → TRUE! ✓
FD_ISSET(6, &rfds) → bit 6 is 0 → FALSE
```

## Example with Multiple Ready FDs:

What if TWO clients send data at the same time?
```
Before select():
rfds: 0001111000  (monitoring fds 3,4,5,6)

Client fd=4 sends "Hi"
Client fd=6 sends "Bye"
(both happen before select() wakes up)

After select():
rfds: 0001010000  (both fd 4 and fd 6 are ready!)
      ││││││││││
      │││└─────── bit 4 = 1 (fd 4 ready!)
      │└──────── bit 6 = 1 (fd 6 ready!)
      └───────── bits 3,5 = 0 (not ready)

Loop processes BOTH:
- FD_ISSET(4, &rfds) → TRUE → handle fd 4
- FD_ISSET(6, &rfds) → TRUE → handle fd 6 */


/*so the select statement will pause and stop, then it release when one of fds has an update, or ready to read then we have to search to find who did this */

/*
You must **search through all fds** to find which bit(s) are set to 1.

## Visual Example:
```
You have: Server fd=3, Clients fd=4,5,6,7,8

Before select():
rfds: {3, 4, 5, 6, 7, 8}  (all bits = 1)

select() blocks... ⏸️
select() blocks... ⏸️
select() blocks... ⏸️

Client fd=5 sends "Hello"

select() wakes up! ▶️

After select():
rfds: {5}  (only bit 5 = 1, others = 0)

BUT select() doesn't tell you "it's fd 5"!
You have to search:

Loop iteration 0: FD_ISSET(0, &rfds)? NO (bit 0 = 0)
Loop iteration 1: FD_ISSET(1, &rfds)? NO (bit 1 = 0)
Loop iteration 2: FD_ISSET(2, &rfds)? NO (bit 2 = 0)
Loop iteration 3: FD_ISSET(3, &rfds)? NO (bit 3 = 0)
Loop iteration 4: FD_ISSET(4, &rfds)? NO (bit 4 = 0)
Loop iteration 5: FD_ISSET(5, &rfds)? YES! ← Found it!
                  Handle fd 5...
Loop iteration 6: FD_ISSET(6, &rfds)? NO (bit 6 = 0)
Loop iteration 7: FD_ISSET(7, &rfds)? NO (bit 7 = 0)
Loop iteration 8: FD_ISSET(8, &rfds)? NO (bit 8 = 0)
```

## What if Multiple FDs are Ready?
```
Clients fd=4 and fd=7 both send data at the same time

After select():
rfds: {4, 7}  (both bits = 1)

Loop will find BOTH:
Loop iteration 4: FD_ISSET(4, &rfds)? YES! ← Handle fd 4
Loop iteration 5: FD_ISSET(5, &rfds)? NO
Loop iteration 6: FD_ISSET(6, &rfds)? NO
Loop iteration 7: FD_ISSET(7, &rfds)? YES! ← Handle fd 7 */


for (int fd = 0; fd <= max_fd; fd++)
		{
			if (!FD_ISSET(fd, &rfds))
				continue;

			if (fd == sockfd)
			{
				socklen_t addr_len = sizeof(servaddr);
				int client_fd = accept(sockfd, (struct sockaddr *)&servaddr, &addr_len);
				if (client_fd >= 0)
				{
					register_client(client_fd);
					break ;
				}
			}
			else
			{
				int read_bytes = recv(fd, buf_read, 1000, 0);
				if (read_bytes <= 0)
				{
					remove_client(fd);
					break ;
				}
				buf_read[read_bytes] = '\0';
				msgs[fd] = str_join(msgs[fd], buf_read);
				send_msg(fd);
			}
		}
	}
	return 0;
}
