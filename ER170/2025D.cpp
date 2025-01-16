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
#define N 3000005
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int dp[M][M];
int main() {
  cin>>n>>m;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<vector<int>> v1, v2;
  v1.clear();
  v2.clear();
  for (int i= 1; i <= n; ++i) {
    if (a[i] == 0) {
        v1.push_back({});
        v2.push_back({});
    } else {
        if (a[i]>0) {
            if (v1.empty()) continue;
            v1.back().push_back(a[i]);
        } else {
            if (v2.empty()) continue;
            v2.back().push_back(-a[i]);
        }
    }
  }
  for (int i = 0; i < m; ++i) {
    sort(v1[i].begin(), v1[i].end());
    sort(v2[i].begin(), v2[i].end());
  }
  for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j]=-1;
        }
    }
    dp[0][0]=0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (dp[i][j]<0) continue;
           // cout<<"ij="<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            int j2=i-j;
            int n1=upper_bound(v1[i].begin(), v1[i].end(), j)-v1[i].begin();
            int n2=upper_bound(v2[i].begin(), v2[i].end(), j2)-v2[i].begin();
            int n11=upper_bound(v1[i].begin(), v1[i].end(), j+1)-v1[i].begin();
            int n22=upper_bound(v2[i].begin(), v2[i].end(), j2+1)-v2[i].begin();
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]+n22+n1);
            dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+n11+n2);
        }
    }
    int ans=0;
    for (int i = 0; i <= m; ++i) {
        ans=max(ans, dp[m][i]);
    }
    printf("%d\n", ans);
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
