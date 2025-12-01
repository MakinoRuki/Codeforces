
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
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int n1=0,n01=0,n00=0;
    for (int i = 1; i <= 2*n; ++i) {
      cnt[i]=0;
    }
    for (int i = 1; i <= 2*n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    for (int i = 1; i <= 2*n; ++i) {
      if (!cnt[i]) continue;
      if (cnt[i]%2) n1++;
      else {
        if ((cnt[i]/2)%2) n01++;
        else n00++;
      }
    }
  //  cout<<n1<<" "<<n00<<" "<<n01<<endl;
    int ans=n1+n01*2;
    ans += n00/2*4;
    n00 %= 2;
    if (n00) {
      if (n1 >= 2) ans+=2;
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
