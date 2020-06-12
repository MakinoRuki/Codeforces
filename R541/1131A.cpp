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
#define N 300005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
ll w1,h1,w2,h2;
int main() {
  ll ans;
  cin>>w1>>h1>>w2>>h2;
  if (w1==w2) {
    ans = w1+w2+h1+h2+h1+h2+4;
  } else {
    ans = w2+2+w1+2+h1+h2+2+h2+1+w1-w2+1+h1+2-6;
  }
  cout<<ans<<endl;
  return 0;
}
