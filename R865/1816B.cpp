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
#define N 300005
#define M 1502
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int ans[3][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int cur=1;
    for (int i = 1; i <= n; i+=2) {
        if (i!=n) ans[2][i]=cur++;
        if (i+1<=n) ans[1][i+1] = cur++;
    }
    for (int i = 2; i <= n; i += 2) {
        if (i!=n) ans[2][i] = cur++;
        if (i+1<=n) ans[1][i+1] = cur++;
    }
    ans[1][1] = cur++;
    ans[2][n] = cur++;
    for (int i = 1; i <= 2; ++i) {
        for (int j= 1; j <= n; ++j) {
            printf("%d ", ans[i][j]);
        }
        cout<<endl;
    }
  }
  return 0;
}

