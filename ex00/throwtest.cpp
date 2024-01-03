#include <iostream>
using namespace std;

int main() {
  int num1, num2;

  cout << "two number input";
  cin >> num1 >> num2;

  try {
    if (num2 == 0) throw num2;
  } catch (int expn) {
    cout << "제수는 " << expn << "이 될수 없습니다" << endl;
    cout << "프로그램을 다시 실행하세요";
  }
  cout << "end of main" << endl;

  return (0);
}