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
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    int en = 0, on = 0;
    vector<int> id1, id2;
    id1.clear();
    id2.clear();
    for (int i = 1; i <= 2*n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]%2) {
        on++;
        id1.push_back(i);
      } else {
        en++;
        id2.push_back(i);
      }
    }
    if ((on%2==0) && (en%2 ==0)) {
      if (id1.size() > 0) {
        for (int i = 2; i < id1.size(); i+=2) {
          printf("%d %d\n", id1[i], id1[i+1]);
        }
        for (int i = 0; i < id2.size(); i+=2) {
          printf("%d %d\n", id2[i], id2[i+1]);
        }
      } else {
        for (int i = 2; i < id2.size(); i+=2) {
          printf("%d %d\n", id2[i], id2[i+1]);
        }
        for (int i = 0; i < id1.size(); i+=2) {
          printf("%d %d\n", id1[i], id1[i+1]);
        }
      }
    } else {
      for (int i = 1; i < id1.size(); i+=2) {
        printf("%d %d\n", id1[i], id1[i+1]);
      }
      for (int i = 1; i < id2.size(); i+=2) {
        printf("%d %d\n", id2[i], id2[i+1]);
      }
    }
  }
  return 0;
}
