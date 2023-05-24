#include <iostream>
#include "intSLLst.h"

using namespace std;

IntSLLst::~IntSLLst(){
    for(IntNode *p; !isEmpty();){
        p = topo->proximo;
        delete topo;
        topo = p;
    }
}

void IntSLLst::addToTopo(int el){
    topo = new IntNode(el,topo);
    if(resto == 0)
        resto = topo;
}

void IntSLLst::addToResto(int el){
    if(resto != 0){
        resto->proximo = new IntNode(el);
        resto = resto->proximo;
    }
    topo = resto = new IntNode(el);
}

int IntSLLst::deleteFromTopo(){
    int el = topo->info;
    IntNode* tmp = topo;

    if(topo == resto){
        topo = resto = 0;
    }
    else topo = topo->proximo;
    delete tmp;
    return el;
}

int IntSLLst::deleteFromResto(){
    int el = resto->info;
    if(resto == topo){
        delete topo;
        topo = resto = 0;
    }else{
        IntNode *tmp;
        for(tmp = topo; tmp->proximo != resto; tmp = tmp->proximo);
        delete resto;
        resto = tmp;
        resto->proximo = 0;
    }
    return el;
}

void IntSLLst::deleteNode (int el){
    if(topo != 0){ //lista não é vazia
        if(topo == resto && el == topo->info){//lista com 1 el
            topo = resto = 0;
            delete topo;
        }
        else if (topo->info == el){// se el é o 1 elem da lista
            IntNode* tmp = topo;
            topo = topo->proximo;
            delete tmp;
        }else{
            IntNode *pred,*tmp;
            for(pred = topo, tmp = topo->proximo; tmp->info != el; pred = pred->proximo, tmp = tmp->proximo);
            if (tmp != 0){
                pred->proximo = tmp->proximo;
                if(tmp == resto){
                    pred = resto;
                }
                delete tmp;
            }


        }
    }        
}

bool IntSLLst::isInList(int el) const {
    IntNode *tmp;
    for(tmp = topo; (tmp->info != el) && tmp != 0; tmp = tmp->proximo);
    return tmp != 0;
}

void IntSLLst::showList(){
    IntNode *tmp;
    for(tmp = topo; tmp != 0; tmp = tmp->proximo){
        cout << tmp->info << "->"; 
    }
    delete tmp;
}

int main (){
    IntSLLst list;

    cout << list.isEmpty()<< endl;

    list.addToTopo(10);
    list.addToTopo(20);
    list.addToTopo(30);

    list.showList();

    return 0;
    
}