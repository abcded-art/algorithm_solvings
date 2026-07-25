#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int start = 1, end = 0;

    for(int i : diffs){
        end = max(i, end);
    }

    answer = end;

    while(start < end){
        int middle = start + end >> 1;

        long long result = 0;

        for (int i = 0; i < diffs.size(); i++){
            if(diffs[i] <= middle){
                result += times[i];
            } else {
                result += (diffs[i] - middle) * (times[i] + times[i - 1]) + times[i];
            }
        }
        if(result > limit){
            start = middle + 1;
        } else {
            answer = middle;
            end = middle;
        }
    }
}