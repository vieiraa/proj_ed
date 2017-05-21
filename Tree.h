#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <utility>
#include <sstream>
#include <map>

using namespace std;

class Element;

class Father {
    Element *father;
    char flag;

public:
    Father(Element *, char);
    Father();
    void setFather(Element *);
    void setFlag(char);
    Element *getFather();
    char getFlag();
};

class Element {
    public:
        pair<char, int> data;
        Element *left;
        Element *right;
        Father father;

        Element(pair<char, int> p);
        Element();
        void setFather(Element *);
        void setFlag(string);
        void setPair(pair<char, int> p);
        void setLeft(Element *);
        void setRight(Element *);
        void setFather(Element *, char);
        Father *getFather();
        Element *getLeft();
        pair<char, int> &getData();
};

class BinaryTree {
    private:
        Element *root;

    public:
//      CONSTRUCTOR
        BinaryTree();

//      GENERAL FUNCTIONS
        bool empty();
        void setRoot(Element *);
        Element *getRoot();
};

Element *search(Element *, pair<char, int>);
map<char, string> preOrder(Element *);
map<char, string> test(Element *);
void printPre(Element *);

#endif //TREE_H
