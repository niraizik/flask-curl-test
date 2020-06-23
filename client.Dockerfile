FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    gcc \
    curl \
    libcurl4 \
    libcurl4-openssl-dev \
&& rm -rf /var/lib/apt/lists/*


WORKDIR /app

COPY . /app

RUN gcc -o client client.c -lcurl

CMD ["./client"]