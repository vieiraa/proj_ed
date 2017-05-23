#ifndef TREE_H
#define TREE_H

#include "stack.h"
#include "list.h"
#include <sstream>

class Element {
    public:
        pair<char, int> data;
        Element *left;
        Element *right;
        
        Element(pair<char, int>, Element *, Element *);
        Element();
        
        void setFather(Element *);
        void setFlag(string);
        void setPair(pair<char, int> p);
        void setLeft(Element *);
        void setRight(Element *);
        
        Element *getLeft();
        Element *getRight();
        pair<char, int> getData();
        char getDataFirst();
        int getDataSecond();
        bool isLeaf();
};

void traversal(Element, Stack, List *);

#endif //TREE_H