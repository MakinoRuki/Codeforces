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
#define N 100002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t,n;
int p[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &p[i]);
    }
    int cnt = 1;
    vector<int> ids;
    ids.clear();
    ids.push_back(p[1]);
    int cur=1;
    for (int i = 2; i <= n; ++i) {
      if (i == 2) cur = i;
      else {
        if (p[i] > p[i-1]) {
          if (p[cur] > p[cur-1]) {
            cur = i;
          } else {
            ids.push_back(p[cur]);
            cur = i;
          }
        } else {
          if (p[cur] < p[cur-1]) {
            cur = i;
          } else{
            ids.push_back(p[cur]);
            cur = i;
          }
        }
      }
    }
    if (n > 1) {
      ids.push_back(p[cur]);
    }
    cout<<ids.size()<<endl;
    for (int i = 1; i <= ids.size(); ++i) {
      printf("%d", ids[i-1]);
      if (i < ids.size()) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
