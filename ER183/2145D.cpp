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
#define M 40
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
bool dp[M][M*M];
vector<int> ans;
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    ans.clear();
    k = n*(n-1)/2-k;
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n*n; ++j) {
            dp[i][j] = 0;
        }
    }
    dp[0][0]=true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i*i; ++j) {
            if (dp[i][j]) {
                for (int i2 = 1; i2 + i <= n; ++i2) {
                    int dt=i2*(i2-1)/2;
                    dp[i+i2][j+dt] = true;
                }
            }
        }
    }
    int cur=n;
    if (dp[n][k]) {
        int cn=n, ck=k;
        while(cn) {
            int i;
            for (i = 1; i <= cn; ++i) {
                if (dp[cn-i][ck-i*(i-1)/2]) {
                    for (int j = cn-i+1; j <= cn; ++j) {
                        ans.push_back(j);
                    }
                    cn -= i;
                    ck -= i*(i-1)/2;
                    break;
                }
            }
        }
        while(cn) {
            ans.push_back(cn);
            cn--;
        }
        for (auto x : ans) {
            printf("%d ", x);
        }
        cout<<endl;
    } else {
        puts("0");
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
