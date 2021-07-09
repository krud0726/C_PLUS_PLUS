#include <iostream>
#include "Manager.h"
#include "Developer.h"
int main() {
    Manager ceo {"Kim", "CEO", 40'000'000};

    Manager design {"Lee", "Design", 8'000'000};
    Manager develop {"Park", "Development", 9'000'000};
    Manager qa {"Kim", "QA", 5'000'000};

    ceo.addEmployee(&design);
    ceo.addEmployee(&develop);
    ceo.addEmployee(&qa);

    std::cout << "Part1 Finished!!" << std::endl;

    Developer dev1 {"Kim", "Dev1", 4'000'000};
    Developer dev2 {"Jon", "Dev2", 5'000'000};

    develop.addEmployee(&dev1);
    develop.addEmployee(&dev2);

    std::cout << "Part2 Finished!!" << std::endl;

    ceo.print(0);

    return 0;
}
