//
// Created by Erik Gabrielsen on 11/7/22.
//

#include <iostream>
#include <utility>
#include "Peer.h"

using namespace std;

Peer::~Peer() {
    delete id;
    delete name;
    for (auto p : transactions)
    {
        delete p;
    }

    transactions.clear();
}

Peer::Peer() {
    id = nullptr;
    name = nullptr;
}

Peer::Peer(int newID, string newName) {
    id = new int(newID);
    name = new string(std::move(newName));
}

int Peer::getId() const {
    if (id == nullptr) return -1;
    return *(id);
}

Peer::Peer(Peer& other) {
    id = new int;
    name = new string;

    *id = *other.id;
    *name = *other.name;

    for (int i = 0; i < transactions.size(); ++i) {
        Transaction* otherTransaction = other.transactions.at(i);
        auto newTransaction = new Transaction(*otherTransaction);
        transactions.push_back(newTransaction);
    }
}

Peer& Peer::operator=(const Peer& other)
{
    if (this == &other) return *this;

    delete id;
    delete name;

    for (auto p : transactions)
    {
        delete p;
    }

    transactions.clear();

    id = new int;
    name = new string;

    *id = *other.id;
    *name = *other.name;

    for (int i = 0; i < transactions.size(); ++i) {
        Transaction* otherTransaction = other.transactions.at(i);
        auto newTransaction = new Transaction(*otherTransaction);
        transactions.push_back(newTransaction);
    }

    return *this;
}

string Peer::getName() const {
    if (name == nullptr) return {};
    return *(name);
}

void Peer::setName(string *newName) {
    Peer::name = newName;
}

void Peer::addTransaction(Transaction* newTransaction){
    transactions.push_back(newTransaction);
}