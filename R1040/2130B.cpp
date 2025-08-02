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
int cnt[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    int n0=0,n1=0,n2=0;
    int tot=0;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        tot += a[i];
        if (a[i]==0)n0++;
        if (a[i]==1)n1++;
        if (a[i]==2)n2++;
    }
    if (m < tot) {
        for (int i = 1; i <= n; ++i) {
            printf("%d ", a[i]);
        }
        cout<<endl;
        continue;
    }
    int dt=m-tot;
    if (dt==1) {
       for (int i = 1; i <= n0; ++i) {
           printf("0 ");
       }
       for (int i = 1; i <= n2; ++i) {
           printf("2 ");
       }
       for (int i = 1; i <= n1; ++i) {
           printf("1 ");
       }
       cout<<endl;
    } else {
        puts("-1");
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
