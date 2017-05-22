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
        queue.push(&root);
    }

    /* cout << queue.toString() << endl; */
//     cout << "ala" << endl;
//     queue.print();
    /* sleep(5); */

    /* for (map<char, int>::iterator it = aux.begin(); it != aux.end(); *++it) { */
    /*     cout << "first = " << it->first << endl; */
    /*     cout << "second = " << it->second << endl; */
    /* } */
    queue.sort();
    queue.sort();

//     cout << "printing after sorting..." << endl;
//     cout << queue.toString() << endl;
    
}

void Huffman::createTree() {
    /* static Element root, left, right; */
    Element first, second;
    /* BinaryTree auxTree; */
    static int c = 0;

//     cout << queue.toString() << endl;

    while (queue.size() > 1) {
        cout << queue.toString() << endl;
        first = queue.pop();
        second = queue.pop();
        
        cout << "First: " << first.getData().first << " : " << first.getData().second << endl;
        cout << "Second: " << second.getData().first << " : " << second.getData().second << endl;
        
        char fF = first.getData().first;
        int fS = first.getData().second;
        char sF = second.getData().first;
        int sS = second.getData().second;

/*         cout << "fF = " << fF << endl; */
/*         cout << "fS = " << fS << endl; */
/*         cout << "sF = " << sF << endl; */
/*         cout << "sS = " << sS << endl; */

/*         sleep(10); */

//         cout << "cheguei ake" << endl;

        Element *left = new Element(make_pair(fF, fS), NULL, NULL);
        Element *right = new Element(make_pair(sF, sS), NULL, NULL);
        Element *root = new Element(make_pair('/', (fS+sS)), left, right);
        /* left.setPair(make_pair(fF, fS)); */
        /* left.setLeft(NULL); */
        /* left.setRight(NULL); */
        /* right.setPair(make_pair(sF, sS)); */
        /* right.setLeft(NULL); */
        /* right.setRight(NULL); */
        /* root.setLeft(&left); */
        /* root.setRight(&right); */

//         cout << "balbal" << endl;
//         queue.print();
//         printPre(&root);
        /* sleep(5); */

        /* cout << "testing..." << endl; */

        /* printPre(auxTree.getRoot()); */

        queue.push(root);
    }

//     cout << "print queue after this shit..." << endl;
//     cout << queue.toString() << endl;

    /* cout << "teste..." << endl; */
    /* cout << queue.getFront()->data.getLeft()->getData().second << endl; */

    /* queue.print(); */
    
    Element root = queue.pop();
    tree.setRoot(&root);

//     cout << "printing preorder after tree creation..." << endl;

//     printPre(tree.getRoot());
}

string Huffman::code() {
    static string output = "";
    Stack stack;
    List list;

//     cout << "printing preorder on code()..." << endl;
//     printPre(tree.getRoot());
    traversal(tree.getRoot(), stack, &list);

//     cout << list.toString() << endl;
    
    for (int i = 1; i <= list.size(); i++)
        output += list.visit(i).second;

    return output;
}
