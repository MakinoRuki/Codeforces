
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
#define N 1000005
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
int sum[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    map<int, int> mp;
    mp.clear();
    sum[0]=0;
    for (int i = 1; i <= n; ++i) {
      if (s[i-1] == 'a') sum[i]=sum[i-1]+1;
      else sum[i]=sum[i-1]-1;
    }
    if (sum[n] == 0) {
      puts("0");
      continue;
    }
    int ans=-1;
    mp[0]=0;
    for (int i = 1; i <= n; ++i) {
      int cur=sum[i];
      int pre=cur-sum[n];
      if (mp.find(pre) != mp.end()) {
        int dt = i-mp[pre];
        if (dt < n) {
          ans=(ans < 0 ? dt : min(ans, dt));
        }
      }
      mp[cur] = i;
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
