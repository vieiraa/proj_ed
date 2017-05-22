#include <unistd.h>
#include "Tree.h"
#include "huffman.h"

Huffman::Huffman(string s) {
    BinaryTree auxTree;
    Element root, left, right;

    input = s;

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
    
    tree = queue.pop();
}

string Huffman::code() {
    static string output = "";
    Stack stack;
    List list;

    traversal(tree, stack, &list);
    
    cout << endl << list.toString();
    
//  SORTING THE ENCRYPTED CODE
    for(int i = 0; i < input.size(); i++)
        output += list.visitSecond(list.searchFirst(input[i]));

    return output;
}
