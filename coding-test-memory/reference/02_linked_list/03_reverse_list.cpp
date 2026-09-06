#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;

    while (cur != nullptr) {
        ListNode* next = cur->next; // 다음 위치 백업
        cur->next = prev;           // 화살표 뒤집기
        prev = cur;                 // prev 전진
        cur = next;                 // cur 전진
    }

    return prev;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    head = reverseList(head);

    for (ListNode* p = head; p != nullptr; p = p->next) {
        cout << p->val << ' ';
    }
    cout << '\n';

    while (head != nullptr) {
        ListNode* next = head->next;
        delete head;
        head = next;
    }
}
