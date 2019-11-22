#include <stdio.h>
#include <stdlib.h>
#include "icmp.h"


int main(int argc, char *argv[])
{
	if(argc != 3){
		printf("parameter error \n");
		printf("please input as : sudo ./Ping 'devicename' 'timeout' \n");
		printf("for example : sudo ./Ping wlp2s0 100 \n");
		exit(0);
	}

	subnet_scanner(argv[1], argv[2]);
	return 0;
}
