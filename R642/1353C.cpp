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
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d", &n);
    ll ans=0LL;
    for (int i = 1; i <= n/2; ++i) {
      ans += (ll)i*(ll)i;
    }
    ans = ans*8LL;
    cout<<ans<<endl;
  }
  return 0;
}
