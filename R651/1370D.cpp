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
#define N 200005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n, k;
int a[N];
bool check(int x, int f) {
  int tot=0;
  for (int i = 1; i <= n; ++i) {
    if (tot%2==f) {
      if (a[i]<=x) tot++;
    } else {
      tot++;
    }
  }
  return tot>=k;
}
int main() {
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int l = 0, r = 1000000000;
  while(l < r) {
    int mid=(l+r)/2;
    if (check(mid, 0) || check(mid, 1)) {
      r = mid;
    } else {
      l = mid+1;
    }
  }
  cout<<r<<endl;
  return 0;
}
