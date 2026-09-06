#include <iostream>
using namespace std;

int factorial(int n) {
    // 종료 조건이 반드시 필요하다.
    if (n <= 1) {
        return 1;
    }

    return n * factorial(n - 1);
}

void countdown(int n) {
    if (n == 0) {
        cout << "done\n";
        return;
    }

    cout << n << '\n';
    countdown(n - 1);
}

int main() {
    cout << factorial(5) << '\n';
    countdown(3);
}
