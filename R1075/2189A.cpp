
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
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h,l;
    scanf("%d%d%d", &n, &h, &l);
    for (int i= 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    int cnt1=0,cnt2=0;
    for (int i =1 ; i <= n; ++i) {
      if (a[i] <= max(h, l)) cnt2++;
      if (a[i] <= min(h, l)) cnt1++;
    }
    printf("%d\n", min(cnt1, cnt2/2));
  }
  return 0;
}

