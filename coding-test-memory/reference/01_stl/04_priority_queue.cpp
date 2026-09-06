#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main() {
    // 최대 힙: 가장 큰 값이 top
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(10);
    maxHeap.push(5);
    cout << maxHeap.top() << '\n'; // 10

    // 최소 힙: 가장 작은 값이 top
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(10);
    minHeap.push(5);
    cout << minHeap.top() << '\n'; // 3
}
