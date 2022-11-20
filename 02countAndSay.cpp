#include <iostream>
using namespace std;
#include <vector>
#include <string>

// 1
// 11
// 21
// 1211

string speaknext(const string& str) {
    int m = str.length();
    string curr;
    int i{}, j{}, cnt{};
    while(i < m) {
        j = i + 1;
        cnt = 1;
        while(j < m) {
            if(str[j] != str[i]) break;
            cnt++, j++;
        }
        curr += (cnt+48);
        curr += str[i];
        i=j;
    }
    return curr;
}

string countSay(int n) {
    string s = "1";
    for(int i = 1; i < n; i++) {
        s = speaknext(s);
    }
    return s;
}

int main () {
    for(int i = 1; i < 200; i++)
    cout << countSay(i) << endl;

    return 0;
}