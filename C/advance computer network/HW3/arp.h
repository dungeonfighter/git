#ifndef __ARP_UTIL_H__
#define __ARP_UTIL_H__
#include <netinet/if_ether.h>
#include <netpacket/packet.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/ethernet.h>
#include <linux/if.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/ioctl.h>
//#include <net/if.h>

struct arp_packet
{
    //各項欄位資訊查詢man Page
    //Header 
    //Dest mac
    unsigned char mac_target[ETH_ALEN];
    //Source mac
    unsigned char mac_source[ETH_ALEN];
    //Ethertype 
    unsigned short ethertype;
 
    //ARP Frame
    // 乙太網類型值0x1
    unsigned short hw_type;
    //proto - IP協議(0x0800)
    unsigned short proto_type;
    //MAC地址長度
    unsigned char mac_addr_len;
    //IP地址長度
    unsigned char ip_addr_len;
    //操作碼 - 0x1表示ARP請求包,0x2表示應答包
    unsigned short operation_code;
    //發送方mac
    unsigned char mac_sender[ETH_ALEN];
    //發送方ip
    unsigned char ip_sender[4];
    //接收方mac
    unsigned char mac_receiver[ETH_ALEN];
    //接收方ip
    unsigned char ip_receiver[4];
    //填充數據
    unsigned char padding[18];//暫時用不到
};
void print_usage();
void print_arp_packet(struct arp_packet rcvbuff);
void print_arp_by_sender_reciever(struct arp_packet rcvbuff);
void print_arp_using_filter(struct arp_packet rcvbuff,const char* ip);
bool is_ip(const char* ip );
bool is_mac(const char* mac);
void arp_l_a(int mode , const char* temp);
void query_mode(char* aim ,char* my_ether_name);
void spoof_mode(char* F_mac , char* T_ip , char *my_ether_name);
void mac_string_to_uchar_array(char* s_max , unsigned char* u_max);
bool fill_arp_packet(struct arp_packet* arp , int opcode , unsigned char* d_mac , unsigned char* s_mac ,char* d_ip , char* s_ip   );

#endif
