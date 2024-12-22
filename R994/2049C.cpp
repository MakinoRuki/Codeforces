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
#define N 300005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d%d", &n, &x, &y);
    if (n%2) {
        a[x] = 2;
        int z = x;
        for (int i = 1; i < n; ++i) {
            z++;
            if (z > n) z = 1;
            if (i%2) a[z] = 1;
            else a[z] = 0;
        }
    } else {
        for (int i = 1; i <= n; ++i) {
            if (i%2) a[i] = 1;
            else a[i]=0;
        }
        if (a[x] == a[y]) {
            a[x] = 2;
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

