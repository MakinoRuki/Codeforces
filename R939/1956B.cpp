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
const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    int n2=0,n1=0;
    set<int> ss;
    ss.clear();
    for (int i =1; i <= n; ++i) {
      if (ss.find(a[i]) == ss.end()) {
        ss.insert(a[i]);
      } else {
        ss.erase(a[i]);
      }
    }
    n1 = (int)ss.size();
    n2 = (n-n1)/2;
    printf("%d\n", n2);
  }
  return 0;
}
