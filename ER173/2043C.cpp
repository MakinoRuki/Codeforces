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
int a[N];
pair<int,int> check(int l, int r) {
    int mn=0,mx=0;
    int sum=0;
    for (int i = l; i <= r; ++i) {
        sum += a[i];
        if (sum < 0) sum=0;
        mx=max(mx, sum);
    }
    sum=0;
    for (int i = l; i <= r; ++i) {
        sum += a[i];
        if (sum > 0) sum=0;
        mn=min(mn, sum);
    }
    return make_pair(mn, mx);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      scanf("%d", &n);
      int id=-1;
      for (int i = 1; i <= n; ++i) {
          scanf("%d", &a[i]);
          if (a[i] != -1 && a[i] != 1) id = i;
      }
      if (id < 0) {
          auto pr = check(1, n);
          int l=pr.first;
          int r=pr.second;
          printf("%d\n", r-l+1);
          for (int i = l; i <= r; ++i) {
              printf("%d ", i);
          }
          cout<<endl;
      } else {
          auto pr1 = check(1, id-1);
          auto pr2 = check(id+1, n);
          int lmn=0,lmx=0;
          int rmn=0,rmx=0;
          int sum=0;
          for (int i = id-1; i >= 1; --i) {
              sum += a[i];
              lmn=min(lmn, sum);
              lmx=max(lmx, sum);
          }
          sum=0;
          for (int i = id+1; i <= n; ++i) {
              sum += a[i];
              rmx=max(rmx, sum);
              rmn=min(rmn, sum);
          }
          set<ll> ss;
          ss.clear();
          for (int i = pr1.first; i <= pr1.second; ++i) {
              ss.insert(i);
          }
          for (int i = pr2.first; i <= pr2.second; ++i) {
              ss.insert(i);
          }
          for (int i = lmn+rmn; i <= rmx+lmx; ++i) {
              ss.insert(a[id]+(ll)i);
          }
          vector<ll> v(ss.begin(), ss.end());
          printf("%d\n", (int)v.size());
          for (int i = 0; i < v.size(); ++i) {
             printf("%lld ", v[i]);
          }
          cout<<endl;
      }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
