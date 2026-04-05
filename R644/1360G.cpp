
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
#define N 200005
#define M 100
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
int b[N];
int mt[M][M];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int r,c;
    scanf("%d%d%d%d", &n, &m, &r, &c);
    if (r*n != c*m) {
      puts("NO");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0;j < m; ++j) {
        mt[i][j]=0;
      }
    }
    int cur=0;
    for (int i = 0; i < n; ++i) {
      for (int j = cur; j < cur + r; ++j) {
        mt[i][j%m]=1;
      }
      cur += r;
    }
    puts("YES");
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d", mt[i][j]);
      }
      cout<<endl;
    }
  }
  return 0;
}
