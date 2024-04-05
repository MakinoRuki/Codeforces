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
#include <list>
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int a,b,c;
    scanf("%d%d%d", &a, &b, &c);
    int fa=0,fb=0,fc=0;
    int dbc=abs(b-c);
    if ((dbc%2)==0) {
      fa=1;
    }
    int dac=abs(a-c);
    if ((dac%2)==0) {
      fb=1;
    }
    int dab=abs(a-b);
    if ((dab%2)==0) {
      fc=1;
    }
    printf("%d %d %d\n", fa, fb, fc);
  }
  return 0;
}
