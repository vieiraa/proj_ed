#include "stack.h"
#include <sstream>

Stack::Stack() {
    top = NULL;
    sizeS = 0;
}

int Stack::size() {
    return sizeS;
}

bool Stack::empty() {
    return !top;
}

char Stack::getTop() {
    return top->data;
}

void Stack::invert() {
    if(this->empty())
        return;
    
    int aux = this->size();
    char arr[aux];
    
    for(int i = 0; !this->empty(); arr[i] = this->pop(), i++);
    for(int i = 0; i < aux; i++)
        this->push(arr[i]);
}

string Stack::toString() {
    if(this->empty())
        return "Empty";

    string show = "Stack: {";
    stringstream data;
    
    for(StackNode *p = this->top; p; p = p->next) {
        data << p->data;
        
        if(!p->next)
            show += data.str() + "}";
        else
            show += data.str() + ", ";
        
        data.str("");
    }
    
    return show;
}

void Stack::push(char data) {
    StackNode *node = new StackNode();

    node->data = data;
    node->next = this->top;
    this->top = node;
    
    this->sizeS++;
}

char Stack::pop() {
    if(this->empty())
        return '\0';
    
    StackNode *p   = this->top;
    this->top = p->next;
    
    char data = p->data;
    p->next  = NULL;
    delete p;
    
    this->sizeS--;
    
    return data;
}