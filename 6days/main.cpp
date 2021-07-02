#include <iostream>
#include "complex.h"
#include <typeinfo>

using namespace std;


// 실습 6-1 - Complex class

int main() {
    complex c1;
    complex c11();  // function declaration
    complex c2 = 1;
    complex c3(1);
    complex c4 = complex();

    cout << c1 << '\n';
    cout << typeid(c11).name() << '\n';

    complex c5{1,2};
    complex c6 = {1,6};
    complex c7{};
    complex c8 ={};

    cout << c5 << '\n';
    cout << c5.add(c6) << '\n';
    cout << c5.add(1) << '\n';

    auto c9 = complex{1};
    cout << typeid(c9).name() << '\n';
    auto c10 = complex{1, 1};
    cout << typeid(c10).name() << '\n';

    return 0;
}

/*
 * 공부내용 정리
 - 기본적으로 complex 객체에서 add 함수 실행시 상수가 들어갈 경우 임시 객체가 생성된다.
 그리고 임시객체가 생성된 후 임시객체 내부의 멤버 변수들이 더해지는 것이다.

 - c11()은 기본적으로 생성자가 아닌 함수의 선언으로 정의가 된다.
 - 객체를 생성할 경우, 굳이 ()를 붙여줄 필요가 없으며 붙이면 함수 정의로 인식된다.

 < 중요 >
 - 우리가 ostream >> 연산자 오버로딩을 할 경우,
  파라미터에 기본적으로 std::ostream& os 라는 것을 넣어주어야 한다.

  - 일단 이렇게 파라미터를 넣어주는 이유는 간단하다.
  이렇게 파라미터를 넣어주어야 return os 구문을 실행시킬 수 있다.
  만약 파라미터에 ostream 객체가 없으면 우리는 return value를 어디서 찾을 것인가라는
  간단한 의문을 던질 수 있다.

  그러면 이러한 return os 를 왜 넣어주어야 하는 것인가?
  그것도 간단하다. 기본적으로 cout << "" << "" << 이러한 구문을 보면
  연쇄적으로 << operator가 사용이되는것을 볼 수 있다. 이 때, 우리는
  ostream 객체가 왼쪽의 처음 cout 객체로 부터 시작해서 함수 실행 후 반환되고,
  또 반환되고, 반복적으로 ostream os 객체가 반환되기 때문에 << 연산자를 연쇄적으로
  실행시킬 수 있는 것이다.

  그러면 우리는 함수선언에서 ostream& os 라는 파라미터를 인자로 넣어주는데
  실제로 main 함수에서는 그러한 객체를 넣어주지 않는다. 실제로는 출력할 객체나
  숫자 등만 operator<<( 내용물 ) 등으로 입력되어 보인다. 하지만
  여기서 주의할 점은 operator<< () 는 단항 연산자가 아니다. 이항 연산자이다.
  엥? 그게 문제가 되나? 라고 생각할 수 있다.

  그러나 이러한 의구심은 우리가 편히 사용하는 + , - , * , / 을 생각해보자
  우리는 이미 이러한 이항 연산자의 함수를 사용하면서 매개변수를 오른족에만
  두고 코딩하지 않는다. 즉, 왼쪽과 오른쪽의 숫자를 두고 함수의 인자로 넘겨주고
  이 함수가 인식 및 계산하여 결과물을 출력하는거보면
  cout << " " 의 구문에서도 왼쪽의 cout과 오른쪽의 " "가 함수의 인자로 삽입되어
  이항 연산자가 실행되는 것을 알 수 있다.

*/