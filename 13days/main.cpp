#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack<char> stack(1);
    try{
        stack.push('a');
        stack.push('b');
    }
    catch(const StackException& e){
        cout << e.what() << endl;
    }
    stack.print();
    return 0;
}
