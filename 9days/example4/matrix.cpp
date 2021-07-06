//
// Created by User on 2021-07-06.
//
#include "matrix.h"
using namespace std;

// 기본 생성자
matrix::matrix(size_t row, size_t col) noexcept { }

// 생성자
matrix::matrix(initializer_list<initializer_list<int>> rows) : _data(rows.begin(), rows.end()) { }

// 오퍼레이터 오버로딩, 멤버 함수 구현 ( 플러스 )
matrix matrix::operator+(const matrix &rhs) const {

    matrix temp;
    temp._data.resize(rhs._data.size(), vector<int>(rhs._data[0].size()));
    for(int i =0; i< _data.size(); i++)
    {
        for(int j =0; j<(_data[0].size()); j++)
        {
            temp._data[i][j] = _data[i][j] + rhs._data[i][j];
        }
    }
    return temp;
}

// 오퍼레이터 오버로딩, 멤버 함수 구현 ( 마이너스 )
matrix matrix::operator-(const matrix &rhs) const {
    matrix temp;
    for(int i =0; i<_data.size(); i++)
    {
        for(int j=0; j<_data[i].size(); j++){
            temp._data[i][j] = _data[i][j] - rhs._data[i][j];
        }
    }
    return temp;
}

// 오퍼레이터 오버로딩, 멤버 함수 구현 ( 비교 연산자 )
bool matrix::operator==(const matrix &rhs) const {
    return _data == rhs._data;
}

// 오퍼레이터 오버로딩, 멤버 함수 구현 ( 비교 연산자 )
bool matrix::operator!=(const matrix &rhs) const {
    return !(_data == rhs._data);
}

// 사이즈 함수
std::pair<size_t, size_t> matrix::size() const {
    return pair<size_t, size_t> {_data.size(), _data[0].size()};
}

// 주어진 [] 오퍼레이터 사용. [][] 사용 가능
matrix matrix::transpose() {
    matrix temp;
    temp._data.resize(_data[0].size(), vector<int>(_data.size()));
    for(int i = 0; i<_data.size(); i++) {
        for (int j = 0; j < _data[0].size(); j++) {
            temp._data[j][i] = _data[i][j];
        }
    }
    return temp;
}

// free 함수 구현
std::ostream& operator<<(std::ostream& os, const matrix& m){
    for(const auto& row : m._data)
    {
        os <<"| ";
        for(const auto& col : row)
        {
            os << " " << col << " ";
        }
        os << " |"<<endl;
    }
    return os;
}