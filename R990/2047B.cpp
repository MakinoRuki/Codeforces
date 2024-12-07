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
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[N];
ll fac[20];
int cnt[28];
ll calc(string& s) {
    for (int i = 0; i < 26; ++i) {
        cnt[i]=0;
    }
    for (int i = 0; i < s.size(); ++i) {
        cnt[s[i]-'a']++;
    }
    ll res=fac[n];
    for (int i = 0; i < 26; ++i) {
        res /= fac[cnt[i]];
    }
    return res;
}
int main() {
  fac[0]=1LL;
  for (int i = 1; i <= 10; ++i) {
      fac[i] = fac[i-1] * i;
  }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    ll ans = fac[n];
    string res=s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c = s[i];
            s[i] = s[j];
            ll v = calc(s);
            if (v < ans) {
                ans=v;
                res=s;
            }
            s[i] = c;
        }
    }
    cout<<res<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

