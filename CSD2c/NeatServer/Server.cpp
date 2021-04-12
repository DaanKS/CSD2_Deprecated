#include "Server.h"
#include <vector>
#include <atomic>
#include <cstring>
#include <thread>
#include <chrono>



using namespace std;

TCPservertje::TCPservertje(int portNumber)
{
this->portNumber = portNumber;
}

int TCPservertje::startTheServer()
{
  //create a socket
  int listening = socket(AF_INET, SOCK_STREAM, 0);
  if (listening == -1)
  {
    cerr << "Can't create a socket!";
    return -1;
  }
  //bind the socket to a IP / port
  sockaddr_in hint;
  hint.sin_family = AF_INET;
  hint.sin_port = htons(portNumber);
  inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr); //127.0.0.1

  if(bind(listening, (sockaddr*)&hint, sizeof(hint)) == -1)
  {
    cerr << "Can't bind to IP/port";
    return -2;
  }
  //mark the socket for listening
  if (listen(listening, SOMAXCONN) == -1)
  {
    cerr << "Can't listen!";
    return -3;
  }
  //accept call
  sockaddr_in client;
  socklen_t clientSize = sizeof(client);
  char host[NI_MAXHOST];
  char svc[NI_MAXSERV];

  int clientSocket = accept(listening,
                          (sockaddr*)&client,
                          &clientSize);
  if (clientSocket == -1)
  {
    cerr << "Problem with client connecting";
    return -4;
  }

  // close the listening socket
  close(listening);

  memset(host, 0, NI_MAXHOST);
  memset(svc, 0, NI_MAXSERV);

  int result = getnameinfo((sockaddr*)&client,
                                    sizeof(client),
                                    host,
                                    NI_MAXHOST,
                                    svc,
                                    NI_MAXSERV,
                                    0);

  if(result)
  {
    cout << host << " connected on " << svc << endl;
  }
  else
  {
    inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
    cout << host << " connected on " << ntohs(client.sin_port) << endl;
  }

  //while receiving display message, echo message
  char buf[4096];
  while (true)
  {
    //clear the buffer
    memset(buf, 0, 4096);
    //wait for a message
    int bytesRecv = recv(clientSocket, buf, 4096, 0);
    if (bytesRecv == -1)
    {
      cerr << "Bye" << endl;
      break;
    }
    if (bytesRecv == 0)
    {
      cout << "The client disconnected" << endl;
      break;
    }
    //display message
    // cout << "Received: " << std::string(buf, 0., bytesRecv) << endl;
    string sliderVariabel = string(buf, 0., bytesRecv);
    int sliderVariabelInt = stoi(sliderVariabel);
  //  cout << sliderVariabelInt << endl;

    //resend message
    send(clientSocket, buf, bytesRecv + 1, 0);

  }
  // close the socket
  close(clientSocket);
return 0;
}
int TCPservertje::sliderOutput(std::mutex& theMutex)
{
  std::unique_lock<std::mutex> myLock(theMutex);
  return sliderVariabelInt;
  myLock.unlock();
}



TCPservertje::~TCPservertje()
{}
