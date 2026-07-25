/**
 * std::greater<T> 설명
 * 두 값 x, y에 대해 x > y를 판단
 * 
 * std::greater<int>()(3, 1); // true
 * std::greater<int>()(2, 5); // false
 * 
 * 필요한 헤더 파일
 * algorithm, functional
 * 
 * 활용 방안
 * 1. sort 비교 함수
 *  - A: 배열 가정
 *  sort(A, A + N, greater<int>());
 * 
 * 2. priority_queue (우선순위 큐)
 *  - 최소 힙 만들기
 *  - 필요한 헤더 파일: queue
 *  priority_queue<int, vector<int>, greater<int>> min_heap;
 * 
 * 3. set/map의 정렬 기준 커스터마이징
 *  - 필요한 헤더 파일: set
 *  set <int, greater<int>> s; // 내림차순 정렬 set
 * 
 * 4. 사용자 정의 구조체에 greater 활용
 *  - 구조체, 연산자 오버로딩 사용
 * 
 */


#include <iostream>
#include <algorithm>
#include <functional>
#define endl '\n';
using namespace std;

typedef struct Person {
    int age;
} Person;

bool operator>(const Person &a, const Person &b){
    return a.age > b.age;
}

bool operator<(const Person &a, const Person &b){
    return a.age < b.age;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int A[50];
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    
    sort(A, A + N);
    
    for(int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
    cout << '\n';
    
    vector<Person> people = {{30}, {20}, {40}};
    sort(people.begin(), people.end(), greater<Person>());
    sort(people.begin(), people.end(), less<Person>());


    return 0;
}
