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

    cout << queue.toString() << endl;

    /* for (map<char, int>::iterator it = aux.begin(); it != aux.end(); *++it) { */
    /*     cout << "first = " << it->first << endl; */
    /*     cout << "second = " << it->second << endl; */
    /* } */
    queue.sort();
    queue.sort();
}

void Huffman::createTree() {
    static Element root, left, right;
    Element *first, *second;
    /* BinaryTree auxTree; */
    static int c = 0;

    /* cout << queue.toString() << endl; */

    while (queue.size() > 1) {
        first = queue.pop();
        second = queue.pop();

        int fF = first->getData().first;
        int fS = first->getData().second;
        int sF = second->getData().first;
        int sS = second->getData().second;

        treeP.push_back(first);
        treeP.push_back(second);

        cout << "cheguei ake" << endl;

        root.setPair(make_pair('/', fS + sS));
        left.setPair(make_pair(fF, fS));
        right.setPair(make_pair(sF, sS));
        root.setLeft(&left);
        root.setRight(&right);
        left.setFather(&root, '0');
        right.setFather(&root, '1');


        auxTree.setRoot(&root);

        cout << "testing..." << endl;

        /* printPre(auxTree.getRoot()); */

        queue.push(&root);
    }

    cout << "print queue..." << endl;
    cout << queue.toString() << endl;

    /* cout << "teste..." << endl; */
    /* cout << queue.getFront()->data.getLeft()->getData().second << endl; */

    /* queue.print(); */

    tree.setRoot(queue.pop());

    cout << "printing preorder after tree creation..." << endl;

    printPre(tree.getRoot());
}

string Huffman::code() {
    static string output = "";
    map<char, string> aux;

    cout << "printing preorder on code()..." << endl;
    printPre(tree.getRoot());

    aux = preOrder(tree.getRoot());

    /* for (map<char, string>::iterator it = aux.begin(); it != aux.end(); *++it) */
    /*     cout << "map[" << it->first << "] = " << it->second << endl; */

    for (int i = 0; i < input.size(); i++) {

        output += aux[input[i]];
    }

    return output;
}
