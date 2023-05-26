#ifndef STACK
#define STACK

class IntNode{
    public:
        int info;
        IntNode* proximo;
        IntNode( int el, IntNode* ptr = 0){
            info = el;
            proximo = ptr;
        }
};

class IntStack{
    public:
        IntStack(){
            topo = 0;
        }
        ~IntStack();
        bool isEmpty(){
            return topo == 0;
        }
        void push(int el);
        int pop();
        int topEl();
        void clear();
        void showStack();


    private:
        IntNode *topo;
};

#endif