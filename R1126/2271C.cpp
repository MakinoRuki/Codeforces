
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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
const int base = 337;

int n, t;
int a[N];

int main() {
  scanf("%d", &t);

  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);

    // 对于2^k <= n < 2^(k+1)，最大美丽值都是2^(k+1)-1，
    // 达到它的最大长度都是2^(k+2)-1。
    // 令m=2^k，则最大美丽值为2m-1，最大长度为4m-1。
    int m = 1;
    a[1] = 1;

    // 在2^k <= n < 2^(k+1)时，重复序列的构造方法是：
    // 前一个周期复制两遍，再把最后一个数乘2。
    // n=1：     [1]
    // n=2~3：   [1,2]
    // n=4~7：   [1,2,1,4]
    // n=8~15：  [1,2,1,4,1,2,1,8]
    while (m * 2 <= n) {
      for (int i = 1; i <= m; ++i) {
        a[m + i] = a[i];
      }

      m *= 2;
      a[m] *= 2;
    }

    int k = 4 * m - 1;
    printf("%d\n", k);

    // 重复周期，截取前4m-1个数。
    // 包含空前缀的4m个前缀异或值中，0到2m-1各出现两次。
    // 因此f(a)=2m，美丽值=(4m-1)-2m=2m-1。
    for (int i = 1; i <= k; ++i) {
      printf("%d%c", a[(i - 1) % m + 1], " \n"[i == k]);
    }
  }

  return 0;
}
