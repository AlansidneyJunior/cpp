#include <iostream>

using namespace std;

class MyClass{
    public:
        int i;
        void myMethod();
};

void MyClass::myMethod(){
    cout << "Bom dia Seu Ze!";
}
int main (){
    MyClass obj;
    obj.myMethod();
    // cout << obj << endl;
    return 0;
}