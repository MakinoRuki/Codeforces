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
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int a[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    //a[i] = rand()%2;
    //cout<<a[i]<<" ";
  }
  cout<<endl;
  int ans=0;
  int cnt=0;
  int pre = 0;
  for (int i = 2; i < n; ++i) {
    if (!a[i] && a[i-1] && a[i+1]) {
      if (pre > 0 && pre == i - 2) {
        cnt++;
      } else {
        ans += (cnt+1)/2;
        cnt = 1;
      }
      pre = i;
    }
  }
  ans += (cnt+1)/2;
  cout<<ans<<endl;
  return 0;
}
