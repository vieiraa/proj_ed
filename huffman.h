#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Queue.h"
#include "Tree.h"

using namespace std;

class Huffman {
    Queue queue;
    Stack stack;
    List list;
    Element tree;
    string input;
    string codedInput;
    map<char, int> aux;

public:
    Huffman(string);
    void createTree();
    string code();
    string decode();
};

#endif
