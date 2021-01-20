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
#include <random>
#define eps 1e-7
#define M 21
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n;
int k;
ll d;
bool pr[N];
int main() {
  cin>>t;
  memset(pr, false, sizeof(pr));
  for (int i = 2; i * i <= 500000; ++i) {
    if (!pr[i]) {
      for (int j = i*i; j <= 500000; j += i) {
        pr[j] = true;
      }
    }
  }
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld", &d);
    ll p1=-1,p2=-1;
    for (int i = 2; i <= 500000; ++i) {
      if (!pr[i]) {
        if (p1<0) {
          if (i-1>=d) {
            p1=i;
          }
        } else {
          if (i-p1>=d) {
            p2 = i;
            break;
          }
        }
      }
    }
    ll res1=p1*p1*p1;
    ll res2=p1*p2;
    if (res1<res2) printf("%lld\n", res1);
    else printf("%lld\n", res2);
    // for (ll x = 2; x <= 10000; ++x) {
    //   vector<int> ds;
    //   ds.clear();
    //   for (ll y = 1; y * y <= x; ++y) {
    //     if (x%y==0) {
    //       ds.push_back(y);
    //       if (x/y != y) {
    //         ds.push_back(x/y);
    //       }
    //     }
    //   }
    //   sort(ds.begin(), ds.end());
    //   if (x==28) {
    //     for (int j = 0; j < ds.size(); ++j) {
    //       cout<<"j="<<j<<" "<<ds[j]<<endl;
    //     }
    //   }
    //   if (ds.size() >= 4) {
    //     int j;
    //     for (j = 1; j < ds.size(); ++j) {
    //       if (ds[j]-ds[j-1]<d) {
    //         break;
    //       }
    //     }
    //     if (j >= ds.size()) {
    //       cout<<"x="<<x<<endl;
    //       break;
    //     }
    //   }
    // }
  }
  return 0;
}
