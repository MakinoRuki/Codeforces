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
#define N 3000005
#define M 750
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
int sum[2][N];
int bit[N];
int lowbit(int x) {
    return x&(-x);
}
void update(int x, int v) {
    while(x <= 7*n) {
        bit[x] += v;
        x += lowbit(x);
    }
}
int query(int x) {
    if (x < 0) return 0;
    int res=0;
    while(x) {
        res += bit[x];
        x -= lowbit(x);
    }
    return res;
}
int main() {
  cin>>n;
  string s;
  cin>>s;
  memset(sum, 0, sizeof(sum));
  memset(bit, 0, sizeof(bit));
  for (int i = 1; i <= n; ++i) {
    sum[0][i]=sum[0][i-1];
    sum[1][i]=sum[1][i-1];
    if (s[i-1]=='1') {
        sum[1][i]++;
    } else {
        sum[0][i]++;
    }
  }
  ll ans=0LL;
  update(5*n, 1);
  for (int i = 1; i <= n; ++i) {
    int cur = sum[0][i]-3*sum[1][i]+5*n;
   // if (i==2) cout<<"cur="<<cur<<endl;
    int r1 = query(cur-2);
   // if (i==2) cout<<"r1="<<r1<<endl;
    int r2 = query(cur+1)-query(cur);
    ans += r1 + r2;
  //  cout<<"i="<<i<<" "<<r1<<" "<<r2<<" "<<ans<<endl;
    update(cur, 1);
  }
  printf("%lld\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
