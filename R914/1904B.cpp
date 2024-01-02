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
vector<pair<int,int>> v;
int ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    v.clear();
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());
    vector<int> tmp;
    tmp.clear();
    ll tot=0LL;
    for (int i = 0; i < v.size(); ++i) {
      if (i == 0) {
        tmp.push_back(v[i].second);
        tot += v[i].first;
      } else {
        if (tot < v[i].first) {
          for (int j = 0; j < tmp.size(); ++j) {
            ans[tmp[j]] = i;
          }
          tmp.clear();
          tot += v[i].first;
          tmp.push_back(v[i].second);
        } else {
          tmp.push_back(v[i].second);
          tot += v[i].first;
        }
      }
    }
    if (!tmp.empty()) {
      for (int j = 0; j < tmp.size(); ++j) {
        ans[tmp[j]] = n;
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", ans[i]-1);
    }
    cout<<endl;
  }
  return 0;
}
