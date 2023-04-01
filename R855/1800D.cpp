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
#define N 200005
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    int i = 0;
    int i2 = 1;
    int tot=0;
    while(i < n-1) {
      if (i+2 < n && s[i] == s[i+2]) {
        tot++;
        if (i + 3 < n && s[i+1] == s[i+3]) {
          tot++;
        }
        i += 2;
      } else {
        i += 1;
      }
    }
    tot = n-1-tot;
    printf("%d\n" ,tot);
  }
  return 0;
}
