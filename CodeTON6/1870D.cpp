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
#define N 600005
#define M 5002
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
ll dt[N];
ll ans[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      dt[i]=0;
    }
    scanf("%d", &k);
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      while(!v.empty() && a[i] <= a[v.back()]) {
        v.pop_back();
      }
      v.push_back(i);
    }
    // int sz=(int)v.size();
    // cout<<"sz="<<sz<<endl;
    ll pre=0;
    for (int i = 0;i < v.size(); ++i) {
      ll tmp = (i == 0 ? a[v[i]] : a[v[i]] - a[v[i-1]]);
      ll q = k / tmp;
      if (q == 0) break;
      if (i > 0) q = min(q, pre);
      dt[v[i]] += q;
    //  cout<<"i="<<i<<" "<<v[i]<<" "<<dt[v[i]]<<endl;
      k = k - tmp * q;
      pre = q;
    }
    ll cur=0LL;
    for (int i = n; i >= 1; --i) {
      cur = max(cur, dt[i]);
      ans[i] = cur;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld ",ans[i]);
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
