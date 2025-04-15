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
ll a[N];
int dp[M][M][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y,z;
    scanf("%d%d", &n, &m);
    vector<string> mp;
    mp.clear();
    for (int i = 1; i <= n; ++i) {
        string s;
        cin>>s;
        mp.push_back(s);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dp[i][j][0] = dp[i][j][1] =0;
        }
    }
    bool ok=true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mp[i][j] == '1') {
                if (i==0) dp[i][j][0]=1;
                if (j==0) dp[i][j][1]=1;
                if (i && j) {
                    if (dp[i-1][j][0]) dp[i][j][0]=1;
                    if (dp[i][j-1][1]) dp[i][j][1]=1;
                    if (!dp[i][j-1][1] && !dp[i-1][j][0]) {
                        ok=false;
                        break;
                    }
                } 
            }
        }
        if (!ok) break;
    }
    if (ok) puts("Yes");
    else puts("No");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
