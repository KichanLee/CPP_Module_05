#include <exception>
#include <iostream>

using namespace std;

// 사용자 정의 예외 클래스
class DivisionByZeroException : public std::exception {
 public:
  const char* what() const throw() { return "0으로 나눌 수 없습니다."; }
};

void Divide(int num1, int num2) {
  if (num2 == 0) throw DivisionByZeroException();
  cout << "나눗셈의 몫: " << num1 / num2 << endl;
  cout << "나눗셈의 나머지: " << num1 % num2 << endl;
}

int main() {
  int num1, num2;
  cout << "두 개의 숫자 입력: ";

  cin >> num1 >> num2;

  try {
    Divide(num1, num2);
    cout << "나눗셈 끝\n";
  } catch (const DivisionByZeroException& e) {
    cerr << "예외 발생: " << e.what() << '\n';
    cout << "프로그램 재시작\n";
  }
  return 0;
}
