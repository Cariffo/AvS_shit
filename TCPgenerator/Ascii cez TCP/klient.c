/* 
 * File:   main.c
 * Author: student
 *
 * Created on May 30, 2016, 2:16 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>          
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8888
#define MSGLEN 2000
#define ASCIILEN ((126-32)+1)
/*
 * 
 */
int main(int argc, char** argv) {
    int Socket;
    struct sockaddr_in server;
    char client_message[MSGLEN], server_reply[MSGLEN], ascii[ASCIILEN];
    
    
    Socket = socket(AF_INET, SOCK_STREAM, 0);
    
    server.sin_family=AF_INET;
    server.sin_port=htons(PORT);
    server.sin_addr.s_addr=inet_addr("127.0.0.1");
    
    connect(Socket, (struct sockaddr *) &server, sizeof(server));
    
    memset(client_message, '\0', MSGLEN);
    memset(server_reply, '\0', MSGLEN);
    
    for(;;) {
 //       for(i=32; i<=126; i++)
 //       {
        
/*
        printf("> ");
        
        scanf("%s", client_message);
        //printf("%d", ASCIILEN);
        send(Socket, client_message, strlen(client_message),0);
*/
        recv(Socket, ascii, ASCIILEN,0);
        
        printf("%s\n", ascii);
        
/*
        
        recv(Socket, client_message, MSGLEN, 0);
        printf("%s\n", client_message);
        write (Socket, "got it", strlen(client_message));
*/

 //       }
    }
        
    close(Socket);
    return (EXIT_SUCCESS);
}

