#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 200005
using namespace std;
typedef long long ll;
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    cin>>n;
    for (int i = 0; i < n; ++i) {
      cin>>a[i];
    }
    int minv = a[0];
    int idx1 = 0;
    int x = -1, y = -1;
    int maxv = a[0];
    int idx2 = 0;
    for (int i = 0; i < n; ++i) {
      int cur = a[i] - i;
      if (cur > minv) {
        x = idx1;
        y = i;
        break;
      }
      if (cur < minv) {
        minv = cur;
        idx1 = i;
      }
      cur = a[i] + i;
      if (cur < maxv) {
        x = idx2;
        y = i;
        break;
      }
      if (cur > maxv) {
        maxv = cur;
        idx2 = i;
      }
    }
    if (x < 0) {
      cout<<"NO"<<endl;
    } else {
      cout<<"YES"<<endl;
      cout<<x+1<<" "<<y+1<<endl;
    }
  }
  return 0;
}
