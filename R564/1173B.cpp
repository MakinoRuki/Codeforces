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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n;
int main() {
  cin>>n;
  int m = (n+2)/2;
  cout<<m<<endl;
  for (int i = 1; i <=min(n, m); ++i) {
    cout<<1<<" "<<i<<endl;
  }
  int det = max(0, n-m);
  for (int i = 1; i <= det; ++i) {
    cout<<i+1<<" "<<m<<endl;
  }
  return 0;
}
