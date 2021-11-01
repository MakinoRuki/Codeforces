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
#define N 500002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, h;
int n;
ll k;
int q;
vector<int> mx[N][2];
vector<int> mn[N][2];
int a[N*20];
bool row[N];
int main() {
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i*m+j]);
      }
    }
    for (int i = 0; i < n; ++i) {
      mx[i][0].clear();
      mn[i][0].clear();
      for (int j = 0; j < m; ++j) {
        if (j == 0) {
          mx[i][0].push_back(a[i*m+j]);
          mn[i][0].push_back(a[i*m+j]);
        } else {
          mx[i][0].push_back(max(mx[i][0].back(), a[i*m+j]));
          mn[i][0].push_back(min(mn[i][0].back(), a[i*m+j]));
        }
      }
      mx[i][1].clear();
      mn[i][1].clear();
      for (int j = m-1; j >= 0; --j) {
        if (j == m-1) {
          mx[i][1].push_back(a[i*m+j]);
          mn[i][1].push_back(a[i*m+j]);
        } else {
          mx[i][1].push_back(max(mx[i][1].back(), a[i*m+j]));
          mn[i][1].push_back(min(mn[i][1].back(), a[i*m+j]));
        }
      }
    }
    int k;
    for (k = 0; k < m-1; ++k) {
      set<pair<int,int>> ls;
      ls.clear();
      set<pair<int,int>> rs;
      rs.clear();
      for (int i = 0; i < n; ++i) {
        ls.insert(make_pair(-mx[i][0][k], i));
        rs.insert(make_pair(mn[i][1][m-k-2], i));
        row[i] = false;
      }
      auto r = (*ls.begin());
      int id = r.second;
      int lmn = mn[id][0][k];
      int rmx = mx[id][1][m-k-2];
      row[id] = true;
      int cnt=1;
      ls.erase(make_pair(-mx[id][0][k], id));
      rs.erase(make_pair(mn[id][1][m-k-2], id));
      while(true) {
        bool found=false;
        while(!rs.empty()) {
          auto pr = *rs.begin();
          int id = pr.second;
          if (pr.first <= rmx) {
            found=true;
            row[id] = true;
            cnt++;
            rs.erase(make_pair(mn[id][1][m-k-2], id));
            ls.erase(make_pair(-mx[id][0][k], id));
            lmn = min(lmn, mn[id][0][k]);
            rmx = max(rmx, mx[id][1][m-k-2]);
          } else {
            break;
          }
        }
        while(!ls.empty()) {
          auto pr = *ls.begin();
          int id = pr.second;
          if (-pr.first >= lmn) {
            found=true;
            row[id] = true;
            cnt++;
            rs.erase(make_pair(mn[id][1][m-k-2], id));
            ls.erase(make_pair(-mx[id][0][k], id));
            lmn = min(lmn, mn[id][0][k]);
            rmx = max(rmx, mx[id][1][m-k-2]);
          } else {
            break;
          }
        }
        if (!found) break;
      }
      if (cnt >= 1 && cnt < n) {
        break;
      }
    }
    if (k >= m-1) {
      puts("NO");
    } else {
      puts("YES");
      string ans="";
      for (int i = 0; i < n; ++i) {
        if (row[i]) ans += "R";
        else ans += "B";
      }
      cout<<ans<<" ";
      printf("%d\n", k+1);
    }
  }
  return 0;
}
