#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 0;

    int s=1, e=0;

    for(int i : diffs)
        e=max(i, e);

    answer = e;

    while(s<e){
        int m=s+e>>1;
        long long res=0;
        for(int i=0; i<diffs.size(); i++){
            if(diffs[i] <= m){
                res+=times[i];
            }
            else{
                res+=(diffs[i]-m)*(times[i]+times[i-1])+times[i];
            }
        }
        if(res>limit)
            s =m+1;
        else{
            answer=m;
            e=m;
        }
    }

    return answer;
}