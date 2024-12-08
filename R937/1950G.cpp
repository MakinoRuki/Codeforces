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
#define M 16
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
bool b[M][M];
bool dp[(1<<M)][M];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<string,string>> ss;
    ss.clear();
    for (int i = 0;i < n; ++i) {
        string s1, s2;
        cin>>s1>>s2;
        ss.push_back(make_pair(s1,s2));
        for (int j = 0; j < n; ++j) {
            b[i][j]=false;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i != j) {
                if (ss[i].first==ss[j].first || ss[i].second==ss[j].second) {
                    b[i][j] = true;
                }
            }
        }
    }
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            dp[i][j]=false;
        }
    }
    for (int i = 0; i < n; ++i) {
        dp[(1<<i)][i] = true;
    }
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j]) {
                for (int k = 0; k < n; ++k) {
                    if ((1<<k)&i) continue;
                    if (!b[j][k]) continue;
                    dp[i^(1<<k)][k] = true;
                }
            }
        }
    }
    int ans=n;
    for (int i = 0; i < (1<<n); ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j]) {
               // cout<<"ij="<<i<<" "<<j<<endl;
                int x=i;
                int cnt=0;
                while(x) {
                    if (x&1) cnt++;
                    x/=2;
                }
                ans=min(ans, n-cnt);
            }
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

