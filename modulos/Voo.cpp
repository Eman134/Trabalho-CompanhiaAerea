#include "Voo.h"
#include "Aviao.h"
#include <iostream>

using namespace std;

void Voo::cadastrarVoo() {
    Aviao aviao;
    if (aviao.getQtdAvioes() == 0) {
        cout << "Nao possui avioes cadastrados para fazer um voo." << endl;
        return;
    } else {
        cout << "Possui " << aviao.getQtdAvioes() << " avioes cadastrados." << endl;
    }
}