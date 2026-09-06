#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {2, 4, 1, 5, 3};

    // prefix[i] = 앞에서 i개 원소의 합
    // 누적 합은 int 범위를 넘기 쉬우므로 long long을 사용한다.
    vector<long long> prefix(nums.size() + 1, 0);

    for (int i = 0; i < (int)nums.size(); i++) {
        prefix[i + 1] = prefix[i] + nums[i];
    }

    // [left, right] 구간 합
    int left = 1;
    int right = 3;

    long long rangeSum = prefix[right + 1] - prefix[left];
    cout << rangeSum << '\n'; // 4 + 1 + 5 = 10
}
