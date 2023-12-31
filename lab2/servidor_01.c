#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MSG 1024

/*
    Servidor aguarda por mensagem do cliente, imprime na tela
    e depois envia resposta e finaliza processo
*/

int main(void)
{
    int socket_desc, conexao, c;
    struct sockaddr_in servidor, cliente;
    char *mensagem;
    char resposta[MAX_MSG];
    int tamanho, count;

    // para pegar o IP e porta do cliente
    char *cliente_ip;
    int cliente_port;

    /*********************************************************/
    // Criando um socket
    // AF_INET = ARPA INTERNET PROTOCOLS -- IPv4
    // SOCK_STREAM = orientado a conexao
    // 0 = protocolo padrao para o tipo escolhido -- TCP
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1)
    {
        printf("Nao foi possivel criar o socket\n");
        return -1;
    }

    int reuso = 1;
    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuso, sizeof(reuso)) < 0)
    {
        perror("Não foi possível reusar endereço");
        return -1;
    }

#ifdef SO_REUSEPORT
    if (setsockopt(socket_desc, SOL_SOCKET, SO_REUSEPORT, (const char *)&reuso, sizeof(reuso)) < 0)
    {
        perror("Não foi possível reusar porta");
        return -1;
    }
#endif

    // Preparando a struct do socket
    servidor.sin_family = AF_INET;
    // Ficará ouvindo na porta 1234
    servidor.sin_port = htons(1234);
    // Obtem IP do S.O.
    servidor.sin_addr.s_addr = INADDR_ANY;

    // Associando o socket a porta e endereco
    if (bind(socket_desc, (struct sockaddr *)&servidor, sizeof(servidor)) < 0)
    {
        perror("Erro ao fazer bind\n");
        return -1;
    }
    puts("Bind efetuado com sucesso\n");

    // Ouvindo por conexoes
    listen(socket_desc, 3);

    /*********************************************************/
    // Aceitando e tratando conexoes
    puts("Aguardando por conexoes... \n(pressione CTRL+C para encerrar o processo)\n\n");
    c = sizeof(struct sockaddr_in);
    conexao = accept(socket_desc, (struct sockaddr *)&cliente, (socklen_t *)&c);
    if (conexao < 0)
    {
        perror("Erro ao receber conexao\n");
        return -1;
    }
    /*********************************************************/

    /********* comunicao entre cliente e servidor ****************/

    // pegando IP e porta do cliente
    cliente_ip = inet_ntoa(cliente.sin_addr);
    cliente_port = ntohs(cliente.sin_port);
    printf("cliente conectou\nIP:PORTA -> %s:%d\n", cliente_ip, cliente_port);

    // lendo dados enviados pelo cliente
    if ((tamanho = read(conexao, resposta, MAX_MSG)) < 0)
    {
        perror("Erro ao receber dados do cliente: ");
        return -1;
    }

    // Coloca terminador de string
    resposta[tamanho] = '\0';
    printf("O cliente falou: %s\n", resposta);

    // Enviando resposta para o cliente
    mensagem = "Ola cliente, tudo bem?\n";
    write(conexao, mensagem, strlen(mensagem));
    /*********************************************************/

    // http://www.gnu.org/software/libc/manual/html_node/Closing-a-Socket.html
    shutdown(socket_desc, 2);

    printf("Servidor finalizado...\n");
    return 0;
}