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
#define N 1000005
#define M 6000000
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
int dp[N];
int nxt[N][30];
int main() {
 // cin>>t;
//  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < 26; ++j) {
            nxt[i][j] = -1;
        }
    }
    for (int i = 0; i <= n; ++i) {
        dp[i] = 0;
    }
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < k; ++j) {
            nxt[i][j] = nxt[i+1][j];
            if (s[i] - 'a' == j) nxt[i][j] = i;
        }
        int mx=-1;
        bool ok = true;
        for (int j = 0; j < k; ++j) {
            if (nxt[i][j] < 0) {
                ok=false;
                break;
            }
            mx = max(mx, nxt[i][j]);
        }
        if (ok) {
            dp[i] = dp[mx+1] + 1;
        }
    }
    scanf("%d", &q);
    while(q-->0) {
        string s2;
        cin>>s2;
        int cur=0;
        int sz=(int)s2.size();
        int i;
        for (i = 0; i < sz; ++i) {
            int c = s2[i]-'a';
            cur = nxt[cur][c];
            if (cur < 0) break;
            cur++;
        }
        if (i < sz) {
            puts("0");
        } else {
            printf("%d\n", dp[cur]+1);
        }
    }
 // }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
