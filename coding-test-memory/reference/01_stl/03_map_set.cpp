#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
using namespace std;

void mapCrud() {
    cout << "[map]\n";

    // Create: key를 기준으로 정렬되며, 같은 key는 하나만 저장된다.
    map<string, int> score = {{"kim", 90}, {"lee", 80}};
    score.insert({"park", 70});       // 이미 있는 key면 삽입 실패
    score.emplace("choi", 60);        // 객체를 컨테이너 안에서 생성
    score["jung"] = 50;               // 없으면 생성, 있으면 값 변경

    // Read: 조회만 할 때 []를 쓰면 없는 key가 생성되므로 find/at을 사용한다.
    auto it = score.find("kim");
    if (it != score.end()) {
        cout << it->first << ' ' << it->second << '\n';
    }
    cout << boolalpha << (score.count("lee") > 0) << '\n';
    cout << score.at("park") << '\n'; // 없으면 out_of_range 예외

    // Update: 기존 key의 value는 바꿀 수 있다.
    score["kim"] = 95;
    score.at("lee") = 85;
    score.insert_or_assign("park", 75); // 없으면 삽입, 있으면 수정

    // Delete: erase(key)는 삭제된 원소 수(0 또는 1)를 반환한다.
    cout << "removed: " << score.erase("choi") << '\n';

    // map 순회 결과는 key의 오름차순이다.
    for (const auto& [name, value] : score) {
        cout << name << ' ' << value << '\n';
    }
}

void unorderedMapCrud() {
    cout << "[unordered_map]\n";

    // Create: 정렬하지 않는 대신 평균 O(1)에 삽입/조회/삭제한다.
    unordered_map<string, int> score;
    score.insert({"kim", 90});
    score.emplace("lee", 80);
    score["park"] = 70;

    // Read
    auto it = score.find("kim");
    if (it != score.end()) {
        cout << it->first << ' ' << it->second << '\n';
    }
    if (score.count("lee")) {
        cout << score.at("lee") << '\n';
    }

    // Update
    score["kim"] = 95;
    score.insert_or_assign("park", 75);

    // Delete
    score.erase("lee");

    // 순회 순서는 보장되지 않는다.
    for (const auto& [name, value] : score) {
        cout << name << ' ' << value << '\n';
    }
}

void setCrud() {
    cout << "[set]\n";

    // Create: 값 자체가 key이며, 중복 없이 정렬해서 저장한다.
    set<int> numbers = {3, 1, 3}; // 실제 저장: {1, 3}
    auto [it, inserted] = numbers.insert(2);
    cout << "inserted: " << boolalpha << inserted << ", value: " << *it << '\n';
    numbers.emplace(5);

    // Read: []가 없으므로 값으로 찾거나 반복자로 순회한다.
    auto found = numbers.find(3);
    if (found != numbers.end()) {
        cout << "found: " << *found << '\n';
    }
    cout << boolalpha << (numbers.count(10) > 0) << '\n';

    // Update: set의 원소는 key이므로 직접 수정할 수 없다.
    // 3을 4로 바꾸려면 3을 삭제한 뒤 4를 삽입한다.
    if (numbers.erase(3) > 0) {
        numbers.insert(4);
    }

    // Delete
    numbers.erase(1);             // 값으로 삭제
    auto eraseIt = numbers.find(5);
    if (eraseIt != numbers.end()) {
        numbers.erase(eraseIt);   // 반복자로 삭제
    }

    for (int value : numbers) {
        cout << value << ' ';     // 정렬된 순서
    }
    cout << '\n';
}

void unorderedSetCrud() {
    cout << "[unordered_set]\n";

    // Create: 중복 없이 저장하며 순서는 보장되지 않는다.
    unordered_set<int> numbers = {3, 1, 3};
    numbers.insert(2);
    numbers.emplace(5);

    // Read
    auto it = numbers.find(3);
    if (it != numbers.end()) {
        cout << "found: " << *it << '\n';
    }
    if (numbers.count(1)) {
        cout << "1 exists\n";
    }

    // Update: unordered_set도 원소를 직접 수정할 수 없다.
    if (numbers.erase(3) > 0) {
        numbers.insert(4);
    }

    // Delete
    cout << "removed: " << numbers.erase(1) << '\n';

    for (int value : numbers) {
        cout << value << ' ';     // 출력 순서는 실행 환경에 따라 달라질 수 있다.
    }
    cout << '\n';
}

int main() {
    mapCrud();
    unorderedMapCrud();
    setCrud();
    unorderedSetCrud();
}
