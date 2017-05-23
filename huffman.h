#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <map>
#include "Queue.h"

class Huffman {
    Queue queue;
    Stack stack;
    List list;
    Element tree;
    string dataString;
    string input;
    string codedInput;
    map<char, int> aux;
    pair<char, int> aux2;
    int size;

public:
    Huffman(string);
    void createTree();
    string code();
    string decode();
    string listToString();
    string queueToString();
};

#endif