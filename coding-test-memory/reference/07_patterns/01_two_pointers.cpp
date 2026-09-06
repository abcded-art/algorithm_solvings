#include <iostream>
#include <vector>
using namespace std;

bool hasPairSum(const vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        if (sum == target) return true;

        if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main() {
    // 정렬된 배열이라는 전제가 중요하다.
    vector<int> nums = {1, 2, 4, 7, 11, 15};
    cout << boolalpha << hasPairSum(nums, 15) << '\n';
}
