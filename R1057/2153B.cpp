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
#define M 40
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
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y,z;
    scanf("%d%d%d", &x, &y, &z);
    bool ok=true;
    for (int i = 0; i <= 30; ++i) {
        int bx = ((1<<i)&x)>0;
        int by = ((1<<i)&y)>0;
        int bz = ((1<<i)&z)>0;
        if (bx && by) {
            if (!bz) {
                ok=false;
                break;
            }
        } else if (bx != by) {
            if (bz) {
                ok=false;
                break;
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
