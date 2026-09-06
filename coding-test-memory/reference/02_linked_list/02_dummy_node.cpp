#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int main() {
    // dummy는 결과 리스트의 맨 앞에 임시 노드를 하나 두는 패턴이다.
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;

    for (int value : {7, 0, 8}) {
        cur->next = new ListNode(value); // 새 노드를 뒤에 연결
        cur = cur->next;                 // 방금 만든 노드로 이동
    }

    ListNode* result = dummy->next;

    for (ListNode* p = result; p != nullptr; p = p->next) {
        cout << p->val << ' ';
    }
    cout << '\n';

    delete dummy;
    while (result != nullptr) {
        ListNode* next = result->next;
        delete result;
        result = next;
    }
}
