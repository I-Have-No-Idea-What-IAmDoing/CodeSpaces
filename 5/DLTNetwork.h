//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_DLTNETWORK_H
#define PROGRAM5_TEMPLATE_DLTNETWORK_H

#include <vector>
#include <iostream>
#include "User.h"
#include "Peer.h"

class DLTNetwork {
public:
    DLTNetwork();

    void start();

private:
    std::vector<User *> users;
    std::vector<Peer *> peers;
};


#endif //PROGRAM5_TEMPLATE_DLTNETWORK_H
