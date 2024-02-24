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
#include <random>
#include <ctime>
#define N 300005
#define M 2002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
vector<pair<int,int>> os;
ll ans[N];
ll pos[N];
const ll mx=1000000000000000000LL;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k;
    scanf("%d%d", &n, &q);
    os.clear();
    ll cur=0;
    for (int i = 1; i <= n; ++i) {
      int b,x;
      scanf("%d%d", &b, &x);
      if (b == 1) {
        cur++;
        if (cur > mx) {
          cur = mx+1LL;
        }
        pos[i]=cur;
      } else {
        
        if (cur  > (mx)/(x+1LL)) {
       //   if (i==11) cout<<"!!!"<<" "<<cur<<endl;
          cur = (mx)+1LL;
         // if (i==11) cout<<"???"<<" "<<cur<<endl;
        } else {
          cur= cur*(x+1LL);
        }
        pos[i]=cur;
       // if (i==11) cout<<"***"<<" "<<cur<<endl;
      }
     // cout<<"i2="<<i<<" "<<cur<<" "<<pos[i]<<endl;
      os.push_back(make_pair(b, x));
    }
    for (int i = 1; i <= q; ++i) {
      ans[i]=-1;
    }
    for (int i = 1; i <= q; ++i) {
      scanf("%lld", &k);
      while(true) {
        int l = 1, r = n;
        while(l < r) {
          int mid=(l+r)/2;
          if (pos[mid] >= k) {
            r = mid;
          } else {
            l = mid+1;
          }
        }
        if (os[r-1].first == 1) {
          ans[i] = os[r-1].second;
          break;
        } else {
          k = k % pos[r-1];
          if (k == 0) k = pos[r-1];
        }
      }
      //cout<<"i="<<i<<endl;
    }
    for (int i =1; i <= q; ++i) {
      printf("%lld ", ans[i]);
    }
    cout<<endl;
  }
  return 0;
}
