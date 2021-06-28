#include "student.h"
#include "professor.h"

int main() {
    Student st{"Kim", JUNIOR};
    Professor pf{"Lee","6401"};
    print(st);
    print(pf);
    return 0;
}
