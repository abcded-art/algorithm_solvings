#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    vector<int> nums = {3, 1, 4};

    nums.push_back(2);
    cout << nums.back() << '\n';
    nums.pop_back();

    cout << nums[0] << '\n';
    cout << nums.size() << '\n';
    cout << boolalpha << nums.empty() << '\n';

    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());

    for (int x : nums) {
        cout << x << ' ';
    }
    cout << '\n';

    string s = "hello";
    cout << s[0] << '\n';
    cout << s.size() << '\n';
    cout << s.substr(1, 3) << '\n'; // "ell"

    size_t pos = s.find("ll");
    if (pos != string::npos) {
        cout << pos << '\n';
    }
}
