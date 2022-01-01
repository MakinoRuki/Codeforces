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
#define N 20000
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
int x[N];
int p[N];
vector<string> ss;
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &x[i]);
    }
    ss.clear();
    for (int i= 1; i <= n; ++i) {
      string s;
      cin>>s;
      ss.push_back(s);
    }
    for (int i = 0; i <= m; ++i) {
      cnt[i] = 0;
    }
    int ans = INT_MIN;
    for (int i = 0; i < (1<<n); ++i) {
      int tot=0;
      for (int j = 0; j < m; ++j) {
        cnt[j] = 0;
      }
      for (int j = 0; j < n; ++j) {
        for (int j2 = 0; j2 < m; ++j2) {
          if (ss[j][j2] == '1') {
            if ((1<<j) & i) {
              cnt[j2]++;
            } else {
              cnt[j2]--;
            }
          }
        }
        if ((1<<j)&i) tot -= x[j+1];
        else tot += x[j+1];
      }
      vector<pair<int,int>> rk1, rk2;
      rk1.clear();
      rk2.clear();
      for (int j = 0; j < m; ++j) {
        if (cnt[j] >= 0) rk1.push_back(make_pair(cnt[j], j));
        else rk2.push_back(make_pair(cnt[j], j));
      }
      sort(rk1.begin(), rk1.end());
      sort(rk2.begin(), rk2.end());
      reverse(rk1.begin(), rk1.end());
     // if (i == 6) cout<<"tot="<<tot<<endl;
      for (int j = 0; j < rk1.size(); ++j) {
        tot += (m-j) * rk1[j].first;
      }
      for (int j = 0; j <rk2.size(); ++j) {
        tot += (j+1) * rk2[j].first;
      }
      if (tot > ans) {
        ans = tot;
        for (int j = 0; j < rk1.size(); ++j) {
          p[rk1[j].second] = m-j;
        }
        for (int j = 0; j < rk2.size(); ++j) {
          p[rk2[j].second] = j+1;
        }
      }
    }
    for (int i = 0; i < m; ++i) {
      printf("%d", p[i]);
      if (i < m-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
