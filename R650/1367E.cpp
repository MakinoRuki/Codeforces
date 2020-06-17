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
#define N 2005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
string s;
int par[N];
int cnt[N];
int num[27];
int find(int u) {
  return u == par[u] ? u : par[u] = find(par[u]);
}
int main() {
  cin>>t;
  //q = 1;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    cin>>s;
    int ans;
    for (ans = n; ans >= 1; ans--) {
      for (int i = 0; i < ans; ++i) {
        par[i] = i;
        cnt[i] = 0;
      }
      memset(num, 0, sizeof(num));
      for (int i = 0; i < n; ++i) {
        num[s[i]-'a']++;
      }
      for (int i = 0; i < ans; ++i) {
        int j = (i+k) % ans;
        int pi = find(i);
        int pj = find(j);
        if (pi != pj) {
          par[pi] = pj;
        }
      }
      for (int i = 0; i < ans; ++i) {
        int pi = find(i);
        cnt[pi]++;
      }
      vector<int> rk;
      rk.clear();
      for (int i = 0; i < ans; ++i) {
        if (par[i] == i) rk.push_back(cnt[i]);
      }
      sort(rk.begin(), rk.end());
      int i;
      for (i = rk.size()-1; i >= 0; --i) {
        int j;
        int id = -1;
        int minv = 2001;
        for (int j = 0; j < 26; ++j) {
          if (num[j] >= rk[i]) {
            if (num[j] < minv) {
              minv = num[j];
              id = j;
            }
          }
        }
        if (id < 0) break;
        num[id] -= rk[i];
      }
      if (i >= 0) continue;
      break;
    }
    cout<<ans<<endl;
  }
  return 0;
}
