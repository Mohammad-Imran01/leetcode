#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void nexPerm(vector<int>& arr) {
    int n = arr.size(), l, k;

    for (k = n-2; k >= 0; k--)
        if(arr[k] < arr[k+1]) break;
    if(k < 0) reverse(arr.begin(), arr.end());
    else {
        for(l = n-1; l > k; l--)
            if (arr[k] <  arr[l])
                break;
        swap(arr[k], arr[l]);
        reverse(arr.begin()+1+k, arr.end());
    }
}
// 1 2 3
void print(const vector<int>& arr) {
    for(auto a: arr) cout << a;
    cout << endl;
}

int main () {
    
    vector <int> arr {1,2,3};
    int k {}, l {}, n=arr.size();

    for(int k = n-2; k >= 0; k--) 
        if(arr[k] < arr[k+1])
            break;

    if(k < 0) reverse(arr.begin(), arr.end());
    else {
        for(int l = n-1; l > k; l--)
            if(arr[l] > arr[k])
                break;
        swap(arr[k], arr[l]);
        reverse(arr.begin()+1+k, arr.end());
    }

    print(arr);

    cout << "\n_________________________________________";
    return 0;
}