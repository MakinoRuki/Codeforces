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
#define M 1005
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
int sum[N];
int check(int idx, int k, int bd) {
    if (idx >= bd) return -1;
    if (idx < 1) return -1;
    int i;
    for (i = idx; i < bd; ++i) {
        if (2 * sum[i] - i >= 2 * sum[idx-1] - (idx-1)) {
            break;
        }
    }
    if (i >= bd) return -1;
    while(i + 1 < bd && b[i + 1] == 0 && 2*sum[i+1]-(i+1)>=2*sum[idx-1]-(idx-1)) {
        i++;
    }
    return i;
}
int check2(int idx, int k, int bd) {
    if (idx  <= bd|| idx > n) return -1;
    int i;
    for (i = idx; i > bd; --i) {
        if (2 * sum[idx] - idx >= 2*sum[i-1] - (i-1)) {
            break;
        }
    }
    if (i <= bd) return -1;
    while(i - 1 > bd && b[i-1] == 0 && 2*sum[idx]-idx >= 2*sum[i-2]-(i-2)) {
        i--;
    }
    return i;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    b[0]=sum[0]=0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] <= k) {
            b[i] = 1;
        } else {
            b[i] = 0;
        }
        sum[i] = sum[i-1] + b[i];
    }
    int l = 0, r = n+1;
    for (l = 1;  l <= n; ++l) {
        if (2*sum[l]-l >= 0) {
            break;
        }
    }
    for (r = n; r >= 1; --r) {
        if (2*sum[n]-n >= 2*sum[r-1] - (r-1)) {
            break;
        }
    }
    if (l +1 < r) {
        puts("Yes");
        continue;
    }
    set<int> ss;
    ss.clear();
    bool found=false;
    for (int i = 1; i <  n; ++i) {
        int dt = 2*sum[i]-i;
        if (!ss.empty() && (*ss.begin()) <= dt) {
            found=true;
            break;
        }
        if (dt >= 0) ss.insert(dt);
    }
    l=1,r=n;
    while(l<r) {
        swap(b[l], b[r]);
        l++,r--;
    }
    for (int i = 1; i <= n; ++i) {
        sum[i]=sum[i-1]+b[i];
    }
    ss.clear();
    for (int i = 1; i <  n; ++i) {
        int dt = 2*sum[i]-i;
        if (!ss.empty() && (*ss.begin()) <= dt) {
            found=true;
            break;
        }
        if (dt >= 0) ss.insert(dt);
    }
    if (found) puts("Yes");
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
