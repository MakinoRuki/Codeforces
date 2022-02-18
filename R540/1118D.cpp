#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>n>>m;
  for (int i =1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  int x = 1, y = n;
  while(x < y) {
    swap(a[x], a[y]);
    x++;
    y--;
  }
  ll l = 1, r = m;
  while(l < r) {
    ll mid = (l+r)/2;
  //  cout<<l<<" "<<r<<" "<<mid<<endl;
    ll tot=0LL;
    int det = 0;
    for (int i = 1; i <= n; ++i) {
      tot += max(a[i]-det, 0);
      if (i % mid  ==0) {
        det++;
      }
     // cout<<"tot="<<tot<<endl;
    }
    if (tot >= m) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  ll tot=0LL;
  int det=0;
  for (int i = 1; i <= n; ++i) {
    tot += max(a[i]-det, 0);
    if (i %r  ==0) {
      det++;
    }
  }
  if (tot >= m) {
    printf("%lld\n", r);
  } else {
    puts("-1");
  }
  return 0;
}
