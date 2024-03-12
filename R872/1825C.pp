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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
      b[i]=0;
    }
    set<int> ss;
    ss.clear();
    int n1=0,n2=0;
    int nn=0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == -1) n1++;
      else if (a[i] == -2) n2++;
      else ss.insert(a[i]);
      if (a[i] > 0) b[a[i]]=1;
    }
    int sz=(int)ss.size();
    nn = m - sz;
    int ans=max(min(m,sz+n1), min(m,sz+n2));
    int cnt=0;
    for (int i = 1; i <= m; ++i) {
      if (b[i] > 0) {
        ans = max(ans, sz + min(cnt,n1) + min(nn-cnt,n2));
      } else {
        cnt++;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
