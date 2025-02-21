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
#define M 1005
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
    sort(a+1, a+n+1);
    if (a[1] != a[2]) {
      puts("No");
    } else {
      map<int,int> cnt;
      cnt.clear();
      cnt[a[2]]++;
      bool ok=true;
      for (int i = 3; i <= n; i += 2) {
        int x=a[i+1];
        while(cnt.find(x) != cnt.end()) {
          x++;
        }
        int y=a[i];
        while(y < x) {
          if (cnt.find(y) != cnt.end()) {
            y++;
          } else {
            break;
          }
        }
        if (y == x) {
          cnt[x]++;
        } else {
          ok=false;
          break;
        }
      }
      if (ok) puts("Yes");
      else puts("No");
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
