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
#define M 52
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
vector<string> mp;
int dis(int i, int j, int x, int y) {
  return abs(i-x) + abs(j-y);
}
int main() {
  cin>>t;
  int r,c;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    vector<int> ds;
    ds.clear();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        int res = max(dis(i,j,0,0), dis(i,j,0,m-1));
        res = max(res, dis(i,j,n-1,0));
        res = max(res, dis(i,j,n-1,m-1));
        ds.push_back(res);
      }
    }
    sort(ds.begin(), ds.end());
    for (int i = 0; i < ds.size(); ++i) {
      printf("%d", ds[i]);
      if (i<ds.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
