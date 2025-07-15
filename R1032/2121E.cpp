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
int a[N];
int b[N];
int dp[N][2][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l,r;
    scanf("%d%d", &l, &r);
    vector<int> dl, dr;
    dl.clear();
    dr.clear();
    while(l) {
        dl.push_back(l%10);
        l/=10;
    }
    while(r) {
        dr.push_back(r%10);
        r/=10;
    }
    reverse(dl.begin(), dl.end());
    reverse(dr.begin(), dr.end());
    int sz=(int)dl.size();
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                dp[i][j][k]=inf;
            }
        }
    }
    for (int d = 1; d <= 9; ++d) {
        int ll=0, rr=0;
        if (d > dr[0] || d < dl[0]) continue;
        if (d > dl[0]) ll=1;
        if (d < dr[0]) rr=1;
        int cnt=0;
        if (d == dl[0])cnt++;
        if (d == dr[0])cnt++;
        dp[1][ll][rr] = min(dp[1][ll][rr], cnt);
    }
    for (int i = 1; i < sz; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (dp[i][j][k]>=inf) continue;
                for (int d = 0; d <= 9; ++d) {
                    int nll=j, nrr=k;
                    if (j == 0 && d < dl[i]) continue;
                    if (k == 0 && d > dr[i]) continue;
                    if (j == 0 && d > dl[i]) nll=1;
                    if (k == 0 && d < dr[i]) nrr=1;
                    int cnt=0;
                    if (d == dl[i]) cnt++;
                    if (d == dr[i]) cnt++;
                    dp[i+1][nll][nrr] = min(dp[i+1][nll][nrr], dp[i][j][k]+cnt);
                }
            }
        }
    }
    int ans=inf;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            ans=min(ans, dp[sz][i][j]);
        }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
