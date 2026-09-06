#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;

    Node(int x) : val(x), next(nullptr) {}
};

void addOneByValue(int x) {
    x++;
    cout << "함수 안의 복사본: " << x << '\n';
}

void addOneByReference(int& x) {
    x++;
}

void addOneByPointer(int* x) {
    (*x)++;
}

int main() {
    int a = 10;

    addOneByValue(a);      // 원본 변화 없음
    cout << a << '\n';    // 10

    addOneByReference(a);  // 원본 수정
    cout << a << '\n';    // 11

    addOneByPointer(&a);   // 주소 전달 후 원본 수정
    cout << a << '\n';    // 12

    Node* p = new Node(7);

    // p는 Node의 주소
    // *p는 실제 Node 객체
    // (*p).val == p->val
    cout << p->val << '\n';

    p->next = new Node(9);
    cout << p->next->val << '\n';

    delete p->next;
    delete p;
}
