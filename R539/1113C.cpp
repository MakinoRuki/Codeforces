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
#define M 12
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, v, k;
int a[N];
int main() {
  cin>>n;
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  map<pair<int,int>, int> cnt;
  cnt.clear();
  int sum=0;
  cnt[make_pair(0, 0)]++;
  ll ans = 0LL;
  for (int i = 1; i <= n; ++i) {
    sum ^= a[i];
    int b = i % 2;
    ans += cnt[make_pair(sum, b)];
    cnt[make_pair(sum, b)]++;
  }
  cout<<ans<<endl;
  return 0;
}
