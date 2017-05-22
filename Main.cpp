#include "huffman.h"

int main() {
    string input;

    cout << "Type the text: ";
    getline(cin, input);
    
    cout << endl << "String Original: " << input << endl;
    cout << "Tamanho Original = " << input.size() * 8 << " bits" << endl;
    
    Huffman compactor(input);
    compactor.createTree();

    string show = compactor.code();
    
    cout << endl << "Dados e suas aparições no input -> " << compactor.queueToString() << endl;
    cout << "Dados e suas codificações -> " << compactor.listToString() << endl;
    
    cout << endl << "String Codificada: " << show << endl;
    cout << "Tamanho Codificado = " << show.size() << " bits" << endl;
    
    show = compactor.decode();
    
    cout << endl << "String Decodificada: " << show << endl;
    cout << "Tamanho Decodificado = " << show.size() * 8 << " bits" << endl;

    return 0;
}
