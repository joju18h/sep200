//TcpPacketParser.h - Header file for TcpPacketParser class
//George Paul Robert, 117928226

#ifndef TCP_H_
#define TCP_H_

#include "PacketParser.h"

#define TCP_MAX 65535
#define TCP_HEADER 20

class TcpPacketParser : public PacketParser{
    int source_port;
    int dest_port;
    int sequence_port;
    int ack_number;
    int checksum;
    int length;
    char data[TCP_MAX - TCP_HEADER];

    public:
        TcpPacketParser();
        ~TcpPacketParser();
        bool parse(const char *packet);
        void display(std::ostream &os) const;
};

#endif //UDP_H