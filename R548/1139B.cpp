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
#define N 200002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
ll a[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i]);
  }
  ll ans=0LL;
  ll cur=a[n];
  for (int i = n; i >= 1; --i) {
    ans += cur;
    cur = max(0LL, cur-1);
    cur = min(cur, a[i-1]);
  }
  cout<<ans<<endl;
  return 0;
}
