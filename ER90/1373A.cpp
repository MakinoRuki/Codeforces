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
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, p;
int t;
ll a,b,c;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>a>>b>>c;
    if (a < c) {
      cout<<1;
    } else {
      cout<<-1;
    }
    cout<<" ";
    if (a*b <= c) {
      cout<<-1<<endl;
    } else {
      cout<<b<<endl;
    }
  }
  return 0;
}
