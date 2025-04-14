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
#define M 10000005
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
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    bool found=false;
    for (int i = 1; i <= n; ++i) {
        if (a[i] == 0) {
            found=true;
            break;
        }
    }
    if (!found) {
        puts("1");
        printf("%d %d\n", 1, n);
    } else {
        if (a[1] || a[n]) {
            if (a[1]) {
                puts("2");
                printf("%d %d\n", 2, n);
                printf("%d %d\n", 1, 2);
            } else {
                puts("2");
                printf("%d %d\n", 1, n-1);
                printf("%d %d\n", 1, 2);
            }
        } else {
            puts("3");
            printf("%d %d\n", 1, 2);
            printf("%d %d\n", 2, n-1);
            printf("%d %d\n", 1,2);
        }
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
