#include "Core/DDWebServer.h"

int main()
{
	// Launch new WebServer instance
	DDWebServer webServerInstance;
	{
		if (!webServerInstance.Init()) return 1;
		webServerInstance.Run();
	}

	return 0;
}