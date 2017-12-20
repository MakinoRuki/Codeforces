#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n;
    vector<int> a;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin>>x;
        a.push_back(x);
    }
    for (int i = 0; i < n; ++i) {
        int x = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j] > a[i]) x = (x < 0 ? a[j] : min(a[j], x));
        }
        if (x < 0) {
            for (int j = 0; j < n; ++j) {
                x = (x < 0 ? a[j] : min(a[j], x));
            }
        }
        cout<<x;
        if (i < n - 1) cout<<" ";
        else cout<<endl;
    }
    return 0;
}
