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
#define N 300005
#define M 2010
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
ll dp[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      string s;
      cin>>s;
      vector<int> id0,id1;
      id0.clear();
      id1.clear();
      for (int i = 0; i < n; ++i) {
          if (s[i] == '0') {
              id0.push_back(i+1);
          } else {
              id1.push_back(i+1);
          }
      }
      ll ans=0LL;
      int cur=id1.size()-1;
      if (id0.size() >0) {
          int l = id0.size()-1;
          while(cur >= 0) {
              while(l>=0 && id0[l]>id1[cur]) {
                  l--;
              }
              if (l>=0) {
                  ans += id1[cur];
                  l--;
                  cur--;
              } else {
                  break;
              }
          }
      }
      int l = 0;
      while(l < cur) {
          ans += id1[cur];
          l++;
          cur--;
      }
      ans = (ll)n*(ll)(n+1)/2LL-ans;
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
