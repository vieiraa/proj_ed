#include "Tree.h"

Father::Father(Element *e, char c) {
    this->father = e;
    this->flag = c;
}

Father::Father(){}

void Father::setFather(Element *e) {
    father = e;
}

void Father::setFlag(char f) {
    flag = f;
}

Element *Father::getFather() {
    return father;
}

char Father::getFlag() {
    return flag;
}

Element::Element(pair<char, int> p) {
    setPair(p);
}

Element::Element(){};

void Element::setFather(Element *e, char c) {
    father.setFather(e);
    father.setFlag(c);
}
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

Father *Element::getFather() {
    return &father;
}

pair<char, int> &Element::getData() {
    return data;
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

void printPre(Element *root) {

    if (!root)
        return;

    cout << root->getData().second << " " << endl;

    if (root->left)
        printPre(root->left);

    if (root->right)
        printPre(root->right);
}
