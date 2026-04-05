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
#include <unordered_set>
#define N 1000005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
set<int> segs[N];
int main() {
  cin>>n>>m;
  vector<int> as;
  as.clear();
  for (int i = 1; i*i <= n; ++i) {
    if (n%i==0) {
      as.push_back(i);
      if (n/i!=i && n/i!=n) {
        as.push_back(n/i);
      }
    }
  }
  sort(as.begin(), as.end());
  for (int i = 1; i <= m; ++i) {
    int a,b;
    scanf("%d%d",&a, &b);
    a--;
    b--;
    segs[a].insert(b);
    segs[b].insert(a);
  }
  bool found = false;
  for (int i = 0; i < as.size(); ++i) {
    int k = as[i];
    bool ok = true;
    for (int u = 0; u < n; ++u) {
      for (auto v : segs[u]) {
        int u2 = (u+k)%n;
        int v2 = (v+k)%n;
        if (segs[u2].find(v2) == segs[u2].end()) {
          ok = false;
          break;
        }
      }
    }
    if (ok) {
      found=true;
      break;
    }
  }
  if (found) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
