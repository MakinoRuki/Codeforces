#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 1005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int pre=0;
    int an=0, bn=0;
    int l=1, r = n;
    int c = 0;
    int cnt=0;
    while(l <= r) {
      int cur=0;
      cnt++;
      while(l <= r) {
        if (!c) {
          cur += a[l];
          l++;
          if (cur > pre) break;
        } else {
          cur += a[r];
          r--;
          if (cur > pre) break;
        }
      }
      if (!c) an += cur;
      else bn += cur;
      c = !c;
     // cout<<c<<" "<<pre<<" "<<cur<<endl;
      pre = cur;
    }
    cout<<cnt<<" "<<an<<" "<<bn<<endl;
  }
  return 0;
}
