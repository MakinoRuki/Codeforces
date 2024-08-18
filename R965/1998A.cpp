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
    int xc, yc;
    scanf("%d%d%d", &xc, &yc, &k);
    vector<pair<int,int>> v;
    v.clear();
    if (k%2) {
      v.push_back(make_pair(k*xc, k*yc));
      k /= 2;
    } else {
      if (xc == 0 && yc == 0) {
        v.push_back(make_pair(3, 3));
        v.push_back(make_pair(-3, -3));
      } else {
        v.push_back(make_pair(2*k*xc, 2*k*yc));
        v.push_back(make_pair(-k*xc, -k*yc));
      }
      k = (k-2)/2;
    }
    for (int i = 1; i <= k; ++i) {
      v.push_back(make_pair(1000000+i, 1000000+i));
      v.push_back(make_pair(-1000000-i, -1000000-i));
    }
    for (int i = 0; i < v.size(); ++i) {
      printf("%d %d\n", v[i].first, v[i].second);
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
