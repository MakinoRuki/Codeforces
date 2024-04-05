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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int, int> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      mp[a[i]]++;
    }
    if (mp.size() == 1) {
      puts("Yes");
    } else {
      if (mp.size() == 2) {
        int d1=(*mp.begin()).second;
        int d2=(*(++mp.begin())).second;
        if (min(d1,d2) == n/2 && max(d1,d2)==(n+1)/2) {
          puts("Yes");
        } else {
          puts("No");
        }
      } else {
        puts("No");
      }
    }
  }
  return 0;
}
