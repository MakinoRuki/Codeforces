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
#define N 302
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q;
int l1, r1, l2, r2;
int main() {
  cin>>q;
  for (int cas=1; cas<=q; ++cas) {
    cin>>l1>>r1>>l2>>r2;
    if (l1 == r2) {
      cout<<r1<<" "<<l2<<endl;
    } else {
      cout<<l1<<" "<<r2<<endl;
    }
  }
  return 0;
}
