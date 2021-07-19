#include <iostream>
#include <string>
#include <cstddef>

using namespace std;

class StackFullException{
    const size_t _size{};
    const int _current{};
public:
    StackFullException(size_t size, int current) : _size(size), _current(current){ };

    void print() const{
        cerr << "The Stack is full!" << ", size: " << _size << ", current: " << _current << endl;
    }
};
class StackEmptyException{
public:
    void print() const{
        cerr << "The Stack is Empty!" << endl;
    }
};
template<typename T>
class Stack{
    size_t size = 0;
    int top = 0;
    T* s = nullptr;
public:
    Stack(size_t sz) : size(sz), top(0) {
        if(sz < 0) throw "size cannot be negative";
        s = new T[sz];
    }
    size_t getSize() { return size;}
    size_t getCurrent() { return top; }
    bool isEmpty() { return top == 0; }
    void push(T c){
        if(top >= size) throw StackFullException(size, top);
        s[top++] = c;
    }

    T pop() {
        if(top == 0) throw StackEmptyException();
        T r = s[--top];
        return r;
    }

    void print() const{
        for(int i = 0; i< top; i++){
            cout << s[i];
        }
        cout << endl;
    }
    ~Stack(){if(s) delete[] s;}
};
int main() {
    int size;
    cin >> size;
    Stack<double> myStack(size);

    for(int i=0; i<100; i++){
        double value;
        cin >> value;
        if(value == 'Q') break;
        try {
            myStack.push(value);
        }catch(StackFullException& s){
            s.print();
        }
    }

    try {
        for (int i = 0; i < 100; i++) {
            cout << myStack.pop() << endl;
        }
    }catch(StackEmptyException& s){
        s.print();
    }
    return 0;
}
