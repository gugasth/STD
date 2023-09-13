#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG 1024

int main(int argc, char *argv[])
{
    // 1° ip, 2° porta, 3° arquivo

    // declara a ip
    char ip[MAX_MSG];
    
    // le a ip
    ip[MAX_MSG] = argv[1];

    // declara e le a porta
    int porta = argv[2];

    // declara o arquivo
    char arquivo[MAX_MSG];

    // recebe o arquivo
    arquivo[MAX_MSG] = argv[3]; 







    // variaveis
    int socket_desc;
    struct sockaddr_in servidor;
    char *mensagem;
    char resposta_servidor[MAX_MSG];
    int tamanho;

    /*****************************************/
    /* Criando um socket */
    // AF_INET = ARPA INTERNET PROTOCOLS
    // SOCK_STREAM = TCP
    // 0 = protocolo IP
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);

    if (socket_desc == -1)
    {
        printf("Nao foi possivel criar socket\n");
        return -1;
    }

    /* Informacoes para conectar no servidor */
    
    // familia ARPANET
    servidor.sin_family = AF_INET;
    // IP do servidor
    servidor.sin_addr.s_addr = inet_addr("191.36.13.98");
    // Porta - hton = host to network short (2bytes)
    servidor.sin_port = htons(1234);

    // Conectando no servidor remoto
    if (connect(socket_desc, (struct sockaddr *)&servidor, sizeof(servidor)) < 0)
    {
        printf("Nao foi possivel conectar\n");
        return -1;
    }
    printf("Conectado no servidor\n");
    /*****************************************/

    /******* TROCA DE MENSAGENS **************/

    // Servidor manda a primeira mensagem, então consumindo mensagem de boas vindas
    if ((tamanho = recv(socket_desc, resposta_servidor, MAX_MSG, 0)) < 0)
    {
        printf("Falha ao receber resposta\n");
        return -1;
    }
    resposta_servidor[tamanho] = '\0';
    puts(resposta_servidor);

    // Envia mensagem para o servidor
    mensagem = "Ola, tudo bem?\n";
    printf("Enviando: %s\n", mensagem);
    if (send(socket_desc, mensagem, strlen(mensagem), 0) < 0)
    {
        printf("Erro ao enviar mensagem\n");
        return -1;
    }

    // Recebendo resposta do servidor (echo)
    if ((tamanho = recv(socket_desc, resposta_servidor, MAX_MSG, 0)) < 0)
    {
        printf("Falha ao receber resposta\n");
        return -1;
    }
    printf("Resposta: ");
    resposta_servidor[tamanho] = '\0';
    puts(resposta_servidor);

    /*****************************************/
    close(socket_desc);

    printf("Cliente finalizado com sucesso!\n");
    return 0;
}
