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
#define N 500005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
const int base=337;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int n0=0,n1=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') n0++;
      else n1++;
    }
    if (n0 == 0) {
      puts("Yes");
    } else if (n1 == 0) {
      puts("No");
    } else {
      if (s[0]=='1' && s.back()=='1') {
        puts("Yes");
      } else {
        int cnt=0;
        if (s[0] == '0') cnt++;
        if (s.back() == '0') cnt++;
        int cnt2=0;
        for (int i = 1; i < n; ++i) {
          if (s[i] == '1' && s[i-1] == '1') cnt2++;
        }
        if (cnt <= cnt2) {
          puts("Yes");
        } else {
          puts("No");
        }
      }
    }
  }
  return 0;
}
