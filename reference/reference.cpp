#include <iostream>

using namespace std;

int main(){
    int var = 5;
    int* ptr = &var;
 
    cout << " var: " << var << " &var: "<< &var << " ptr: " << ptr << " &ptr: " << &ptr; 
    return 0;
}