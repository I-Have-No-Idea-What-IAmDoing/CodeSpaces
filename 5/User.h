//
// Created by Erik Gabrielsen on 11/7/22.
//

#ifndef PROGRAM5_TEMPLATE_USER_H
#define PROGRAM5_TEMPLATE_USER_H

#include <string>

class User {
public:
    User();

    User(User &other);

    User(int id, std::string name, std::string address, int homePeerId);

    ~User();

    User& operator=(const User&);

    std::string toString();

    std::string getName() const;

    std::string getAddress() const;

    int getHomePeerId() const;

    void setAddress(std::string *address);

    void setName(std::string *name);

private:
    int *id;
    std::string *name;
    std::string *address;
    int *homePeerId;
};


#endif //PROGRAM5_TEMPLATE_USER_H
