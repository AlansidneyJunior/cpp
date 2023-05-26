#ifndef INT_LINKED_LIST
#define INT_LINKED_LIST

class IntNode{
    public:
        int info;
        IntNode* proximo;
        IntNode(int el, IntNode* ptr = 0){
            info = el;
            proximo = ptr;
        }
};

class IntSLLst{
    public:
        IntSLLst(){
            topo = resto = 0;
        }
        ~IntSLLst();
        int isEmpty(){
            return topo == 0;
        }
        void addToTopo(int);
        void addToResto(int);
        int deleteFromTopo();
        int deleteFromResto();
        void deleteNode(int);
        bool isInList(int) const;
        void showList();

    private:
        IntNode* topo, *resto;
};

#endif