# Ft_ping

This project aims to copy how the real ping command works !

## Use

This project uses a docker container as a VM, you need to have both docker and docker compose installed on your system, then you can use [start.sh](./start.sh).

You can just run `./start.sh` or `sudo ./start.sh` since it uses docker to create a container where you can run `make` then `ft_ping <ip>`.

## How it works

The programs aims to replicate the `ping` utility command, here's how it works:
- We create a main socket with timeout/ttl parameters using `socket()` and `setsockopt()`.
- A loop will now run:
	- It will send a packet to the destination:
		- First we record the time at which we sent the packet
		- We first create a `t_packet` which contains a `icmphdr` struct and a buffer.
		- We send it through our main socket using `sendto()`
		- We also set our global `send` variable to false
	- After sending the packet, we will listen and receive the response:
		- We use `recv()` to get the answer as raw bytes
		- We can then retrieve the IP header and store it inside a `ip` struct
		- Then we get the ICMP header using `icmphdr`
		- We will then be able to check if the answer is OK or not
		- Check the time at which we received the packet and compute the diff to get how long it took.

## Useful

- Ping wiki page with packets informations: https://en.wikipedia.org/wiki/Ping_(networking_utility)
- Most network utility functions set ERRNO to a value when an error happens, using `perror()` we can nicely print the corresponding error message.
