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
#define N 500005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<pair<int,int>> ss;
    ss.clear();
    int len = 0;
    ll res=1LL;
    for (int i = 1; i <= n; ++i) {
      ss.insert(make_pair(a[i], i));
      auto itr = *ss.begin();
      if (itr.first >= len+1) {
        len++;
      } else {
        ss.erase(itr);
      }
      printf("%d", len);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
