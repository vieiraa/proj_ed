#include "huffman.h"

int main() {
    string input;

    cout << "Type the text: ";
    getline(cin, input);

    cout << "Tamanho original = " << input.size() * 8 << " bits" << endl;
    
    Huffman compactor(input);
    compactor.createTree();

    string show = compactor.code();

    cout << endl << "String: " << show << endl;
    cout << "Tamanho codificado = " << show.size() * 8 << " bits" << endl;

    return 0;
}
