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
#define N 2000005
#define M 60
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
vector<string> mp;
map<ll, int> cnt;
int main() {
  mt19937_64 rnd((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    mp.clear();
    vector<ll> p;
    p.clear();
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      mp.push_back(s);
      p.push_back(rnd());
    }
    cnt.clear();
    ll ans=0LL;
    int ax=-1,ay=-1;
    for (int j = 0; j < m; ++j) {
      ll v = 0LL;
      for (int i = 0; i < n; ++i) {
        int bt = (mp[i][j]=='1');
        v += bt * p[i];
      }
      for (int i = 0; i < n; ++i) {
        int bt=(mp[i][j]=='1');
        v -= bt*p[i];
        v += (!bt)*p[i];
        cnt[v]++;
        if (cnt[v] > ans) {
          ans = cnt[v];
          ax=i,ay=j;
        }
        v -= (!bt)*p[i];
        v += bt*p[i];
      }
    }
    string anss=string(n, '0');
    if (ans > 0) {
      for (int i = 0; i < n; ++i) {
        anss[i] = mp[i][ay];
      }
      if (anss[ax] == '1') anss[ax] = '0';
      else anss[ax] = '1';
    }
    printf("%lld\n", ans);
    cout<<anss<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

