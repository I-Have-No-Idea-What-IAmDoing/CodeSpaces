//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_TRANSACTION_H
#define PROGRAM5_TEMPLATE_TRANSACTION_H


class Transaction {
public:
    Transaction();

    Transaction(Transaction &other);

    Transaction(double i, int i1, int i2);

    virtual ~Transaction();

    Transaction& operator=(const Transaction&);
private:
    double *amount;
    int *userFromId;
    int *userToId;

};


#endif //PROGRAM5_TEMPLATE_TRANSACTION_H
