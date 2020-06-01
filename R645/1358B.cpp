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
//#include <priority_queue>
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
map<int, int> mp;
int main() {
  cin>>t;
  for (int cas=1;  cas<=t; ++cas) {
    cin>>n;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    ll sum=0LL;
    ll ans=1;
    for (auto v : mp) {
      sum += v.second;
      if (sum >= v.first) {
        ans = max(ans, sum+1);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
