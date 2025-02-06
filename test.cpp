
#include <stdio.h>
#include <list>

class Object{


public:
Object(){
    printf("Created Object\n");
}

};

class Tranform{

    Object& parent;
    std::list<Object*> list;

public:
    Tranform(Object parent): parent(parent){
        printf("Created Transform\n");
    }
};


int main(){

    Object a;

    Tranform t(a);

}

