# nossa imagem sempre será de outra já existente, uso do FROM
FROM ubuntu:22.04

# RUN será executado quando construírmos a imagem, e não quando criar o container
# - RUN apt-get update \ 
# -    && apt-get install -y figlet \
# -    && rm -rf /var/lib/apt/lists/*

# qual o diretório de trabalho pra quando a pessoa rodar o container
# - WORKDIR /app

# Copiar o conteúdo pra imagem
# - COPY mensagem.txt /app/

# quando alguem usar um container a partir dessa imagem,
# executar esse comando
# sintaxe é vetor de strings [Comando, arg1, argN] 
# args são os argumentos do comando

# CMD ["figlet", "mensagem.txt"] 
# - CMD cat /app/mensagem.txt | figlet

# criei a imagem indo no diretório std e usando o comando
# docker build -t stdfiglet .

# rodei com o comando
# docker run --rm stdfiglet

# docker run -it --rm stdfiglet
# figlet < mensagem.txt




# DESAFIO botar o app java na imagem e rodar
# - WORKDIR /app
# - COPY ./appjava/app/build/install/app /aplicativo
# - CMD /aplicativo/bin/app
# rodar com <docker build -t aplicacao .>
# <docker run --rm aplicacao>

FROM gradle:8-jdk17-alpine

WORKDIR /aplicativo
COPY ./appjava /aplicativo
RUN gradle installDist


CMD /aplicativo/app/build/install/app/bin/app