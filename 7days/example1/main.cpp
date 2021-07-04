#include "String.h"

using namespace std;


int main() {
    vector <String> vec; vec.reserve(3);    // 벡터는 내부 공간을 자동으로 늘리 때마다 복사함
    String str1 = "abc";
    String str2 = "def";

    cout << str1.compare("abc") << endl;


    // copy constructor
    String str3(str1.append(str2));

    // constructor
    vec.emplace_back(str3.data());

    // constructor(1)
    vec.push_back(str2.data());
    vec.push_back(str1);

    for(const auto& it : vec)
    {
        cout << it.data() << "\n";
    } // str1, str2, str3 변수 소멸됨, 벡터에 저장된 원소 2개도 소멸됨
      // 6 번 생성자 호출됨, 6번 소멸자 호출됨
      // RAII : 생성자에서 자원을 획득하고, 소멸자에서 자원을 해제하는 원리를 이용함


}
