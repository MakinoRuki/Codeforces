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
#define N 500005
#define M 405
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    vector<pair<int,int>> v;
    v.clear();
    int ans=0;
    for (int i = 1; i <= n; ++i) {
        if (v.empty()) {
            v.push_back(make_pair(a[i], 1));
        } else if (a[i] == v.back().first) {
            v.back().second++;
        } else if (a[i] == v.back().first+1) {
            v.push_back(v.back());
            v.back().first = a[i];
            v.back().second++;
        } else {
            v.clear();
            v.push_back(make_pair(a[i], 1));
        }
        int sz = (int)v.size();
        if (sz <= k) {
            ans = max(ans, v.back().second);
        } else {
            ans = max(ans, v[sz-1].second - v[sz-1-k].second);
        }
    }
    int sz = (int)v.size();
        if (sz <= k) {
            ans = max(ans, v.back().second);
        } else {
            ans = max(ans, v[sz-1].second - v[sz-1-k].second);
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
