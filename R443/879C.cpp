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
#define N 1000
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
vector<pair<string,int>> op;
int bits[N];
int main() {
  cin>>n;
  op.clear();
  for (int i = 1; i <= n; ++i) {
    string s;
    int x;
    cin>>s;
    scanf("%d", &x);
    op.push_back(make_pair(s, x));
  }
  memset(bits, -1, sizeof(bits));
  int os = 0;
  int as = (1<<10)-1;
  int xs = 0;
  for (int b = 9; b >= 0; --b) {
    int res1=1;
    int res0=0;
    for (int j = 0; j < n; ++j) {
      if (op[j].first == "|") {
        if ((1<<b) & op[j].second) {
          res1 |= 1;
          res0 |= 1;
        }
      } else if (op[j].first == "^") {
        if ((1<<b)&op[j].second) {
          res1 ^= 1;
          res0 ^= 1;
        }
      } else {
        if ((1<<b) & op[j].second) continue;
        res1 &= 0;
        res0 &= 0;
      }
    }
    if (res1 == 1 && res0 == 1) {
      os |= (1<<b);
    } else if (res1 == 0 && res0 == 0) {
      as ^= (1<<b);
    } else if (res0 == 1 && res1 == 0) {
      xs ^= (1<<b);
    }
  }
  puts("3");
  cout<<"|"<<" "<<os<<endl;
  cout<<"&"<<" "<<as<<endl;
  cout<<"^"<<" "<<xs<<endl;
  return 0;
}
