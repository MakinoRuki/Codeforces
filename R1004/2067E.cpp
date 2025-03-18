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
int a[N];
int b[N];
int mn[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    int n0=0;
    int id=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] == 0) {
            n0++;
            if (id == 0) id = i;
        }
    }
    if (id == 0) {
        printf("%d\n", n);
        continue;
    }
    int ans=n-n0;
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        if (a[i]) {
            b[++cnt] = a[i];
        } else {
            if (i == id) b[++cnt] = a[i];
        }
    }
    for (int i = 1; i < cnt; ++i) {
        if (i == 1) mn[i] = b[i];
        else mn[i] = min(mn[i-1], b[i]);
    }
    int mx=0;
    set<int> ss;
    bool ok=true;
    for (int i = cnt; i > 1; --i) {
        ss.insert(b[i]);
        while(ss.find(mx) != ss.end()) {
            mx++;
        }
        if (mn[i-1] < mx) {
            ok=false;
            break;
        }
    }
    if (ok) ans++;
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
