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
#define N 500005
#define M 15
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n == 1) {
      puts("1");
    } else if (n == 2) {
      printf("1 2\n");
    } else {
      int cur=4;
      for (int i = 1; i <= n; ++i) {
        if (i == 1) {
          printf("2");
        } else if (i == (n+1)/2) {
          printf("1");
        } else if (i == n) {
          printf("3");
        } else {
          printf("%d", cur++);
        }
        cout<<" ";
      }
      cout<<endl;
    }
  }
  return 0;
}
