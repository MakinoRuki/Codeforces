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
#define M 500005
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q, p;
int l, r;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    map<int,int> mp;
    mp.clear();
    vector<int> ans;
    ans.clear();
    int res = n;
    for (int i = 1; i <= n; ++i) {
      mp[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
      if (mp.find(i) == mp.end()) {
        res = min(res, i);
      }
    }
    int cur = 1;
    while(cur <= n) {
      set<int> ss;
      ss.clear();
      int i;
      int tmp = 0;
      for (i = cur; i <= n; ++i) {
        ss.insert(a[i]);
        while(tmp<=n && ss.find(tmp) != ss.end()) {
          tmp++;
        }
        if (tmp == res) break;
      }
      ans.push_back(res);
      while(cur <= i) {
        mp[a[cur]]--;
        if (mp[a[cur]] == 0) {
          mp.erase(a[cur]);
          if (a[cur] < res) {
            res = a[cur];
          }
        }
        cur++;
      }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
