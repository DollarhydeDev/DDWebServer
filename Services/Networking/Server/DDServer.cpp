#include "DDServer.h"

DDServer::DDServer() : _logger(DDLogger::GetInstance()), _serverSocket(), _wsaData() {}
DDServer::~DDServer()
{
	WSACleanup();
}

DDWebRequest DDServer::ParseRequest(const char* requestData)
{
    DDWebRequest request;

    // TO DO: add function to DD string for locating characters
    // Will use new DDString methods to split up the request data and parse it

    return request;
}
void DDServer::SendResponse(SOCKET client)
{
    const char* body = "<html><body>Hello from Web server!</body></html>";
    int bodyLength = strlen(body);

    char response[512] = { 0 }; // Response buffer
    int responseLength = snprintf(response, sizeof(response),
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: %d\r\n"
        "Connection: close\r\n"
        "\r\n"
        "%s",
        bodyLength, body);

    send(client, response, responseLength, 0);
}

DDServer& DDServer::GetInstance()
{
    static DDServer instance;
    return instance;
}
bool DDServer::Init()
{
	int result = WSAStartup(MAKEWORD(2, 2), &_wsaData);
	if (result != 0)
	{
		_logger.LogError("Server initialization failed");
		return false;		
	}

	_logger.LogInfo("Server initialized");
	return true;
}

DDWebRequest DDServer::WaitForRequest(DDString portToListenOn)
{
    if (_serverSocket.BindAndListen(portToListenOn.Data()))
    {
        while (true)
        {
            SOCKET client = _serverSocket.AcceptConnection();
            if (client != INVALID_SOCKET)
            {
                _logger.LogInfo("New client connection established.");

                char buffer[4096] = { 0 };
                int bytesReceived = recv(client, buffer, sizeof(buffer) - 1, 0);
                if (bytesReceived > 0)
                {
                    buffer[bytesReceived] = '\0';
                    _logger.LogInfo("Received request");

                    DDWebRequest request = ParseRequest(buffer);
                    SendResponse(client);

                    closesocket(client);
                    return request;
                }

                closesocket(client);
            }
        }
    }

    return DDWebRequest();
}

