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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int ans[N];
vector<int> ids[10];
int mv[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    cin>>s;
    for (int i = 0; i < 10; ++i) {
      ids[i].clear();
    }
    for (int i = 0; i < n; ++i) {
      ans[i] = -1;
    }
    for (int i = 0; i < n; ++i) {
      ids[s[i]-'0'].push_back(i);
    }
    int bg = 0;
    for (int i = 0; i < 10; ++i) {
      if (ids[i].size() > 0) {
        bg = ids[i][0];
        break;
      }
    }
    bool found=false;
    for (int d = 0; d <= 10; ++d) {
      for (int i = 0; i < n; ++i) {
        ans[i] = -1;
      }
      int ed = 0;
      string tmp="";
      for (int d1 = 0; d1 < d; ++d1) {
        for (int i = 0; i < ids[d1].size(); ++i) {
          ed = max(ed, ids[d1][i]+1);
        }
      }
      for (int i = 0; i < n; ++i) {
        if (s[i]-'0' < d) {
          ans[i] = 1;
          tmp.push_back(s[i]);
        } else if (s[i] - '0' == d && i >= ed) {
          ans[i] = 1;
          tmp.push_back(s[i]);
        }
      }
      for (int i = 0; i < n; ++i) {
        if (ans[i] < 0) {
          ans[i] = 2;
          tmp.push_back(s[i]);
        }
      }
      int i;
      for (i = 1; i < n; ++i) {
        if (tmp[i] < tmp[i-1]) {
          break;
        }
      }
      if (i >= n) {
        found=true;
        break;
      }
    }
    if (!found) {
      puts("-");
      continue;
    }
    string res="";
    for (int i = 0; i < n; ++i) {
      res += ans[i] + '0';
    }
    cout<<res<<endl;
  }
  return 0;
}
