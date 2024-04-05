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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
ll a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int c1=0,c2=0,c3=0;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '.') {
        cnt++;
      } else {
        if (cnt == 1) c1++;
        else if (cnt == 2) c2++;
        else if (cnt>=3) c3++;
        cnt=0;
      }
    }
    if (cnt>0) {
      if (cnt==1) c1++;
      else if (cnt==2) c2++;
      else c3++;
    }
    if (c1==0 && c2==0 && c3==0) {
      puts("0");
    } else if (c3 > 0) {
      puts("2");
    } else {
      printf("%d\n", c2*2+c1);
    }
  }
  return 0;
}
