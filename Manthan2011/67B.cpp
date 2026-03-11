/* 对于i，把大于等于i+k的数字跟它连边，然后拓扑排序。b[i]就是i的degree限制。 */

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
#define N 3000005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod1 = 1000000007LL;
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
int a[M];
int mat[M][M];
int deg[M];
bool vis[M];
int ans[M];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
    
  // }
  cin>>n>>k;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    vis[i]=false;
    deg[i]=0;
  }
  int cnt=0;
  memset(mat, 0, sizeof(mat));
  for (int i = 1; i <= n; ++i) {
    for (int j = i+k; j <= n; ++j) {
      mat[j][i]=1;
    }
  }
  set<int> ss;
  ss.clear();
  for (int i =1; i <= n; ++i) {
    if (a[i] == 0) {
      ss.insert(i);
    }
  }
  while(!ss.empty()) {
    auto x = *ss.begin();
    ss.erase(x);
    vector<int> tmp;
    tmp.clear();
    ans[++cnt] = x;
    vis[x] = true;
    for (int i = 1; i <= n; ++i) {
      if (mat[x][i] && deg[i] < a[i]) {
        deg[i]++;
        if (deg[i] == a[i]) {
          tmp.push_back(i);
        }
      }
    }
    for (auto z : tmp) {
      if (!vis[z]) ss.insert(z);
    }
  }
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) ans[++cnt] = i;
  }
  for (int i =1; i <= n; ++i) {
    printf("%d ", ans[i]);
  }
  cout<<endl;
  return 0;
}
 
