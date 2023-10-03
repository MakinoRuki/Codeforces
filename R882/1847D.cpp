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
#define N 500002
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
string s;
vector<pair<int,int>> sg;
int pr[N];
int bit[N];
int lowbit(int x) {
  return x&(-x);
}
void update(int pos, int val) {
  while(pos <= n) {
    bit[pos] += val;
    pos += lowbit(pos);
  }
}
int query(int pos) {
  int cnt=0;
  while(pos) {
    cnt += bit[pos];
    pos -= lowbit(pos);
  }
  return cnt;
}
int main() {
  cin>>n>>m>>q;
  cin>>s;
  sg.clear();
  for (int i =1; i <= m; ++i) {
    int l,r;
    scanf("%d%d", &l, &r);
    sg.push_back(make_pair(l, r));
  }
  vector<pair<pair<int,int>,int>> rk;
  rk.clear();
  for (int i = 0; i < sg.size(); ++i) {
    int l = sg[i].first;
    int r = sg[i].second;
    rk.push_back(make_pair(make_pair(l, 0), i));
    rk.push_back(make_pair(make_pair(r, 1), i));
  }
  sort(rk.begin(), rk.end());
  int id = 0;
  set<int> ss;
  ss.clear();
  vector<pair<int,int>> vv;
  vv.clear();
  for (int i = 1; i <= n; ++i) {
    while(id < rk.size() && (rk[id].first.first == i) && (rk[id].first.second == 0)) {
      ss.insert(rk[id].second);
      id++;
    }
    pr[i] = n+1;
    if (!ss.empty()) {
      vv.push_back(make_pair((*ss.begin()), i));
    }
    while(id < rk.size() && (rk[id].first.first == i) && (rk[id].first.second == 1)) {
      ss.erase(rk[id].second);
      id++;
    }
  }
  sort(vv.begin(), vv.end());
  for (int i = 0; i < vv.size(); ++i) {
    pr[vv[i].second] = i+1;
  }
  for (int i = 0; i <= n; ++i) {
    bit[i] = 0;
  }
  int tot=0;
  int tot2=0;
  for (int i = 1; i <= n; ++i) {
    if (s[i-1] == '1') {
      tot++;
      if (pr[i] <= n) {
        update(pr[i], 1);
      }
    }
    if (pr[i] <= n) {
      tot2++;
    }
  }
  // for (int i = 1; i <= n; ++i) {
  //   cout<<"i="<<i<<" "<<pr[i]<<" "<<query(i)<<endl;
  // }
  while(q-->0) {
    int x;
    scanf("%d", &x);
    if (s[x-1] == '1') {
      tot--;
      if (pr[x] <= n) {
        update(pr[x], -1);
      }
      s[x-1] = '0';
    } else {
      tot++;
      if (pr[x] <= n) {
        update(pr[x], 1);
      }
      s[x-1] = '1';
    }
   // if (x == 5) cout<<"v="<<tot<<" "<<tot2<<" "<<query(min(tot, tot2))<<endl;
    printf("%d\n", min(tot,tot2) - query(min(tot,tot2)));
  }
  return 0;
}
