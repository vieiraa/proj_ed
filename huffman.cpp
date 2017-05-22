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
    static Element root, left, right;
    Element *first, *second;
    /* BinaryTree auxTree; */
    static int c = 0;

//     cout << queue.toString() << endl;

    while (queue.size() > 1) {
        first = queue.pop();
        second = queue.pop();

        char fF = first->getData().first;
        int fS = first->getData().second;
        char sF = second->getData().first;
        int sS = second->getData().second;

/*         cout << "fF = " << fF << endl; */
/*         cout << "fS = " << fS << endl; */
/*         cout << "sF = " << sF << endl; */
/*         cout << "sS = " << sS << endl; */

/*         sleep(10); */

//         cout << "cheguei ake" << endl;

        root.setPair(make_pair('/', fS + sS));
        left.setPair(make_pair(fF, fS));
        right.setPair(make_pair(sF, sS));
        root.setLeft(&left);
        root.setRight(&right);

//         cout << "balbal" << endl;
//         queue.print();
//         printPre(&root);
        /* sleep(5); */

        /* cout << "testing..." << endl; */

        /* printPre(auxTree.getRoot()); */

        queue.push(&root);
    }

//     cout << "print queue after this shit..." << endl;
//     cout << queue.toString() << endl;

    /* cout << "teste..." << endl; */
    /* cout << queue.getFront()->data.getLeft()->getData().second << endl; */

    /* queue.print(); */

    tree.setRoot(queue.pop());

//     cout << "printing preorder after tree creation..." << endl;

//     printPre(tree.getRoot());
}

string Huffman::code() {
    static string output = "";
    Stack stack;
    map<char, string> encodedString;

//     cout << "printing preorder on code()..." << endl;
//     printPre(tree.getRoot());

    encodedString = traversal(tree.getRoot(), stack);

     for (map<char, string>::iterator it = encodedString.begin(); it != encodedString.end(); *++it)
         cout << "map[" << it->first << "] = " << it->second << endl;
    
    for (int i = 0; i < input.size(); i++)
        output += encodedString[input[i]];

    return output;
}
