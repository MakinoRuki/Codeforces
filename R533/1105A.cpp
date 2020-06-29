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
const ll mod = 1000000007LL;
int n;
int a[N];
int main() {
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans=102*n;
  int t0 = 101;
  for (int i = 1; i <= 101; ++i) {
    int tot=0;
    for (int j = 1; j <= n; ++j) {
      if (a[j] == i) continue;
      if (a[j] > i) {
        tot += a[j]-(i+1);
      } else {
        tot += i-1-a[j];
      }
    }
    if (tot < ans) {
      ans = tot;
      t0 = i;
    }
  }
  cout<<t0<<" "<<ans<<endl;
  return 0;
}
