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
#define N 600005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int dpmx[2][N];
int dpmn[2][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      dpmx[0][i] = 0;
      dpmx[1][i] = 0;
      dpmn[0][i] = 0;
      dpmn[1][i] = 0;
    }
    int cur = 1;
    dpmx[0][1] = 1;
    dpmx[1][1] = 1;
    for (int i = 1; i <= n; ++i) {
      string s;
      cin>>s;
      if (s[0] == '+') {
        int v,x;
        scanf("%d%d", &v, &x);
        ++cur;
        dpmx[0][cur] = max(dpmx[0][cur], dpmx[0][v] + x);
        dpmx[1][cur] = max(dpmx[1][v], dpmx[0][cur]);
        dpmn[0][cur] = min(dpmn[0][cur], dpmn[0][v] + x);
        dpmn[1][cur] = min(dpmn[1][v], dpmn[0][cur]);
       // cout<<"cur="<<cur<<" "<<dpmx[1][cur]<<" "<<dpmn[1][cur]<<endl;
      } else {
        int u,v,k;
        scanf("%d%d%d", &u, &v, &k);
        if (k >= dpmn[1][v] && k <= dpmx[1][v]) {
          puts("YES");
        } else {
          puts("NO");
        }
      }
    }
  }
  return 0;
}
