#include <iostream>
#include <string>
using namespace std;

string multi(string n1, char m) {
    string a;
    int n = 0;
    while(n1.length()) {
        n += ((m-'0')*(n1.back()-'0'));
        a.push_back(n%10+'0');
        n/=10;
        n1.pop_back();
    }
    if(n) a.push_back(n+'0');
    return {a.rbegin(), a.rend()};
}
string add (string s1, string s2) {
    string a;
    int carry{};
    while(s1.length() && s2.length()) {
        carry += (s1.back()-'0' + s2.back()-'0');
        a.push_back(carry % 10 + '0');
        carry /= 10;
        s1.pop_back(), s2.pop_back();
    }
    while(s1.length()) {
        carry += (s1.back()-'0');
        a.push_back(carry % 10 + '0');
        carry /= 10;
        s1.pop_back();
    }
    while(s2.length()) {
        carry += (s2.back()-'0');
        a.push_back(carry % 10 + '0');
        carry /= 10;
        s2.pop_back();
    }
    if(carry) a.push_back(carry + '0');
    return {a.rbegin(), a.rend()};
}
string multiply(string a, string b) {
    string ans;
    int len{};
    while(b.length()) {
        int m = len;
        string k = multi(a, b.back());
        while(m--) k.push_back('0');
        ans = add(ans, k);
        b.pop_back();
        len++;
    }
    return ans;
}

int main () {
    cout << multiply("123", "100");
}