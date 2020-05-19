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
int t;
int q;
ll n;
int main() {
  cin>>q;
  for (int i = 1; i <= q; ++i) {
    scanf("%lld", &n);
    ll ans=0LL;
    while(n > 1) {
      if (n%2==0) {
        ans++;
        n /= 2;
      } else if (n%3==0) {
        ans++;
        n /= 3;
        n *= 2;
      } else if (n%5 == 0) {
        ans++;
        n /= 5;
        n *= 4;
      } else {
        break;
      }
    }
    if (n == 1) cout<<ans<<endl;
    else cout<<-1<<endl;
  }
  return 0;
}
