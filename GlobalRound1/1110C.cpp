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
#define N 35000000
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q;
int bits[N];
int main() {
  for (int i = 1; i < N; ++i) {

  }
  cin>>q;
  for (int cas=1; cas<=q; ++cas) {
    ll a;
    scanf("%lld", &a);
    ll pw = 0;
    while((1LL<<pw) <= a) pw++;
    if ((1LL<<pw)-1 == a) {
      int i;
      int j=1;
      for (i = 1; i * i <= a; ++i) {
        if (a%i == 0) {
          if (i < a) j = max(j, i);
          if (a/i < a) j = max(j, (int)a/i);
        }
      }
      cout<<j<<endl;
    } else {
      cout<<(1LL<<pw)-1<<endl;
    }
  }
  return 0;
}
