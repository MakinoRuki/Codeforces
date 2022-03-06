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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>n;
  for (int i=  1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int ans=0;
  int cnt=0;
  for (int i= n; i >= 1; --i) {
    if (cnt == 0) {
      cnt++;
    } else {
      if (a[i+1] <= a[i] * 2) {
        cnt++;
      } else {
        cnt = 1;
      }
    }
    ans=max(ans, cnt);
  }
  cout<<ans<<endl;
  return 0;
}
