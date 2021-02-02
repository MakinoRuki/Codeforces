#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, q;
ll x[N], y[N];
bool vis[N];
ll getdis(int i, int j) {
  return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}
bool check(int i, int j, int k) {
  ll a = x[i]-x[j];
  ll b = y[i]-y[j];
  ll c = x[k]-x[j];
  ll d = y[k]-y[j];
  return (a*c+b*d)>0;
}
int main() {
  cin>>n;
  memset(vis, false, sizeof(vis));
  for (int i= 1; i <= n; ++i) {
    scanf("%lld%lld", &x[i], &y[i]);
  }
  bool ok = true;
  vis[1] = true;
  vector<int> ans;
  ans.clear();
  ans.push_back(1);
  int cur = 1;
  int pre=-1;
  for (int i = 1; i < n; ++i) {
    int j;
    ll dis=0;
    int id=-1;
    for (j = 1; j <= n; ++j) {
      if (!vis[j]) {
        ll dis2 = getdis(cur, j);
        if (dis2>dis) {
          dis=dis2;
          id = j;
        }
      }
    }
  //  cout<<i<<" "<<id<<endl;
    if (pre>=1) {
      if (check(pre, cur, id)) {
        ans.push_back(id);
        vis[id]=true;
        pre=cur;
        cur=id;
      } else {
        ok=false;
        break;
      }
    } else {
      ans.push_back(id);
      vis[id]=true;
      pre=cur;
      cur=id;
    }
  }
 // cout<<"v="<<check(1,2,4)<<endl;
  if (!ok) {
    cout<<-1<<endl;
  } else {
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i<ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
