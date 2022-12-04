//
// Created by Erik Gabrielsen on 11/18/22.
//

#ifndef STACK_BALLOON_H
#define STACK_BALLOON_H


class Balloon {
public:
    Balloon();

    bool isPopped();

    virtual int pop() = 0;

protected:
    int balloonAmount;
    bool popped;
};


#endif //STACK_BALLOON_H
