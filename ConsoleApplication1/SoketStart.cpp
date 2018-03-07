#include <stdio.h>
#include <WinSock2.h>

int main(int argc, char * argv[])
{
	SOCKET sock; //소켓 생성 구조체.
	WSADATA wsa; //윈속 초기화 구조체.

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// "인터넷 영역을 사용하는 TCP방식의 프로토콜"

	if (sock == INVALID_SOCKET) //INVALID_SOCKET은 양수가 아닌 에러코드 갑을 의미한다. 
								//왜냐하면 SOCKET 자료형이 unsinged int 양수 이기 때문.
								//socket은 핸들 값으로 나오기 때문에 선언한 변수에 저장시켜서 이용해야 한다.
		return 1;
	
	printf("성공\n");

	WSACleanup();

	return 0;
	
}