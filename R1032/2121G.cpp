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
#define N 1000005
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
int k;
int t;
int a[N];
int b[N];
string s;
int bit[N];
ll sum[N];
int dt;
int lowbit(int x) {
    return x&(-x);
}
void update1(int pos, int v) {
    while(pos <= 3*n+dt) {
        bit[pos] += v;
        pos += lowbit(pos);
    }
}
void update2(int pos, ll v) {
    while(pos <= 3*n+dt) {
        sum[pos] += v;
        pos += lowbit(pos);
    }
}
int query1(int pos) {
    int res=0;
    while(pos) {
        res += bit[pos];
        pos -= lowbit(pos);
    }
    return res;
}
ll query2(int pos) {
    ll res=0LL;
    while(pos) {
        res += sum[pos];
        pos -= lowbit(pos);
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    for (int i = 0; i <= 3*n+dt; ++i) {
        bit[i]=0;
        sum[i]=0;
    }
    ll ans=0LL;
    int ss=0;
    dt = n+2;
    update1(0+dt, 1);
    update2(dt, 0);
    for (int i = 1; i <= n; ++i) {
        ss += (s[i-1] - '0');
        int v = 2*ss-i;
        ll cnt=query1(v-1+dt);
        ll pv = query2(v-1+dt);
        ans += cnt*ss-pv;
        update1(v+dt, 1);
        update2(v+dt, ss);
    }
  //  cout<<"ans="<<ans<<endl;
    for (int i = 0; i<=3*n+dt; ++i) {
        bit[i]=0;
        sum[i]=0;
    }
    for (int i = 0; i < n; ++i) {
        s[i] = (1-(s[i]-'0'))+'0';
    }
    ss = 0;
    update1(dt, 1);
    update2(dt, 0);
    for (int i = 1; i <= n; ++i) {
        ss += (s[i-1] - '0');
        int v = 2*ss-i;
        ll cnt = query1(v+dt);
        ll pv = query2(v+dt);
        ans += cnt*ss-pv;
        update1(v+dt, 1);
        update2(v+dt, ss);
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
