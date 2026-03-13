
#include <iostream>
#include <sstream>
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
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int p[N];
int idx[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
      idx[p[i]] = i;
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int cur=0;
    int l=0,r=0;
    bool ok=true;
    vector<int> rk2;
    vector<pair<int,int>> rk1;
    rk1.clear();
    rk2.clear();
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      if (i > 1 && a[i] != a[i-1]) {
        rk2.push_back(cur);
       // cout<<"cur="<<cur<<endl;
        ss.insert(cur);
        cur=a[i];
        l=i;
        r=i;
      } else {
        cur = a[i];
        r = i;
        if (l<=0) l = i;
      }
    }
    rk2.push_back(cur);
    ss.insert(cur);
   // cout<<"cur="<<cur<<endl;
    for (auto x : ss) {
      rk1.push_back(make_pair(idx[x], x));
    }
    sort(rk1.begin(), rk1.end());
    if ((int)rk1.size() != (int)rk2.size()) {
      ok=false;
    } else {
      for (int i = 0; i < rk1.size(); ++i) {
        if (rk1[i].second != rk2[i]) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  return 0;
}

