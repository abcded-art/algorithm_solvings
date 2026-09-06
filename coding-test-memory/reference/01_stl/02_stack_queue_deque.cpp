#include <iostream>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

int main() {
    stack<int> st;
    st.push(10);
    st.push(20);
    cout << st.top() << '\n';
    st.pop();
    cout << st.top() << '\n';

    queue<int> q;
    q.push(10);
    q.push(20);
    cout << q.front() << '\n';
    q.pop();
    cout << q.front() << '\n';

    deque<int> dq;
    dq.push_back(2);
    dq.push_front(1);
    dq.push_back(3);

    cout << dq.front() << ' ' << dq.back() << '\n';
    dq.pop_front();
    dq.pop_back();
}
