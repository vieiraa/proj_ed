#include "huffman.h"

int main() {
    string input;

    cout << "Type the text: " << endl;
    getline(cin, input);

//     cout << "tamanho original = " << input.size() * 8 << " bits" << endl;
    
    Huffman compactor(input);
    compactor.createTree();

    string show = compactor.code();

//     cout << "String: " << show << endl;
//     cout << "tamanho codificado = " << show.size() * 8 << " bits" << endl;

    return 0;
}
