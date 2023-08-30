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
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int d;
    scanf("%d%d%d", &n, &m, &d);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<pair<int,int>> ss;
    ss.clear();
    ll mx = 0;
    ll sum = 0LL;
    for (int i = 1; i <= n; ++i) {
      sum -= d;
      if (a[i] > 0) {
        sum += a[i];
        ss.insert(make_pair(a[i], i));
        if (ss.size() > m) {
          sum -= (*ss.begin()).first;
          ss.erase(ss.begin());
        }
      }
      mx = max(mx, sum);
      //cout<<"i="<<i<<" "<<sum<<endl;
    }
    printf("%lld\n", mx);
  }
  return 0;
}
