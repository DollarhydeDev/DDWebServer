#pragma once

#include "../../DataTypes/String/DDString.h"

class DDLogger
{
private:
	DDString _infoPrefix;
	DDString _errorPrefix;

public:
	DDLogger();
	static DDLogger& GetInstance();

	void LogInfo(DDString message);
	void LogInfo(const char* message);

	void LogError(DDString message);
	void LogError(const char* message);
};

