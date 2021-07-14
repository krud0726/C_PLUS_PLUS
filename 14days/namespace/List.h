//
// Created by User on 2021-07-14.
//

#ifndef NS_LIST_H
#define NS_LIST_H
#include <iostream>
#include <array>
#include <algorithm>
#include <optional>
#include <cassert>
namespace container {
    template<typename T, size_t N>
    class List {
    public:
        List() : _cur_pos(0) {};

        List(const List &other) : _data(other._data) {}

        List &operator=(const List &l) {
            _cur_pos = l._cur_pos;
            _data = l._data;
            return *this;
        }

        int add(const T &t) {
            if (_cur_pos != N) {
                _data[_cur_pos++] = t;
                return true;
            } else { return false; }
        }

        std::optional<T> find(const T &t) const {
            auto it = std::find(begin(), end(), t);
            if (it != end()) { return *it; }
            else { return std::nullopt; }
        }

        std::optional<T> remove(const T &t) {
            auto remove_it = std::remove(begin(), end(), t);
            if (remove_it != end()) {
                _cur_pos--;
                while (remove_it != end()) {
                    *remove_it = T();
                    ++remove_it;
                }
                return t;
            } else {
                return std::nullopt;
            }
        }

        T *begin() { return _data.begin(); }

        T *end() { return _data.end(); }

        size_t size() const { return _data.size(); }

    private:
        int _cur_pos = 0;
        std::array<T, N> _data;
    };
}
#endif //NS_LIST_H
