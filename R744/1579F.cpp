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
#define M 105
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m, k;
int a[N];
int getgcd(int x, int y) {
  return y == 0 ? x : getgcd(y, x % y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int g=getgcd(n, k);
    // if (g == 1) {
    //   vector<int> tmp;
    //   tmp.clear();
    //   int cur=0;
    //   for (int i = 1; i <= n; ++i) {
    //     tmp.push_back(a[cur+1]);
    //     cur = (cur+n-k) % n;
    //   }
    //   int cnt=0;
    //   int ans=0;
    //   int sz=(int)tmp.size();
    //   for (int i = 0; i < 2*tmp.size(); ++i) {
    //     if (tmp[i%sz]) cnt++;
    //     else {
    //       ans=max(ans, cnt);
    //       cnt=0;
    //     }
    //   }
    //   ans=max(ans, cnt);
    //   if (ans == 2*n) {
    //     puts("-1");
    //   } else {
    //     printf("%d\n", ans);
    //   }
    //   continue;
    // }
    int ans=0;
    bool ok=true;
    for (int i = 1; i <= g; ++i) {
      int cnt=0;
      int tot=0;
      int res=0;
      vector<int> tmp;
      tmp.clear();
      int j = i;
      while(tmp.size() < n/g) {
        tmp.push_back(a[j]);
        j = (j-1+n-k)%n+1;
      }
      int sz=(int)tmp.size();
      for (int j = 0; j < 2*tmp.size(); ++j) {
        //if (i==2) cout<<"j="<<j<<" "<<tmp[j]<<endl;
        if (tmp[j%sz]) cnt++;
        else {
          res = max(res, cnt);
          cnt=0;
        }
      }
      res=max(res, cnt);
      if (res == 2*sz) {
        ok=false;
        break;
      }
      ans = max(ans, res);
    }
    if (ok) printf("%d\n", ans);
    else puts("-1");
  }
  return 0;
}
