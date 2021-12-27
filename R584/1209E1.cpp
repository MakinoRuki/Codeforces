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
#define N 200
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int l, r;
int t;
string s;
int mat[5][N];
int col[N];
void dfs(int cur, vector<pair<int,int>>& rk, vector<vector<int>>& rx, int& ans) {
  if (cur >= min(n, (int)rk.size())) {
    int sum=0;
   // cout<<"x="<<endl;
    for (int i = 0; i < n; ++i) {
      int mx=0;
      for (int j = 0; j < min(n, (int)rk.size()); ++j) {
        mx=max(mx, rx[i][j]);
    //    cout<<rx[i][j]<<" ";
      }
    //  cout<<endl;
      sum += mx;
    }
    ans=max(ans, sum);
    return;
  }
  int c = rk[cur].second;
//  cout<<"c="<<cur<<" "<<rk[cur].second<<endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int j2 = (j+i) % n;
      rx[j2][cur] = mat[j+1][c];
    //  cout<<"x="<<j2<<" "<<cur<<" "<<j<<" "<<c<<" "<<mat[j+1][c]<<endl;
    }
    dfs(cur+1, rk, rx, ans);
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        scanf("%d", &mat[i][j]);
      }
    }
    vector<pair<int,int>> rk;
    rk.clear();
    for (int j = 1; j <= m; ++j) {
      int mx = mat[1][j];
      for (int i = 2; i <= n; ++i) {
        mx = max(mx, mat[i][j]);
      }
      rk.push_back(make_pair(mx, j));
    }
    sort(rk.begin(), rk.end());
    reverse(rk.begin(), rk.end());
    vector<vector<int>> rx(n, vector<int>(m,0));
    int ans=0;
    dfs(0, rk, rx, ans);
    cout<<ans<<endl;
  }
  return 0;
}
