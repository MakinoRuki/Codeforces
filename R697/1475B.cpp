#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
ll n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%lld", &n);
    if (n%2020 <= n/2020) {
      cout<<"YES"<<endl;
    } else {
      cout<<"NO"<<endl;
    }
  }
  return 0;
}
