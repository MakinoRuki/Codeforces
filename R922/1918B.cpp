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
int b[N];
int bit[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> v;
    v.clear();
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i =1; i <= n; ++i) {
      scanf("%d", &b[i]);
      v.push_back(make_pair(a[i], b[i]));
    }
    sort(v.begin(), v.end());
    for (int i  =0; i < v.size(); ++i) {
      printf("%d ", v[i].first);
    }
    cout<<endl;
    for (int i = 0; i < v.size(); ++i) {
      printf("%d ", v[i].second);
    }
    cout<<endl;
  }
  return 0;
}
