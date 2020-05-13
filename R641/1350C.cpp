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
int n;
int a[N];
vector<int> ps[N*2];
int main() {
  cin>>n;
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  for (int i = 1; i <= 200000; ++i) {
    ps[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    int x=a[i];
    for (int j =2; j * j <= x; ++j) {
      int cnt=0;
      while(x%j == 0) {
        x/=j;
        cnt++;
      }
      if (cnt) ps[j].push_back(cnt);
    }
    if (x>1) ps[x].push_back(1);
  }
  ll ans=1LL;
  for (int i = 2; i <= 200000; ++i) {
    if (ps[i].size()) {
      sort(ps[i].begin(), ps[i].end());
      if (ps[i].size() == n) {
        for (int k = 1; k <= ps[i][1]; ++k) {
          ans = ans*(ll)i;
        }
      } else if (ps[i].size() == n-1) {
        for (int k = 1; k <= ps[i][0]; ++k) {
          ans = ans*(ll)i;
        }
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
