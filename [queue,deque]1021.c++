/*
https://www.acmicpc.net/problem/1021
*/
#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

/*
 
 push X: 정수 X를 큐에 넣는 연산이다.
 pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 큐에 들어있는 정수의 개수를 출력한다.
 empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
 front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.

 */

/*
 
 push_front X: 정수 X를 덱의 앞에 넣는다.
 push_back X: 정수 X를 덱의 뒤에 넣는다.
 pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 size: 덱에 들어있는 정수의 개수를 출력한다.
 empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
 front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
 
 */

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    deque<int> dq;
    int n, m, count;
    count = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        dq.push_back(i);
    }
    for(int i = 0; i < m; i++){
        int input;
        int index;
        index = 0;
        cin >> input;
        
        while(dq[index] != input){
            index++;
        }
//        cout << "dq " << i << endl;
//        for(int j = 0; j < dq.size(); j++){
//            cout << dq[j] << " ";
//        }
        if(dq.front() == input){
            dq.pop_front();
        }
        else{
//            int nth = 1;
            while(dq.front() != input){
                if(dq.size() / 2 >= index){
                    dq.push_back(dq.front());
                    dq.pop_front();
                    count++;
                }
                else{
                    dq.push_front(dq.back());
                    dq.pop_back();
                    count++;
                }
//                cout << endl;
//                cout << "[n'th: " << nth++ << "]"<< endl;
//                for(int j = 0; j < dq.size(); j++){
//                    cout << dq[j] << " ";
//                }
            }
            dq.pop_front();
        }
//        cout << endl << endl;
    }
    cout << count << endl;
}
