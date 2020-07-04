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
#define N 1005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n==1) cout<<1<<endl;
    else if (n==2) cout<<1<<endl;
    else {
      if (n%2) {
        cout<<(n/2+1)<<endl;
      } else {
        cout<<n/2<<endl;
      }
    }
  }
  return 0;
}
