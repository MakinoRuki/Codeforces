
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
#define N 2000005
#define M 505
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
int p[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n == 1) {
      puts("1");
      puts("1");
    } else if (n == 2) {
      puts("2");
      printf("1 2\n");
    } else if (n == 3) {
      puts("2");
      printf("1 2 2\n");
    } else if (n == 4) {
      puts("3");
      printf("1 2 2 3\n");
    } else if (n == 5) {
      puts("3");
      printf("1 2 2 3 3\n");
    } else {
      // 根据四色定理，n>=6至少要4种颜色染色。如果2个数模4同余那么XOR之后必是大于2的偶数所以必不是素数，所以可以同色。
      puts("4");
      for (int i = 1; i <= n; ++i) {
        if (i % 4) printf("%d ", i%4);
        else printf("4 ");
      }
      cout<<endl;
    }
  }
  return 0;
}

