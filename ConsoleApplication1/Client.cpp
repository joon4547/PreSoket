#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>

int main(int argc, char* argv[])
{
	SOCKET clientsock; //클라이언트 프로그램 소켓 핸들 생성. 
	WSADATA wsa;
	struct sockaddr_in sockinfo;//서버 연결 할 주소 구조체 생성

	char message[30]; //recv함수 메시지 받을 배열 선언
	int strlen;	//recv 리턴 값 저장 할 변수 선언

	if (argc != 3)	//입력 (IP, PORT) 가 입력되지 않을 떄 오류 표시
	{
		printf("Usage : %s <IP> <PORT> \n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		printf("초기화 실패\n");

	clientsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientsock == INVALID_SOCKET)
		printf("소켓 생성 실패\n");

	memset(&sockinfo, 0, sizeof(sockinfo));	//주소 구조체 함수 초기화

	sockinfo.sin_family = AF_INET; //주소 체계 명시.
	sockinfo.sin_port = htons(atoi(argv[2]));	//포트를 두 번째로 입력 받음
	sockinfo.sin_addr.s_addr = inet_addr(argv[1]);//IP를 첫 번째로 입력 받음	




	//connect(클라이언트 소켓, (SOCKADDR*) &서버주소구조체, sizeof(서버주소구조체)
	if (connect(clientsock, (SOCKADDR*)&sockinfo, sizeof(sockinfo) == SOCKET_ERROR)) //서버 측에 연결 요청
		printf("서버 접속 실패 \n");

	strlen = recv(clientsock, message, sizeof(message) - 1, 0);

	//recv 함수 반환 값 저장
	if (strlen == -1)	//recv함수 반환 값이 -1이면 메시지 수신 실패
		printf("메세지 수신 실패\n");

	printf("Server say : %s \n", message); //수신 된 메시지 표시

	closesocket(clientsock);

	WSACleanup();

}