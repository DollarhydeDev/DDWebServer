#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#pragma comment(lib, "Ws2_32.lib")

#include "List/DDList.h"
#include "String/DDString.h"

#include "ServerSocket/DDServerSocket.h"
#include "WebServerActions/DDWebRequest.h"

#include "Logging/DDLogger.h"
#include "Routing/DDWebRouter.h"

class DDServer
{
	// Members
private:
	WSADATA _wsaData;
	DDServerSocket _serverSocket;

	DDLogger& _logger;
	DDWebRouter& _router;

	// Constructors
public:
	DDServer();
	~DDServer();

	// Private Functions
private:
	DDWebRequest ParseRequest(const DDString& requestData);
	void SendResponse(SOCKET client);

	// Public functions
public:
	static DDServer& GetInstance();

	bool Init();
	DDWebRequest WaitForRequest(DDString portToListenOn);

};

