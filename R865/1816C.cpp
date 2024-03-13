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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll mn=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
        mn=(i==1?a[i]:min(mn,a[i]));
    }
    if (a[1] > mn) {
        ll dt=a[1]-mn;
        a[1]-=dt;
        a[2]-=dt;
    }
    for (int i =2; i < n; ++i) {
        if (a[i] < a[i-1]) {
            ll dt=a[i-1]-a[i];
            a[i] += dt;
            a[i+1] += dt;
        } else if (a[i] > a[i-1]) {
            ll dt=a[i]-a[i-1];
            a[i] -= dt;
            a[i+1] -= dt;
        }
    }
    // if (a[n] < a[n-1]) {
    //     puts("NO");
    // } else {
    //     puts("YES");
    // }
    if (a[n] < a[n-1]) {
        if (n%2) {
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        puts("YES");
    }
  }
  return 0;
}
