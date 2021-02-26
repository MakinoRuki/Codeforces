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
int n, k;
int a[N];
bool vis[N];
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  memset(vis, false, sizeof(vis));
  sort(a+1, a+n+1);
  for (int i = 2; i <= n; ++i) {
    int j = i-1;
    while(j >= 1 && !vis[j] && a[i] > a[j] && a[i] <= a[j]+k) {
      vis[j] = true;
      j--;
    }
  }
  int ans=0;
  for (int i =1 ; i <= n; ++i) {
    if (!vis[i]) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
