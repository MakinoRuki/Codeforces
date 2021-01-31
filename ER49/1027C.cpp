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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
vector<int> av;
bool check(ll a1, ll b1, ll a2, ll b2) {
  ll x = (a1*a1+b1*b1)*a2*b2;
  ll y = (a2*a2+b2*b2)*a1*b1;
  if (x < y) return true;
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    av.clear();
    int a;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a);
      av.push_back(a);
    }
    sort(av.begin(), av.end());
    vector<pair<int,int>> rk;
    rk.clear();
    int num=av[0];
    int cnt=1;
    for (int i = 1; i < av.size(); ++i) {
      if (av[i] == av[i-1]) {
        cnt++;
      } else {
        if (cnt>1) rk.push_back(make_pair(num, cnt));
        num = av[i];
        cnt = 1;
      }
    }
    if (cnt>1) rk.push_back(make_pair(num, cnt));
    int ans1 = 0;
    int ans2=0;
    ll det1 = -1;
    ll det2=-1;
    for (int i = 0; i < rk.size(); ++i) {
      if (i+1<rk.size() && rk[i].second > 1 && rk[i+1].second > 1) {
        if (det1 < 0 || check(rk[i].first, rk[i+1].first, det1, det2)) {
          ans1 = i;
          ans2 = i+1;
          det1 = rk[i].first;
          det2 = rk[i+1].first;
        }
      }
      if (rk[i].second >= 4 && (det1<0 || check(rk[i].first, rk[i].first, det1, det2))) {
        det1 = rk[i].first;
        det2 = rk[i].first;
        ans1 = i;
        ans2= i;
      }
    }
 //   if (rk[ans].second >= 4) printf("%d %d %d %d\n", rk[ans].first, rk[ans].first, rk[ans].first, rk[ans].first);
    printf("%d %d %d %d\n", rk[ans1].first, rk[ans1].first, rk[ans2].first, rk[ans2].first);
  }
  return 0;
}
