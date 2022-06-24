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
#define N 250
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int p[N];
bool vis[N];
ll getgcd(ll x, ll y) {
  return y==0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i = 1; i <= n; ++i) {
      a[i] = s[i-1]-'a';
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      vis[i] = false;
    }
    ll res=1LL;
    for (int i = 1; i <=n; ++i) {
      if (!vis[i]) {
        vector<int> ids;
        ids.clear();
        int cur= i;
        while(!vis[cur]) {
          ids.push_back(cur);
          vis[cur]=true;
          cur =p[cur];
        }
        int sz = (int)ids.size();
        if (sz == 1) continue;
        int d;
     //   cout<<"i="<<i<<endl;
        // for (int j = 0; j < ids.size(); ++j) {
        //   cout<<"jj="<<j<<" "<<ids[j]<<endl;
        // }
        for (d = 1; d <= sz; ++d) {
          int c = a[ids[0]];
          for (int j = 0; j < ids.size()-1; ++j) {
            a[ids[j]] = a[p[ids[j]]];
          }
          a[ids.back()] = c;
          int j;
        //  cout<<"d="<<d<<endl;
          for (j = 0; j < ids.size(); ++j) {
           // cout<<"j="<<j<<" "<<a[ids[j]]<<endl;
            if (a[ids[j]] != s[ids[j]-1]-'a') {
              break;
            }
          }
          if (j >= ids.size()) {
            break;
          }
        }
        ll g = getgcd(res, d);
        res = res/g*d;
      }
    }
    printf("%lld\n", res);
  }
  return 0;
}
