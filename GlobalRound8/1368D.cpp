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
#define N 1002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n;
int cnt[25];
int main() {
  cin>>n;
  memset(cnt, 0, sizeof(cnt));
  for (int i = 1; i <= n; ++i) {
    int a;
    scanf("%d", &a);
    for (int j = 0; j < 20; ++j) {
      if ((1<<j)&a) cnt[j]++;
    }
  }
  ll ans=0LL;
  while(true) {
    bool found=false;
    ll tmp=0LL;
    for (int i = 0; i < 20; ++i) {
      if (cnt[i]) {
        found=true;
        tmp += (1LL<<i);
        cnt[i]--;
      }
    }
    if (!found) break;
    ans += tmp*tmp;
  }
  cout<<ans<<endl;
  return 0;
}
