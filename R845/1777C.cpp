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
#include <ctime>
#define N 100005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<int> ds[N];
int main() {
  cin>>t;
  for (int i = 1; i < N; ++i) {
    for (int j = i; j < N; j += i) {
      ds[j].push_back(i);
    }
  }
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    vector<int> v(ss.begin(), ss.end());
    int ans = -1;
    int j = 0;
    ss.clear();
    map<int,int> mp;
    mp.clear();
    for (int i = 0; i <v.size(); ++i) {
      j = max(j, i);
      while(j < v.size() && mp.size() < m) {
        int x = v[j];
        for (int k = 0; k < ds[x].size(); ++k) {
          if (ds[x][k]<=m) mp[ds[x][k]]++;
        }
        j++;
      }
      // if (i == 0) {
      //   cout<<v[i]<<" "<<j<<" "<<mp[1]<<" "<<mp[2]<<endl;
      // }
      if (mp.size() == m) {
        int dt = v[j-1]-v[i];
        if (ans < 0) ans = dt;
        else ans = min(ans, dt);
      }
      int x = v[i];
      for (int k = 0; k < ds[x].size(); ++k) {
        if (ds[x][k]<=m) {
          mp[ds[x][k]]--;
          if (mp[ds[x][k]] == 0) mp.erase(ds[x][k]);
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
