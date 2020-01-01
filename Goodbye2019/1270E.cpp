#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#define N 1005
using namespace std;
typedef long long ll;
int n;
int x[N], y[N];
int main() {
  cin>>n;
  for (int i = 0; i < n; ++i) {
    cin>>x[i]>>y[i];
  }
  while(true) {
    vector<int> pts;
    pts.clear();
    for (int i = 0; i < n; ++i) {
      if ((x[i]+y[i]) % 2 == 0) {
        pts.push_back(i);
      }
    }
    if (pts.size() < n && pts.size() > 0) {
      cout<<pts.size()<<endl;
      for (int i = 0; i < pts.size(); ++i) {
        cout<<pts[i]+1;
        if (i < pts.size()-1) cout<<" ";
        else cout<<endl;
      }
      break;
    }
    pts.clear();
    for (int i = 0 ; i < n; ++i) {
      if (x[i] % 2 == 0) {
        pts.push_back(i);
      }
    }
    if (pts.size() > 0 && pts.size() < n) {
      cout<<pts.size()<<endl;
      for (int i = 0; i < pts.size(); ++i) {
        cout<<pts[i]+1;
        if (i < pts.size()-1) cout<<" ";
        else cout<<endl;
      }
      break;
    }
    for (int i = 0; i < n; ++i) {
      // 负数除以2要下取整。
      if (x[i] < 0 && x[i] % 2 != 0) x[i]--;
      x[i] /= 2;
      if (y[i] < 0 && y[i] % 2 != 0) y[i]--;
      y[i] /= 2;
    }
  }
  return 0;
}
