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
ll k;
int t;
int a[N];
int d[N];
int dt[N];
bool check(int l1, int r1, int l2, int r2) {
    if (l1 <= r2 && r1 >= l2) {
        return true;
    }
    return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &d[i]);
    }
    vector<pair<int,int>> lr;
    lr.clear();
    lr.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        int l,r;
        scanf("%d%d", &l, &r);
        lr.push_back(make_pair(l, r));
    }
    // int l = lr.back().first;
    // int r = lr.back().second;
    int l=0,r=0;
    int cur=0;
    bool ok = true;
    int mn = lr.back().first;
    for (int i = n; i >= 1; --i) {
        if (i==n) dt[i] = mn;
        else {
            dt[i] = max(lr[i].first, dt[i+1]-abs(d[i+1]));
        }
    }
    for (int i = 1; i <= n; ++i) {
      //  cout<<"i="<<i<<" "<<dt[i]<<endl;
        if (d[i] == 1) {
            cur++;
        } else if (d[i] == -1) {
            if (cur < dt[i]) {
                if (cur +1 >= dt[i]) {
                    d[i] = 1;
                    cur++;
                } else {
                    ok=false;
                    break;
                }
            } else {
                d[i] = 0;
            }
        }
        if (cur >= lr[i].first && cur <= lr[i].second) {
            continue;
        }
        ok=false;
        break;
    }
    // for (int i = n; i >= 1; --i) {
    //     int l2=l, r2=r;
    //     int l3=lr[i-1].first, r3=lr[i-1].second;
    //     if (d[i] == 1 || d[i] == -1) {
    //         if (check())
    //     }
    //     // if (d[i] == 1) {
    //     //     if (!check(l2-1, r2-1, l3, r3)) {
    //     //         ok=false;
    //     //         break;
    //     //     }
    //     //     l2 = max(l3, l2-1);
    //     //     r2 = min(r3, r2-1);
    //     // } else if (d[i] == -1) {
    //     //     l2 = max(l3, max(0, l2-1));
    //     //     r2 = min(r3, r2);
    //     // } else {
    //     //     if (!check()) {
                
    //     //     }
    //     //     l2 = max(l2, l3);
    //     //     r2 = min(r2, r3);
    //     // }
    //     // if (l2 <= r2) {
    //     //     // if (d[i] == -1) {
    //     //     //     if (!check(l2+1, r2+1, l, r)) {
    //     //     //         d[i] = 0;
    //     //     //     } else {
    //     //     //         d[i] = 1;
    //     //     //     }
    //     //     // }
    //     // } else {
    //     //     ok=false;
    //     //     break;
    //     // }
    //     if (l2 > r2) {
    //         ok=false;
    //         break;
    //     }
    //     l = l2, r= r2;
    // }
    if (!ok) puts("-1");
    else {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", d[i]);
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
