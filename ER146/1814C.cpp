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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int r[N];
vector<int> ans[2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int s1, s2;
    scanf("%d%d%d", &n, &s1, &s2);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &r[i]);
      rk.push_back(make_pair(r[i], i));
    }
    sort(rk.begin(), rk.end());
    reverse(rk.begin(), rk.end());
    int cnt1=0, cnt2=0;
    ans[0].clear();
    ans[1].clear();
    for (int i = 0; i < rk.size(); ++i) {
      ll v = rk[i].first;
      int id = rk[i].second;
      if ((cnt1+1)*s1*v < (cnt2+1)*s2*v) {
        ans[0].push_back(id);
        cnt1++;
      } else {
        ans[1].push_back(id);
        cnt2++;
      }
    }
    printf("%d", cnt1);
    for (int i = 1; i <= cnt1; ++i) {
      printf(" %d", ans[0][i-1]);
    }
    cout<<endl;
    printf("%d", cnt2);
    for (int i = 1; i <= cnt2; ++i) {
      printf(" %d", ans[1][i-1]);
    }
    cout<<endl;
  }
  return 0;
}
