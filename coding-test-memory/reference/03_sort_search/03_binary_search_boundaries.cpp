#include <iostream>
#include <vector>
using namespace std;

// target 이상인 첫 위치. 없으면 nums.size()를 반환한다.
int lowerBound(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size(); // 정답 후보 구간: [left, right)

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// target보다 큰 첫 위치. 같은 값의 마지막 위치는 upperBound - 1이다.
int upperBound(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

int main() {
    vector<int> nums = {1, 2, 2, 2, 5, 8};
    int first = lowerBound(nums, 2);
    int afterLast = upperBound(nums, 2);

    cout << first << ' ' << afterLast - 1 << '\n'; // 1 3
    cout << afterLast - first << '\n';             // 2의 개수: 3
}
