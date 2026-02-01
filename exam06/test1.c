#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <netinet/ip.h>


int count = 0;
int max_fd = 0;

FD_SET rfds,wfds,afds;

int ids[65536];
char *msgs[65536];

char buff_read[1001];
char buff_write[42];

void fatal_error(){
    write(2,"Fatal error\n",12);
    exit(1)
}



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

void notify_others(int author, char *msg){
    for (int fd =0; fd <=max_fd; fd++){
        if(FD_ISSET(fd, &wfds) && fd != author){
            send(fd, msg, strlen(msg), 0)
        }

    }
}

int create_socket(){
    max_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(max_fd < 0)
        fatal_error();
    FD_SET(max_fd, &adfs);
    return (max_fd);
}

void send_msg(int fd){
    char *msg;
    while(extract_message(&(msgs[fd]), &msg)){
        sprintf(buff_write, "client %d", ids[fd]):
        notify_all(fd, buff_write);
        notify_all(fd, msg);
        free(msg);
    }
}

int create_socket(){
    max_fd =socket(AF_INET, SOCK_STREAM, 0);
    if(max_fd <0)
        fatal_error();
    FD_SET(max_fd, &afds);
    return(max_fd);
}
int main(int argc, char **argv){
    if( argc != 2){
        write(2,"Wrong number of arguments\n",26);
        exit(1);
    }
    int sockfd = create_socket();
    struct sockaddr_in servaddr;
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1
	servaddr.sin_port = htons(atoi(argv[1]));

	if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1)
	    fatal_error();

	if (listen(sockfd, SOMAXCONN) == -1)
	    fatal_error();

	while(1){
	wfds=rfds=afds;
	if(select(max_fd+1, &rfds, &wfds, NULL, NULL) < 0)
        fatal_error();
	for(int fd = 0; fd <= max_fd; fd++){

	if(!FD_ISSET(fd, &rfds))
	    continue;

	if (fd == socket_fd){
	    socklen_t add_len = sizeof(servaddr);
	    int client_fd = accept(socket_fd,(struct sockaddr *)&servaddr, add_len)
		if(client_fd >= 0){
		    register_client(client_fd);
			break;
		}
	}
	else{
	    int read_bytes = recv(fd, read_buff, 1000 , 0);
		if(read_bytes <= 0){
		    remove_client(fd);
            break;
		}
		read_buff[read_bytes]='\0';
		msgs[fd] = str_join(msgs[fd], read_buff);
		send_msg(fd);
	}


	}

	}
	}


	}

    returh (0);
}
