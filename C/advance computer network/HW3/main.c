#include <netinet/in.h>
#include <sys/types.h>
#include "arp.h"
#include <math.h>
/* 
 * Change "enp2s0f5" to your device name (e.g. "eth0"), when you test your hoework.
 * If you don't know your device name, you can use "ifconfig" command on Linux.
 * You have to use "enp2s0f5" when you ready to upload your homework.
 */
#define DEVICE_NAME "enp2s0f5"

/*
 * You have to open two socket to handle this program.
 * One for input , the other for output.
 */

int main(int argc, char **argv)
{
	if (geteuid() != 0)//check root
	{
		printf("ERROR: You must be root to use this tool \n");
		return 0;
	}

	if (argc == 1)
	{
		printf("parameters error , please refer to commands below \n");
		print_usage();
	}
	else if (argc == 2 && strcmp(argv[1], "-help") == 0)
	{
		print_usage();
	}
	else if (argc == 3)
	{
		if (strcmp(argv[1], "-l") == 0 && strcmp(argv[2], "-a") == 0)
		{
			arp_l_a(0, "none");
		}
		if (strcmp(argv[1], "-l") == 0 && is_ip(argv[2]))
		{
			arp_l_a(1, argv[2]);
		}
		if (strcmp(argv[1], "-q") == 0 && is_ip(argv[2]))
		{
			query_mode(argv[2] ,DEVICE_NAME);
		}
		if (is_mac(argv[1]) && is_ip(argv[2])){
			spoof_mode(argv[1], argv[2] , DEVICE_NAME);
		}
	}
	else {
		printf("parameters error , please refer to commands below \n");
		print_usage();
	}
	
	return 0;
}
