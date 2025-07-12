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
#define N 500005
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
ll ans[N];
int getgcd(int x, int y) {
    return y == 0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &m, &q);
    a[0]=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    vector<int> ps;
    ps.clear();
    for (int i = 1; i * i <= m; ++i) {
        if ((m%i)==0) {
            ps.push_back(i);
            ans[i]=0;
            if (i != m/i) {
                ps.push_back(m/i);
                ans[m/i]=0;
            }
        }
    }
    for (auto p : ps) {
        ans[p] += a[1]%p;
        for (int i = 2; i <= n; ++i) {
            ll dt = ((a[i]-a[i-1])%p+p)%p;
            // 这里加和的时候不能mod。
            ans[p] += dt;
        }
    }
    while(q-->0) {
        int tp, i, x, k;
        scanf("%d", &tp);
        if (tp == 1) {
            scanf("%d%d", &i, &x);
            for (auto p : ps) {
                ans[p] -= ((a[i]-a[i-1])%p+p)%p;
                ans[p] += ((x-a[i-1])%p+p)%p;
                if (i < n) {
                    ans[p] -= ((a[i+1]-a[i])%p+p)%p;
                    ans[p] += ((a[i+1]-x)%p+p)%p;
                }
            }
            a[i] = x;
        } else {
            scanf("%d", &k);
            int g = getgcd(k, m);
            if (ans[g] < m) {
                puts("Yes");
            } else {
                puts("No");
            }
        }
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
