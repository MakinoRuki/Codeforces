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
#define N 200005
#define M 1002
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<int> s1, s2;
    s1.clear();
    s2.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      s1.insert(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      s2.insert(b[i]);
    }
    int sz1 = (int)s1.size();
    int sz2 = (int)s2.size();
    if (sz1 >= 2 && sz2 >= 2) {
      puts("YES");
    } else if (sz1 == 1 && sz2 >= 3) {
      puts("YES");
    } else if (sz2 == 1 && sz1 >= 3) {
      puts("YES");
    } else {
      puts("NO");
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
