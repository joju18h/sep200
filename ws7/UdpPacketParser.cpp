//UdpPacketParser.cpp, implementation file for UdpPacketParser class
//George Paul Robert, 117928226

#include "UdpPacketParser.h"

UdpPacketParser::UdpPacketParser(){
    source_port = 0;
    dest_port = 0;
    length = 0;
    checksum = 0;
    data[0] = '\0';
}

UdpPacketParser::~UdpPacketParser(){
    source_port = 0;
    dest_port = 0;
    length = 0;
    checksum = 0;
    data[0] = '\0';
}

bool UdpPacketParser::parse(const char *packet){
    bool retval = false;
    const char *readHead = packet; // packet[0]
    unsigned int sum = 0.0;

    source_port = (*readHead++)* 0x100;
    source_port += (*readHead++);

    dest_port = (*readHead++) * 0x100;
    dest_port += (*readHead++);

    length = (*readHead++) * 0x100;
    length += (*readHead++);

    checksum = (*readHead++) * 0x100;
    checksum += (*readHead++);

    sum = source_port + dest_port + length;

    if(sum == checksum){
        memcpy(data, readHead, sizeof(char) * length);
        retval = true;
    }
    else{
        retval = false;
    }

    return retval;
}

void UdpPacketParser::display(std::ostream &os) const{
    os << std::endl << "Report for UDP Packet Parser" << std::endl;
    os << "source port: " << source_port << std::endl;
    os << "dest port: " << dest_port << std::endl;
    os << "data length: " << length << std::endl;
    os << "data:\t" << data << std::endl << std::endl;
}