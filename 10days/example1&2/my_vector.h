//
// Created by User on 2021-07-07.
//

#ifndef TEMPLATE_MY_VECTOR_H
#define TEMPLATE_MY_VECTOR_H

#include <algorithm>
#include <initializer_list>
#include <memory>
#include "my_vector_iterator.h"

template<typename T>
class my_vector{
public:
    // 생성자
    explicit my_vector(size_t N= 0) noexcept : _size(N), _data(new T[N]) { };

    // 생성자
    my_vector(std::initializer_list<int> lst) noexcept : _size(lst.size()), _data(new T[lst.size()]) {
        std::copy(lst.begin(), lst.end(), _data.get());
    };

    // 복사 생성자
    my_vector(const my_vector<T>& other) noexcept : _size(other._size), _data(new T[other._size]){
        std::copy(other._data.get(), other._data.get() + other._size, _data.get());
    };

    // subscript operator
    T& operator[](int i)
    {
        return _data[i];
    }

    // 멤버 함수
    size_t size() const
    {
        return _size;
    }

// ------------------------------ 실습 2
    my_vector_iterator<T> begin(){
        return my_vector_iterator<T>(_data.get());
    }

    my_vector_iterator<T> end(){
        return my_vector_iterator<T>(_data.get() + _size);
    }

private:
    size_t _size;
    std::unique_ptr<T[]> _data;
};


#endif //TEMPLATE_MY_VECTOR_H
