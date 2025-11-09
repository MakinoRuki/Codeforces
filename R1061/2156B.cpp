
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
#define N 1000005
#define M 5002
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    string s;
    cin>>s;
    vector<int> vv;
    vv.clear();
    int cnt=0;
    bool found=false;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') {
            cnt++;
        } else {
            found=true;
            if (cnt) {
                vv.push_back(cnt);
                cnt=0;
            }
            vv.push_back(0);
        }
    }
    if (cnt) {
        vv.push_back(cnt);
    }
    while(q-->0) {
        int x;
        scanf("%d", &x);
        if (!found) {
            printf("%d\n", x);
            continue;
        }
        ll ans=0;
        int cur=0;
        while(x) {
            if (vv[cur]==0) {
                x/=2;
                ans++;
            } else {
                ans += min(x, vv[cur]);
                if (x >= vv[cur]) {
                    x -= vv[cur];
                } else {
                    x = 0;
                }
            }
            cur++;
            if (cur == vv.size()) {
                cur = 0;    
            }
        }
        printf("%lld\n", ans);
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
