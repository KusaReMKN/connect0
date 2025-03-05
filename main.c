#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <err.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int
main(void)
{
	struct sockaddr sa;
	struct sockaddr_in sin;
	socklen_t slen;
	int sock;
	char name[16];

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock == -1)
		err(1, "socket");

	sin.sin_family      = AF_INET;
	sin.sin_port        = 9;
	sin.sin_addr.s_addr = 0;	/* 宛先は 0 */
	if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == -1)
		err(1, "connect");

	slen = sizeof(sa);
	if (getsockname(sock, &sa, &slen) == -1)
		err(1, "getsockname");

	(void)memcpy(&sin, &sa, sizeof(sin));
	if (inet_ntop(AF_INET, &sin.sin_addr, name, sizeof(name)) == NULL)
		err(1, "inet_ntop");
	(void)puts(name);

	(void)close(sock);

	return 0;
}
