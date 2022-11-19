//
// Created by Erik Gabrielsen on 11/7/22.
//

#include "User.h"

#include <utility>

using namespace std;
User::User(){
    id = new int;
    name = new std::string;
    homePeerId = new int;
    address = new string;
}

User::~User() {
    delete id;
    delete name;
    delete homePeerId;
    delete address;
}

string User::getName() const {
    return *(name);
}

void User::setName(string *newName) {
    User::name = newName;
}

User::User(User& other) {
    id = new int;
    name = new std::string;
    homePeerId = new int;
    address = new string;

    *id = *other.id;
    *name = *other.name;
    *homePeerId = *other.homePeerId;
    *address = *other.address;
}

User::User(int newId, string newName, string newAddress, int newHomePeerId)
{
    id = new int (newId);
    homePeerId = new int(newHomePeerId);
    name = new string(std::move(newName));
    address = new string(std::move(newAddress));
}

User& User::operator=(const User& other)
{
    if (this == &other) return *this;

    delete id;
    delete name;
    delete homePeerId;
    delete address;


    id = new int;
    name = new string;
    homePeerId = new int;
    address = new string;

    *id = *other.id;
    *name = *other.name;
    *homePeerId = *other.homePeerId;
    *address = *other.address;


    return *this;
}

string User::toString()
{
    return "[" + to_string(*(id)) + "] " + *(name) + " from '" + *address + "' on Peer " + to_string(*(homePeerId));
}

string User::getAddress() const {
    return *(address);
}

void User::setAddress(string *newAddress) {
    User::address = newAddress;
}

int User::getHomePeerId() const {
    return *homePeerId;
}
