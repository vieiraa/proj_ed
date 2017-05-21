#include "father.h"

Father::Father(Element *e, char c) {
    this->father = e;
    this->flag = c;
}

Father::Father(){}

void Father::setFather(Element &e) {
    father = &e;
}

void Father::setFlag(string f) {
    flag = f;
}

Element *Father::getFather() {
    return father;
}

string Father::getFlag() {
    return flag;
}

