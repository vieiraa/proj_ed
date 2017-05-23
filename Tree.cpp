#include "Tree.h"

Element::Element(pair<char, int> p, Element *l, Element *r) {
    data = p;
    left = l;
    right = r;
}

Element::Element(){};

void Element::setPair(pair<char, int> p) {
    this->data = p;
}

void Element::setLeft(Element *e) {
    this->left = e;
}

void Element::setRight(Element *e) {
    this->right = e;
}

Element *Element::getLeft() {
    return left;
}

Element *Element::getRight() {
    return right;
}

pair<char, int> Element::getData() {
    return data;
}

char Element::getDataFirst() {
    return data.first;
}

int Element::getDataSecond() {
    return data.second;
}

bool Element::isLeaf() {
    return !left && !right && this->getDataFirst() != '/';
}

void traversal(Element root, Stack stack, List *list) {
    int static indx = 1;
    
    if(root.isLeaf()) {
        stringstream aux;
        Stack auxS;
        
        for(; !stack.empty(); auxS.push(stack.pop()));
        
        for(char c; !auxS.empty();) {
            c = auxS.pop();
            stack.push(c);
            aux << c;
        }
        
        list->insert(indx, make_pair(root.getDataFirst(), aux.str()));
        indx++;
        
        return;
    }
    
    stack.push('0');
    traversal(*(root.left), stack, list);
    stack.pop();
    
    stack.push('1');
    traversal(*(root.right), stack, list);
    stack.pop();
}