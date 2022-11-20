//
// Created by Erik Gabrielsen on 11/7/22.
//

#include <cmath>
#include "Transaction.h"

Transaction::Transaction() = default;

Transaction::~Transaction() {
    delete amount;
    delete userFromId;
    delete userToId;
}

Transaction::Transaction(Transaction& other) {
    amount = new double;
    userFromId = new int;
    userToId = new int;

    *amount = *other.amount;
    *userFromId = *other.userFromId;
    *userToId = *other.userToId;
}

Transaction& Transaction::operator=(const Transaction& other)
{
    if (this == &other) return *this;

    delete amount;
    delete userFromId;
    delete userToId;

    amount = new double;
    userFromId = new int;
    userToId = new int;

    *amount = *other.amount;
    *userFromId = *other.userFromId;
    *userToId = *other.userToId;

    return *this;
}

Transaction::Transaction(double i, int i1, int i2) {
    amount = new double(i);
    userFromId = new int(i1);
    userToId = new int(i2);
}

double Transaction::getAmount() const {
    if (amount == nullptr) return nan("");
    return *amount;
}

int Transaction::getUserFromId() const {
    if (userFromId == nullptr) return -1;
    return *userFromId;
}

int Transaction::getUserToId() const {
    if (userToId == nullptr) return -1;
    return *userToId;
}
