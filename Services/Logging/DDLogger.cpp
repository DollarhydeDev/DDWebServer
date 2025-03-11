#include "DDLogger.h"

DDLogger::DDLogger()
{
	_infoPrefix = "[INFO] ";
	_errorPrefix = "[ERROR] ";
}

DDLogger& DDLogger::GetInstance()
{
	static DDLogger instance;
	return instance;
}

void DDLogger::LogInfo(DDString message)
{
	std::cout << _infoPrefix << message << std::endl;
}
void DDLogger::LogInfo(const char* message)
{
	std::cout << _infoPrefix << message << std::endl;
}

void DDLogger::LogError(DDString message)
{
	std::cout << _errorPrefix << message << std::endl;
}
void DDLogger::LogError(const char* message)
{
	std::cout << _errorPrefix << message << std::endl;
}
