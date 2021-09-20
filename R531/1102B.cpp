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
#define M 12
#define N 10000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
ll n, k;
int a[N];
int col[N];
int main() {
  cin>>n>>k;
  map<int, int> cnt;
  cnt.clear();
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    cnt[a[i]]++;
    col[i] = 0;
  }
  bool ok = true;
  for (auto itr : cnt) {
    if (itr.second > k) {
      ok=false;
      break;
    }
  }
  if (!ok) puts("NO");
  else {
    int cnt=0;
    for (int i = 1; i <= k; ++i) {
      set<int> ss;
      ss.clear();
      for (int j = 1; j <= n; ++j) {
        if (col[j] == 0) {
          if (n-cnt-1 >= k-i && ss.find(a[j]) == ss.end()) {
            col[j] = i;
            cnt++;
            ss.insert(a[j]);
          } else if (n-cnt-1<k-i) {
            break;
          }
        }
      }
    }
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      printf("%d", col[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
