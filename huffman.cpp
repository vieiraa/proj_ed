#include "huffman.h"

Huffman::Huffman(string s) {
    Element root, left, right;

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

    queue.sort();
    queue.sort();
    
    dataString = queue.toString();
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
    string output = "";

    traversal(tree, stack, &list);
    
//  SORTING THE ENCRYPTED CODE
    for(int i = 0; i < input.size(); i++)
        output += list.visitSecond(list.searchFirst(input[i]));
    
    for(int i = 0; i < input.size(); i++) {
        codedInput += list.visitSecond(list.searchFirst(input[i]));
        codedInput += '*';
    }

    return output;
}

string Huffman::decode() {
    string output;
    string aux = output = "";
    
    if(list.size() == 1 && aux2.second > 1) {
        for(int i = 0; i < size; i++)
            output += list.visitFirst(1);
        
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

string Huffman::listToString() {
    return list.toString();
}

string Huffman::queueToString() {
    return dataString;
}