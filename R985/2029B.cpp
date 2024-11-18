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
#define M 405
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, p;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s1,s2;
    cin>>s1>>s2;
    int n0=0,n1=0;
    for (int i = 0; i < n; ++i) {
      if (s1[i] == '0') n0++;
      else n1++;
    }
    bool ok=true;
    for (int i = 0; i < s2.size(); ++i) {
      if (n0 == 0 || n1 == 0) {
        ok=false;
        break;
      }
      if (s2[i] == '0') {
        n1--;
      } else {
        n0--;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

