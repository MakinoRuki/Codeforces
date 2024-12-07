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
#define M 5005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m;
int k;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    ll s0=0LL,s1=0LL;
    int n0=0,n1=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        tot += a[i];
        if (i%2) {
            s1+=a[i];
            n1++;
        } else {
            s0+=a[i];
            n0++;
        }
    }
    if (tot%n) {
        puts("NO");
        continue;
    }
    if ((s1%n1)==0 && s1/n1==tot/n) {
        if ((s0%n0)==0 && s0/n0==tot/n) {
            puts("YES");
        } else {
            puts("NO");
        }
    } else {
        puts("NO");
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

