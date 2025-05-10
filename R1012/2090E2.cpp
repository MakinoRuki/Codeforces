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
#define M 1002
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
ll k;
int t;
ll a[N];
ll b[N];
ll sum[N];
int idx;
bool check(int x) {
  deque<int> dq;
  ll res=0LL;
  for (int i = idx; i >= idx-n; --i) {
    while(!dq.empty() && dq.front()-i>x) {
      dq.pop_front();
    }
    if (i < idx) {
      // 对每个a[i]来说，调整之后的delta会跟着它旋转因此只影响它自己的结果。
      // 也可以想，如果a[i]需要调整那么它在到达目标位置之前一路把b减为0，对其他旋转过来的位置不会有影响；
      // 如果a[i]不需要调整那么就也肯定不会对其他位置有影响。
      res += max(0LL, sum[dq.front()]-sum[i]);
    }
    if (res > k) return false;
    while(!dq.empty() && sum[i] <= sum[dq.back()]) {
      dq.pop_back();
    }
    dq.push_back(i);
  }
  return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%lld", &n, &k);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
      tot += a[i];
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &b[i]);
    }
    if (tot <= k) {
      puts("0");
      continue;
    }
    sum[0]=0LL;
    for (int i = 1; i <= n; ++i) {
      sum[i] = sum[i-1]+a[i]-b[i];
    }
    for (int i = n+1; i <= 2*n; ++i) {
      sum[i] = sum[i-1] + a[i-n]-b[i-n];
    }
    idx = n;
    for (int i = n+1; i <= 2*n; ++i) {
      if (sum[i] < sum[idx]) {
        idx = i;
      }
    }
    int l = 1, r = n;
    while(l < r) {
      int mid=(l+r)/2;
    //  cout<<"lr="<<l<<" "<<r<<" "<<mid<<endl;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid+1;
      }
    }
    printf("%d\n", r);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
