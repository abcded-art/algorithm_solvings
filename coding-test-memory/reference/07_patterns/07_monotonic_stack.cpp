#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 오른쪽에서 처음 만나는 더 큰 값. 없으면 -1.
vector<int> nextGreater(const vector<int>& nums) {
    vector<int> answer(nums.size(), -1);
    stack<int> st; // 아직 답을 찾지 못한 인덱스, 값은 감소하는 순서

    for (int i = 0; i < (int)nums.size(); i++) {
        while (!st.empty() && nums[st.top()] < nums[i]) {
            answer[st.top()] = nums[i];
            st.pop();
        }
        st.push(i);
    }
    return answer;
}

int main() {
    vector<int> nums = {2, 1, 2, 4, 3};
    for (int value : nextGreater(nums)) cout << value << ' ';
    cout << '\n';
}
