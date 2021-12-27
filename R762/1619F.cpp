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
int a[N];
vector<int> res[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    int q1 = n/m, r1 = n%m;
    int q2 = (r1 * ((n+m-1)/m) * k) / n;
    int r2 = (r1 * ((n+m-1)/m) * k) % n;
    for (int i = 0; i <= k * m; ++i) {
      res[i].clear();
    }
    int y = 0, x = 0;
    for (int i = 1; i <= n; ++i) {
      int ub = q2;
      if (i <= r2) ub++;
      for (int j = 1; j <= ub; ++j) {
        res[x*m+y].push_back(i);
      //  cout<<"i="<<i<<" "<<x<<" "<<y<<endl;
        x++;
        if (x >= k) x = 0;
        if (res[x * m + y].size() >= (y+1<=r1 ? q1+1: q1)) {
          y++;
        }
      }
    }
    for (int i = 0; i < k; ++i) {
      set<int> ss;
      for (int j = 1; j <= n;++j) {
        ss.insert(j);
      }
      for (int j = 0; j < r1; ++j) {
        for (int j2 = 0; j2 < res[i*m+j].size(); ++j2) {
          ss.erase(res[i*m+j][j2]);
        }
      }
      vector<int> v(ss.begin(), ss.end());
      int i2 = 0;
      for (int j = r1; j < m; ++j) {
        for (int j2 = 0; j2 < q1; ++j2) {
          res[i * m + j].push_back(v[i2++]);
        }
      }
      for (int j = 0; j < m; ++j) {
        printf("%d", (int)res[i * m +j].size());
        for (int j2 = 0; j2 < res[i*m+j].size(); ++j2) {
          printf(" %d", res[i*m+j][j2]);
        }
        cout<<endl;
      }
    }
  }
  return 0;
}
