#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "List/DDList.h"
#include "Logging/DDLogger.h"
#include "ServerSocket/DDServerSocket.h"

#include "WebServerActions/DDWebRequest.h"

class DDServer
{
	// Members
private:
	WSADATA _wsaData;
	DDLogger& _logger;
	DDServerSocket _serverSocket;

	// Constructors
public:
	DDServer();
	~DDServer();

	// Private Functions
private:
	DDWebRequest ParseRequest(const char* requestData);
	void SendResponse(SOCKET client);

	// Public functions
public:
	static DDServer& GetInstance();

	bool Init();
	DDWebRequest WaitForRequest(DDString portToListenOn);

};

