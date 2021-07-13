//
// Created by User on 2021-07-13.
//

#ifndef EXCEPTION_STACKEXCEPTION_H
#define EXCEPTION_STACKEXCEPTION_H
#include <stdexcept>
#include <string>
#include <sstream>

class StackException : public std::runtime_error {
public:
    StackException(const std::string& msg, const char* file, size_t line)
            : std::runtime_error(msg), _msg{msg}, _file_name(file), _line(line){
        std::ostringstream oss;
        oss << file << ":" <<  line << ":" << "Exception: " << msg << std::endl;
        _msg = oss.str();
    };
    ~StackException() noexcept{ }

    const char* what() const noexcept{
        return _msg.c_str();
    }
private:
    std::string _msg;
    std::string _file_name;
    size_t _line = 0;
};
#endif //EXCEPTION_STACKEXCEPTION_H
