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
#define N 100
#define M 80
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, q;
int k;
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
    int sz = (int)cnt.size();
    if (sz == 1) {
      puts("NO");
    } else {
      auto itr = cnt.rbegin();
      if (itr->second == 1) {
        puts("YES");
        for (int i = n; i >= 1; --i) {
          printf("%d", a[i]);
          if (i > 1) cout<<" ";
          else cout<<endl;
        }
      } else {
        puts("YES");
        printf("%d ", a[n]);
        printf("%d", a[1]);
        for (int i = n-1; i >= 2; --i) {
          printf(" %d", a[i]);
        }
        cout<<endl;
      }
    }
  }
  return 0;
}
