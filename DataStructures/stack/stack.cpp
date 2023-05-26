#include <iostream>
#include "stack.h"

using namespace std;

IntStack::~IntStack(){
    for(IntNode *p; !isEmpty();){
        p = topo->proximo;
        delete topo;
        topo = p;
    }
}

void IntStack::push(int el){
    topo = new IntNode(el,topo);
}

int IntStack::pop(){
    int el = topo->info;
    IntNode *tmp = topo;
    topo = topo->proximo;
    delete tmp;
    return el;
}

int IntStack::topEl(){
    return topo->info;
}

void IntStack::showStack(){
    for(IntNode *p = topo; p != 0; p = p->proximo){
        cout << p->info << "\n";
    }
    cout << "\n";
}

int main(){

    int n;
    IntStack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    stack.showStack();
    stack.pop();
    stack.pop();

    stack.push(4);
    stack.push(5);

    stack.showStack();
    cout << stack.isEmpty() << endl;

    
    stack.pop();
    stack.pop();
    stack.pop();

    cout << stack.isEmpty();



    return 0;
}