#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 200005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
ll k;
int q;
int a[N];
int b[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      // a[i] = rand()%n + 1;
      // int sg = rand()%2;
      // if (sg) a[i] *= -1;
      // cout<<a[i]<<" ";
    }
    //cout<<endl;
    if (n % 2 == 0) {
      for (int i =1; i <= n; i += 2) {
        if ((a[i] > 0 && a[i+1] > 0) || (a[i]<0 && a[i+1]<0)) {
          printf("%d %d", a[i+1], -a[i]);
        } else {
          printf("%d %d", abs(a[i+1]), abs(a[i]));
        }
        if (i+1 < n) cout<<" ";
        else cout<<endl;
      }
    } else {
      if (n > 2*10000) {
        vector<int> ids[N];
        for (int i = 1; i <= n; ++i) {
          ids[abs(a[i])].push_back(i);
        }
        int id;
        for (int i = 1; i <= 10000; ++i) {
          if (ids[i].size() >= 3) {
            id = i;
            break;
          }
        }
        int id1=ids[id][0];
        int id2=ids[id][1];
        int id3=ids[id][2];
        int s1 = (a[id1]>0 ? 1:-1);
        int s2= (a[id2]>0 ? 1 : -1);
        int s3 = (a[id3]>0 ? 1 : -1);
        if ((a[id1] > 0 && a[id2] > 0 && a[id3] > 0)||(a[id1] < 0 && a[id2] < 0 && a[id3] < 0)) {
          b[id1] = 2;
          b[id2] = -1;
          b[id3] = -1;
        } else if (s1 != s2 && s1 != s3) {
          b[id1] = 2;
          b[id2] = 1;
          b[id3] = 1;
        } else if (s2 != s1 && s2 != s3) {
          b[id2] = 2;
          b[id1] = b[id3] = 1;
        } else {
          b[id3] = 2;
          b[id1] = b[id2] = 1;
        }
        vector<int> v;
        v.clear();
        for (int i = 1; i <= n; ++i) {
          if (i != id1 && i != id2 && i != id3) {
            v.push_back(i);
          }
        }
        for (int i = 0; i < v.size(); i += 2) {
          b[v[i]] = a[v[i+1]];
          b[v[i+1]] = -a[v[i]];
        }
        for (int i = 1; i <= n; ++i) {
          printf("%d", b[i]);
          if (i < n) cout<<" ";
          else cout<<endl;
        }
      } else {
        if (a[1]+a[2] != 0) {
          b[1]=a[3];
          b[2]=a[3];
          b[3] = -(a[1]+a[2]);
        } else if (a[1] + a[3] != 0) {
          b[1] = a[2];
          b[3] = a[2];
          b[2] = -(a[1]+a[3]);
        } else {
          b[2] = a[1];
          b[3]= a[1];
          b[1] = -(a[2]+a[3]);
        }
        for (int i = 4; i <= n; i += 2) {
          b[i] = a[i+1];
          b[i+1] = -a[i];
        }
        for (int i = 1; i <= n; ++i) {
          printf("%d", b[i]);
          if (i < n) cout<<" ";
          else cout<<endl;
        }
      }
    }
  }
  return 0;
}
