#ifndef LISTA_DINAMICA_H
#define LISTA_DINAMICA_H

#include <iostream>
#include <utility>

using namespace std;

class ListNode {
    public:
        pair<char, string> data;
        ListNode *next;
};

class List {
    private:
        ListNode *head;
        int sizeQ;
        
    public:
        //GENERAL FUNCTIONS
        List();
        int size();
        bool empty();
        pair<char, string> visit(int);
        char visitFirst(int);
        string visitSecond(int);
        int search(pair<char, string>);
        int searchFirst(char);
        int searchSecond(string);
        string toString();
        
        //INSERT FUNCTIONS
        int insert(int, pair<char, string>);
        int insertHead(pair<char, string>);
        int insertIndx(int, pair<char, string>);
        
        //REMOVE FUNCTIONS
        int del(int, pair<char, string> *);
        int delHead(pair<char, string> *);
        int delIndx(int, pair<char, string> *);
};

#endif //LISTA DINAMICA_H