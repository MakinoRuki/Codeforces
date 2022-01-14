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
#define N 52
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, q, k;
int t;
int a[N];
int cnt[26];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; ++i) {
      cnt[s[i]-'a']++;
    }
    int on = 0;
    int tot=0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % 2) {
        on++;
      }
      tot += cnt[i]/2;
    }
    int q = tot/k;
    int r = tot%k;
    if (r > 0) {
      if (on >= k-r) {
        printf("%d\n", q*2+1);
      } else {
        if (r*2 + on >= k) {
          printf("%d\n", q*2+1);
        } else {
          printf("%d\n", q*2);
        }
      }
    } else {
      if (on >= k) {
        printf("%d\n", q*2+1);
      } else {
        printf("%d\n", q*2);
      }
    }
  }
  return 0;
}
