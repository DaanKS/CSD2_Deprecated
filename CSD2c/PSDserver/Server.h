#ifndef _SERVER_H_
#define _SERVER_H_


#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

class TCPservertje{

public:
TCPservertje(int portNumber);
~TCPservertje();

int startTheServer();
int sliderOutput();

int Alles();

int sliderVariabelInt;
int sliderVariabel2;
protected:
string sliderVariabel;
int portNumber;
int clientSocket;
};

#endif
