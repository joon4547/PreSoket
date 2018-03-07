#include <stdio.h>
#include <WinSock2.h>

int main(int argc, char * argv[])
{
	SOCKET sock,clientsock; //���� ���� ����ü. ���ϰ� Ŭ���̾�Ʈ ���� �ڵ�.
	WSADATA wsa; //���� �ʱ�ȭ ����ü.
	struct sockaddr_in sockinfo,clientinfo;	//����,Ŭ���̾�Ʈ���� �ּ� ����ü ����.
	int clientsize;	//Ŭ���̾�Ʈ size�� ���� ����.
	
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		printf("�ʱ�ȭ ����\n");

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// "���ͳ� ������ ����ϴ� TCP����� ��������"

	if (sock == INVALID_SOCKET)		//INVALID_SOCKET�� ����� �ƴ� �����ڵ� ���� �ǹ��Ѵ�. 
		printf("���� ���� ����\n");	//�ֳ��ϸ� SOCKET �ڷ����� unsinged int ��� �̱� ����.
									//socket�� �ڵ� ������ ������ ������ ������ ������ ������Ѽ� �̿��ؾ� �Ѵ�.
		
	sockinfo.sin_family = AF_INET;  //sin_family�� � �ּ� ü�踦 ������� ���. AF_INET (���ͳ� �ּ�ü��)�� ����ϹǷ� Sockaddr_in�� ����ϰ� �ּ�ü�������� �־��־���.
	sockinfo.sin_port = htons(1234); //sin_port�� ��Ʈ��ȣ�� �����ϴ� �κ�. ���� ���忡�� Ŭ���̾�Ʈ�� ���� �� ��, IP�� ��Ʈ ��ȣ�� ���񽺸� �����ϱ� ������ ��� �Ǵ� ��. ���÷� 1234��Ʈ�� ����.
	sockinfo.sin_addr.s_addr = htonl(INADDR_ANY); //IP�ּҸ� �����ϴ� �κ�. INADDR_ANY �� 0.0.0.0�ּҸ� ����ϴµ� �̰��� ��� ��� ������ �ּҷ� ���� ����ϰڴٴ� �ǹ�.

	//Int bind ( ���� �� , (SOCKADDR*)&�����ּұ���ü ���尪 , sizeof(�����ּұ���ü ���尪) )	
	if (bind(sock, (SOCKADDR*)&sockinfo, sizeof(sockinfo)) == SOCKET_ERROR)
		printf("bind ����");
		
	//int listen (SOCKET, backlog)  //SOCKET�� ���� �ڵ� ��, backlog�� ��� ��. ������ ���� ������ 5������ ������ ���ÿ� 5�� ��ΰ� ������.
	if (listen(sock, 5) == SOCKET_ERROR) 
		printf("��⿭ ����");

	clientsize = sizeof(clientinfo); //size���� ������ ����.

	printf("Ŭ���̾�Ʈ�κ��� ������ ��ٸ��� �ֽ��ϴ�...\n");

	clientsock = accept(sock, (SOCKADDR*)& clientinfo, &clientsize); //Ŭ���̾�Ʈ ���� �ڵ� ���� ����.

	if (clientsock == INVALID_SOCKET)	//Ŭ���̾�Ʈ ����  Ȯ��.
		printf("Ŭ���̾�Ʈ ���� ���� ����");
	
	printf("����\n");

	WSACleanup();

	return 0;
	
}