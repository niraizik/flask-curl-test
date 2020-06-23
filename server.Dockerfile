FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y \
    python3 \
    python3-pip \
    libpq-dev \
    pylint \
&& rm -rf /var/lib/apt/lists/*

COPY ./requirements.txt /app/

WORKDIR /app

RUN pip3 install --requirement requirements.txt

COPY . /app

RUN pylint -E *.py

CMD ["python3","app.py"]