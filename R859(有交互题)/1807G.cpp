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
#define N 200005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
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
    sort(a+1, a+n+1);
    if (a[1] != 1) {
        puts("NO");
        continue;
    }
    ll sum=1LL;
    int i;
    for (i = 2; i <= n; ++i) {
        if (a[i] > sum) {
            break;
        }
        sum += a[i];
    }
    if (i <= n) {
        puts("NO");
    } else {
        puts("YES");
    }
  }
  return 0;
}
