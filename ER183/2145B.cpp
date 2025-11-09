
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    string s;
    cin>>s;
    int n0=0,n1=0,n2=0;
    for (int i = 0; i < k; ++i) {
      if (s[i] == '0') n0++;
      else if (s[i] == '1') n1++;
      else n2++;
    }
    string ans="";
    for (int i = 1; i <= n; ++i) {
      bool f0=false;
      bool f1=false;
      if (n0+n2>=i || n1+n2>=n-i+1) {
        f1=true;
      }
      if (k<n && n0<i && n1<=n-i) {
        f0=true;
      }
      if (f1 && f0) {
        ans += "?";
      } else if (f1) ans += "-";
      else ans += "+";
    }
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
