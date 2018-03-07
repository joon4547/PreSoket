#include <stdio.h>
#include <WinSock2.h>

int main(int argc, char * argv[])
{
	SOCKET sock; //���� ���� ����ü.
	WSADATA wsa; //���� �ʱ�ȭ ����ü.

	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
		return 1;

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);	// "���ͳ� ������ ����ϴ� TCP����� ��������"

	if (sock == INVALID_SOCKET) //INVALID_SOCKET�� ����� �ƴ� �����ڵ� ���� �ǹ��Ѵ�. 
								//�ֳ��ϸ� SOCKET �ڷ����� unsinged int ��� �̱� ����.
								//socket�� �ڵ� ������ ������ ������ ������ ������ ������Ѽ� �̿��ؾ� �Ѵ�.
		return 1;
	
	printf("����\n");

	WSACleanup();

	return 0;
	
}