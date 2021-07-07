#include "matrix.h"
using namespace std;

matrix::matrix(size_t row, size_t col) noexcept {
    //기본 생성자 함수를 구현하시오
}

matrix::matrix(std::initializer_list<std::initializer_list<int>> rows) : _data(rows.begin(), rows.end()){ }

matrix matrix::operator+(const matrix& rhs) const {
    matrix temp;
    temp._data.resize(rhs._data.size(), vector<int>(rhs._data[0].size()));

    for(int i =0; i< _data.size(); i++)
    {
        for(int j=0; j<(_data[0].size()); j++)
        {
            temp._data[i][j] = _data[i][j] + rhs._data[i][j];
        }
    }

    return temp;
}

matrix matrix::operator-(const matrix& rhs) const {
    matrix temp;
    temp._data.resize(rhs._data.size(), vector<int>(rhs._data[0].size()));
    for(int i =0; i<_data.size(); i++)
    {
        for(int j =0; j<_data[i].size(); j++)
        {
            temp._data[i][j] = _data[i][j] - rhs._data[i][j];
        }
    }

    return temp;

}
bool matrix::operator==(const matrix& b) const {

    return _data == b._data;
}

bool matrix::operator!=(const matrix& b) const {
    return !(this->operator==(b));
}

std::pair<size_t , size_t> matrix::size() const {
    return pair<size_t, size_t> {_data.size(), _data[0].size()};
}

matrix matrix::transpose(){
    matrix temp;
    temp._data.resize(_data[0].size(), vector<int>(_data.size()));
    for(int i =0; i<_data.size(); i++){
        for(int j=0; j<_data[0].size(); j++)
        {
            temp._data[j][i] = _data[i][j];
        }
    }
    return temp;

}

std::ostream& operator << (std::ostream& os, const matrix& m) {
    for(const auto& row : m._data)
    {
        os << "| ";
        for(const auto& col : row)
        {
            os << " " << col << " ";
        }
        os << " |" << endl;
    }
    return os;
}