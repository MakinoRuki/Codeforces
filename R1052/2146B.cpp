
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
#define M 305
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
int cnt[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<vector<int>> ss;
    ss.clear();
    map<int,int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      int l;
      scanf("%d", &l);
      vector<int> v;
      v.clear();
      for (int j = 1; j <= l; ++j) {
        int x;
        scanf("%d", &x);
        v.push_back(x);
        mp[x]++;
      }
      ss.push_back(v);
    }
    int i;
    for (i =1; i <= m; ++i) {
      if (mp.find(i) == mp.end()) {
        break;
      }
    }
    if (i <= m) {
      puts("No");
      continue;
    }
    int cnt=0;
    for (auto v : ss) {
      bool ok = true;
      for (auto x : v) {
        if (mp[x] == 1) ok=false;
      }
      if (ok) cnt++;
    }
    if (cnt>=2) {
      puts("Yes");
    } else {
      puts("No");
    }
  }
  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
