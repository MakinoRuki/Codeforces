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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
int a[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  //  scanf("%d", &n);
    int a,b;
    scanf("%d%d%d", &n, &a, &b);
    cin>>s;
    if (s[a-1] == s[b-1]) {
      puts("0");
    } else {
      puts("1");
    }
  //}
  return 0;
}
