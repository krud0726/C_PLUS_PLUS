//
// Created by User on 2021-07-07.
//

#ifndef TEMPLATE_MY_VECTOR_ITERATOR_H
#define TEMPLATE_MY_VECTOR_ITERATOR_H
#include "my_vector.h"

template<typename T>
class my_vector;

template<typename T>
class my_vector_iterator{
public:
    // 기본 생성자
    my_vector_iterator(T* e = nullptr) : _e(e) {};

    T& operator*() { return *_e; }
    // prefix 연산자, for(auto it = vec.begin(); it != vec.end(); ++it) 등에 사용
    my_vector_iterator<T>& operator++()
    {
        _e++;
        return *this;
    };

    // == 연산자
    bool operator==(const my_vector_iterator<T>& e) const
    {
        return _e == e._e;
    };

    // != 연산자
    bool operator!=(const my_vector_iterator<T>& e) const
    {
        return _e != e._e;
    };

private:
    T* _e = nullptr;        // my_vector의 원소를 가리킴
};

template<typename T, typename U>
inline U my_accumulate(T _begin, T _end, U init)
{
    // 템플릿 함수 구현
    while(_begin != _end)
    {
        init = init + (*_begin);
        ++_begin;
    }
    return init;
}

#endif //TEMPLATE_MY_VECTOR_ITERATOR_H
