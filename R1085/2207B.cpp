
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
#define N 2000005
#define M 505
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
ll a[N];
ll b[N];
bool vis[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 1; i <= n; ++i) {
      scanf("%lld", &a[i]);
    }
    for (int i =1; i <= m; ++i) {
      vis[i]=false;
    }
    int sz = min(n+1, m);
    set<pair<int,int>> ss;
    ss.clear();
    int num=0;
    int cur=1;
    for (int i = 1; i <= h; ++i) {
      int sz = min(m, n-cur+2);
      if (ss.size() < sz) {
        ss.insert(make_pair(1, ++num));
      } else {
        auto pr = *ss.begin();
        ss.erase(pr);
        pr.first++;
        ss.insert(pr);
      }
      if (cur <= n && a[cur] == i) {
        auto pr = *ss.rbegin();
        ss.erase(pr);
        cur++;
      }
    }
    if (!ss.empty()) {
      printf("%d\n", (*ss.begin()).first);
    } else {
      puts("0");
    }
  }
  return 0;
}

