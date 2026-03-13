
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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
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
ll b[N];
ll c[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int l = 1, r=n;
    for (int i = n; i >= 1; --i) {
      if (i&1) a[i]=r--;
      else a[i]=l++;
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d ", a[i]);
    }
    cout<<endl;
  }

  // cin>>n;
  // for (int i= 1; i <= n; ++i) {
  //   a[i]=i;
  // }
  // do {
  //   if (check2()) {
  //     for (int i = 1; i <= n; ++i) {
  //       printf("%d ", a[i]);
  //     }
  //     cout<<endl;
  //   }
  // } while(next_permutation(a+1, a+n+1));
  return 0;
}

