//UdpPacketParser.h - UdpPacketParser class header file
//George Paul Robert, 117928226

#ifndef UDP_H_
#define UDP_H_

#include "PacketParser.h"

#define UDP_MAX 65535
#define UDP_HEADER 8

class UdpPacketParser : public PacketParser{
    unsigned int source_port;
    unsigned int dest_port;
    unsigned int length;
    unsigned int checksum;
    unsigned char data[UDP_MAX - UDP_HEADER];

    public:
        UdpPacketParser();
        ~UdpPacketParser();
        bool parse(const char *packet);
        void display(std::ostream &os) const;
};

#endif //UDP_H_