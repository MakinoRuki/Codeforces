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
#define N 3000005
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
int vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        vis[i]=-1;
        rk.push_back(make_pair(a[i], i));
    }
    sort(rk.begin(), rk.end());
    int ans=0;
    for (int i = rk.size()-1; i >= 0; --i) {
        int id = rk[i].second;
        int lv=-1,rv=-1;
        if (id-1>=1 && vis[id-1]) {
            lv=vis[id-1];
        }
        if (id+1<=n && vis[id+1]) {
            rv=vis[id+1];
        }
        if (lv < 0 && rv < 0) {
            ans++;
            vis[id]=a[id];
        } else if (lv > 0 && rv > 0) {
            if (lv == rk[i].first || rv == rk[i].first) {
                ans--;
                vis[id] = max(lv, rv);
            } else {
                vis[id]=min(lv, rv);
            }
        } else if (lv > 0) {
            vis[id]=lv;
        } else {
            vis[id]=rv;
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
