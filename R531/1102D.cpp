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
#define M 12
#define N 10000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, x, y;
string s;
int main() {
  cin>>n>>s;
  int m = n/3;
  int c0=0, c1=0, c2=0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      c0++;
    } else if (s[i] == '1') {
      c1++;
    } else {
      c2++;
    }
  }
  if (c0 == m && c1 == m && c2 == m) {
    cout<<s<<endl;
  } else {
    vector<int> ids[3];
    for (int i = 0; i < n; ++i) {
      ids[s[i]-'0'].push_back(i);
    }
    if (c0 > m && c1 <= m && c2 <= m) {
      int cur=m;
      for (int j = 0; j < m-c1; ++j) {
        s[ids[0][cur++]] = '1';
      }
      for (int j = 0; j < m-c2; ++j) {
        s[ids[0][cur++]] = '2';
      }
    } else if (c1 > m && c0 <= m && c2 <= m) {
      for (int j = 0; j < m-c0; ++j) {
        s[ids[1][j]] = '0';
      }
      int cur = ids[1].size() - (m-c2);
      for (int j = cur; j < ids[1].size(); ++j) {
        s[ids[1][cur++]] = '2';
      }
    } else if (c2 > m && c0 <= m && c1 <= m) {
      for (int j = 0; j < m-c0; ++j) {
        s[ids[2][j]] = '0';
      }
      for (int j = m-c0; j < m-c0+m-c1; ++j) {
        s[ids[2][j]] = '1';
      }
    } else if (c0 > m && c1 > m && c2 < m) {
      for (int j = m; j < ids[0].size(); ++j) {
        s[ids[0][j]] = '2';
      }
      for (int j = m; j < ids[1].size(); ++j) {
        s[ids[1][j]] = '2';
      }
    } else if (c0 > m && c2 > m && c1 < m) {
      for (int j = m; j < ids[0].size(); ++j) {
        s[ids[0][j]] = '1';
      }
      for (int j = 0; j < c2-m; ++j) {
        s[ids[2][j]] = '1';
      }
    } else if (c1 > m && c2 > m && c0 < m) {
      for (int j = 0; j < c1-m; ++j) {
        s[ids[1][j]] = '0';
      }
      for (int j = 0; j < c2-m; ++j) {
        s[ids[2][j]] = '0';
      }
    }
    cout<<s<<endl;
  }
  return 0;
}
