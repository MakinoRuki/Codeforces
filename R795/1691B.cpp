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
#define N 100005
#define M 3000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q, p;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int,int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    bool ok = true;
    for (auto itr : cnt) {
      if (itr.second == 1) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("-1");
      continue;
    }
    vector<int> ids;
    ids.clear();
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      if (i == 1 || a[i] == a[i-1]) {
        ids.push_back(i);
      } else {
        ans.push_back(ids.back());
        for (int j = 0; j < ids.size()-1; ++j) {
          ans.push_back(ids[j]);
        }
        ids.clear();
        ids.push_back(i);
      }
    }
    if (!ids.empty()) {
      ans.push_back(ids.back());
      for (int j = 0; j < ids.size()-1; ++j) {
        ans.push_back(ids[j]);
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
