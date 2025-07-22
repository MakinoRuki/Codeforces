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
int a[N];
int b[N];
int sum[N];
int lowbit(int x) {
    return x&(-x);
}
void update(int p, int v) {
    while(p < N) {
        sum[p] += v;
        p += lowbit(p);
    }
}
int query(int p) {
    int res=0;
    while(p) {
        res += sum[p];
        p -= lowbit(p);
    }
    return res;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int tot=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        tot += a[i];
        //update(a[i], 1);
    }
    ll ans=0LL;
    sort(a+1, a+n+1);
    for (int i = 2; i < n; ++i) {
        // Trick: 初始化成取不到的边界之外的值。
        int l = n+1, r = i;
        for (int j = 1; j < i; ++j) {
            while(l-1 > i && a[l-1] > a[n]-a[i]-a[j]) {
                l--;
            }
            while(r + 1 <= n && a[r+1] < a[i]+a[j]) {
                r++;
            }
            if (l <= r) {
                ans += r-l+1;
            }
        }
    }
    printf("%lld\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
