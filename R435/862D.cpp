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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, k;
int main() {
  cin>>n;
  int id0 = -1, id1 = -1;
  int det = 0,l = 0, r = n-1;
  int c0 = 0, c1 = 0;
  string q(n, '0');
  cout<<"? "<<q<<endl;
  fflush(stdout);
  int tot=0;
  scanf("%d", &tot);
  c0 = n-tot;
  c1 = tot;
  while(true) {
    if (l == r) {
      if (c0>0) {
        id0 = l;
      } else {
        id1 = l;
      }
      break;
    }
    if (id0 >= 0 && id1 >= 0) {
      break;
    }
    int mid = (l+r)/2;
    string q(n, '0');
    for (int i = l; i <= mid; ++i) {
      q[i] = '1';
    }
    cout<<"? "<<q<<endl;
    fflush(stdout);
    tot=0;
    scanf("%d", &tot);
    tot -= det;
    int len = r-l+1;
    int len1 = mid-l+1;
    int y1 = (tot + c1 - len1)/2;
    int y0 = len-len1-y1;
    if (y1 < len-len1 && y0 < len-len1) {
      det += c1 - y1;
      l = mid+1;
      c1 = y1;
      c0 = y0;
    } else {
      if (y1 == len-len1) {
        id1 = r;
      } else {
        id0 = r;
      }
      det += y1;
      r = mid;
      c1 -= y1;
      c0 -= y0;
    }
  }
  printf("! %d %d\n", id0+1, id1+1);
  return 0;
}
