#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {1, 3, 5, 7, 9};
    cout << binarySearch(nums, 7) << '\n';

    // STL 버전
    auto it = lower_bound(nums.begin(), nums.end(), 6);
    if (it != nums.end()) {
        cout << *it << '\n'; // 7
    }
}
