

#include <iostream>
#include <sstream>
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
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
ll b[N];
ll c[N];
int calc(int bg, int ed, int cnt) {
  if (bg > 0 && ed < n-1) {
    if (cnt==1) return 0;
    if (cnt ==2) return 0;
    return cnt/3;
  }
  if ((bg == 0) && (ed == n-1)) {
    if (cnt==1) return 1;
    if (cnt==2) return 1;
    return (cnt+2)/3;
  }
  if (cnt==1) return 0;
  if (cnt == 2)return 1;
  return (cnt+1)/3;
}
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int bg=-1,ed=-1;
    int cnt=0;
    int ans=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '1') {
        if (cnt > 0) {
          ans += calc(bg, ed, cnt);
        }
        cnt=0;
        bg=-1,ed=-1;
        ans++;
      } else {
        ed = i;
        if (bg<0) bg=i;
        cnt++;
      }
    }
    if (cnt>0) ans += calc(bg, ed, cnt);
    printf("%d\n", ans);
  }

  // cin>>n;
  // for (int i= 1; i <= n; ++i) {
  //   a[i]=i;
  // }
  // do {
  //   if (check2()) {
  //     for (int i = 1; i <= n; ++i) {
  //       printf("%d ", a[i]);
  //     }
  //     cout<<endl;
  //   }
  // } while(next_permutation(a+1, a+n+1));
  return 0;
}

