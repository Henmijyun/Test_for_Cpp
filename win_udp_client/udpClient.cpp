#pragma warning(disable:4996)

#include <WinSock2.h>
#include <iostream>
#include <string>

using namespace std;
#pragma comment(lib,"ws2_32.lib") // �̶��÷�


uint16_t serverport = 8080;
std::string serverip = "120.78.124.123";    // ������IP


int main()
{
	// windows ���е�
	WSADATA WSAData;
	WORD sockVersion = MAKEWORD(2, 2);
	if (WSAStartup(sockVersion, &WSAData) != 0)
		return 0;

	SOCKET clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
	if (INVALID_SOCKET == clientSocket)
	{
		cout << "socket error!";
		return 0;
	}

	sockaddr_in dstAddr;
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_port = htons(serverport);
	dstAddr.sin_addr.S_un.S_addr = inet_addr(serverip.c_str());

	char buffer[1024];

	while (true)
	{
		std::string message;
		std::cout << "������# ";
		std::getline(std::cin, message);
		sendto(clientSocket, message.c_str(), (int)message.size(), 0, (sockaddr*)&dstAddr, sizeof(dstAddr));

		struct sockaddr_in temp;
		int len = sizeof(temp);
		int s = recvfrom(clientSocket, buffer, sizeof buffer, 0, (sockaddr*)&temp, &len);
		if (s > 0)
		{
			buffer[s] = '\0';
			std::cout << "server echo# " << buffer << std::endl;
		}
	}

	// windows ����
	closesocket(clientSocket);
	WSACleanup();

	return 0;
}