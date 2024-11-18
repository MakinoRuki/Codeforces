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
#define N 500005
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
int p[3][N];
int ans[N][2];
int idx[N][3];
int cur[3];
vector<string> ss = {"q", "k", "j"};
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 0; i < 3; ++i) {
      for (int j = 1; j <= n; ++j) {
        scanf("%d", &p[i][j]);
      }
    }
    for (int i = 0; i < 3; ++i) {
      cur[i] = -1;
    }
    for (int i = 1; i <= n; ++i) {
      ans[i][0]=ans[i][1]=-1;
    }
    for (int i = n-1; i >= 1; --i) {
      for (int j = 0; j < 3; ++j) {
        if (p[j][i] > p[j][n]) {
          ans[i][0] = j;
          ans[i][1] = n;
        } else if (cur[j] > 0) {
          if (p[j][i] > p[j][cur[j]]) {
            ans[i][0] = j;
            ans[i][1] = cur[j];
          }
        }
      }
      if (ans[i][0] >= 0) {
        for (int j = 0; j < 3; ++j) {
          if (cur[j] < 0 || p[j][i] < p[j][cur[j]]) {
            cur[j] = i;
          }
        }
      }
    }
    if (ans[1][0] < 0) puts("NO");
    else {
      puts("YES");
    //  cout<<"ans="<<ans[3][0]<<" "<<ans[3][1]<<endl;
      vector<pair<int,int>> vv;
      vv.clear();
      int x = 1;
      while(x != n) {
        vv.push_back(make_pair(ans[x][0], ans[x][1]));
        x = ans[x][1];
      }
      printf("%d\n", (int)vv.size());
      for (int i = 0; i < vv.size(); ++i) {
        cout<<ss[vv[i].first]<<" "<<vv[i].second<<endl;
      }
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

