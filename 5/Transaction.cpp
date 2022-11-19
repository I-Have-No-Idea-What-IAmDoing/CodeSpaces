//
// Created by Erik Gabrielsen on 11/7/22.
//

#include "Transaction.h"

Transaction::Transaction() = default;

Transaction::~Transaction() {

}

Transaction::Transaction(Transaction& other) {

}

Transaction& Transaction::operator=(const Transaction& other)
{
    return *this;
}

Transaction::Transaction(double i, int i1, int i2) {
    amount = new double(i);
    userFromId = new int(i1);
    userToId = new int(i2);
}
