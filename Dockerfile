FROM debian:latest
RUN apt-get update -y && apt-get install gcc -y && apt-get install make -y && apt-get install tcpdump -y && apt install inetutils-ping -y && apt-get install automake autoconf texinfo -y
COPY app /app
