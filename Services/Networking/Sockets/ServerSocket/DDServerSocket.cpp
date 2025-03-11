#include "DDServerSocket.h"

DDServerSocket::DDServerSocket() : _logger(DDLogger::GetInstance())
{
    _listenSocket = INVALID_SOCKET;
    ZeroMemory(&_socketSettings, sizeof(_socketSettings));
    _socketSettings.ai_family = AF_INET;
    _socketSettings.ai_socktype = SOCK_STREAM;
    _socketSettings.ai_protocol = IPPROTO_TCP;
}
DDServerSocket::~DDServerSocket()
{
    CloseSocket();
}

bool DDServerSocket::BindAndListen(const char* port, int backlog)
{
    _logger.LogInfo("Initializing server socket...");

    addrinfo* addressInfo = nullptr;
    if (getaddrinfo(NULL, port, &_socketSettings, &addressInfo) != 0)
    {
        _logger.LogInfo("getaddrinfo failed");
        return false;
    }

    _listenSocket = socket(addressInfo->ai_family, addressInfo->ai_socktype, addressInfo->ai_protocol);
    if (_listenSocket == INVALID_SOCKET)
    {
        _logger.LogInfo("Socket creation failed.");
        freeaddrinfo(addressInfo);
        return false;
    }

    if (bind(_listenSocket, addressInfo->ai_addr, (int)addressInfo->ai_addrlen) == SOCKET_ERROR)
    {
        _logger.LogInfo("Bind failed.");
        closesocket(_listenSocket);
        freeaddrinfo(addressInfo);
        return false;
    }

    freeaddrinfo(addressInfo);

    if (listen(_listenSocket, backlog) == SOCKET_ERROR)
    {
        _logger.LogInfo("Listen failed.");
        closesocket(_listenSocket);
        return false;
    }

    _logger.LogInfo("Server socket is now listening");
    return true;
}

SOCKET DDServerSocket::AcceptConnection()
{
    SOCKET clientSocket = accept(_listenSocket, NULL, NULL);
    if (clientSocket == INVALID_SOCKET)
    {
        _logger.LogInfo("Failed to accept client connection.");
        return INVALID_SOCKET;
    }

    _logger.LogInfo("Client connected!");
    return clientSocket;
}

void DDServerSocket::CloseSocket()
{
    if (_listenSocket != INVALID_SOCKET)
    {
        closesocket(_listenSocket);
        _listenSocket = INVALID_SOCKET;
        _logger.LogInfo("Socket closed.");
    }
}