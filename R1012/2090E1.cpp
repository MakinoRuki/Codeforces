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
ll sa[N], sb[N];
int ans[N];
int calc(vector<int>& tk, int cur, ll dt) {
    int l = cur, r = tk.size()-1;
    while(l < r) {
        int mid=(l+r+1)/2;
        ll dt2 = sa[tk[mid]]-sb[tk[mid]];
        if (dt2 >= dt) {
            l = mid;
        } else {
            r = mid-1;
        }
    }
    return r;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    sa[2*n+1]=0;
    sb[2*n+1]=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        ans[i] = inf;
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &b[i]);
    }
    for (int i = 2*n; i >= 1; --i) {
        if (i <= n) sa[i] = sa[i+1]+a[i];
        else sa[i]=sa[i+1]+a[i-n];
    }
    for (int i = 2*n; i >= 1; --i) {
        if (i <= n) sb[i] = sb[i+1]+b[i];
        else sb[i]=sb[i+1]+b[i-n];
    }
    vector<int> tk;
    tk.clear();
    tk.push_back(2*n+1);
    int cur=0;
    for (int i = 2*n; i >= 1; --i) {
        ll dt1 = sa[i]-sb[i];
        while(cur < tk.size() && tk[cur]-i>n) {
            cur++;
        }
        auto itr = calc(tk, cur, dt1);
        if (dt1 <= sa[tk[itr]]-sb[tk[itr]]) {
            if (i <= n) ans[i] = min(ans[i], tk[itr]-i);
            else ans[i-n] = min(ans[i-n], tk[itr]-i);
        }
        while(cur < tk.size()) {
            ll dt2 = sa[tk.back()]-sb[tk.back()];
            if (dt1 >= dt2) {
                tk.pop_back();
            } else {
                break;
            }
        }
        tk.push_back(i);
    }
    int res=0;
    for (int i = 1; i <= n; ++i) {
        res=max(res, ans[i]);
    }
    printf("%d\n", res);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
