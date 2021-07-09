//
// Created by User on 2021-07-07.
//

#ifndef EIGHT4_LIST_H
#define EIGHT4_LIST_H
#include <iostream>
#include <array>
#include <algorithm>
#include <optional>
#include <cassert>

template<typename T, size_t N>
class List{
public:
    List() : _cur_pos(0) { };
    List(const List& other){
        std::for_each(other._data.begin(), other._data.end(), [&](T x){
            _data[_cur_pos++] = x;
        });
    }

    List& operator=(const List& l){
        _cur_pos = 0;
        for(auto it = l._data.begin(); it != l._data.end(); ++it)
        {
            _data[_cur_pos++] = *it;
        }
        return *this;
    }
    int add(const T& t)
    {
        if(_cur_pos != N) {
            _data[_cur_pos++] = t;
            return true;
        }
        return false;
    }

    std::optional<T> find(const T& t) const
    {
        // const 선언 시 it 값 변경 불가
        for(auto it = _data.begin(); it!=_data.end(); ++it)
        {
            if(*it == t) { return *it; }
        }
        return std::nullopt;
    }

    std::optional<T> remove(const T& t)
    {
        auto p_end = std::remove(List::begin(), List::end(), t);

        if(p_end == List::end())
        {
            return std::nullopt;
        }
        else
        {
            while(p_end != List::end())
            {
                *p_end = T();
                p_end++;
            }
            _cur_pos--;
            return t;
        }
    }

    T* begin() {return _data.begin(); }
    T* end() { return _data.end(); }
    size_t size() const { return _data.size(); }

private:
    int _cur_pos = 0;
    std::array<T, N> _data;
};


#endif //EIGHT4_LIST_H
