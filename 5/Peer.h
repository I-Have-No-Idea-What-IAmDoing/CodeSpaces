//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_PEER_H
#define PROGRAM5_TEMPLATE_PEER_H

#include <string>
#include <vector>
#include "Transaction.h"

class Peer {
public:

    Peer();

    Peer(Peer &other);

    Peer(int newID, std::string newName);

    ~Peer();

    Peer& operator=(const Peer&);

    int getId() const;

    std::string getName() const;

    void setName(std::string *name);

    void addTransaction(Transaction* newTransaction);

    int getNumberOfTransaction();

    Transaction * getTransaction(int index);
private:
    int *id;
    std::string *name;
    std::vector<Transaction*> transactions;

};


#endif //PROGRAM5_TEMPLATE_PEER_H
