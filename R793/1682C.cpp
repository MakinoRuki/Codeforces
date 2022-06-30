#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> mp;
    mp.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    int tot = (int)mp.size();
    int cnt=0;
    for (auto itr : mp) {
      if (itr.second > 1) {
        cnt++;
      }
    }
    int dt = tot - cnt;
  //  cout<<tot<<" "<<cnt<<endl;
    if (dt == 0) {
      printf("%d\n", tot);
    } else if (dt <= 2) {
      printf("%d\n", cnt+1);
    } else {
      if (dt % 2) {
        printf("%d\n", cnt + dt/2+1);
      } else {
        printf("%d\n", tot - dt/2);
      }
    }
  }
  return 0;
}
