// SockClientTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stdio.h>  
#include <boost/thread.hpp>
#include <Winsock2.h>  
#include "weights.h"

#pragma comment(lib,"ws2_32.lib")

#pragma warning(disable:4996)

#include <iostream>
class MyClientSocket {
public:
	
	MyClientSocket() {

		WORD wVersionRequested;
		WSADATA wsaData;
		int err;
		wVersionRequested = MAKEWORD(1, 1);

		err = WSAStartup(wVersionRequested, &wsaData);

		if (err != 0) {
			return;
		}

		if (LOBYTE(wsaData.wVersion) != 1 ||
			HIBYTE(wsaData.wVersion) != 1) {
			WSACleanup();
			return;
		}

		sockClient = socket(AF_INET, SOCK_STREAM, 0);
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

		}
		catch (const std::exception&)
		{
			closesocket(sockClient);
			WSACleanup();
		}

	};

	 int receiveMsg(char recvBuf[1024]) {
		 // wait for the msg until receive NULL msg
		 
		 int ret = recv(sockClient, recvBuf, 1024, 0);
		 printf("Receive:%s %d\n", recvBuf, sizeof(recvBuf));
		 return ret;
	 }
	 int sendMsg() {
		 const char baseCh[] = "hello, this is message from cpp!";
		 send(sockClient, baseCh, strlen(baseCh) + 1, 0);
		 return 0;
	 }
	 ~MyClientSocket() {
		 closesocket(sockClient);
		 WSACleanup();
	 }
private:
	SOCKET sockClient = { 0 };
};



int main()
{
	// 1. 把 JSON 解析至 DOM。
	//const char* json = "{\"pena_max_latg_double\": 5.0,\"pena_latg_double\": 5.0, \"pena_spd_double\": 5.0, \"pena_a_max_double\": 5.0, \"pena_a_min_double\": 5.0, \"pena_curv_rate_double\": 5.0, \"dynamic_obstacle_lethal_cost_double\": 5.0, \"dynamic_obstacle_high_cost_double\": 5.0}";
	


	
	//boost::thread thr(Reciever);
	MyClientSocket myClientSocket;
	char json[1024];
	myClientSocket.receiveMsg(json);
	Weights w(json);
	std::cout <<"GetJson:" << w.getJson() << std::endl;
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
