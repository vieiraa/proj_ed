#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <utility>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

class Element;

class Father {
    Element *father;
    char flagL;
    char flagR;

public:
    Father(Element *, char, char);
    Father();
    void setFather(Element *);
    void setFlag(char, char);
    Element *getFather();
    char getLFlag();
    char getRFlag();
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
        void setFather(Element *, char, char);
        Father *getFather();
        Element *getLeft();
        pair<char, int> &getData();
};

class BinaryTree {
    private:
        Element *root;
        map<char, string> hash;

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
void encode(vector<Element *>, map<char, string> *);
void printPre(Element *);

#endif //TREE_H
