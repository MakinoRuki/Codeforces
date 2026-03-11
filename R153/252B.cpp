#include <iostream>
#include <sstream>
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int b[N], c[N];
bool check() {
  bool ok1=true;
  bool ok2=true;
  for (int i = 1; i <= n; ++i) {
    if (b[i] != a[i]) {
      ok1=false;
    }
    if (c[i] != a[i]) {
      ok2=false;
    }
  }
  return (!ok1) && (!ok2);
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //   scanf("%d", &n);
  // }
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i]=a[i];
    c[i]=a[i];
  }
  sort(b+1, b+n+1);
  sort(c+1, c+n+1);
  int l=1,r=n;
  while(l<r) {
    swap(c[l], c[r]);
    l++;
    r--;
  }
  if (n == 1) {
    puts("-1");
    return 0;
  }
  if (b[1] == b[n]) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      if (a[i] != a[j]) {
        swap(a[i], a[j]);
        if (check()) {
          printf("%d %d\n", i, j);
          return 0;
        }
        swap(a[i], a[j]);
      }
    }
  }
  puts("-1");
  return 0;
}
 
