
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
#define M 305
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
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    for (int i = 1; i <= n; ++i) {
      a[i] = i;
    }
    bool ok=true;
    int pre=0;
    for (int i = 1; i <= n; ++i) {
      if (s[i-1] == '1') {
        int l = pre+1, r = i-1;
        if (l==r) {
          ok=false;
          break;
        }
        while(l < r) {
          swap(a[l], a[r]);
          l++;
          r--;
        }
        pre= i;
      }
    }
    if (pre < n) {
      int l = pre+1, r= n;
      if (l==r) {
        ok=false;
      } else {
        while(l<r) {
          swap(a[l], a[r]);
          l++,r--;
        }
      }
    }
    if (!ok) puts("No");
    else {
      puts("Yes");
      for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
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
