
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
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll sum=0LL;
    vector<int> v;
    v.clear();
    map<int,int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    int cnt=0;
    // 偶数不需要判凸多边形成立条件，因为每条边都出现了偶数次。
    for (auto pr : mp) {
      if (pr.second & 1) {
        v.push_back(pr.first);
      }
      sum += (ll)pr.second/2LL*2LL*(ll)pr.first;
      cnt += pr.second/2*2;
    }
    sort(v.begin(), v.end());
    ll ans = 0LL;
    if (cnt > 2) ans = sum;
    for (int i = 0; i < v.size(); ++i) {
      int x= v[i];
      if (sum > x && cnt+1>2) {
        ans = max(ans, sum + x);
      }
      // 需要考虑到多出来的边有两条也就是类似梯形那种。
      if (i+1<v.size() && sum + v[i] > v[i+1] && cnt+2>2) {
        ans = max(ans, sum + v[i] + v[i+1]);
      }
    }
    printf("%lld\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
