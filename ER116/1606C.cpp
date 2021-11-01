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
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, m, h;
int n;
ll k;
int q;
string s;
ll p1[20];
int main() {
  cin>>t;
  p1[0] = 1LL;
  for (int i = 1; i <= 9; ++i) {
    p1[i] = p1[i-1] * 10LL;
  }
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%lld", &n, &k);
    ll res = 0LL;
    vector<ll> pw;
    pw.clear();
    for (int i = 1; i <= n; ++i) {
      int x;
      scanf("%d", &x);
      pw.push_back(p1[x]);
    }
    vector<ll> sum;
    sum.clear();
    for (int i = 0; i < n-1; ++i) {
      if (i == 0) sum.push_back(pw[i+1]/pw[i]-1);
      else sum.push_back(sum[i-1] + pw[i+1]/pw[i]-1);
     // cout<<i<<" "<<sum[i]<<endl;
    }
    k++;
    int i = n-1;
    for (i = n-1; i > 0; --i) {
      if (sum[i-1] < k) {
        break;
      }
    }
    ll pre = (i == 0 ? 0 : sum[i-1]);

    for (int j = 0; j < i; ++j) {
      res += (pw[j+1]/pw[j]-1) * pw[j];
    }
  //  cout<<i<<" "<<pre<<" "<<res<<endl;
    res += (ll)(k-pre) * (ll)pw[i];
    printf("%lld\n", res);
  }
  return 0;
}
