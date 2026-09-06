#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 모든 원소가 양수일 때, 합이 target 이상인 가장 짧은 연속 구간 길이.
int minSubarrayLength(const vector<int>& nums, int target) {
    int answer = nums.size() + 1;
    int left = 0;
    long long windowSum = 0;

    for (int right = 0; right < (int)nums.size(); right++) {
        windowSum += nums[right];

        // 조건을 만족하는 동안 왼쪽을 줄여 최소 길이를 찾는다.
        while (windowSum >= target) {
            answer = min(answer, right - left + 1);
            windowSum -= nums[left++];
        }
    }
    return answer == (int)nums.size() + 1 ? 0 : answer;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << minSubarrayLength(nums, 7) << '\n'; // 2: [4, 3]
}
