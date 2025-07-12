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
int sx, sy, ex, ey;
int a[N];
int ls[N], rs[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    vector<int> rk;
    rk.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        rk.push_back(a[i]);
    }
    sort(rk.begin(), rk.end());
    int vv = rk[k-1];
    vector<int> ids;
    ids.clear();
    int cnt=0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] < vv) {
            ids.push_back(i);
        } else if (a[i] == vv) {
            cnt++;
        }
    }
    for (int i = 0; i <= n+1; ++i) {
        ls[i]=0,rs[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
        ls[i] = ls[i-1];
        if (a[i] == vv) {
            ls[i]++;
        }
    }
    for (int i = n; i >= 1; --i) {
        rs[i] = rs[i+1];
        if (a[i] == vv) {
            rs[i]++;
        }
    }
    int l = 0, r = (int)ids.size()-1;
    bool ok=true;
    int ld=0,rd=0;
    while(l <= r) {
        int l1=ids[l],r1=ids[r];
        if (a[l1] != a[r1]) {
            ok=false;
            break;
        }
        if (ls[l1]-ld != rs[r1]-rd) {
            if (ls[l1]-ld > rs[r1]-rd) {
                ld += (ls[l1]-ld)-(rs[r1]-rd);
            } else {
                rd += (rs[r1]-rd)-(ls[l1]-ld);
            }
        }
        l++;
        r--;
    }
    if (cnt-(ld+rd)+(int)ids.size() >= k-1) {
        if (ok) puts("Yes");
        else puts("No");
    } else {
        puts("No");
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
