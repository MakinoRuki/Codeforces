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
#define N 305
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
int n,k;
int rs[N], cs[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    vector<string> ans(n, string(n, '0'));
    for (int i = 0; i < n; ++i) {
      int x = 0, y = i;
      for (int j = 0; j < n; ++j) {
        if (!k) break;
        ans[x][y] = '1';
        x = (x+1)%n;
        y = (y+1)%n;
        k--;
      }
    }
    int maxr = -inf;
    int minr = inf;
    int maxc = -inf;
    int minc = inf;
    for (int i = 0; i < n; ++i) {
      int sum=0;
      for (int j = 0; j < n; ++j) {
        if (ans[i][j]=='1') sum++;
      }
      maxr = max(maxr, sum);
      minr = min(minr, sum);
      sum=0;
      for (int j = 0; j < n; ++j) {
        if (ans[j][i]=='1') sum++;
      }
      maxc = max(maxc, sum);
      minc = min(minc, sum);
    }
    int tot=(maxr-minr)*(maxr-minr)+(maxc-minc)*(maxc-minc);
    cout<<tot<<endl;
    for (int i = 0; i < n; ++i) {
      cout<<ans[i]<<endl;
    }
  }
  return 0;
}
