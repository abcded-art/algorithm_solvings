#include <iostream>
#include <vector>
using namespace std;

int sumVector(const vector<int>& nums) {
    int sum = 0;

    for (int x : nums) {
        sum += x;
    }

    return sum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    // index 기반 순회
    for (int i = 0; i < (int)nums.size(); i++) {
        cout << nums[i] << ' ';
    }
    cout << '\n';

    // range-for
    for (int x : nums) {
        cout << x << ' ';
    }
    cout << '\n';

    // while
    int i = 0;
    while (i < (int)nums.size()) {
        cout << nums[i] << ' ';
        i++;
    }
    cout << '\n';

    cout << sumVector(nums) << '\n';
}
