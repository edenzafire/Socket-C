// ========================== servidor.c ==========================
#include "servidor.h"

int main() {
    int servidor_fd, novo_cliente_fd;
    struct sockaddr_in endereco_servidor, endereco_cliente;
    socklen_t tamanho_cliente = sizeof(endereco_cliente);

    servidor_fd = criar_socket();
    configurar_endereco(&endereco_servidor);
    bindar_socket(servidor_fd, &endereco_servidor);
    escutar(servidor_fd);

    tela_boas_vindas();

    while (1) {
        novo_cliente_fd = accept(servidor_fd, (struct sockaddr*)&endereco_cliente, &tamanho_cliente);
        if (novo_cliente_fd < 0) {
            perror("Erro no accept");
            continue;
        }

        if (fork() == 0) {
            close(servidor_fd);
            lidar_com_cliente(novo_cliente_fd);
            exit(0);
        } else {
            close(novo_cliente_fd);
        }
    }

    close(servidor_fd);
    return 0;
} 


