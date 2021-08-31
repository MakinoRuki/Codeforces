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
#define N 1005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m;
int t;
int a[N];
int main() {
 cin>>t;
 for (int cas=1; cas<=t; ++cas) {
   scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
  // for (int i = 1; i <= 1000; ++i) {
  //   a[i] = i;
  // }
  // n=1000;
  // int r = 0;
  // do {
  //   r++;
  //   if (r > 10) break;
  //   if (r == 2) {
  //   for (int i =1; i <=1000; ++i) {
  //     cout<<a[i]<<" ";
  //   }
  //   cout<<endl;
  //   }
    int ans = 0;
    bool pre=false,now=false;
    int cnt=0;
    while(true) {
      now=false;
      cnt++;
      if (cnt%2) {
        for (int i = 1; i <= n; i += 2) {
          if (i+1<=n && a[i] >a[i+1]) {
            swap(a[i], a[i+1]);
            now=true;
          }
        }
      } else {
        for (int i = 2; i <= n; i += 2) {
          if (i+1 <= n && a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
            now=true;
          }
        }
      }
      if (cnt >= 2 && !now && !pre) {
        ans--;
        break;
      } else {
        ans++;
        pre=now;
      }
    }
    printf("%d\n", ans);
//  } while(next_permutation(a+1, a+1001));
  }
  return 0;
}
