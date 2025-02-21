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
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
bool check(ll x, int b) {
  for (int i = 0; i < b-1; ++i) {
    x/=10;
  }
  if ((x%10)==7) return true;
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ds;
    ds.clear();
    bool found=false;
    while(n) {
      ds.push_back(n%10);
      if ((n%10)==7) found=true;
      n/=10;
    }
    if (found) {
      puts("0");
      continue;
    }
    ds.push_back(0);
    reverse(ds.begin(), ds.end());
    int ans=inf;
    for (int i = 0; i < ds.size()-1; ++i) {
      ll cur = ds[i];
      ll dt = 0;
      ll dt2=0;
      // if (cur > 7) {
      //   ans = min(ans, ds[i]-7);
      // } else {
      //   ans = min(ans, ds[i]+3);
      // }
      for (int j = i+1; j < ds.size(); ++j) {
        cur = cur * 10 + ds[j];
        dt = dt * 10 + 9;
      }
      dt2=dt;
      dt2=dt2*10+9;
      for (int c1 = 0; c1 <= 8; ++c1) {
        for (int c2=0;c2 <= 8; ++c2) {
          if (check(cur + c1 * dt + c2 * dt2, (int)ds.size()-1-i+1)) {
            ans = min(ans, c1+c2);
          }
        }
      }
      // int cnt=0;
      // while(true) {
      //   int dd = check(cur);
      //   if (dd == 7) break;
      //   cur += dt;
      //   cnt++;
      //   if (dd > 7) {
      //     ans = min(ans, cnt + dd-7);
      //   } else {
      //     ans = min(ans, cnt + dd+3);
      //   }
      // }
      //ans = min(ans, cnt);
      //cout<<"i="<<i<<" "<<ans<<endl;
    }
    int cur = ds.back();
    int cnt=0;
    while((cur%10) != 7) {
      cur += 9;
      cnt++;
    }
    ans = min(ans, cnt);
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
