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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<int> v;
    v.clear();
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      v.push_back(b[i]);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int cur=1;
    int id=1;
    for (int i = 0; i < v.size(); ++i) {
      while(id <= n && a[id] > v[i]) {
        b[cur++] = a[id++];
      }
      b[cur++] = v[i];
    }
    while(id <= n) {
      b[cur++] = a[id++];
    }
    for (int i = 1; i <= n+m; ++i) {
      printf("%d ", b[i]);
    }
    cout<<endl;
  }
  return 0;
}
