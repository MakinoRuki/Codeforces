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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
ll k;
int t;
int a[N];
int cnt[N];
string s;
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%lld", &n, &k);
    cin>>s;
    sum[n] = 0;
    for (int i = n-1; i >= 0; --i) {
      if (s[i] == '1') sum[i]=sum[i+1]+1;
      else sum[i] = sum[i+1]-1;
    }
    vector<int> rk;
    rk.clear();
    for (int i = 1; i < n; ++i) {
      rk.push_back(sum[i]);
    }
    sort(rk.begin(), rk.end());
    ll tot = 0LL;
    reverse(rk.begin(), rk.end());
    int cur=1;
    for (int i = 0; i < rk.size(); ++i) {
      if (tot >= k) break;
      tot += rk[i];
      cur++;
    }
    if (tot < k) puts("-1");
    else printf("%d\n", cur);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

