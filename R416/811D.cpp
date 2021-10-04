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
#define M 105
#define N 5002
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m;
vector<string> mat;
int path[M][M];
int dx[4] = {-1,1,0,0};
int dy[4] = {0, 0, -1,1};
int main() {
  map<char, char> mp;
  mp.clear();
  mp['L'] = 'L';
  mp['R'] = 'R';
  mp['U'] = 'U';
  mp['D'] = 'D';
  cin>>n>>m;
  int fx,fy;
  mat.clear();
  for (int i = 1; i <= n; ++i) {
    string s;
    cin>>s;
    mat.push_back(s);
    for (int j = 0; j < m; ++j) {
      if (s[j] == 'F') {
        fx=i-1;
        fy=j;
      }
    }
  }
  memset(path, -1, sizeof(path));
  path[0][0] = 0;
  queue<int> q;
  q.push(0);
  while(!q.empty()) {
    int cur=q.front();
    q.pop();
    int x=cur/m;
    int y=cur%m;
    for (int d = 0;d < 4; ++d) {
      int nx=x+dx[d];
      int ny=y+dy[d];
      if (nx>=0 && nx<n && ny>=0 && ny < m && path[nx][ny]<0 && mat[nx][ny] != '*') {
        path[nx][ny] = cur;
        q.push(nx*m+ny);
      }
    }
  }
//  cout<<"!!!"<<endl;
  vector<pair<int,int>> ans;
  ans.clear();
  int cx = fx, cy = fy;
  while(true) {
  //  cout<<cx<<" "<<cy<<endl;
    ans.push_back(make_pair(cx+1, cy+1));
    if (cx == 0 && cy == 0) {
      break;
    }
    int nx,ny;
    nx = path[cx][cy]/m;
    ny = path[cx][cy]%m;
    cx = nx;
    cy = ny;
  }
  reverse(ans.begin(), ans.end());
//  cout<<"???"<<endl;
  // if (m > 1 && mat[0][1] != '*') {
  //   cout<<"R"<<endl;
  //   fflush(stdout);
  //   int x,y;
  //   scanf("%d%d", &x, &y);
  //   if (x == 1 && y == 1) {
  //     //cout<<"xxx"<<endl;
  //     mp['R'] = 'L';
  //     mp['L'] = 'R';
  //   } else {
  //     cout<<"L"<<endl;
  //     fflush(stdout);
  //     scanf("%d%d", &x, &y);
  //   }

  //   for (int j = 1; j <= m; ++j) {
  //     if (1 + 1 <= n && mat[1][j-1] != '*') {
  //       cout<<"D"<<endl;
  //       fflush(stdout);
  //       scanf("%d%d", &x, &y);
  //       if (x == 1 && y == j) {
  //         mp['D'] = 'U';
  //         mp['U'] = 'D';
  //       }
  //       cx = x,cy=y;
  //       break;
  //     } else {
  //       cout<<mp['R']<<endl;
  //       fflush(stdout);
  //       scanf("%d%d", &x, &y);
  //       cx=x,cy=y;
  //     }
  //   }
  // } else if (n > 1 && mat[1][0] != '*') {
  //   cout<<"D"<<endl;
  //   fflush(stdout);
  //   int x,y;
  //   scanf("%d%d", &x, &y);
  //   if (x == 1 && y == 1) {
  //     mp['D'] = 'U';
  //     mp['U'] = 'D';
  //   } else {
  //     cout<<"U"<<endl;
  //     fflush(stdout);
  //     scanf("%d%d", &x, &y);
  //   }
  //   for (int i = 1; i <= n; ++i) {
  //     if (1 + 1 <= m && mat[i-1][1] != '*') {
  //       cout<<"R"<<endl;
  //       fflush(stdout);
  //       scanf("%d%d", &x, &y);
  //       if (x == i && y == 1) {
  //         mp['R'] = 'L';
  //         mp['L'] = 'R';
  //       }
  //       cx=x,cy=y;
  //       break;
  //     } else {
  //       cout<<mp['D']<<endl;
  //       fflush(stdout);
  //       scanf("%d%d", &x, &y);
  //       cx=x, cy=y;
  //     }
  //   }
  // }
  // for (int i = 0; i < ans.size(); ++i) {
  //   cout<<ans[i].first<<" "<<ans[i].second<<endl;
  // }
  // while(!(cx == 1 && cy == 1)) {
  //   if (cy > 1) {
  //     cout<<mp['L']<<endl;
  //     fflush(stdout);
  //   } else {
  //     cout<<mp['U']<<endl;
  //     fflush(stdout);
  //   }
  //   scanf("%d%d", &cx, &cy);
  // }
  cx = 1, cy=1;
  int id = 0;
  while(!(cx == fx+1 && cy == fy+1)) {
    if (cx + 1 == ans[id+1].first) {
      cout<<mp['D']<<endl;
    } else if (cx -1 == ans[id+1].first) {
      cout<<mp['U']<<endl;
    } else if (cy + 1 == ans[id+1].second) {
      cout<<mp['R']<<endl;
    } else {
      cout<<mp['L']<<endl;
    }
    fflush(stdout);
    int nx,ny;
    scanf("%d%d", &nx, &ny);
    if (!(nx == ans[id+1].first && ny == ans[id+1].second)) {
      if (cx != ans[id+1].first) {
        mp['D'] = 'U';
        mp['U'] = 'D';
      } else {
        mp['L'] = 'R';
        mp['R'] = 'L';
      }
      if (nx + 1 == cx) {
        cout<<mp['D']<<endl;
      } else if (nx -1 == cx) {
        cout<<mp['U']<<endl;
      } else if (ny + 1 == cy) {
        cout<<mp['R']<<endl;
      } else if (ny -1 == cy) {
        cout<<mp['L']<<endl;
      }
    } else {
      cx=nx,cy=ny;
      id++;
    }
  }
  return 0;
}
