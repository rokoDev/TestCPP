//
//  SomeClass_test.cpp
//  NetTest
//
//  Created by roko on 7/22/16.
//  Copyright © 2016 roko. All rights reserved.
//

#include "config.h"
#include "Rectangle.h"
#include "SomeClass_test.hpp"
#include "CommonInclude.h"

class SocketAddress {
    
public:
    SocketAddress(uint32_t inAddress, uint16_t inPort) {
        GetAsSockAddrIn()->sin_family = AF_INET;
        GetAsSockAddrIn()->sin_addr.s_addr = htonl(inAddress);
        GetAsSockAddrIn()->sin_port = htons(inPort);
    }
    
    SocketAddress(const sockaddr & inSockAddr) {
        memcpy(&_sockAddr, &inSockAddr, sizeof(sockaddr));
    }
    
    size_t getSize() const { return sizeof(sockaddr); }
    
private:
    sockaddr_in * GetAsSockAddrIn() {
        return reinterpret_cast<sockaddr_in*>(&_sockAddr);
    }
    
private:
    sockaddr _sockAddr;
};

typedef shared_ptr<SocketAddress> SocketAddressPtr;

#endif
