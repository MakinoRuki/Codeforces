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
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
ll a[N];
int main() {
  cin>>t;
//  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1>>s2;
    vector<pair<int,int>> v1, v2;
    v1.clear();
    v2.clear();
    for (int i = 0; i < n; ++i) {
      if (s1[i] == 'a' || s1[i] == 'c') {
        v1.push_back(make_pair(s1[i]-'a', i));
      }
      if (s2[i] == 'a' || s2[i] == 'c') {
        v2.push_back(make_pair(s2[i]-'a', i));
      }
    }
    if (v1.size() != v2.size()) {
      puts("NO");
      continue;
    }
    bool ok=true;
    for (int i = 0; i < v1.size(); ++i) {
      if (v1[i].first != v2[i].first) {
        ok=false;
        break;
      }
      if (v1[i].first == 0) {
        if (v1[i].second > v2[i].second) {
          ok=false;
          break;
        }
      } else {
        if (v1[i].second < v2[i].second) {
          ok=false;
          break;
        }
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
