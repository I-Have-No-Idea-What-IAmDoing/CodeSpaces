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

    DLTNetwork(DLTNetwork &other);
    DLTNetwork& operator=(const DLTNetwork& other);
    void start();

    ~DLTNetwork();

    void CreatePeer(std::vector<std::string> commandArguments);
    void CreateUser(std::vector<std::string> commandArguments);
    void DisplayAll(const std::vector<std::string>& commandArguments);
    void CreateTransaction(std::vector<std::string> commandArguments);
private:
    std::vector<User *> users;
    std::vector<Peer *> peers;

    static int StringToCommand(const std::string& a);
};


#endif //PROGRAM5_TEMPLATE_DLTNETWORK_H
