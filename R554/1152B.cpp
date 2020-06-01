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
const ll mod = 998244353LL;
int x;
int main() {
  cin>>x;
  vector<int> ans;
  ans.clear();
  int t=0;
  while(true) {
    int i;
    for (i = 20; i >= 0; --i) {
      if ((1<<i)&x) continue;
      break;
    }
    if (i >= 0) {
      ans.push_back(i+1);
      x ^= ((1<<(i+1))-1);
      t++;
      for (i = 20 ; i >= 0; --i) {
        if ((1<<i)&x)continue;
        break;
      }
      if (i>=0) {
        x++;
        t++;
      } else {
        break;
      }
    } else {
      break;
    }
  }
  cout<<t<<endl;
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
