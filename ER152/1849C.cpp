#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 300005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
string s;
int nxt[N][2];
int pre[N][2];
int main() {
  cin>>t;
  vector<pair<int,int>> v;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    v.clear();
    cin>>s;
    for (int i = 0; i <= n + 1; ++i) {
      nxt[i][0] = nxt[i][1] = -1;
      pre[i][0] = pre[i][1] = -1;
    }
    for (int i = n; i >= 0; --i) {
      if (i + 1 <= n) {
        nxt[i][0] = (s[i] == '0' ? i+1 : nxt[i+1][0]);
        nxt[i][1] = (s[i] == '1' ? i+1 : nxt[i+1][1]);
      }
    }
    for (int i = 1; i <= n+1; ++i) {
      if (i > 1) {
        pre[i][0] = (s[i-2] == '0' ? i-1 : pre[i-1][0]);
        pre[i][1] = (s[i-2] == '1' ? i-1 : pre[i-1][1]);
      }
    }
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= m; ++i) {
      int l, r;
      scanf("%d%d", &l, &r);
      int bg=-1, ed=-1;
      if (s[l-1] == '1') {
        int id = nxt[l][0];
        if (id < 0 || id > r) {
          ss.insert(make_pair(-1, -1));
          continue;
        }
      } else {
        int id = nxt[l][1];
        if (id < 0 || id > r) {
          ss.insert(make_pair(-1, -1));
          continue;
        }
        id = nxt[id][0];
        if (id < 0 || id > r) {
          ss.insert(make_pair(-1, -1));
          continue;
        }
      }
      bg = (s[l-1] == '0' ? nxt[l][1] : l);
      ed = (s[r-1] == '1' ? pre[r][0] : r);
      if (bg <= ed) {
    //  cout<<"i="<<i<<" "<<bg<<" "<<ed<<endl;
        ss.insert(make_pair(bg, ed));
      } else {
        ss.insert(make_pair(-1,-1));
      }
    }
    int sz = (int)ss.size();
    printf("%d\n", sz);
  }
  return 0;
}
