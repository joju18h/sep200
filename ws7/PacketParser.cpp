//PacketParser.cpp- Implementation file for PacketParser class
//George Paul Robert, 117928226

#include "PacketParser.h"

std::ostream& operator<<(std::ostream& os, PacketParser& parser){
    parser.display(os);
    return os;
};