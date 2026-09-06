#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    // 예: 회의실 배정 - 끝나는 시간이 빠른 회의를 먼저 선택
    vector<pair<int, int>> meetings = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {8, 9}, {5, 9}
    };

    sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b) {
        if (a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0;
    // 시작 시간이 음수여도 첫 회의를 선택할 수 있게 최솟값에서 시작한다.
    int lastEnd = numeric_limits<int>::min();

    for (auto [start, end] : meetings) {
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }

    cout << count << '\n';

    // Greedy는 정렬 기준을 외우는 것보다 그 선택이 항상 최적인지
    // 교환 논증 등으로 설명할 수 있는지가 중요하다.
}
