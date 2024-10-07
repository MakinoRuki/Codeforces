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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &q);
    vector<int> v;
    v.clear();
    for (int i = 1; i <= m; ++i) {
      int x;
      scanf("%d", &x);
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    while(q-->0) {
      int x;
      scanf("%d", &x);
      if (x <= v[0]) {
        printf("%d\n", v[0]-1);
      } else if (x >= v.back()) {
        printf("%d\n", n - v.back());
      } else {
       // int l = lower_bound(v.begin(), v.end(), x)-v.begin();
        int r = upper_bound(v.begin(), v.end(), x)-v.begin();
        int l = r-1;
       // cout<<l<<" "<<r<<" "<<v[l]<<" "<<v[r]<<endl;
        int dt = v[r] - v[l];
        printf("%d\n", dt/2);
      }
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

