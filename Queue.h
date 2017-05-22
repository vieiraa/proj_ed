#ifndef QUEUE_H
#define QUEUE_H

#include "Tree.h"
#include <iostream>

using namespace std;

class Node {
    public:
        Element data;
        Node *next;
        Node *prev;
};

class Queue {
    private:
        Node *front;
        Node *back;
        int sizeQ;

    public:
//      CONSTRUCTOR
        Queue();

//      GENERAL FUNCTIONS
        bool empty();
        int size();
        void sort();
        Node *getFront();

//      PUSH FUNCTIONS
        void push(Element *);

//      POP FUNCTIONS
        Element pop();

//      PRINT FUNCTIONS
        string toString();
        void print();
};

#endif //QUEUE_H
