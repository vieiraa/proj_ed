#include "list.h"
#include <sstream>

List::List() {
    this->head = NULL;
    this->sizeQ = 0;
}

int List::size() {
    return this->sizeQ;
}

bool List::empty() {
    return !this->head;
}

pair<char, string> List::visit(int pos) {    
    if((pos-1) > this->sizeQ)
        pos = this->sizeQ;
    
    ListNode *p = this->head;
    
    for(int i = 1; i < pos; p = p->next, i++);
        
    return p->data;
}

char List::visitFirst(int pos) {    
    if((pos-1) > this->sizeQ)
        pos = this->sizeQ;
    
    ListNode *p = this->head;
    
    for(int i = 1; i < pos; p = p->next, i++);
        
    return p->data.first;
}

string List::visitSecond(int pos) {    
    if((pos-1) > this->sizeQ)
        pos = this->sizeQ;
    
    ListNode *p = this->head;
    
    for(int i = 1; i < pos; p = p->next, i++);
        
    return p->data.second;
}

int List::search(pair<char, string> data) {
    ListNode *p = this->head;
    
    for(int i = 1; p; p = p->next, i++)
        if(p->data == data)
            return i;
        
    return 0;
}

int List::searchFirst(char data) {
    ListNode *p = this->head;
    
    for(int i = 1; p; p = p->next, i++)
        if(p->data.first == data)
            return i;
        
    return 0;
}

int List::searchSecond(string data) {
    ListNode *p = this->head;
    
    for(int i = 1; p; p = p->next, i++)
        if(!(p->data.second.compare(data)))
            return i;
        
    return 0;
}

int List::insert(int pos, pair<char, string> data) {
    if(pos < 1)
        return 0;
    
    if((pos-1) > this->sizeQ)
        pos = this->sizeQ;
    
    if(this->empty() || pos == 1)
        return insertHead(data);
    
    return insertIndx(pos, data);
}

int List::insertHead(pair<char, string> data) {
    ListNode *node = new ListNode();
    
    node->data  = data;
    node->next  = this->head;
    this->head  = node;
    
    this->sizeQ++;
    
    return 1;
}

int List::insertIndx(int pos, pair<char, string> data) {
    ListNode *p = this->head;
    ListNode *node = new ListNode();
    int i = 2;
    
    for(; i < pos; p = p->next, i++);
    
    node->data = data;
    node->next = p->next;
    p->next    = node;
    
    this->sizeQ++;
    
    return 1;
}

int List::del(int pos, pair<char, string> *data) {
    if(this->empty() || pos < 1)
        return 0;
    
    if((pos-1) > this->sizeQ)
        pos = this->sizeQ;
    
    if(pos == 1)
        return delHead(data);
    
    return delIndx(pos, data);
}

int List::delHead(pair<char, string> *data) {
    ListNode *p = this->head;
    
    *data      = p->data;
    this->head = p->next;
    
    p->next = NULL;
    delete p;
    
    this->sizeQ--;
}

int List::delIndx(int pos, pair<char, string> *data) {
    ListNode *p = this->head,
         *aux;
    
    for(int i = 2; i < pos; p = p->next, i++);
    
    aux = p->next;
    p->next = aux->next;
    
    *data = aux->data;
    aux->next = NULL;
    delete aux;
}

string List::toString() {
    if(this->empty())
        return "Empty List\n";
    
    stringstream data;
    string show = "List: {";
    
    ListNode *p = this->head;
    
    for(; p; p = p->next) {
        data << p->data.first << " : " << p->data.second;
        
        if(!p->next)
            show += data.str() + "}";
        else
            show += data.str() + ", ";
        
        data.str("");
    }
        
    return show + "\n";    
}
