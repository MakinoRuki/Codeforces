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
#define N 200005
#define M 42
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int c[N];
int a,b;
int xa[N], xb[N];
int cnt[N];
ll sum[4][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  memset(cnt, 0, sizeof(cnt));
  memset(sum, 0LL, sizeof(sum));
  cin>>n>>m>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &c[i]);
  }
  cin>>a;
  for (int i = 1; i <= a; ++i) {
    scanf("%d", &xa[i]);
    cnt[xa[i]] += 1;
  }
  cin>>b;
  for (int i = 1; i <= b; ++i) {
    scanf("%d", &xb[i]);
    cnt[xb[i]] += 2;
  }
  vector<pair<int,int>> rk[4];
  for (int i = 1; i <= n; ++i) {
    rk[cnt[i]].push_back(make_pair(c[i], i));
  }
  for (int i = 0; i < 4; ++i) {
    sort(rk[i].begin(), rk[i].end());
    for (int j = 0; j < rk[i].size(); ++j) {
      sum[i][j] = (j == 0 ? rk[i][j].first : sum[i][j-1] + rk[i][j].first);
    }
  }
  set<pair<int,int>> s1, s2;
  s1.clear();
  s2.clear();
  for (int i = 0; i < rk[0].size(); ++i) {
    s2.insert(rk[0][i]);
  }
  for (int i = k; i < rk[1].size(); ++i) {
    s2.insert(rk[1][i]);
  }
  for (int i = k; i < rk[2].size(); ++i) {
    s2.insert(rk[2][i]);
  }
  int j1 = min((int)rk[1].size()-1, k-1);
  int j2 = min((int)rk[2].size()-1, k-1);
  ll ans = -1;
  ll tot=0LL;
  if (j1 + 1 >= k && j2 + 1 >= k && m-2*k>=0) {
    int dt = m-2*k;
    while(!s2.empty() && s1.size() < dt) {
      tot += (*s2.begin()).first;
      s1.insert(*s2.begin());
      s2.erase(s2.begin());
    }
    if (s1.size() == dt) {
      ll tmp = tot;
      if (j1 >= 0) tmp += sum[1][j1];
      if (j2 >= 0) tmp += sum[2][j2];
      ans = tmp;
    }
  }
  for (int i = 0; i < min(m, (int)rk[3].size()); ++i) {
    while(j1 >= 0 && j1 + 1 > k-(i+1)) {
      if (s1.empty() || rk[1][j1].first > (*s1.rbegin()).first) {
        s2.insert(rk[1][j1]);
      } else {
        s1.insert(rk[1][j1]);
        tot += rk[1][j1].first;
      }
      j1--;
    }
    while(j2 >= 0 && j2 + 1 > k-(i+1)) {
      if (s1.empty() || rk[2][j2].first > (*s1.rbegin()).first) {
        s2.insert(rk[2][j2]);
      } else {
        s1.insert(rk[2][j2]);
        tot += rk[2][j2].first;
      }
      j2--;
    }
    if (i+1+j1+1 >= k && i+1+j2+1>=k && m>=i+1+j1+1+j2+1) {
      int dt = m-(i+1)-(j1+1)-(j2+1);
      while(s1.size() > dt) {
        tot -= (*s1.rbegin()).first;
        s2.insert(*s1.rbegin());
        s1.erase(--s1.end());
      }
      while(!s2.empty() && s1.size() < dt) {
        tot += (*s2.begin()).first;
        s1.insert(*s2.begin());
        s2.erase(s2.begin());
      }
      if (s1.size() == dt) {
        ll tmp = sum[3][i] + tot;
        if (j1 >= 0) tmp += sum[1][j1];
        if (j2 >= 0) tmp += sum[2][j2];
      //  if (tmp == 52086) cout<<"v="<<i<<" "<<j1<<" "<<j2<<" "<<dt<<endl;
        ans = (ans < 0 ? tmp : min(ans, tmp));
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
