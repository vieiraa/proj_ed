#ifndef STACK_H
#define STACK_H

#include <string>

using namespace std;

class StackNode {
    public:
        char data;
        StackNode *next;
};

class Stack {
    private:
        StackNode *top;
        int sizeS;
        
    public:
//      GENERAL FUNCTIONS   
        Stack();
        int size();
        bool empty();
        char getTop();
        void invert();
        string toString();

//      PUSH FUNCTIONS
        void push(char);
        
//      DELETE FUNCTIONS
        char pop();
};

#endif //STACK_H