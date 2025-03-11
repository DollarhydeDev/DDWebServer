#pragma once

#include "List/DDList.h"
#include "Logging/DDLogger.h"
#include "Server/DDServer.h"

class DDWebServer
{
	// Members
private:
	DDServer& _server;
	DDLogger& _logger;

	// Constructors
public:
	DDWebServer();
	~DDWebServer();

	// Private Functions
private:

	// Public functions
public:
	bool Init();
	void Run();
};

