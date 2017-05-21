#include "huffman.h"

int main() {
    string input;
    
    cout << "Type the text: " << endl;
    getline(cin, input);
    
    cout << "tamanho original = " << input.size() << endl;
    
    Huffman compactor(input);
    compactor.createTree();
    
    string show = compactor.code();
    
    cout << "String é: " << show << endl;
    cout << "tamanho codificado = " << show.size() << endl;
    
    return 0;
}
