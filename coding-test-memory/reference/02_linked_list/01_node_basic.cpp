#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

int main() {
    ListNode* head = new ListNode(2);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);

    // 핵심 1: 현재 값
    cout << head->val << '\n';

    // 핵심 2: 다음 노드
    cout << head->next->val << '\n';

    // 핵심 3: 순회
    ListNode* cur = head;

    while (cur != nullptr) {
        cout << cur->val << ' ';
        cur = cur->next;
    }
    cout << '\n';

    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
