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
#define M 16
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
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
    ll k;
    scanf("%d%lld", &n, &k);
    if (n < 50 && (1LL<<(n-1))<k) {
        puts("-1");
        continue;
    }
    if (n == 1) {
        if (k == 1) puts("1");
        else puts("-1");
        continue;
    }
    int l = 1, r = n;
    int cnt=n-2;
    for (int i = 1; i < n; ++i) {
        if (cnt >= 50 || (1LL<<cnt)>=k) {
            a[l] = i;
            l++;
        } else {
            k -= (1LL<<cnt);
            a[r] = i;
            r--;
        }
        cnt--;
    }
    a[l] = n;
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

