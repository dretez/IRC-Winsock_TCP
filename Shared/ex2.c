#include <winsock.h>

#include "ex2.h"

#pragma comment(lib,  "Ws2_32.lib")

int writeN(SOCKET sock, char* buf, int nbytes)
{
	int i, sentbytes;
	char newl = '\n';

	for (i = 0; i < nbytes; i++) {
		sentbytes = send(sock, buf + i, sizeof(char), 0);
		if (sentbytes == SOCKET_ERROR) return sentbytes;
	}

	sentbytes = send(sock, &newl, sizeof(char), 0);
	if (sentbytes == SOCKET_ERROR) return sentbytes;

	return i;
}

int readLine(SOCKET sock, char* buf, int tamMax)
{
	int i;
	char c;
	for (i = 0; i < tamMax - 1; i++) {
		int nread = recv(sock, &c, sizeof(c), 0);
		if (nread == SOCKET_ERROR) return nread; // falha a comunicar com socket
		if (nread == 0) break;
		if (c == '\r') continue;
		if (c == '\n') break;

		buf[i] = c;
	}
	buf[i] = '\0';
	return i;
}

