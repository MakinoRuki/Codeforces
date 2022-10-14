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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int a[N];
int b[N];
//int l[N], r[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1, s2;
    cin>>s1>>s2;
    map<pair<int,int>, int> cnt;
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      int c1 = s1[i-1]-'a';
      int c2 = s2[n-i]-'a';
      cnt[make_pair(min(c1,c2), max(c1,c2))]++;
    }
    int c1 = 0, c2 = 0;
    for (auto itr : cnt) {
      if (itr.first.first != itr.first.second) {
        if (itr.second % 2) {
          c2++;
        }
      } else {
        if (itr.second % 2) {
          c1++;
        }
      }
    }
    if (n % 2) {
      if (c2 > 0 || c1 != 1) {
        puts("NO");
      } else {
        puts("YES");
      }
    } else {
      if (c1 > 0 || c2 > 0) {
        puts("NO");
      } else {
        puts("YES");
      }
    }
  }
  return 0;
}
