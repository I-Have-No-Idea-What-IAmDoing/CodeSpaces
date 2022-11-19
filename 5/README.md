# Program 5 - DLT
Program 5 specifications can be found here: [https://github.com/CS1342-F22/lecture-materials/blob/main/misc/program05/Program05.md](https://github.com/CS1342-F22/lecture-materials/blob/main/misc/program05/Program05.md)

<hr/>

# Program 5 - DLT (Distributed Ledger Technology)
In Program 5, you will be building a simplified version of a DLT utilizing your knowledge of Object-Oriented Programming, Pointers, and Dynamic Memory Allocation. It will be important to understand the Rule of Three for this program as well. 

You will be submitting your completed Program to GitHub no later than **6:00am on Monday, November 21st 2022** for full credit or up to 48 hours after the deadline for a 30 point deduction.

## The DLT
A DLT is a system or platform in which data is distributed across a network of peers as opposed to stored in a central system. One way of thinking about a DLT simply, is having your data spread on multiple devices / computers as opposed to stored on one device. This ensures that there is not a single source of failure when accessing data, and that the data is distributed (which can be more reliable and secure). The most common implementation of a DLT is known as "Blockchain" which is the backing technology of most cryptocurrencies like Bitcoin or Ethereum.

For this program, we will not be actually building a real world DLT, but one that simulates some of its concepts, like the distribution of data!

For more information on DLT's and what they are used for, check out this article: https://www.investopedia.com/terms/d/distributed-ledger-technology-dlt.asp

## Implementation
You will be building a DLT that tracks monetary transactions between people across the globe! We will start out with having a DLT Network class which will be composed of a vector of Users (i.e. `vector<User *>`) and a vector of Peers (i.e. `vector<Peer *>`). The users vector will hold user data, and the vector of peers will represent the different places in which a user can send money to and from. You can think of each Peer as if it were an ATM or local bank and users are sending cash to other locations for another user to pick up. Each user will have a home peer that they are assigned to in which they send and receive transactions.

To begin your program, you will be reading in a file that represents your DLT Network. Each line in the file could be one of the following commands, which indicates a different action to take for your program.

1. `CREATE_PEER [id]|[name]` -> This command will be used to create and add a new `Peer` object to your DLT Network. The text following the command will be used to initialize the peers `name`. Notice that each data point is separated by a '|' (pipe) character.
2. `CREATE_USER [id]|[name]|[address]|[home_peer]` -> This command will create and add a new `User` object to your DLT Network.
3. `CREATE_TRANSACTION [amount]|[user_from]|[user_to]]` -> This command will create a new `Transaction` object, then add the transaction to both the Peer of the "from" user and to the Peer of the "to" User, therefore distributing its information to the 2 sources.
4. `DISPLAY_ALL` -> This command will display all users and peers that are in the network.
5. `DISPLAY_PEER [id]` -> This command will be used to display to the console all transactions that have occurred to and from that peer
6. `DISPLAY_USER [id]` -> This command will be used to display to the console all transactions that have occurred with that user across the network. Here you should see duplicate transactions (one for the source peer, the second for the destination peer).
7. `DISPLAY_PEER_TOTAL [id]` -> This command will be used to calculate the total amount (in USD) sent and received by this peer and display it in the console. (NOTE: Please use proper manipulators to show only 2 decimals)

Once your program has completed reading and executing the commands within the file, your program will terminate.

## Program Specifications
For this program, you must adhere to the following specifications:
- Every object (Peer, User, Transaction), must be created on the heap
- Each class definition should have appropriate definitions for the following:
    - Default Constructor
    - Destructor
    - Copy Constructor
    - Copy Assignment Operator
- Each class definition should appropriately encapsulate the data they represent.
- Transaction and Peer class: All data members should be pointers.
- You are free to add any functions you deem necessary to complete this program, we have given you what data members you will need in each class definition.
- An example input file has been provided for you, however your program should be built to where it can process larger files with different data.

