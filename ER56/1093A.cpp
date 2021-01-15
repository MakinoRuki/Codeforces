#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 2000005
#define N 2005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d", &x);
    int q = x/7;
    int r = x%7;
    if (r == 0) {
      cout<<q<<endl;
    } else {
      cout<<q+1<<endl;
    }
  }
  return 0;
}
