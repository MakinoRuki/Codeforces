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
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      cnt[a[i]]++;
    }
    if (n % 2) {
      puts("NO");
    } else {
      bool ok = true;
      int j = 1;
      sort(a+1, a+n+1);
      for (int i = 0; i < n; i += 2) {
        b[i] = a[j];
        j++;
      }
      for (int i = 1; i < n; i += 2) {
        b[i] = a[j];
        j++;
      }
      for (int i = 0; i < n; ++i) {
        int j = (i-1+n)%n;
        int j2 = (i+1) % n;
        if (b[i] > b[j] && b[i] > b[j2]) {
          continue;
        }
        if (b[i] < b[j] && b[i] < b[j2]) {
          continue;
        }
        ok=false;
        break;
      }
      if (!ok) puts("NO");
      else {
        puts("YES");
        for (int i = 0; i < n; ++i) {
          printf("%d", b[i]);
          if (i < n-1) cout<<" ";
          else cout<<endl;
        }
      }
    }
  }
  return 0;
}
