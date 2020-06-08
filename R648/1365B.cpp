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
#define N 502
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
int t, n;
int a[N], b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    int zn = 0;
    int on = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i =1 ; i <= n; ++i) {
      scanf("%d", &b[i]);
      if (b[i]==1) on++;
      else zn++;
    }
    int i;
    for (i = 1; i < n; ++i) {
      if (a[i] > a[i+1]) break;
    }
    if (i >= n) cout<<"Yes"<<endl;
    else {
      if (zn && on) cout<<"Yes"<<endl;
      else cout<<"No"<<endl;
    }
  }
  return 0;
}
