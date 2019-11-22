#include "icmp.h"

unsigned short in_cksum(void *b, int len)
{
	unsigned short *buf = b;
	unsigned int sum = 0;
	unsigned short result;

	for (sum = 0; len > 1; len -= 2)
		sum += *buf++;
	if (len == 1)
		sum += *(unsigned char *)buf;
	sum = (sum >> 16) + (sum & 0xFFFF);
	sum += (sum >> 16);
	result = ~sum;
	return result;
}

char *get_device_ip(char *devicename)
{

	struct ifreq ifr;
	int sock;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	strcpy(ifr.ifr_name, devicename);
	ioctl(sock, SIOCGIFADDR, &ifr);
	char *ip = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
	close(sock);
	return ip;
}

bool is_ip(const char *ip)
{
	int dots = 0;	/*字符:的个数*/
	int setions = 0; /*ip每一部分总和（0-255）*/

	if (NULL == ip || *ip == '.')
	{ /*排除输入参数为NULL*/
		return false;
	}

	while (*ip)
	{
		if (*ip == '.')
		{
			dots++;
			if (setions >= 0 && setions <= 255)
			{ /*检查ip是否合法*/
				setions = 0;
				ip++;
				continue;
			}
			return false;
		}
		else if (*ip >= '0' && *ip <= '9')
		{										  /*判断是不是数字*/
			setions = setions * 10 + (*ip - '0'); /*求每一段总和*/
		}
		else
			return false;
		ip++;
	}
	/*判断IP最后一段是否合法*/
	if (setions >= 0 && setions <= 255)
	{
		if (dots == 3)
		{
			return true;
		}
	}

	return false;
}

void ip_to_int_array(char *ip, int result[])
{
	if (!is_ip(ip))
	{
		perror("Not ip address ");
	}
	else
	{
		int dots = 0;	/*字符:的个数*/
		int setions = 0; /*ip每一部分总和（0-255）*/

		while (*ip)
		{
			if (*ip == '.')
			{
				result[dots] = setions;
				dots++;
				setions = 0;
			}
			else if (*ip >= '0' && *ip <= '9')
			{										  /*判断是不是数字*/
				setions = setions * 10 + (*ip - '0'); /*求每一段总和*/
			}

			ip++;
		}
		result[dots] = setions;
	}
}

void subnet_scanner(char *argv1, char *argv2)
{
	char dst[20];
	char *mask;
	char *myip;

	int s = 0;
	clock_t t1, t2;
	struct timeval t = {0, 0}; //3s
	int t_out;

	t.tv_usec = 1000 * (atoi(argv2)); //us*1000=ms
	t_out = atoi(argv2);
	struct iphdr *ip;
	struct iphdr *ip_reply;
	struct myicmp *my;
	struct myicmp *icmp_reply;
	struct sockaddr_in connection;
	char *packet;
	char *buffer;
	int sockfd;
	int optval;

	int siz;

	mask = get_device_mask(argv1);
	strncpy(maskpy, mask, 18);
	myip = get_device_ip(argv1);
	printf("Mask: %s\n", maskpy);

	ip_to_int_array(myip, ip_4);

	ip_to_int_array(maskpy, mask_4);

	/*
	for (size_t i = 0; i < 4; i++)
	{
		printf("%d.",ip_4[i]);
	}
	
	printf("\n");*/

	for (size_t i = 0; i < 4; i++)
	{

		if (mask_4[i] == 0)
			ip_4[i] = 0;
	}

	sprintf(dst, "%d.%d.%d.%d", ip_4[0], ip_4[1], ip_4[2], ip_4[3]);
	//printf("%s \n", dst);

	if (getuid() != 0)
	{
		fprintf(stderr, "root privelidges needed\n");
		exit(EXIT_FAILURE);
	}
	//strncpy(dst, "192.168.1.19", 20);

	printf("Source address: %s\n", myip);
	//printf("Destination address: %s\n", dst_addr);
	while (1)
	{

		packet = malloc(sizeof(struct iphdr) + sizeof(struct myicmp));
		buffer = malloc(sizeof(struct iphdr) + sizeof(struct myicmp));
		memset(packet, 0, sizeof(struct iphdr) + sizeof(struct myicmp));
		memset(buffer, 0, sizeof(struct iphdr) + sizeof(struct myicmp));

		ip = (struct iphdr *)packet;
		my = (struct my *)(packet + sizeof(struct iphdr));

		ip->ihl = 5;
		ip->version = 4;
		ip->tos = 0;
		ip->tot_len = sizeof(struct iphdr) + sizeof(struct icmphdr);
		ip->id = htons(0);
		ip->frag_off = 0;
		ip->ttl = 1;
		ip->protocol = IPPROTO_ICMP;
		ip->saddr = inet_addr(myip);
		ip->daddr = inet_addr(dst);
		ip->check = in_cksum((unsigned short *)ip, sizeof(struct iphdr));

		if ((sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
		{
			perror("socket");
			exit(EXIT_FAILURE);
		}

		setsockopt(sockfd, IPPROTO_IP, IP_HDRINCL, &optval, sizeof(int));

		my->icmp.type = ICMP_ECHO;
		my->icmp.code = 0;
		my->icmp.un.echo.id = getpid();
		my->icmp.un.echo.sequence = s++;
		memset(my->data, 0, 10);
		my->data[0] = 0;
		my->data[1] = 7;
		my->data[2] = 3;
		my->data[3] = 0;
		my->data[4] = 4;
		my->data[5] = 0;
		my->data[6] = 0;
		my->data[7] = 3;
		my->data[8] = 6;
		my->data[9] = 'M';

		my->icmp.checksum = in_cksum((my), sizeof(struct myicmp));

		connection.sin_family = AF_INET;
		connection.sin_addr.s_addr = inet_addr(dst);
		t1 = clock();
		sendto(sockfd, packet, ip->tot_len + 10, 0, (struct sockaddr *)&connection, sizeof(struct sockaddr));
		printf("Ping %s (data size = %d, id = %d, seq = %d , timeout = %d ms)\n", dst, 10, my->icmp.un.echo.id, my->icmp.un.echo.sequence, t_out);

		socklen_t addrlen = sizeof(connection);
		setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&t, sizeof(t));
		if ((siz = recvfrom(sockfd, buffer, sizeof(struct iphdr) + sizeof(struct myicmp), 0, (struct sockaddr *)&connection, &addrlen)) == -1)
		{
			//perror("recv");
			printf("     Destination unreachable \n");
		}
		else
		{
			t2 = clock();

			//printf("Received %d byte reply from %s:\n", siz, dst);
			ip_reply = (struct iphdr *)buffer;
			icmp_reply = (struct myicmp *)(buffer + sizeof(struct iphdr));
			/*
			printf("ID: %d\n", ntohs(ip_reply->id));
			printf("TTL: %d\n", ip_reply->ttl);
			printf("protocal: %d\n", ip_reply->protocol);
			printf("icmp type: %d\n", icmp_reply->icmp.type);*/
			if (icmp_reply->icmp.type == 0)
			{
				printf("-----Reply from : %s , ", inet_ntoa(*(struct in_addr *)&ip_reply->saddr));
				printf("time : %lf ms-----\n", 1000 * (t2 - t1) / (double)(CLOCKS_PER_SEC));
			}
			else
			{
				printf("     Destination unreachable \n");
			}
		}
		sleep(2);

		free(packet);
		free(buffer);
		//strncpy(dst, "8.8.8.8", 20);
		ip_4[3]++;
		if(ip_4[3]>255){
			if(mask_4[2]==255)break;
			ip_4[3]=0;
			ip_4[2]++;
		}
		if(ip_4[2]>255){
			if(mask_4[1]==255)break;
			ip_4[2]=0;
			ip_4[1]++;
		}
		if(ip_4[1]>255){
			if(mask_4[0]==255)break;
			ip_4[1]=0;
			ip_4[0]++;
		}
		
		sprintf(dst, "%d.%d.%d.%d", ip_4[0], ip_4[1], ip_4[2], ip_4[3]);
		//printf("%s \n", dst);
	}
	close(sockfd);
}

char *get_device_mask(char *device_name)
{
	struct sockaddr_in *addr;
	struct ifreq ifr;
	char *address;
	int sockfd;
	sockfd = socket(AF_INET, SOCK_DGRAM, 0);
	strcpy(ifr.ifr_name, device_name);
	if (ioctl(sockfd, SIOCGIFNETMASK, &ifr) == -1)
		printf("ioctl error.\n"), exit(0);

	addr = (struct sockaddr_in *)&ifr.ifr_addr;
	address = inet_ntoa(addr->sin_addr);

	return address;
}