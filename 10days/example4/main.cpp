#include <iostream>
#include <vector>

template<typename T>
T sum(T start)
{
    return start;
}

template<typename T, typename... Args>
T sum(T start, Args... args){
    return start + sum(args...);
}

int main() {
    std::cout<< sum(1,2,3,4) << std::endl;
    return 0;
}
