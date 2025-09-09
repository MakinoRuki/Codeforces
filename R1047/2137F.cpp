
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
int b[N];
//vector<int> v[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      if (a[i]== b[i]) {
        ans += (ll)i*(ll)(n-i+1);
      }
    }
    vector<int> v;
    v.clear();
    for (int i = 1; i <= n; ++i) {
      while(!v.empty() && a[v.back()] < a[i]) {
        v.pop_back();
      }
      if (!v.empty()) {
        ll id=v.back();
        if (b[i] < a[i]) {
          ans += id * (ll)(n-i+1);
        } else if (b[i] > a[i]) {
          int l = 0, r = (int)v.size();
          while(l<r) {
            int mid=(l+r+1)/2;
            if (a[v[mid-1]] >= b[i]) {
              l = mid;
            } else {
              r = mid-1;
            }
          }
          if (r > 0) {
            id = v[r-1];
            ans += id * (ll)(n-i+1);
          }
        }
      }
      v.push_back(i);
    }
    // v.clear();
    // for (int i = 1; i <= n; ++i) {
    //   while(!v.empty() && a[v.back()] < b[i]) {
    //     v.pop_back();
    //   }
    //   if (!v.empty()) {
    //     ll id = v.back();
    //     if (b[i]>a[i]) {
    //       ans += id*(ll)(n-i+1);
    //     }
    //   }
    //   v.push_back(i);
    // }
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
