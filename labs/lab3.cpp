#include <iostream>
#include <queue>
#include "lab3.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    SUP_Test *sTest[5] = {0};

    for(int i = 0; i < 5; i++) {
        SUP_Test *temp = (SUP_Test*) malloc(sizeof(SUP_Test));
        char buffer[256];
        char *userComment;
        int s1, s2, s3;
        cout << "Enter 3 n umbers: ";
        cin >> s1 >> s2 >> s3;
        cout << "Enter your comments: ";
        cin.ignore();
        cin.getline(buffer, sizeof(buffer));

        temp->S1_Test_Int1 = s1;
        temp->S2_Test_Int2 = s2;
        temp->S3_Test_Int3 = s3;
        temp->TestMessage = userComment;

        sTest[i] = temp;
    }

    for(int i = 0; i < 5; i++){
        SUP_Test *temp = sTest[i];
        cout << temp->S1_Test_Int1 << " " << temp->S2_Test_Int2 << " " << temp->S3_Test_Int3 << endl;
        cout << temp->TestMessage << endl << endl;

        free(temp->TestMessage);
        free(temp);
    }



    return 0;
}