#include <iostream>

#define GEN_STACK

using std::cout;
using std::string;
using std::endl;

template <typename T>
class Node{
    public:
        T info;
        Node* proximo;

        Node(T el, Node* ptr = 0){
            info = el;
            proximo = ptr;
        }
};

template <typename T>
class GenStack{
    public:

        GenStack(){
            topo = 0;
        }

        ~GenStack(){
            for(Node<T>* p; !isEmpty(); ){
                p = topo->proximo;
                delete topo;
                topo = p;
            }
        }

        bool isEmpty(){
            return topo == 0;
        }

        void push(T el){
            topo = new Node<T>(el, topo);
        }

        T pop(){
            T el = topo->info;
            Node<T>* tmp = topo->proximo;
            delete topo;
            topo = tmp;
            return el;
        }

        T topEl(){
            return topo->info;
        }

        void showStack(){
            std::cout << endl;
            for(Node<T>* p = topo; p != 0; p = p->proximo){
                std::cout << "Value: " << p->info << endl;
            }
        }
    private:
        Node<T>* topo;
};