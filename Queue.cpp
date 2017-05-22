#include "Tree.h"
#include "Queue.h"
#include <sstream>

void swap(pair<char, int> *x, pair<char, int> *y) {
    pair<char, int> aux = *x;
    *x = *y;
    *y = aux;
}

Queue::Queue() {
    this->front = NULL;
    this->back  = NULL;
    this->sizeQ = 0;
}

bool Queue::empty() {
    return !this->front;
}

int Queue::size() {
    return this->sizeQ;
}

void Queue::sort() {
    bool flag;
    Node *aux = front;

    do {
        for (int i = 0; i < size() - 2; i++) {
            for (int j = 0; j < size() - i - 1; j++) {
                flag = false;
                int atual = aux->data.data.second;
                int next = aux->next->data.data.second;

                if (atual > next) {
                    aux->data.data.swap(aux->next->data.data);
                    flag = true;
                    if (aux->next->next)
                        aux = aux->next;
                }
            }
        }
    } while (flag);
}

Node * Queue::getFront() {
    return front;
}

void Queue::push(Element data) {
    Node *node = new Node();
    
    node->next = NULL;
    node->data = data;
    
    if(this->empty()) {
        node->prev = NULL;
        this->front = node;
    }
    else {
        node->prev       = this->back;
        this->back->next = node;
    }
        
    this->back = node;
    
    this->sizeQ++;
}

void Queue::print() {
    Node *aux = front;
    for (int i = 0; i < size(); i++) {
        cout << i << " = " << aux->data.getData().first << endl;
        aux = aux->next;
    }
}

Element Queue::pop() {
    Element data;
    
    if(!this->empty()) {
        Node *p = this->front;
        
        data        = p->data;
        this->front = p->next;
        
        if(this->size() > 1)
            this->front->prev = NULL;
        
        delete p;
        
        this->sizeQ--;
    }
    
    return data;
}

string Queue::toString() {
    stringstream text;
    string show = "Queue: {";
    
    Node *p = this->front;
    
    for(int i = 0; i < this->sizeQ; p = p->next, i++) {
        text << p->data.data.first << " : " << p->data.data.second;
        
        if((i+1) >= this->sizeQ)
            show += text.str() + "}";
        else
            show += text.str() + ", ";
        
        text.str("");
    }
    
    return show;
}
