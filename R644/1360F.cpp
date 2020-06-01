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
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
vector<string> mt;
int main() {
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    mt.clear();
    for (int j = 0; j < n; ++j) {
      string s;
      cin>>s;
      mt.push_back(s);
    }
    string ans="";
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int c = -1;
        bool ok =true;
        for (int i2 = 0; i2 < n; ++i2) {
          if (i==i2) continue;
          int cnt=0;
          for (int j2= 0; j2 < m; ++j2) {
            if (j2==j) continue;
            if (mt[i2][j2] != mt[i][j2]) cnt++;
          }
          if (cnt == 0) continue;
          if (cnt == 1) {
            if (c>=0 && mt[i2][j]-'a' != c) {
              ok=false;
            } else {
              c = mt[i2][j]-'a';
            }
          } else {
            ok = false;
          }
        }
        if (!ok) continue;
        ans = mt[i];
        if (c >= 0) ans[j] = 'a'+c;
      }
    }
    if (ans.empty()) {
      cout<<-1<<endl;
    } else {
      cout<<ans<<endl;
    }
  }
  return 0;
}
