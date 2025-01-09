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
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    map<int, ll> cnt;
    cnt.clear();
    cnt[0]++;
    int n1=0,n0=0;
    n = (int)s.size();
    ll ans=0LL;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') n1++;
        else n0++;
        int dt = n1-n0;
        if (cnt.find(dt) != cnt.end()) {
            //cout<<"i="<<i<<" "<<dt<<" "<<cnt[dt]<<endl;
            ans = (ans + cnt[dt]*(ll)(n-i)%mod) % mod;
        }
        cnt[dt] = (cnt[dt]+i+2)%mod;
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

