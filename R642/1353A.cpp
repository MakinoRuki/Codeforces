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
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d%d", &n, &m);
    if (n == 1) cout<<0<<endl;
    else if (n == 2) cout<<m<<endl;
    else cout<<2*m<<endl;
  }
  return 0;
}
