// ========================== servidor.h ==========================
#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORTA 8080
#define TAM_BUFFER 1024

int criar_socket();
void configurar_endereco(struct sockaddr_in* endereco);
void bindar_socket(int socket_fd, struct sockaddr_in* endereco);
void escutar(int socket_fd);
void lidar_com_cliente(int cliente_fd);
void tela_boas_vindas();

#endif

