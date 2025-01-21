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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 200005
#define M 1002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll k,l;
    scanf("%d%lld%lld", &n, &k, &l);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    int mv=0;
    double cur=0;
    double ans=0;
    if (a[1] > 0) {
        mv = 1;
        ans += 2*a[1];
        a[1] = 0;
    }
    cur = a[1]+k;
    if (n==1 && !mv) {
        ans += 2*(l-cur);
        printf("%d\n", (int)ans);
        continue;
    }
    for (int i = 1; i <= n; ++i) {
        if (i == n) {
            if (cur < l) {
                ans += 2*(l-cur);
            }
        } else {
            if (cur >= a[i+1]) {
                if (a[i+1]+ans/2>=cur) {
                    cur += k;
                    mv=1;
                } else {
                    cur = max(a[i+1]+ans*0.5+k,cur);
                    mv=1;
                }
                continue;
            }
            if (mv) {
                if (2*(a[i+1]-cur) <= ans) {
                    cur += k;
                    mv=1;
                } else {
                    double dt = (a[i+1]-cur-ans/2);
                    cur = a[i+1]-ans*0.5-dt*0.5+k;
                    ans += dt;
                    mv=1;
                }
            } else {
                if (a[i+1]-cur <= ans) {
                    cur += k;
                    mv=1;
                } else {
                    double dt = (a[i+1]-cur-ans);
                    cur = a[i+1]-ans*0.5-dt*0.5+k;
                    ans += dt;
                    mv=1;
                }
            }
        }
    }
    printf("%d\n", (int)ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
