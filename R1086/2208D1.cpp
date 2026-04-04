
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
int mat[M][M];
int ans[M][M];
int b[M][M];
int par[M];
int find(int x) {
  return x == par[x] ? x : par[x] = find(par[x]);
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
 //   int p;
  //  int x,y;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      par[i]=i;
      for (int j = 1; j <= n; ++j) {
        mat[i][j] = s[j-1]-'0';
        //b[i][j] = mat[i][j];
      }
    }
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        ans[i][j]=(i==j?1:0);
        b[i][j]=ans[i][j];
        if (i==j) continue;
        if (!mat[i][j]) continue;
        bool ok=true;
        for (int k =1; k <= n; ++k) {
          if (k == i || k == j) continue;
          if (mat[i][k] && mat[k][j]) {
            ok=false;
            break;
          }
        }
        if (ok) {
        //  cout<<"ij="<<i<<" "<<j<<endl;
          ans[i][j]=true;
          b[i][j]=ans[i][j];
          cnt++;
          int pi = find(i);
          int pj = find(j);
          if (pi != pj) par[pi] = pj;
        }
      }
    }
    for (int k = 1; k <= n; ++k) {
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
          b[i][j] |= b[i][k] & b[k][j];
        }
      }
    }
    bool ok=true;
    for (int i = 1; i <= n; ++i) {
      for (int j =1; j <= n; ++j) {
        if (b[i][j] != mat[i][j]) ok=false;
      }
    }
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      ss.insert(find(par[i]));
    }
    if (cnt != n-1 || !ok || (int)ss.size() != 1) {
      puts("No");
    } else {
      puts("Yes");
      for (int i =1; i <= n; ++i) {
        for (int j = 1;j <= n; ++j) {
          if (i==j) continue;
          if (ans[i][j]) printf("%d %d\n", i, j);
        }
      }
    }
  }
  return 0;
}

