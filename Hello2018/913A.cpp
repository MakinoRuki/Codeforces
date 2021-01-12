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
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
int main() {
  cin>>n>>m;
  int pw=0;
  while((1<<pw) <= m) {
    pw++;
  }
  pw--;
  if (pw < n) {
    cout<<m<<endl;
  } else {
    cout<<(((1<<n)-1)&m)<<endl;
  }
  return 0;
}
