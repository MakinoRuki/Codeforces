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
#define M 10
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
double n, r;
int main() {
  cin>>n>>r;
  double ans = r*sin(acos(-1.0)/n)/(1.0 - sin(acos(-1.0)/n));
  printf("%.7lf\n", ans);
  return 0;
}
