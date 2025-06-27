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
#define M 505
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
// bool check(int x1, int y1, int x2, int y2, int x3, int y3) {
//     // int dt=0;
//     // if (x1-y1 == x2 && x1-y1 == x3) {
//     //     cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
//     //     return (y2 + y3 == x1);
//     // } else if (x1 - y1 == x2 && x1-y1 == y3) {
//     //     cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
//     //     return (y2+x3 == x1);
//     // } else if (x1 - y1 == y2 && x1-y1==x3) {
//     //     cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
//     //     return (x2+y3 == x1);
//     // } else if (x1-y1 == y2 && x1-y1 == y3) {
//     //     cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
//     //     return (x2+x3 == x1);
//     // } else {
//     //     return false;
//     // }
// }
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
    bool ok=false;
    // if (max(x1,y1) == max(x2,y2) && max(x2,y2)==max(x3,y3)) {
    //     if (min(x1,y1)+min(x2,y2)+min(x3,y3) == max(x1,y1)) {
    //         ok=true;
    //     }
    // }
    if (x1 == x2 && x2 == x3 && y1+y2+y3==x1) {
        ok=true;
    } else if (y1==y2 && y2 == y3 && x1+x2+x3==y1) {
        ok= true;
    } else if (x1 == x3+x2 && y3 == y2 && y1 + y2 == x1) {
        ok = true;
    } else if (y1 == y2+y3 && x2 == x3 && x2 + x1 == y1) {
        ok=true;
    }
    // } else if () {
    //     // if (check(max(x1,y1), min(x1,y1), x2, y2, x3, y3) || check(max(x2,y2), min(x2,y2), x1, y1, x3, y3) || check(max(x3,y3), min(x3,y3), x1, y1, x2, y2)) {
    //     //     ok=true;
    //     // }
    // }
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
