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
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
vector<vector<int>> v;
int main() {
 // cin>>t;
  //for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &k, &q);
    v.clear();
    for (int i = 1; i <= n; ++i) {
        vector<int> tmp;
        tmp.clear();
        for (int j = 1; j <= k; ++j) {
            int x;
            scanf("%d", &x);
            tmp.push_back(x);
        }
        v.push_back(tmp);
    }
    for (int j = 0; j < k; ++j) {
        for (int i = 1; i < n; ++i) {
            v[i][j] |= v[i-1][j];
        }
    }
    while(q-->0) {
        scanf("%d", &m);
        int ll=1,rr=n;
        for (int i = 0; i < m; ++i) {
            int r,c;
            string s;
            scanf("%d", &r);
            cin>>s;
            scanf("%d", &c);
            if (s[0] == '>') {
                int x = 1, y = n+1;
                while(x < y) {
                    int mid=(x+y)/2;
                    if (v[mid-1][r-1] > c) {
                        y = mid;
                    } else {
                        x = mid+1;
                    }
                }
                ll = max(ll, y);
            } else {
                int x = 0,y = n;
                while(x < y) {
                    int mid=(x+y+1)/2;
                    if (v[mid-1][r-1] < c) {
                        x = mid;
                    } else {
                        y = mid-1;
                    }
                }
                rr = min(rr, y);
            }
        }
        if (ll <= rr) {
            printf("%d\n", ll);
        } else {
            puts("-1");
        }
    }
  //}
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

