
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
#include <stack>
#include <bitset>
#include <chrono>
#define N 500005
#define M 50
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int b[N];
int lmx[N], lmn[N];
int rmx[N], rmn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int id0=-1,id1=-1;
    for (int i =1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] == 1) id0=i;
      if (a[i] == n) id1=i;
    }
    if (id0 < id1) {
      puts("Yes");
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      lmx[i]=a[i];
      lmn[i]=a[i];
      if (i>1) {
        lmx[i]=max(lmx[i-1], a[i]);
        lmn[i]=min(lmn[i-1],a[i]);
      }
    }
    for (int i =n; i >= 1; --i) {
      rmx[i]=a[i];
      rmn[i]=a[i];
      if (i+1<=n) {
        rmx[i]=max(rmx[i+1],a[i]);
        rmn[i]=min(rmn[i+1], a[i]);
      }
    }
    bool found=false;
    for (int i = 1; i < n; ++i) {
      if (lmx[i] < rmn[i+1] || lmn[i] > rmx[i+1]) {
        found=true;
        break;
      }
    }
    if (found) puts("No");
    else puts("Yes");
  }
  return 0;
}
