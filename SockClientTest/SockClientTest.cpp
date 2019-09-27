// SockClientTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>  
#include <boost/thread.hpp>
#include <Winsock2.h>  

#pragma comment(lib,"ws2_32.lib")

#pragma warning(disable:4996)

#include <iostream>

int Sender() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0) {

		return -1;

	}

	if (LOBYTE(wsaData.wVersion) != 1 ||

		HIBYTE(wsaData.wVersion) != 1) {

		WSACleanup();

		return -1;

	}

	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;

	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	addrSrv.sin_family = AF_INET;

	addrSrv.sin_port = htons(8889);

	connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR));

	const char baseCh[] = "hello, world!";
	for (int clc = 0; clc < 5; clc++)
	{
		send(sockClient, baseCh, strlen(baseCh) + 1, 0);

		char recvBuf[50];

		recv(sockClient, recvBuf, 50, 0);

		printf("severRecv %s\n", recvBuf);

		char t[2];

		std::cin >> t;

	}

	closesocket(sockClient);
	WSACleanup();

	return 0;
}

int Reciever() {
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(1, 1);

	err = WSAStartup(wVersionRequested, &wsaData);

	if (err != 0) {
		return -1;
	}

	if (LOBYTE(wsaData.wVersion) != 1 ||
		HIBYTE(wsaData.wVersion) != 1) {
		WSACleanup();
		return -1;

	}

	SOCKET sockClient = socket(AF_INET, SOCK_STREAM, 0);
	SOCKADDR_IN addrSrv;

	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");

	addrSrv.sin_family = AF_INET;

	addrSrv.sin_port = htons(8890);
	
	try
	{
		int connectCount = 0;
		while (connect(sockClient, (SOCKADDR*)&addrSrv, sizeof(SOCKADDR)) != 0) {
			printf("connecting at No.%d \n", ++connectCount);
			Sleep(3);
		}
		printf("connected!\n");
		const char baseCh[] = "hello, this is message from cpp!";
		send(sockClient, baseCh, strlen(baseCh) + 1, 0);
		int ret = 0;
		do
		{

			char recvBuf[50] = "";

			ret = recv(sockClient, recvBuf, 50, 0);

			printf("Receive:%s\n", recvBuf);

		} while (ret > 0);
	}
	catch (const std::exception&)
	{
		closesocket(sockClient);
		WSACleanup();
	}
	return 0;
}

int main()
{

	
	//boost::thread thr(Reciever);
	Reciever();
	getchar();
	return 0;

}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
