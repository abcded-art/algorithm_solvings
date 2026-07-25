#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <queue>
#include <deque>
#include <stack>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    queue<int> q;

    q.push(10);
    q.push(20);

    q.front();
    q.back();

    q.size();
    q.empty();

    q.pop();

    deque<int> dq;

    dq.push_front(10);
    dq.push_back(20);

    dq.front();
    dq.back();
    dq[1];

    dq.size();
    dq.empty();

    dq.pop_front();
    dq.pop_back();


    stack<int> st;
    
    st.push(10);
    st.push(20);

    st.top();
    
    st.size();
    st.empty();

    st.pop(); 

}