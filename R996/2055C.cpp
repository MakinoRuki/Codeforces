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
ll a[M][M];
ll b[M][M];
void calc(int cx, int cy, int cur, ll x) {
    ll sum1=0;
    ll sum0=0;
    if (cur == 0) {
        for (int j = 0; j < m; ++j) {
            if (j != cy) {
                sum0 += a[cx][j];
                sum1 += b[cx][j];
            }
        }
    } else {
        for (int i = 0; i < n; ++i) {
            if (i != cx) {
                sum0 += a[i][cy];
                sum1 += b[i][cy];
            }
        }
    }
    a[cx][cy] = x-sum0;
    b[cx][cy] = 1-sum1;
}
ll calcz(int x) {
    ll sa0=0,sb0=0;
    ll sa1=0,sb1=0;
    for (int j = 0; j < m-1; ++j) {
        sa0 += a[n-1][j];
        sb0 += b[n-1][j];
    }
    for (int i = 0; i < n-1; ++i) {
        sa1 += a[i][m-1];
        sb1 += b[i][m-1];
    }
    if (sb0 > sb1) {
        sb0 -= sb1;
        sa1 -= sa0;
        return sa1/sb0;
    } else if (sb0 == sb1) {
        return 0;
    } else {
        sb1 -= sb0;
        sa0 -= sa1;
        return sa0/sb1;
    }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    string s;
    cin>>s;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%lld", &a[i][j]);
            b[i][j]=0;
        }
    }
    int cur = -1;
    a[0][0]=0;
    b[0][0]=1;
    ll x=0;
    if (s[0] == 'D') {
        cur=0;
        for (int j = 0; j < m; ++j) {
            x += a[0][j];
        }
    } else {
        cur=1;
        for (int i = 0; i < n; ++i) {
            x += a[i][0];
        }
    }
    int cx=0,cy=0;
    ll z=0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'D') cx++;
        else cy++;
        if (i==(int)s.size()-1) {
            calc(cx, cy, cur, x);
            z = calcz(x);
        } else {
            if (s[i]==s[i+1]) {
                calc(cx, cy, cur, x);
            } else {
                cur = !cur;
                calc(cx, cy, cur, x);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%lld ", b[i][j]*z+a[i][j]);
        }
        cout<<endl;
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
