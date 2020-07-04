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
#define N 2005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int a[N];
int main() {
  cin>>n;
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  vector<pair<int, int>> ops;
  ops.clear();
  int sum=0;
  for (int i = n; i >= 1; --i) {
    int r1 = (a[i]+sum)%n;
    int r2 = (i-1)%n;
    if (r1==r2) continue;
    int det =(r2-r1+n)%n;
    sum += det;
    ops.push_back(make_pair(i, det));
  }
  cout<<ops.size()+1<<endl;
  for (int i = 0; i < ops.size(); ++i) {
    printf("1 %d %d\n", ops[i].first, ops[i].second);
  }
  cout<<2<<" "<<n<<" "<<n<<endl;
  return 0;
}
