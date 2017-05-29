#include <fstream>
#include "huffman.h"

int main(int argc, char **argv) {
    string input;
    char *aux;
    ifstream text;
    int length;

    if (argc > 1) {
        text.open(argv[1]);

        text.seekg(0, text.end);
        length = text.tellg();
        text.seekg(0, text.beg);

        aux = new char[length];

        text.read(aux, length);

        if (text)
            cout << "All characters read." << endl;
        else
            cout << "Only " << text.gcount() << "was red." << endl;

        input.assign(aux);

        if (input[length - 1] == '\n')
            input.pop_back();

        text.close();
    }

    else {
        cout << "Type the text: ";
        getline(cin, input);
    }

    cout << endl << "String Original.: " << input << endl;
    cout << "Tamanho Original: " << input.size() * 8 << " bits" << endl;
    
    Huffman compactor(input);
    compactor.createTree();

    string show = compactor.code();
    
    cout << endl << "Dados e suas aparições no input -> " << compactor.queueToString() << endl;
    cout << "Dados e suas codificações -> " << compactor.listToString() << endl;
    
    cout << endl << "String Codificada.: " << show << endl;
    cout << "Tamanho Codificado: " << show.size() << " bits" << endl;
    
    show = compactor.decode();
    
    cout << endl << "String Decodificada.: " << show << endl;
    cout << "Tamanho Decodificado: " << show.size() * 8 << " bits" << endl;

    return 0;
}
