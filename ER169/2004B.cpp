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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int l1,r1,l2,r2;
    scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
    if (l1 <= r2 && r1 >= l2) {
        int l=max(l1,l2);
        int r=min(r1,r2);
       // cout<<"lr="<<l<<" "<<r<<endl;
        int ans=r-l;
        if (l > min(l1, l2)) ans++;
        if (r < max(r2, r1)) ans++;
        printf("%d\n", ans);
    } else {
        puts("1");
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
