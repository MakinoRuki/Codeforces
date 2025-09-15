
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
int dp[200][200];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    //scanf("%d%d", &n, &k);
    string s1, s2;
    cin>>s1>>s2;
    n = (int)s1.size();
    m = (int)s2.size();
    int ans=n+m;
    for (int i = 0; i < m; ++i) {
      int cnt=0;
      for (int j = 0; j < n; ++j) {
        if (i+cnt >= m) break;
        if (s1[j] == s2[i+cnt]) {
          cnt++;
        }
      }
      ans = min(ans, n+i+m-(i+cnt));
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
