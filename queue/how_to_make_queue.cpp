#include <cstdio>
#include <queue>
#include <string>
using namespace std;

int main() {
    int n, num;
    scanf("%d", &n);
    queue<int> q;
    char input[10];
    for(int i = 0; i < n; i++){
        scanf("%s", input);
        string command = string(input);
        if(command == "push"){
            scanf("%d", &num);
            q.push(num);
        }
        else if(command == "pop"){
            if(q.empty()){
                printf("%d\n", -1);
                continue;
            }
            printf("%d\n", q.front());
            q.pop();
        }
        else if(command == "size"){
            printf("%lu\n", q.size());
        }
        else if(command == "empty"){
            printf("%d\n", q.empty() ? 1 : 0);
        }
        else if(command == "front"){
            if(q.empty()){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", q.front());
            }
        }
        else if(command == "back"){
            if(q.empty()){
                printf("%d\n", -1);
            }
            else{
                printf("%d\n", q.back());
            }
        }
        else{
            printf("Error Occured!\n");
        }
    }
    return 0;
}
