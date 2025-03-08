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
#define N 500005
#define M 750
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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
  //  printf("%lld\n", (k-1)/2+1);
    string s;
    cin>>s;
    int mn=0,mx=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (i==1) {
            mn=a[i];
            mx=a[i];
        } else {
            mn=min(mn, a[i]);
            mx=max(mx, a[i]);
        }
    }
    ll l = 0, r = mx;
    while(l < r) {
        ll mid=(l+r)/2;
        int pre=-1;
        int cnt=0;
     //   cout<<"mid="<<mid<<endl;
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'R') {
                if (a[i+1] <= mid) {
                    continue;
                } else {
                    pre=1;
                }
            } else {
                if (a[i+1] <= mid) {
                    continue;
                } else {
                    if ((pre < 0) || (pre == 1)) {
                        cnt++;
                    }
                    pre=0;
                }
            }
           // cout<<"i="<<i<<" "<<cnt<<" "<<pre<<endl;
        }
        if (cnt <= k) {
            r = mid;
        } else {
            l = mid+1;
        }
    }
    printf("%lld\n", r);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
