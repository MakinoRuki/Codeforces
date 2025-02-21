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
#define M 1005
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
int la[N], ra[N];
bool check(int id1, int id2, int i, int j) {
  if (a[i]+a[j]>a[id1]-a[id2]) {
    return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    la[1] = 0;
    for (int i = 2; i <= n; ++i) {
      la[i] = i;
      if (i-1>1) {
        int id=la[i-1];
        if (a[id]-a[id-1] < a[i]-a[i-1]) {
          la[i] = id;
        }
      }
    }
    ra[n]=0;
    for (int i = n-1; i >= 1; --i) {
      ra[i] = i;
      if (i+1 < n) {
        int id=ra[i+1];
        if (a[id+1]-a[id] < a[i+1]-a[i]) {
          ra[i] = id;
        }
      }
    }
    vector<int> ans;
    ans.clear();
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i+1]) {
        if (i-1>=2) {
          if (check(la[i-1],la[i-1]-1,i,i+1)) {
            ans= {la[i-1], la[i-1]-1, i, i+1};
            break;
          }
        }
        if (i+2<n) {
          if (check(ra[i+2]+1, ra[i+2], i, i+1)) {
            ans = {ra[i+2]+1, ra[i+2], i, i+1};
            break;
          }
        }
        if (i-1>=1 && i+2<=n) {
          if (check(i+2, i-1, i, i+1)) {
            ans = {i+2, i-1, i, i+1};
            break;
          }
        }
      }
    }
    if (!ans.empty()) {
      printf("%d %d %d %d\n", a[ans[0]], a[ans[1]], a[ans[2]], a[ans[3]]);
    } else {
      puts("-1");
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
