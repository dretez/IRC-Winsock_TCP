#pragma once

int writeN(SOCKET sock, char* buf, int nbytes);

int readLine(SOCKET sock, char* buf, int tamMax);

