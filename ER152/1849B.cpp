#include <iostream>
#include <cstdio>
#include <stdio.h>
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
#include <cstring>
#define N 300005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q, p;
int t;
int a[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<int> v0;
    v0.clear();
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] % k == 0) {
        v0.push_back(i);
      } else {
        rk.push_back(make_pair(a[i]%k, i));
      }
    }
    sort(rk.begin(), rk.end(), [](const pair<int,int>& x, const pair<int,int>& y) {
      return (x.first == y.first ? x.second < y.second : x.first > y.first);
    });
    sort(v0.begin(), v0.end());
    for (int i = 0; i < rk.size(); ++i) {
      v0.push_back(rk[i].second);
    }
    for (int i = 0; i < v0.size(); ++i) {
      printf("%d", v0[i]);
      if (i < v0.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
