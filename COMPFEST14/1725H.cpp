
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
 // freopen("data.txt", "r", stdin);
  memset(cnt, 0, sizeof(cnt));
  cin>>n;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    int d = 0;
    while(a[i]) {
      d = (d + a[i]%10);
      a[i] /= 10;
    }
    d %= 3;
    a[i] = d*d%3;
    cnt[a[i]]++;
  }
  string ans="";
  if (cnt[0] <= n/2) {
    int dt=n/2-cnt[0];
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 0) {
        ans += "0";
      } else if (dt) {
        ans += "0", dt--;
      } else {
        ans += "1";
      }
    }
    puts("0");
    cout<<ans<<endl;
  } else {
    int dt = n/2-cnt[1];
    for (int i = 1; i <= n; ++i) {
      if (a[i] == 1) {
        ans += "0";
      } else if (dt) {
        ans += "0", dt--;
      } else {
        ans += "1";
      }
    }
    puts("2");
    cout<<ans<<endl;
  }

  // cin>>n;
  // srand((unsigned)time(0));
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
