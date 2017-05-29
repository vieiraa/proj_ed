#include "huffman.h"

Huffman::Huffman(string s) {
    Element root;

    input = s;
    size = input.size();

    for (int i = 0; i < input.size(); i++) {
        aux[input[i]]++;
    }

    for (map<char, int>::iterator it = aux.begin(); it != aux.end(); *it++) {
        root.setPair(*it);
        root.setLeft(NULL);
        root.setRight(NULL);
        queue.push(root);
    }
    
    cout << "..." << endl;
    queue.sort();
    cout << "..." << endl;
    queue.sort();
    cout << "..." << endl;
    
    dataString = "Dados e suas aparições no input....: " + queue.toString().substr(7);
}

void Huffman::createTree() {
    Element first, second;

    while (queue.size() > 1) {
        first = queue.pop();
        second = queue.pop();
        
//      AUX VALUES   
        char fF = first.getData().first;
        int fS = first.getData().second;
        char sF = second.getData().first;
        int sS = second.getData().second;
        
        Element *root = new Element();
        Element *left = new Element();
        Element *right = new Element();
        
//      SETTING LEFT NODE
        left->setPair(make_pair(fF, fS));
        
        if(fF != '/') {
            left->setLeft(NULL);
            left->setRight(NULL);
        }
        else {
            left->setLeft(first.left);
            left->setRight(first.right);
        }
        
//      SETTING RIGHT NODE
        right->setPair(make_pair(sF, sS));
        
        if(sF != '/') {
            right->setLeft(NULL);
            right->setRight(NULL);
        }
        else {
            right->setLeft(second.left);
            right->setRight(second.right);
        }
        
//      SETTING ROOT/FOREST NODE
        root->setPair(make_pair('/', (fS+sS)));
        root->setLeft(left);
        root->setRight(right);

        queue.push(*root);
    }
    
//  SETTING THE FINAL NODE
    tree = queue.pop();
    aux2 = tree.getData();
}

string Huffman::code() {
    string output;
    string aux = output = "";

    traversal(tree, stack, &list);
    
//  SORTING THE ENCRYPTED CODE
    for(int i = 0; i < input.size(); i++) {
        aux = list.visitSecond(list.searchFirst(input[i]));
        output += aux;
        codedInput += aux;
        codedInput += '*';
    }
    
    myCodedString = output;

    return output;
}

//  DECODING STRING WITH PAIR LIST
string Huffman::decode() {
    string output;
    string aux = output = "";
    
    if(tree.isLeaf()) {
        for(int i = 0; i < tree.getDataSecond(); output += tree.getDataFirst(), i++);
        return output;
    }
    
    for(int i = 0; i < codedInput.size(); i++) {
        if(codedInput[i] == '*') {
            output += list.visitFirst(list.searchSecond(aux));
            i++;
            aux = "";
        }
        
        aux += codedInput[i];
    }
    
    return output;
}

//  DECODING STRING TRAVERSING THE HUFFMAN TREE
string Huffman::toString() {
    return dataString + "\nDados e suas codificações na árvore: " + list.toString().substr(6);
}

string Huffman::decodeT() {
    string output = "";
    
    if(tree.isLeaf()) {
        for(int i = 0; i < tree.getDataSecond(); output += tree.getDataFirst(), i++);
        return output;
    }
    
    traversalT(tree, myCodedString, &output, 0);
    
    return output;
}
