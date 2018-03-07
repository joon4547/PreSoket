#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>

int main(int argc, char* argv[])
{
	SOCKET clientsock; //Ŭ���̾�Ʈ ���α׷� ���� �ڵ� ����. 
	WSADATA wsa;
	struct sockaddr_in sockinfo;//���� ���� �� �ּ� ����ü ����

	char message[30]; //recv�Լ� �޽��� ���� �迭 ����
	int strlen;	//recv ���� �� ���� �� ���� ����

	if (argc != 3)	//�Է� (IP, PORT) �� �Էµ��� ���� �� ���� ǥ��
	{
		printf("Usage : %s <IP> <PORT> \n", argv[0]);
		exit(1);
	}

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		printf("�ʱ�ȭ ����\n");

	clientsock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (clientsock == INVALID_SOCKET)
		printf("���� ���� ����\n");

	memset(&sockinfo, 0, sizeof(sockinfo));	//�ּ� ����ü �Լ� �ʱ�ȭ

	sockinfo.sin_family = AF_INET; //�ּ� ü�� ���.
	sockinfo.sin_port = htons(atoi(argv[2]));	//��Ʈ�� �� ��°�� �Է� ����
	sockinfo.sin_addr.s_addr = inet_addr(argv[1]);//IP�� ù ��°�� �Է� ����	




	//connect(Ŭ���̾�Ʈ ����, (SOCKADDR*) &�����ּұ���ü, sizeof(�����ּұ���ü)
	if (connect(clientsock, (SOCKADDR*)&sockinfo, sizeof(sockinfo) == SOCKET_ERROR)) //���� ���� ���� ��û
		printf("���� ���� ���� \n");

	strlen = recv(clientsock, message, sizeof(message) - 1, 0);

	//recv �Լ� ��ȯ �� ����
	if (strlen == -1)	//recv�Լ� ��ȯ ���� -1�̸� �޽��� ���� ����
		printf("�޼��� ���� ����\n");

	printf("Server say : %s \n", message); //���� �� �޽��� ǥ��

	closesocket(clientsock);

	WSACleanup();

}