#include "DDWebRouter.h"

DDWebRouter::DDWebRouter()
{
}

DDWebRouter& DDWebRouter::GetInstance()
{
	static DDWebRouter instance;
	return instance;
}

DDString DDWebRouter::RouteRequest(const DDWebRequest& webRequest)
{
	if (webRequest.method == "GET" && webRequest.target == "\\home")
	{

	}

	return "";
}
