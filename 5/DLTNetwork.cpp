//
// Created by Erik Gabrielsen on 11/7/22.
//

#include <fstream>
#include <sstream>
#include <iomanip>
#include "DLTNetwork.h"

using namespace std;
DLTNetwork::DLTNetwork() = default;

enum Commands{
    CREATE_PEER,
    CREATE_USER,
    DISPLAY_ALL,
    CREATE_TRANSACTION,
    DISPLAY_PEER,
    DISPLAY_PEER_TOTAL,
    DISPLAY_USER,
};

DLTNetwork::DLTNetwork(DLTNetwork& other) {
    for (int i = 0; i < peers.size(); ++i) {
        Peer* otherPeer = other.peers.at(i);
        auto newPeer = new Peer(*otherPeer);
        peers.push_back(newPeer);
    }

    for (int i = 0; i < users.size(); ++i) {
        User* otherUser = other.users.at(i);
        auto newUser = new User(*otherUser);
        users.push_back(newUser);
    }
}

DLTNetwork& DLTNetwork::operator=(const DLTNetwork& other)
{
    if (this == &other) return *this;

    for (auto p : peers)
    {
        delete p;
    }
    peers.clear();

    for (auto p : users)
    {
        delete p;
    }
    users.clear();

    for (int i = 0; i < peers.size(); ++i) {
        Peer* otherPeer = other.peers.at(i);
        auto newPeer = new Peer(*otherPeer);
        peers.push_back(newPeer);
    }

    for (int i = 0; i < users.size(); ++i) {
        User* otherUser = other.users.at(i);
        auto newUser = new User(*otherUser);
        users.push_back(newUser);
    }


    return *this;
}

DLTNetwork::~DLTNetwork() {
    for (auto p : peers)
    {
        delete p;
    }
    peers.clear();

    for (auto p : users)
    {
        delete p;
    }
    users.clear();
}

void DLTNetwork::start() {
    std::cout << "Starting your DLT Network..." << std::endl;

    ifstream commandFile;

    commandFile.open("input.txt");
    while (commandFile.good())
    {
        string currentCommandLine;
        getline(commandFile, currentCommandLine);

        if (currentCommandLine.empty()) continue;
        istringstream currentFullCommandString(currentCommandLine);

        string currentCommand;
        vector<string> commandArguments;

        currentFullCommandString >> currentCommand;
        currentFullCommandString.ignore();

        while (currentFullCommandString.good())
        {
            string currentArgument;
            getline(currentFullCommandString, currentArgument, '|');
            commandArguments.push_back(currentArgument);
        }

        switch (StringToCommand(currentCommand)) {
            case CREATE_PEER:
                cout << "CREATING PEER: " << commandArguments.at(1) << " [" << commandArguments.at(0) << "]" << endl;
                CreatePeer(commandArguments);
                break;
            case CREATE_USER:
                if (peers.size() >= stoi(commandArguments.at(3))) {
                    cout << "CREATING USER: " << commandArguments.at(1) << " [" << commandArguments.at(0) << "] from '"
                         << commandArguments.at(2) << "' on Peer '"
                         << peers.at(stoi(commandArguments.at(3)) - 1)->getName()
                         << "'[" << commandArguments.at(3) << "]" << endl;
                    CreateUser(commandArguments);
                }
                else {
                    cout << "* ILLEGAL OPERATION: " << endl;
                    cout << "  |--| PEER [" << commandArguments.at(3) << "] DOES NOT EXIST!" << endl;
                    cout << "  |----| Try creating the Peer "
                            "(" << commandArguments.at(3) << ") first before creating this user..." << endl;
                }
                break;
            case DISPLAY_ALL:
                cout << "|DISPLAYING ALL:" << endl;
                DisplayAll(commandArguments);
                break;
            case CREATE_TRANSACTION:
                cout << "CREATING TRANSACTION: $" << commandArguments.at(0) << " from User '"
                << users.at(stoi(commandArguments.at(1)) - 1)->getName() << "' to '"
                << users.at(stoi(commandArguments.at(2)) - 1)->getName() << "'" << endl;
                CreateTransaction(commandArguments);
                break;
            case DISPLAY_PEER:
                cout << "|DISPLAYING PEER " << "["<< commandArguments.at(0) << "] "
                     << peers.at(stoi(commandArguments.at(0)) - 1)->getName() << ":" << endl;
                DisplayPeer(commandArguments);
                break;
            case DISPLAY_PEER_TOTAL:
                cout << "|DISPLAYING PEER TOTAL " << "["<< commandArguments.at(0) << "] "
                     << peers.at(stoi(commandArguments.at(0)) - 1)->getName() << ":" << endl;
                DisplayPeerTotal(commandArguments);
                break;
            case DISPLAY_USER:
                cout << "|DISPLAYING USER "  << "["<< commandArguments.at(0) << "] "
                                             << users.at(stoi(commandArguments.at(0)) - 1)->getName() << ":" << endl;
                DisplayUser(commandArguments);
                break;
            default:
                 cout << "INVALID COMMAND: " << currentCommand << endl;
                break;
        }
    }

    auto ac = peers.at(0)->getName();

    commandFile.close();
}

void DLTNetwork::CreatePeer(vector<string> commandArguments)
{
    int id = stoi(commandArguments.at(0));
    Peer* newPeer = new Peer(id, commandArguments.at(1));
    peers.push_back(newPeer);
}

void DLTNetwork::CreateUser(vector<string> commandArguments)
{
    int id = stoi(commandArguments.at(0));
    int peerId = stoi(commandArguments.at(3));
    User* newUser = new User(id, commandArguments.at(1), commandArguments.at(2), peerId);
    users.push_back(newUser);
}

void DLTNetwork::CreateTransaction(vector<string> commandArguments)
{
    double amount = stoi(commandArguments.at(0));
    int fromID = stoi(commandArguments.at(1));
    int toID = stoi(commandArguments.at(2));

    int fromPeer = users.at(fromID - 1)->getHomePeerId();
    int toPeer = users.at(toID - 1)->getHomePeerId();

    auto* newTransaction = new Transaction(amount, fromID, toID);

    peers.at(fromPeer - 1)->addTransaction(newTransaction);
    peers.at(toPeer - 1)->addTransaction(newTransaction);
}

int DLTNetwork::StringToCommand(const string& StringCommand)
{
    if (StringCommand == "CREATE_PEER") return CREATE_PEER;
    else if(StringCommand == "CREATE_USER") return CREATE_USER;
    else if(StringCommand == "DISPLAY_ALL") return DISPLAY_ALL;
    else if(StringCommand == "CREATE_TRANSACTION") return CREATE_TRANSACTION;
    else if(StringCommand == "DISPLAY_PEER") return DISPLAY_PEER;
    else if(StringCommand == "DISPLAY_PEER_TOTAL") return DISPLAY_PEER_TOTAL;
    else if(StringCommand == "DISPLAY_USER") return DISPLAY_USER;

    return -1;
}

void DLTNetwork::DisplayAll(const std::vector<string>& commandArguments) {
    cout << "| Peers: " << endl;
    for (auto curPeer : peers) {
        cout << "|--] [" << curPeer->getId() << "] " << curPeer->getName() << endl;
    }
    cout << "=========" << endl;
    cout << "| Users: " << endl;
    for (auto curUser : users) {
        cout << "|--] " << curUser->toString() << endl;
    }
}

void DLTNetwork::DisplayPeer(std::vector<string> commandArgs) {
    cout << "| Transactions: " << endl;
    auto currentPeer = peers.at(stoi(commandArgs.at(0)) - 1);
    int transactionSIZE = currentPeer->getNumberOfTransaction();
    if (transactionSIZE <= 0)  cout << "|--] There are no transactions on this Peer." << endl;
    for (int i = 0; i < transactionSIZE; ++i) {
        Transaction* currentTransaction = currentPeer->getTransaction(i);
        if (currentTransaction != nullptr)
            cout << "|----] $" << currentTransaction->getAmount() << " from "
            << users.at(currentTransaction->getUserFromId() - 1)->getName() << "["<< currentTransaction->getUserFromId() <<"] "
            << "to " << users.at(currentTransaction->getUserToId() - 1)->getName() << "["<< currentTransaction->getUserToId() <<"] " << endl;
    }
}

void DLTNetwork::DisplayPeerTotal(std::vector<string> commandArgs) {
    double totalValue = 0;
    auto currentPeer = peers.at(stoi(commandArgs.at(0)) - 1);
    int transactionSIZE = currentPeer->getNumberOfTransaction();
    streamsize ss = cout.precision();
    for (int i = 0; i < transactionSIZE; ++i) {
        Transaction *currentTransaction = currentPeer->getTransaction(i);
        if (currentTransaction != nullptr) totalValue += currentTransaction->getAmount();
    }

    cout << "| Total: $" << setprecision(2) << fixed << totalValue << endl;
    cout << setprecision(ss) << defaultfloat;
}

void DLTNetwork::DisplayUser(std::vector<string> commandArgs) {
    cout << "| Transactions: " << endl;
    bool noTransaction = true;
    int currentUser = stoi(commandArgs.at(0));
    for (auto currentPeer: peers) {
        cout << "|--] " << currentPeer->getName() << "[" << currentPeer->getId() << "]:" << endl;
        int transactionSIZE = currentPeer->getNumberOfTransaction();
        if (transactionSIZE <= 0)  cout << "|--] There are no transactions on this Peer.";
        for (int i = 0; i < transactionSIZE; ++i) {
            Transaction* currentTransaction = currentPeer->getTransaction(i);
            if (currentTransaction != nullptr) {
                if (currentTransaction->getUserFromId() == currentUser or
                    currentTransaction->getUserToId() == currentUser) {
                        cout << "|----] $" << currentTransaction->getAmount() << " from "
                             << users.at(currentTransaction->getUserFromId() - 1)->getName() << "["
                             << currentTransaction->getUserFromId() << "] "
                             << "to " << users.at(currentTransaction->getUserToId() - 1)->getName() << "["
                             << currentTransaction->getUserToId() << "] " << endl;
                    noTransaction = false;
                }
            }
        }
    }

    if (noTransaction)  cout << "|--] There are no transactions on this User." << endl;
}
