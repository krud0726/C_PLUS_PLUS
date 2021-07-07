#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H
#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <vector>



class matrix {
public:
    matrix(size_t row=0, size_t col=0) noexcept ;
    matrix(std::initializer_list<std::initializer_list<int>> rows);
    ~matrix() = default;

    matrix operator+(const matrix& rhs) const;
    matrix operator-(const matrix& rhs) const;
    bool operator==(const matrix& rhs) const;
    bool operator!=(const matrix& rhs) const;

    class Proxy {
    public:
        Proxy(std::vector<int>* vec) : _vec(vec) { }
        int& operator[](int index) {
            return (*_vec)[index];
        }

    private:
        std::vector<int>* _vec;
    };

    Proxy operator[](int index) {
        return Proxy(&_data[index]);
    }

    std::pair<size_t , size_t> size() const;
    matrix transpose();

    friend std::ostream& operator<<(std::ostream &os, const matrix& a);

private:
    std::vector<std::vector<int>> _data;

};



#endif //MATRIX_MATRIX_H

