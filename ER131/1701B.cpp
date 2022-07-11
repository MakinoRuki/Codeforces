#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define eps 1e-8
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> ss;
    ss.clear();
    int i = 1;
    for (int x = 1; x <= n; ++x) {
      if (ss.find(x) == ss.end()) {
        int cur = x;
        while(cur <= n) {
          ss.insert(cur);
          a[i++] = cur;
          cur = cur * 2;
        }
      }
    }
    puts("2");
    for (int j = 1; j <= n; ++j) {
      printf("%d", a[j]);
      if (j < n) cout<<" ";
      else cout<<endl;
    }
  }
  
  return 0;
}
