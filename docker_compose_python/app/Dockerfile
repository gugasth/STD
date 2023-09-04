FROM python:3.10-alpine
WORKDIR /app

# Definindo variáveis de ambiente que serão usadas pela aplicação
ENV FLASK_APP=app.py
ENV FLASK_RUN_HOST=0.0.0.0
ENV PYTHONUNBUFFERED=1

# instalando pacotes com o gerenciador do Alpine Linux
RUN apk add --no-cache gcc musl-dev linux-headers

# Iremos montar um volume e não copiar (COPY app/* .) o código para dentro da imagem.
# Isso permitirá alterar o código fonte do projeto sem a necessidade de alterar a imagem.

# copiando somente o arquivo requirements.txt
COPY requirements.txt requirements.txt

# instalando pacotes python
RUN pip install -r requirements.txt

# Flask coloca um servidor web para ouvir por padrão na porta 5000
EXPOSE 5000

CMD ["flask", "run"]