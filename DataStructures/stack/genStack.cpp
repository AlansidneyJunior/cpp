#include <iostream>
#include "genStack.h"

using std::string;

int main(){
    GenStack<string> stack;

    std::cout << stack.isEmpty() << std::endl;
    stack.push("Jon");
    stack.push("Alan");
    stack.push("Elias");

    stack.showStack();
    stack.push("David");

    stack.showStack();

    stack.pop();
    stack.pop();

    stack.showStack();

    return 0; 
}