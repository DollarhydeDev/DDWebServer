#include "DDWebServer.h"

DDWebServer::DDWebServer() : _server(DDServer::GetInstance()), _logger(DDLogger::GetInstance()) {}
DDWebServer::~DDWebServer()
{
	_logger.LogInfo("Database cleaning up...");
	_logger.LogInfo("Cleanup finished");
}

bool DDWebServer::Init()
{
	_logger.LogInfo("Database initializing...");
	if (!_server.Init())
	{
		_logger.LogError("Database failed to initialize");
		return false;
	}

	_logger.LogInfo("Database initialized");
	return true;
}

void DDWebServer::Run()
{
	_logger.LogInfo("Database started");
	_server.WaitForRequest("8001");
}
