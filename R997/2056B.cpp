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
#define N 200005
#define M 1002
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
int deg[M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      deg[i]=0;
    }
    string s;
    for (int i = 1; i <= n; ++i) {
      cin>>s;
      for (int j = 1; j <= n; ++j) {
        if (s[j-1] == '1') {
          a[i][j]=1;
          if (i < j) deg[j]++;
        } else {
          a[i][j]=0;
          if (i < j) deg[i]++;
        }
      }
    }
    queue<int> q;
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      if (deg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
      auto u = q.front();
      q.pop();
      ans.push_back(u);
      for (int i = u+1; i <= n; ++i) {
        if (a[u][i]) {
          deg[i]--;
          if (deg[i] == 0) q.push(i);
        }
      }
      for (int i = 1; i < u; ++i) {
        if (!a[u][i]) {
          deg[i]--;
          if (deg[i] == 0) q.push(i);
        }
      }
    }
    for (auto x : ans) {
      printf("%d ", x);
    }
    cout<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
