#ifndef __ICMP_UTIL_H__
#define __ICMP_UTIL_H__
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <linux/ip.h>
#include <linux/icmp.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/ioctl.h>
#include <net/if.h>

struct myicmp
{
	struct icmphdr icmp;
	char data[10];
};

int mask_4[4];
int ip_4[4];
char maskpy[20];
unsigned short in_cksum(void *, int);

char* get_device_ip(char *devicename);
void ip_to_int_array(char* ip , int result[] );
bool is_ip(const char *ip);
void subnet_scanner(char* argv1 , char* argv2);
char* get_device_mask(char *device_name);
#endif