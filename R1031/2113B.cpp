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
//ll a[N];
bool check(int x, int y, int z) {
    int dt = y-x-1;
    if ((dt%z) == 0) {
        return true;
    }
    return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int w,h,a,b;
    int x1,y1,x2,y2;
    scanf("%d%d%d%d", &w, &h, &a, &b);
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    bool ok=false;
    if (x1 <= x2 && y1 <= y2) {
        if ((x1+a == x2) || (y1+b == y2)) {
            ok=true;
        } else {
            if (x1+a<x2 && check(x1+a-1, x2, a)) {
                ok=true;
            } else if (y1+b<y2 && check(y1+b-1, y2, b)) {
                ok=true;
            }
        }
    } else if (x1 <= x2 && y1 > y2) {
        if ((x1+a==x2) || (y2+b==y1)) {
            ok=true;
        } else {
            if (x1+a<x2 && check(x1+a-1, x2, a)) {
                ok=true;
            } else if (y2+b < y1 && check(y2+b-1, y1, b)) {
                ok=true;
            }
        }
    } else if (x1 > x2 && y1 <= y2) {
        if ((x2+a==x1) || (y1+b==y2)) {
            ok=true;
        } else {
            if (x2+a<x1 && check(x2+a-1, x1, a)) {
                ok=true;
            } else if (y1+b < y2 && check(y1+b-1, y2, b)) {
                ok=true;
            }
        }
    } else {
        if ((x2+a==x1) || (y2+b==y1)) {
            ok=true;
        } else {
            if (x2 + a < x1 && check(x2+a-1, x1, a)) {
                ok=true;
            } else if (y2+b<y1 && check(y2+b-1, y1, b)) {
                ok=true;
            }
        }
    }
    if (ok) puts("Yes");
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
