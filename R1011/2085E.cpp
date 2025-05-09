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
#define N 3000005
#define M 10000005
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
int b[N];
int cnt[N];
bool check(int k) {
    for (int i = 1; i <= n; ++i) {
        cnt[b[i]]++;
    }
    for (int i = 1; i <= n; ++i) {
        int r = a[i]%k;
        if (cnt[r] > 0) {
            cnt[r]--;
        } else {
            for (int i = 1; i <= n; ++i) {
                cnt[b[i]] = 0;
            }
            return false;
        }
    }
    return true;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot = 0LL;
    int mx=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        mx=max(mx, a[i]);
        tot += a[i];
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
        tot -= b[i];
    }
    tot = abs(tot);
    // if (tot == 0) {
    //     if (check(0xc0ffee)) {
    //         printf("%d\n", 0xc0ffee);
    //     } else {
    //         puts("-1");
    //     }
    //     continue;
    // }
    vector<int> ps;
    ps.clear();
    // d(n)<=2304 holds for all n<=10^10, where d(n)
    // denotes the number of divisors of n.
    for (ll p = 1; p * p <= tot; ++p) {
        if ((tot % p)==0) {
            ps.push_back(p);
            if (p != tot/p) {
                ps.push_back(tot/p);
            }
        }
    }
    ps.push_back(mx+1);
    int ans=-1;
    for (auto p : ps) {
        if (check(p)) {
            ans=p;
            break;
        }
    }
    printf("%d\n", ans);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
