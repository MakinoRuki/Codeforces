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
#define N 2000005
#define M 60
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
bool dp[N];
int cnt[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &k);
    string s;
    cin>>s;
    for (int i = 0; i <(1<<m); ++i) {
      dp[i] = true;
    }
    for (int i = 0; i <m; ++i) {
      cnt[i]=0;
    }
    int st=0;
    int tot=(1<<m)-1;
    for (int i = 0; i < n; ++i) {
      int x = s[i]-'A';
      cnt[x]++;
      if (cnt[x] == 1) {
        st |= (1<<x);
      }
      if (i-k>=0) {
        int y = s[i-k]-'A';
        cnt[y]--;
        if (cnt[y] == 0) st ^= (1<<y);
      }
      if (i >= k-1) {
        int nst = tot ^ st;
        dp[nst] = false;
      //  cout<<"nst="<<nst<<endl;
      }
    }
    int x= s[n-1]-'A';
    dp[tot ^ (1<<x)] = false;
    for (int i = (1<<m)-1; i > 0; --i) {
      for (int j = 0; j < m; ++j) {
        if ((1<<j) & i) {
          int i2 = i ^ (1<<j);
          if (!dp[i]) dp[i2] = false;
        }
      }
    }
    int ans=m;
    for (int i = 0; i < (1<<m); ++i) {
      if (dp[i]) {
        ans = min(ans, __builtin_popcount(i));
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

