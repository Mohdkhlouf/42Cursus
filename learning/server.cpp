#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main()
{   
    int serverSocket = socket(AF_INET,SOCK_STREAM,0);
    if(serverSocket < 0){
        perror("Socket creation Failed");
        return(1);
    }
    std::cout << "Socket created successfully! FD: "<< serverSocket<< std::endl;

    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&serverAddress,sizeof(serverAddress));
    
    
    while (listen(serverSocket, 5) == 0)
    {
  int clientSocket = accept(serverSocket, nullptr, nullptr);


    char buffer[1024] = {0};
    while(recv(clientSocket, buffer, sizeof(buffer), 0) > 0)
    {
        std::cout << "Message from client: " << buffer
                << std::endl;
    }

    }
      







    close(serverSocket);
    return (0);
}