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
#define M 52
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, h;
int k;
int q, p;
int a[N];
int b[N];
int main() {
  cin>>k>>n;
  for (int i = 1; i <= k; ++i) {
    scanf("%d", &a[i]);
    if (i > 1) a[i] += a[i-1];
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &b[i]);
  }
  int cnt=0;
  set<int> ans;
  ans.clear();
  for (int i = 1; i <= k; ++i) {
    int sc = b[1] - a[i];
    set<int> ss;
    ss.clear();
    for (int j = 1; j <= n; ++j) {
      ss.insert(b[j]);
    }
    for (int j = 1; j <= k; ++j) {
      if (ss.find(sc + a[j]) == ss.end()) {
        continue;
      }
     // if (sc==10) cout<<"j="<<j<<" "<<sc+a[j]<<endl;
      ss.erase(sc + a[j]);
    }
    if (!ss.empty()) {
      continue;
    }
  //  cout<<"sc="<<sc<<endl;
    ans.insert(sc);
  }
  cout<<(int)ans.size()<<endl;
  return 0;
}
