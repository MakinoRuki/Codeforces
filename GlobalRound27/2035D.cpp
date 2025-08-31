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
ll cnt[N];
ll ans[N];
ll calc(ll z, ll y) {
    ll res=1LL;
    ll x = 2LL;
    while(y) {
        if (y&1) res=res*x%mod;
        x=x*x%mod;
        y/=2;
    }
    res = res * z % mod;
    return res;
}
ll check(ll x, ll y) {
    for (int i = 1; i <= y; ++i) {
        if (x * 2LL > 1000000000) {
            return 2000000000LL;
        }
        x *= 2LL;
    }
    return x;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        cnt[i]=0;
        while((a[i]%2)==0) {
            cnt[i]++;
            a[i]/=2;
        }
    }
    vector<int> v;
    v.clear();
    ll sum=0LL;
    for (int i = 1; i <= n; ++i) {
        ll dt=0;
     //   cout<<"i="<<i<<endl;
        while(!v.empty() && check(a[i], cnt[i])>a[v.back()]) {
            int id=v.back();
            sum = (sum - calc(a[id], cnt[id]) + mod) % mod;
            sum = (sum + a[id]) % mod;
            v.pop_back();
            cnt[i] += cnt[id];
           // cout<<"id="<<id<<" "<<dt<<" "<<sum<<endl;
        }
        v.push_back(i);
        sum = (sum + calc(a[i], cnt[i])) % mod;
        ans[i] = sum;
    }
    for (int i = 1; i <= n; ++i) {
        printf("%lld ", ans[i]);
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
