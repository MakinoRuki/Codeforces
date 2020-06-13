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
#define N 100005
#define M 100005
#define inf 1000000000
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int x, y, z;
int a, b, c;
int main() {
  cin>>x>>y>>z;
  cin>>a>>b>>c;
  bool ok = true;
  int tot=0;
  tot = a;
  if (x > tot) {
    ok = false;
  } else {
    tot -= x;
    tot += b;
    if (y > tot) {
      ok = false;
    } else {
      tot -= y;
      tot += c;
      if (tot < z) {
        ok = false;
      }
    }
  }
  if (ok) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
