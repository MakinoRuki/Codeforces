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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x;
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    sort(a+1, a+n+1);
    int res=0;
    int id = 1;
    map<int,int> cnt;
    cnt.clear();
    for (res = 0; res <= n; ++res) {
      while(id <= n && a[id] <= res) {
        if (id > 1 && a[id] == a[id-1]) {
          cnt[a[id]%x]++;
        }
        id++;
      }
      if (id == 1 || a[id-1] != res) {
        if (cnt.find(res%x) != cnt.end()) {
          cnt[res%x]--;
          if (cnt[res%x] == 0) {
            cnt.erase(res%x);
          }
        } else {
          break;
        }
      }
    }
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
