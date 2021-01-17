#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int x,y,d;
unordered_map<int, vector<int>> sks;
int main() {
  cin>>n>>m;
  sks.clear();
  for (int i = 1; i <= n; ++i) {
    int s, r;
    scanf("%d%d", &s, &r);
    sks[s].push_back(r);
  }

  for (auto& itr : sks) {
    auto& v = itr.second;
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (int i = 1; i < v.size(); ++i) {
      v[i] += v[i-1];
    }
  }
  int ans = 0;
  int cur=1;
  while(!sks.empty()) {
    int tot=0;
    auto itr = sks.begin();
    while(itr != sks.end()) {
      if (itr->second[cur - 1] >= 0) {
        tot += itr->second[cur-1];
      }
      if (itr->second.size() == cur) {
        sks.erase(itr++);
      } else {
        ++itr;
      }
    }
    cur++;
   // cout<<sks.size()<<endl;
    ans = max(ans, tot);
  }
  printf("%d\n", ans);
  return 0;
}
