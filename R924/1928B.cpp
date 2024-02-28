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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ss.insert(a[i]);
    }
    vector<int> v(ss.begin(), ss.end());
    int ans=0;
    int r=0;
    for (int i = 0; i < v.size(); ++i) {
        while(r < v.size() && v[r] - v[i] <= n-1) {
            r++;
        }
        ans=max(ans, r-i);
    }
    printf("%d\n", ans);
  }
  return 0;
}

