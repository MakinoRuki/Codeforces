
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
int check(int x) {
  int rn=0,rp=x;
  if (x) rn=a[1];
  else rn=a[1]-1;
  for (int i = 2; i <= n; ++i) {
    int n1=i-1-rp;
    int n2=a[i]-n1-1;
    if (n1 < 0 || n2 < 0) return 0;
    int dt = rn-(rp+n2);
    if (dt < 0 || dt > 1) return 0;
    rp += dt;
  }
  return rp==rn;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
  //  cout<<check(0) <<" "<<check(1)<<endl;
    int res=check(0)+check(1);
    printf("%d\n", res);
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
