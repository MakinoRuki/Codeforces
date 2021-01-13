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
#define M 31
#define N 500005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, a;
int t, l, r;
string s;
int getgcd(int x, int y) {
  return y==0 ? x : getgcd(y, x%y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &a);
    int g = getgcd(180, a);
    m = a / g;
    n = 180 / g;
    if (m >= n) {
      cout<<-1<<endl;
    } else {
      if (n - m >= 2) {
        cout<<n<<endl;
      } else {
        cout<<2*n<<endl;
      }
    }
  }
  return 0;
}
