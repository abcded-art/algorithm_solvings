#include <iostream>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
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
    
    int testCase;
    cin >> testCase;
    
    for(auto i = 0 ; i < testCase; i++){
        deque<int> dq;
        string inputFunction;
        cin >> inputFunction;
        int countR = 0;
        int countD = 0;
        for(auto t : inputFunction){
            if(t == 'R'){
                countR++;
            }
            else{
                countD++;
            }
        }
        int inputNumber;
        cin >> inputNumber;
        
        string inputNumString;
        cin >> inputNumString;
        
//        cout << "inputNumString Before: " << inputNumString << endl;
        inputNumString = inputNumString.substr(1, inputNumString.length() - 2);
//        cout << "inputNumString After: " << inputNumString << endl;
        
        if(inputNumber < countD){
            cout << "error" << endl;
            continue;
        }
        
        stringstream ss(inputNumString);
        string token;
        
        while(getline(ss, token, ',')){
            dq.push_back(stoi(token));
        }
        
        bool isOdd = false;
        
        for(int j = 0; j < inputFunction.size(); j++){
            if(inputFunction[j] == 'R'){
                if(isOdd) isOdd = false;
                else isOdd = true;
            }
            else{
                if(isOdd){
                    dq.pop_back();
                }
                else{
                    dq.pop_front();
                }
            }
        }
        
        if(isOdd){
            cout << "[";
            for(int j = 0; j < dq.size(); j++){
                if(j != dq.size() - 1){
                    cout << dq[dq.size() - 1 - j] << ",";
                }
                else{
                    cout << dq[0];
                }
            }
            cout << "]" << endl;
        }
        else{
            cout << "[";
            for(int j = 0; j < dq.size(); j++){
                if(j != dq.size() - 1){
                    cout << dq[j] << ",";
                }
                else{
                    cout << dq[j];
                }
            }
            cout << "]" << endl;
        }
        
    }
}
