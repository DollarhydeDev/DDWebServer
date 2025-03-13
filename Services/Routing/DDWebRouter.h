#pragma once

#include "String/DDString.h"

#include "WebServerActions/DDWebRequest.h"

class DDWebRouter
{
public:
	DDWebRouter();
	static DDWebRouter& GetInstance();

	DDString RouteRequest(const DDWebRequest& webRequest);
};

