#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int sum[26][N];
vector<int> ids[26];
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    for (int i = 0; i < 26; ++i) {
      ids[i].clear();
    }
    for (int i = 0; i < 26; ++i) {
      for (int j = 0; j <= n; ++j) {
        sum[i][j] = 0;
      }
    }
    for (int i = 1; i <= n; ++i) {
      ids[s[i-1]-'a'].push_back(i);
      for (int j = 0; j < 26; ++j) {
        sum[j][i] = sum[j][i-1];
        if (s[i-1]-'a' == j) {
          sum[j][i]++;
        }
      }
    }
   // cout<<sum[1][2]<<" "<<sum[1][1]<<endl;
    bool ok = true;
    for (int i = 0; i < 26; ++i) {
      for (int j = 1; j < ids[i].size(); ++j) {
        int id1 = ids[i][j];
        int id2 = ids[i][j-1];
        for (int i2 = 0; i2 < 26; ++i2) {
          if (i2 == i) continue;
          if (ids[i2].size() > 0) {
            if (sum[i2][id1-1] - sum[i2][id2] <= 0) {
            //  cout<<i<<" "<<i2<<" "<<id2<<" "<<id1<<endl;
              ok=false;
              break;
            }
          }
        }
        if (!ok) break;
      }
      if (!ok) break;
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
