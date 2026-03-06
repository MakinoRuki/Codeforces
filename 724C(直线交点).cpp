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
#define N 1000005
#define M 1500
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const ll mod3 = 1000003;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int x[N];
int y[N];
ll ans[N];
map<int,set<pair<int,int>>> mp[2];
bool check(int cx, int cy) {
  if (cx == 0 && cy == 0) return true;
  if (cx == n && cy == 0) return true;
  if (cx == 0 && cy == m) return true;
  if (cx == n && cy == m) return true;
  return false;
}
pair<int,int> calc(int kk, int bb, int cx, int cy) {
  vector<pair<int,int>> v;
  v.clear();
  v.push_back(make_pair(0, kk*0+bb));
  v.push_back(make_pair(n, kk*n+bb));
  v.push_back(make_pair((0-bb)/kk, 0));
  v.push_back(make_pair((m-bb)/kk, m));
  for (auto pr : v) {
    if (pr.first >= 0 && pr.first <= n && pr.second >= 0 && pr.second <= m && (pr.first != cx || pr.second != cy)) {
      return pr;
    }
  }
}
void solve(int tp, int bb, int x1, int x2, int cx, ll tm) {
  auto itr = mp[tp][bb].lower_bound(make_pair(x1, -inf));
  while(itr != mp[tp][bb].end() && itr->first >= x1 && itr->first<= x2) {
    int id = itr->second;
    if (ans[id]<0) {
      ans[id] = tm + abs(itr->first-cx);
    }
    mp[tp][bb].erase(itr++);
  }
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d%d", &n, &m);

  // }
  cin>>n>>m>>k;
  mp[0].clear();
  mp[1].clear();
  for (int i = 1; i <= k; ++i) {
    ans[i] = -1;
    scanf("%d%d", &x[i], &y[i]);
    mp[0][x[i]+y[i]].insert(make_pair(x[i],i));
    mp[1][y[i]-x[i]].insert(make_pair(x[i],i));
  }
  ll tm=0LL;
  int cx=0,cy=0;
  int kk = 1, bb = 0;
  set<pair<pair<int,int>, pair<int,int>>> ss;
  ss.clear();
  ss.insert(make_pair(make_pair(1, 0), make_pair(0,0)));
 // int num=0;
  while(true) {
  //  cout<<"??"<<endl;
    auto nxt = calc(kk, bb, cx, cy);
   // num++;
  //  if (num <= 20) cout<<kk<<" "<<bb<<" "<<nxt.first<<" "<<nxt.second<<endl;
    if (ss.find(make_pair(make_pair(kk,bb),nxt)) != ss.end()) break;
    ss.insert(make_pair(make_pair(kk, bb), make_pair(nxt.first, nxt.second)));
    int x1 = min(cx, nxt.first);
    int x2 = max(cx, nxt.first);
    int y1 = min(cy, nxt.second);
    int y2 = max(cy, nxt.second);
    if (kk < 0) {
      solve(0, bb, x1, x2, cx, tm);
    } else {
      solve(1, bb, x1, x2, cx, tm);
    }
    cx = nxt.first;
    cy = nxt.second;
    tm += x2-x1;
    kk *= -1;
    if (kk > 0) bb = cy - cx;
    else bb = cy + cx;
    if (check(cx, cy)) break;
  }
  for (int i = 1; i <= k; ++i) {
    printf("%lld\n", ans[i]);
  }
  return 0;
}
 
