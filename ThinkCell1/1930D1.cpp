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
#define N 600005
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
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    ll ans=0LL;
    for (int i= 0; i < n; ++i) {
      ll cur=0LL;
      int pre=0;
      int need=0;
      for (int j = i; j < n; ++j) {
        if (s[j] == '1') {
          if (j-1<i) {
            ans++;
            pre=0;
            need=1;
          } else {
            if (!pre) {
              if (need) {
                cur++;
                ans += cur;
                pre=1;
                need=0;
              } else {
                ans += cur+1;
                pre=0;
                need=1;
              }
            } else {
              pre=0;
              need=0;
              ans += cur;
            }
          }
        } else {
          if (need) {
            cur++;
            ans += cur;
            pre=1;
            need=0;
          } else {
            ans += cur;
            pre=0;
            need=0;
          }
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
