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
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    map<int,int> idx;
    idx.clear();
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans=-1;
    for (int i = 2; i < n; ++i) {
        if (a[i-1]>=a[i]&&a[i]<=a[i+1]) {
            ans=1;
            break;
        }
        if (a[i-1]<=a[i]&&a[i]>=a[i+1]) {
            ans=1;
            break;
        }
    }
    for (int i = 2; i <= n; ++i) {
        if (abs(a[i]-a[i-1])<=1) {
            ans=0;
        }
    }
    printf("%d\n", ans);
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
