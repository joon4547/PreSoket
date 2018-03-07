#include <stdio.h>
#include <WinSock2.h>

int main(int argc, char * argv[])
{
	SOCKET sock; //소켓 생성 구조체.
	WSADATA wsa; //윈속 초기화 구조체.

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// "인터넷 영역을 사용하는 TCP방식의 프로토콜"

	if (sock == INVALID_SOCKET)
		return 1;
	
	printf("성공\n");

	WSACleanup();

	return 0;
	
}