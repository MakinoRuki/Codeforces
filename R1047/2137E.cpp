
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
int cnt[N];
//vector<int> v[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      b[i]=a[i];
    }
    sort(b+1, b+n+1);
    int mex=0;
    for (int i = 1; i <= n; ++i) {
      if (b[i] == mex) {
        mex++;
      }
    }
    for (int i = 0; i <= n; ++i) {
      cnt[i]=0;
    }
    int num=0;
    int id=-1;
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]]++;
      if (a[i]>mex) num++;
    }
    for (int i = 0; i < mex; ++i) {
      if (cnt[i] > 1) {
        id=i;
        break;
      }
    }
    if (id < 0) {
      for (int i = 1; i <= n; ++i) {
        if (a[i] > mex) {
          if (k&1) a[i]=mex;
          else {
            if (num>1) a[i]=mex+1;
            else a[i]=mex;
          }
        }
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (a[i] >= id) {
          if (a[i]>mex || cnt[a[i]]>1) {
            a[i]=mex;
          }
          int k2=k-1;
          if (k2) {
            if (k2&1) a[i]=id;
            else a[i]=id+1;
          }
        }
      }
    }
    ll ans=0LL;
    for (int i = 1; i <= n; ++i) {
      ans += a[i];
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
