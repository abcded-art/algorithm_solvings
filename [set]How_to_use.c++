#include <vector>
#include <iostream>
#include <set>
#define endl '\n'
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> s;
    multiset<int> ms;
    
    /* Set 기본 사용 */
    s.insert(3); s.insert(1); s.insert(2); s.insert(3);
    for(auto i : s) cout << i << ' ';
    
    cout << endl;
    
    /* Multiset 기본 사용 */
    ms.insert(3); ms.insert(1); ms.insert(2); ms.insert(3);
    for(auto i : ms) cout << i << ' ';
    cout << endl;
    
    /* Set 내림차순 */
    vector<int> v(s.begin(), s.end());
    sort(v.begin(), v.end(), greater<int>());
    for(auto i : v) cout << i << ' ';
    cout << endl;
    
    set<int, greater<int>> s2;
    s2.insert(3); s2.insert(1); s2.insert(2);
    for(auto i : s2) cout << i << ' ';
    cout << endl;
    
    /* 원소 찾기 및 삭제 */
    if(s.find(2) != s.end())
        s.erase(2);
    for(auto i : s) cout << i << ' ';
    cout << endl;
    
    /* 구조체 정렬 */
    struct INFO{
        int age;
        string name;
    } info[3];
    struct compare{
        bool operator() (INFO* a, INFO* b) const{
            return a -> age < b -> age;
        }
    };
    set<INFO*, compare> sStruct;
    info[0] = {31, "Ben"};
    info[1] = {27, "Sally"};
    info[2] = {25, "Ariana"};
    sStruct.insert(&info[0]);
    sStruct.insert(&info[1]);
    sStruct.insert(&info[2]);
    for(auto i : sStruct) cout << i -> name << ' ' << i -> age << endl;
}

