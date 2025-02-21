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
#define N 600005
#define M 750
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
int a[M][M];
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &a[i][j]);
      }
    }
    for (int i = 1; i <= n*m; ++i) {
      cnt[i] = -1;
    }
    for (int i= 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        int c = a[i][j];
        if (cnt[c] < 0) cnt[c] = 0;
        if ((i-1>=1)&&(a[i][j]==a[i-1][j])) cnt[c]=1;
        if ((j-1>=1)&&(a[i][j]==a[i][j-1])) cnt[c]=1;
        if ((i+1<=n)&&(a[i][j]==a[i+1][j])) cnt[c]=1;
        if ((j+1<=m)&&(a[i][j]==a[i][j+1])) cnt[c]=1;
      }
    }
    int n1=0,n2=0;
    for (int i = 1; i <= n*m; ++i) {
      if (cnt[i]==0)n1++;
      else if(cnt[i]==1)n2++;
    }
    if (n2 <= 0) {
      printf("%d\n", n1-1);
    } else {
      printf("%d\n", n1+(n2-1)*2);
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
