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
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int s[N];
int main() {
  cin>>t;
  for (int i = 1; i <= t; ++i) {
    scanf("%d", &n);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &s[i]);
    }
    sort(s+1, s+n+1);
    int ans=s[2]-s[1];
    for (int i = 2; i <= n; ++i) {
      if (i-1>=1) ans=min(ans, s[i]-s[i-1]);
      if (i+1<=n) ans=min(ans, s[i+1]-s[i]);
    }
    cout<<ans<<endl;
  }
  return 0;
}
