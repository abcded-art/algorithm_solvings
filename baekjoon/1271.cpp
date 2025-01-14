#include <iostream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  long m, n;
  cin >> m >> n;
  cout << m / n << endl;
  cout << m % n << endl;
  return 0;
}