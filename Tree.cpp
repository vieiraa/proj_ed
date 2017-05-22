#include <unistd.h>
#include "Tree.h"

Element::Element(pair<char, int> p, Element *l = NULL, Element *r = NULL) {
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
    long int l = (long)left;
    long int r = (long)right;
    if (!left && !right)
        return true;
    return false;
    /* return !left && !right && this->getDataFirst() != '/'; */
}

BinaryTree::BinaryTree() {
    this->root = NULL;
}

bool BinaryTree::empty() {
    return !this->root;
}

void BinaryTree::setRoot(Element *node) {
    this->root = node;
}

Element *BinaryTree::getRoot() {
    return root;
}

Element *search(Element *root, pair<char, int> data) {
    if(!root)
        return NULL;

    if(root->data == data)
        return root;

    Element *p = search(root->left, data);

    if(!p)
        p = search(root->right, data);

    return p;
}

/*
map<char, string> test(Element *element) {
    map<char, string> data;
    stringstream aux;
    Element p;
    queue<Element> queue;

    if(element) {
        queue.push(*element);

        while(!queue.empty()) {
            p = queue.front();
            queue.pop();

            if(p.left) {
                aux << 0;
                data[p.left->getData().first] += aux.str();
                aux.str("");
                queue.push(*(p.left));
            }

            if(p.right) {
                aux << 1;
                data[p.right->getData().first] += aux.str();
                aux.str("");
                queue.push(*(p.right));
            }
        }
    }

    return data;
}


map<char, string> preOrder(Element *tree) {
    static map<char, string> data;
    stringstream aux;
    string flag = "left";

    if (tree) {
        cout << "getdata first = " << tree->getData().first << endl;

        if (tree->getData().first != '/') {
            if (flag == "left")
                aux << 0;
            else
                aux << 1;
            data[tree->getData().first] += aux.str();
            aux.str("");
        }
    }

    if (tree->left) {
        flag = "left";
        return preOrder(tree->left);
    }

    if (tree->right) {
        flag = "right";
        return preOrder(tree->right);
    }

    for (map<char, string>::iterator it = data.begin(); it != data.end(); *++it)
        cout << "map[" << it->first << "] = " << it->second << endl;

    return data;
}

void encode(vector<Element *> treeP, map<char, string> *par) {
    if(!(treeP.size()))
        return;

    cout << "to no encode" << endl;
    
    map<char, string> hash;

    cout << "treeP" << endl;
    for (int i = 0; i < treeP.size(); i++) {
        printPre(treeP[i]);
    }

    sleep(10);
    
    for(int i = 0; i < treeP.size(); i++) {
        for(Element *p = treeP[i]; p->father.getFather(); p = p->father.getFather()) {
            cout << endl << p->father.getFlag() << endl;
            hash[p->getData().first] += p->father.getFlag();   
        }
    }
    
    
    for (map<char, string>::iterator it = hash.begin(); it != hash.end(); *++it) {
        cout << endl << "exibindo hash em encode..." << endl;
        cout << "[" << it->first << "] = " << it->second << endl;
    }
    
    *par = hash;
}
*/

void traversal(Element *root, Stack stack, List *list) {
    int static indx = 1;
    
    cout << "cheguei ake" << endl;
    if (!root) {
        cout << "root eh null" << endl;
        return;
    }
    if(root->isLeaf()) {
        stringstream aux;
        Stack auxS;
        
        for(; !stack.empty(); auxS.push(stack.pop()));
        
        for(char c; !auxS.empty();) {
            c = auxS.pop();
            stack.push(c);
            aux << c;
        }
        
        list->insert(indx, make_pair(root->getDataFirst(), aux.str()));
        indx++;
    }
    
    stack.push('0');
    traversal(root->left, stack, list);
    stack.pop();
    
    stack.push('1');
    traversal(root->right, stack, list);
    stack.pop();
}

void printPre(Element *root) {
    if (!root)
        return;

    cout << root->getData().first << " " << root->getData().second << " " << endl;

    if (root->left)
        printPre(root->left);

    if (root->right)
        printPre(root->right);
}
