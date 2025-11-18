
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
#define M 5002
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
int cnt2[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[i]=0;
      cnt2[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]]++;
    }
    int num=0;
    for (int i = 1; i <= n; ++i) {
      if (cnt[i] % k) {
        num=-1;
        break;
      }
      cnt[i] /= k;
    }
    if (num<0) {
      puts("0");
      continue;
    }
    ll ans=0LL;
    int r = 1;
    for (int i = 1; i <= n; ++i) {
      while(r <= n) {
        if (cnt2[a[r]]+1 > cnt[a[r]]) {
          break;
        }
        cnt2[a[r]]++;
        r++;
      }
     // cout<<"i="<<i<<" "<<r<<endl;
      cnt2[a[i]]--;
      ans += r-i;
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
