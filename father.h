#ifndef FATHER_H
#define FATHER_H

#include "Tree.h"

class Father {
    Element *father;
    string flag;

public:
    Father(Element *, char);
    Father();
    void setFather(Element &);
    void setFlag(string);
    Element *getFather();
    string getFlag();
};

#endif
