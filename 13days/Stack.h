//
// Created by User on 2021-07-13.
//

#ifndef EXCEPTION_STACK_H
#define EXCEPTION_STACK_H

#include "StackException.h"
#include <iostream>

template<typename T>
class Stack{
public:
    Stack(int sz) : size(sz) {
        s = new T[size];
    };          // 객체 초기화 및 필요한 자원을 획득하시오
    ~Stack() noexcept{
        delete []s;
    };      // 사용한 자원을 해제하시오

    // 복사 생성자와 복사 대입 연산자를 삭제하시오
    Stack(Stack const&) = delete;
    Stack& operator=(Stack const&) = delete;

    void push(T c) {
        if(size <= top) {throw StackException("Stack is full!", "main.cpp", __LINE__);}
        s[top++] = c; };

    T pop() {
        if((top == 0) || (size <= 0)) { throw StackException("Stack is empty!", "main.cpp", __LINE__);}
        T r = s[--top]; return r; };

    void print() const{
        for(int i=0; i< top; i++)
        { std::cout << s[i] << "\n"; }
    }
private:
    int size = 0; int top = 0;
    T* s = nullptr;
};
#endif //EXCEPTION_STACK_H
