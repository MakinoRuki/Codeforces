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
int t;
ll a,b,n,m;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>a>>b>>n>>m;
    if (a>b) swap(a,b);
    if (a>=m && (a+b-m)>=n) {
      cout<<"Yes"<<endl;
    } else {
      cout<<"No"<<endl;
    }
  }
  return 0;
}
