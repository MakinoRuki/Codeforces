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
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int mn[30];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    string ans="";
    for (int i = 0; i < 26; ++i) {
      mn[i] = i;
    }
    for (int i = 0; i < n; ++i) {
      int c = s[i]-'a';
      int dt = 0;
      for (int j = 0; j <= min(c, k); ++j) {
        int c2 = c-j;
        if (mn[c2] < mn[c]) {
          mn[c] = mn[c2];
          dt = j;
        }
      }
      ans.push_back(mn[c] + 'a');
      for (int j = c; j >= mn[c]; --j) {
        mn[j] = mn[c];
      }
      k -= dt;
    }
    cout<<ans<<endl;
  }
  return 0;
}
