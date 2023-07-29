//TcpPacketParser.cpp - Implementation file for TcpPacketParser class
//George Paul Robert, 117928226

#include "TcpPacketParser.h"

//Constructor
TcpPacketParser::TcpPacketParser(){
    source_port = 0;
    dest_port = 0;
    sequence_port = 0;
    ack_number = 0;
    checksum = 0;
    length = 0;
    data[0] = '\0';
}
//destructor
TcpPacketParser::~TcpPacketParser(){
    source_port = 0;
    dest_port = 0;
    sequence_port = 0;
    ack_number = 0;
    checksum = 0;
    length = 0;
    data[0] = '\0';
}

bool TcpPacketParser::parse(const char *packet){
    bool retval = false;
    const char *readHead = packet;
    unsigned int sum = 0.0;
    //tried parsing using pointers and manually using array indexes, both work
    source_port = ((*readHead++) * 0x100);
    source_port += (*readHead++);

    dest_port = packet[2] * 0x100 + packet[3];

    sequence_port = packet[4] * 0x1000000 + packet[5] * 0x10000 + packet[6] * 0x100 + packet[7];

    ack_number = packet[8] * 0x1000000 + packet[9] * 0x10000 + packet[10] * 0x100 + packet[11];

    //12,13,14,15 ignore 1

    checksum = packet[16] * 0x100 + packet[17];

    //18,19 //ignore 2

    length = packet[20] * 0x100 + packet[21];
    sum = source_port + dest_port + sequence_port + ack_number +length;

    if(sum == checksum){
        memcpy(data, packet + 22, sizeof(char) * length);
        retval = true;
    }
    else{
        retval = false;
    }

    return retval;
}

void TcpPacketParser::display(std::ostream &os) const
{
    os << "Report for TCP Packet Parser" << std::endl;
    os << "source port: " << source_port << std::endl;
    os << "dest port:  " << dest_port << std::endl;
    os << "seq number: " << sequence_port << std::endl;
    os << "ack number: " << ack_number << std::endl;
    os << "data length: " << length << std::endl;
    os << "data:\t " << data << std::endl << std::endl;
}
