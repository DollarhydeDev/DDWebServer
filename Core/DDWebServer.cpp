#include "DDWebServer.h"

DDWebServer::DDWebServer() : _server(DDServer::GetInstance()), _logger(DDLogger::GetInstance()) {}
DDWebServer::~DDWebServer()
{
	_logger.LogInfo("Server cleaning up...");
	_logger.LogInfo("Cleanup finished");
}

bool DDWebServer::Init()
{
	_logger.LogInfo("Server initializing...");
	_logger.LogInfo("Server initialized");
	return true;
}

void DDWebServer::Run()
{
	_logger.LogInfo("Server started");
}
