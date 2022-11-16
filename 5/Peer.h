//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_PEER_H
#define PROGRAM5_TEMPLATE_PEER_H

#include <string>
#include <vector>
#include "Transaction.h"

class Peer {

private:
    int *id;
    std::string *name;
    std::vector<Transaction *> transactions;
};


#endif //PROGRAM5_TEMPLATE_PEER_H
