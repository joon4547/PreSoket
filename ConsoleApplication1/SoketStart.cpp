#include <stdio.h>
#include <WinSock2.h>

int main(int argc, char * argv[])
{
	SOCKET sock,clientsock; //소켓 생성 구조체. 소켓과 클라이언트 소켓 핸들.
	WSADATA wsa; //윈속 초기화 구조체.
	struct sockaddr_in sockinfo,clientinfo;	//소켓,클라이언트소켓 주소 구조체 선언.
	int clientsize;	//클라이언트 size를 담을 변수.
	
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		printf("초기화 실패\n");

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// "인터넷 영역을 사용하는 TCP방식의 프로토콜"

	if (sock == INVALID_SOCKET)		//INVALID_SOCKET은 양수가 아닌 에러코드 갑을 의미한다. 
		printf("소켓 생성 실패\n");	//왜냐하면 SOCKET 자료형이 unsinged int 양수 이기 때문.
									//socket은 핸들 값으로 나오기 때문에 선언한 변수에 저장시켜서 이용해야 한다.
		
	sockinfo.sin_family = AF_INET;  //sin_family는 어떤 주소 체계를 사용할지 명시. AF_INET (인터넷 주소체계)를 사용하므로 Sockaddr_in을 사용하고 주소체계정보를 넣어주엇다.
	sockinfo.sin_port = htons(1234); //sin_port는 포트번호를 지정하는 부분. 서버 입장에서 클라이언트가 접속 할 떄, IP와 포트 번호로 서비스를 제공하기 때문에 사용 되는 것. 예시로 1234포트를 지정.
	sockinfo.sin_addr.s_addr = htonl(INADDR_ANY); //IP주소를 지정하는 부분. INADDR_ANY 는 0.0.0.0주소를 사용하는데 이것은 모든 사용 가능한 주소로 부터 대기하겠다는 의미.

	//Int bind ( 소켓 값 , (SOCKADDR*)&소켓주소구조체 저장값 , sizeof(소켓주소구조체 저장값) )	
	if (bind(sock, (SOCKADDR*)&sockinfo, sizeof(sockinfo)) == SOCKET_ERROR)
		printf("bind 실패");
		
	//int listen (SOCKET, backlog)  //SOCKET은 소켓 핸들 값, backlog는 통로 값. 정해진 값은 없으니 5정도만 넣으면 동시에 5개 통로가 개설됨.
	if (listen(sock, 5) == SOCKET_ERROR) 
		printf("대기열 실패");

	clientsize = sizeof(clientinfo); //size값을 변수에 저장.

	printf("클라이언트로부터 접속을 기다리고 있습니다...\n");

	clientsock = accept(sock, (SOCKADDR*)& clientinfo, &clientsize); //클라이언트 소켓 핸들 값을 저장.

	if (clientsock == INVALID_SOCKET)	//클라이언트 소켓  확인.
		printf("클라이언트 소켓 연결 실패");
	
	printf("성공\n");

	WSACleanup();

	return 0;
	
}