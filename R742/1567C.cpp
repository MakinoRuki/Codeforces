#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
ll pw[M];
ll calc(int x, int b) {
  if (b == 1 && x != 9) return 0LL;
  if (x == 9 && b != 1) return 0LL;
  if (x == 9) {
    if (b == 0 || b == 2) return 0LL;
    return 10LL;
  }
  if (b == 0) {
    return x+1;
  } else {
    return 9-x;
  }
}
int main() {
  pw[0] = 1;
  for (int i = 1; i <= 10; ++i) {
    pw[i] = pw[i-1] * 3;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int cnt=0;
    int m = n;
    while(m) {
      cnt++;
      m/=10;
    }
    cnt=min(cnt, 9);
    vector<int> ds;
    ds.clear();
    m = n;
    while(m) {
      ds.push_back(m%10);
      m/=10;
    }
    ll ans = 0LL;
    for (int i = 0; i < pw[cnt]; ++i) {
      int bt[M];
      for (int j = 0; j <= 10; ++j) {
        bt[j] = 0;
      }
      int add[M];
      for (int j = 0; j <= 10; ++j) {
        add[j] = 0;
      }
      int x = i;
      int now =0;
      while(x) {
        bt[now] = x%3;
        x/=3;
        now++;
      }
      bool ok = true;
      int tot = n;
      for (int j = 0; j <= 9; ++j) {
        if (bt[j] == 2 || (bt[j] == 1 && add[j])) {
          if (j+2 >= ds.size()) {
            ok=false;
            break;
          }
          add[j+2]++;
        }
      }
      if (!ok) continue;
      ll tmp = 1LL;
      for (int j = 0; j < ds.size(); ++j) {
        int x = ds[j];
        if (add[j]) x = (x-1+10)%10;
        tmp *= calc(x, bt[j]);
      }
    //  cout<<"x="<<endl;
      // for (int j = 0; j < ds.size(); ++j) {
      //   cout<<j<<" "<<bt[j]<<endl;
      // }
     // cout<<"v="<<tmp<<endl;
      ans += tmp;
    }
    ans -= 2;
    printf("%lld\n", ans);
  }
  return 0;
}
