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
#define M 3000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int d, c;
int b[N], p[N];
int tp[N];
int v[2][N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
    
  // }
  cin>>n>>c>>d;
  vector<pair<int,int>> rk1;
  vector<pair<int,int>> rk2;
  rk1.clear();
  rk2.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &b[i], &p[i]);
    string s;
    cin>>s;
    if (s[0] == 'C') tp[i] = 0;
    else tp[i] = 1;
    if (tp[i] == 0) {
      rk1.push_back(make_pair(p[i], b[i]));
    } else {
      rk2.push_back(make_pair(p[i], b[i]));
    }
  }
  sort(rk1.begin(), rk1.end());
  sort(rk2.begin(), rk2.end());
  for (int i = 0; i < rk1.size(); ++i) {
    v[0][i] = (i == 0 ? rk1[i].second : max(rk1[i].second, v[0][i-1]));
  }
  for (int i = 0; i < rk2.size(); ++i) {
    v[1][i] = (i == 0 ? rk2[i].second : max(rk2[i].second, v[1][i-1]));
  }
  int ans = 0;
  if (!rk1.empty() && !rk2.empty()) {
    int res=0;
    int cnt=0;
    for (int i = rk1.size()-1; i >= 0; --i) {
      if (rk1[i].first <= c) {
        res += v[0][i];
        cnt++;
       // cout<<"i="<<rk1[i].first<<" "<<v[0][i]<<endl;
        break;
      }
    }
    for (int i = rk2.size()-1; i >= 0; --i) {
      if (rk2[i].first <= d) {
        res += v[1][i];
        cnt++;
       // cout<<"i2="<<rk2[i].first<<" "<<v[1][i]<<endl;
        break;
      }
    }
    if (cnt == 2) ans=max(ans, res);
  }
  int j = 0;
  for (int i = rk1.size()-1; i >= 0; --i) {
    while(j < i && rk1[j].first <= c-rk1[i].first) {
      j++;
    }
    if (j >= i) {
      if (i > 0)
      ans = max(ans, rk1[i].second + v[0][i-1]);
    } else {
      if (j > 0) {
        j--;
      }
      if (rk1[j].first <= c-rk1[i].first) {
        ans = max(ans, rk1[i].second + v[0][j]);
      }
    }
  }
  j = 0;
  for (int i = rk2.size()-1; i >= 0; --i) {
    while(j < i && rk2[j].first <= d-rk2[i].first) {
      j++;
    }
    if (j >= i) {
      if (i > 0)
      ans = max(ans, rk2[i].second + v[1][i-1]);
    } else {
      if (j > 0) {
        j--;
      }
      if (rk2[j].first <= d-rk2[i].first) {
        ans = max(ans, rk2[i].second + v[1][j]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
