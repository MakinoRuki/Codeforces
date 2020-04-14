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
#include <queue>
#define N 1000005
using namespace std;
typedef long long ll;
int t, n, m;
int c[N];
bool vis[N];
bool vis2[N];
int deg[N];
int base[N][2];
int rlen[N];
vector<pair<int, int>> cnt[N];
int dis[N][2];
string s;
void dfs(int cur) {
	if (base[cur][0] >= 0) return ;
	if (dis[cur][0] >= 0) return;
	int cur2=cur;
	if (s[cur] == 'R') cur2++;
	if (s[cur] == 'L') cur2--;
	if (s[cur] == 'U') cur2 -= m;
	if (s[cur] == 'D') cur2 += m;
	dfs(cur2);
	if (base[cur2][0] >= 0) {
		dis[cur][0] = base[cur2][0];
		dis[cur][1] = (base[cur2][1]+1) % rlen[base[cur2][0]];
	} else {
		dis[cur][0] = dis[cur2][0];
		dis[cur][1] = (dis[cur2][1] + 1) % rlen[dis[cur][0]];
	}
//	cout<<"***"<<cur<<" "<<dis[cur][0]<<" "<<dis[cur][1]<<" "<<c[cur]<<endl;
	cnt[dis[cur][0]][dis[cur][1]].second += !c[cur];
	//if (cur ==2) cout<<"***"<<cnt[dis[cur][0]][dis[cur][1]].second<<endl;
}
int main() {
	scanf("%d", &t);
	char s2[N];
	for (int cas=1; cas<=t; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%s", s2);
			for (int j = 0; j < m; ++j) {
				//scanf("%c", &ct);
				c[i*m+j] = s2[j]-'0';
			}
			//scanf("%c", &ct);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				deg[i*m+j] = 0;
			}
		}
		s.clear();
		for (int i = 0; i < n; ++i) {
			scanf("%s", s2);
			for (int j = 0; j < m; ++j) {
				//scanf("%c", &ct);
				s.push_back(s2[j]);
			}
			//scanf("%c", &ct);
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				char ct = s[i*m+j];
				if (ct == 'R') deg[i*m+j+1]++;
				if (ct == 'L') deg[i*m+j-1]++;
				if (ct == 'U') deg[(i-1)*m+j]++;
				if (ct == 'D') deg[(i+1)*m+j]++;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cnt[i*m+j].clear();
				vis[i*m+j] = false;
				vis2[i*m+j] = false;
				base[i*m+j][0] = -1;
				base[i*m+j][1] = -1;
				dis[i*m+j][0] = -1;
				dis[i*m+j][1] = -1;
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (!vis[i*m+j]) {
					//set<int> ss;
					//ss.clear();
					int cur = i*m+j;
					vector<int> ss;
					ss.clear();
					while(true) {
						if (vis[cur]) break;
						if (vis2[cur]) break;
						//if (ss.find(cur) != ss.end()) break;
						vis[cur]=true;
						vis2[cur]= true;
						ss.push_back(cur);
						if (s[cur] == 'R') cur++;
						else if (s[cur] == 'L') cur--;
						else if (s[cur] == 'U') cur -= m;
						else cur += m;
					}
					bool ok = vis2[cur];
					while(ss.size()) {
						vis2[ss.back()] = false;
						ss.pop_back();
					}
					if (!ok) {
						continue;
					}
				//	if (ss.find(cur) == ss.end()) continue;
					int len = 0;
					int cur2=cur;
					while(true) {
						if (s[cur2]=='R') cur2++;
						else if (s[cur2] == 'L') cur2--;
						else if (s[cur2] == 'U') cur2 -= m;
						else cur2 += m;
						len++;
						if (cur2 == cur) break;
					}
					rlen[cur] = len;
					cur2 = cur;
					int len2=0;
					cnt[cur].resize(len);
					while(true) {
						base[cur2][0] = cur;
						base[cur2][1] = len2;
						cnt[cur][len2] = make_pair(len2, !c[cur2]);
						len2 = (len2-1+len) % len;
						if (s[cur2] == 'R') cur2++;
						else if (s[cur2] == 'L') cur2--;
						else if (s[cur2] == 'U') cur2 -= m;
						else cur2 += m;
						if (cur2 == cur) break;
					}
					//sort(cnt[cur].begin(), cnt[cur].end());
				}
			}
		}
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (deg[i*m+j] == 0) {
					dfs(i*m+j);
				}
			}
		}
		// for (int i = 0; i < n; ++i) {
		// 	for (int j = 0; j < m; ++j) {
		// 	//	cout<<"i="<<i<<","<<"j="<<j<<":"<<i<<" "<<j<<endl;
		// 		if (base[i*m+j][0] < 0) {
		// 			//cout<<dis[i*m+j][0]<<" "<<dis[i*m+j][1]<<endl;
		// 		}
		// 	}
		// }
		int n1 = 0;
		int n2 = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (base[i*m+j][0] >= 0) n1++;
				if (base[i*m+j][0] == i*m+j) {
				//	cout<<"i="<<i*m+j<<endl;
					for (auto p : cnt[i*m+j]) {
					//	cout<<p.first<<" "<<p.second<<endl;
						if (p.second) n2++;
					//	cout<<"n2="<<n2<<endl;
					}
				}
			}
		}
		printf("%d %d\n", n1, n2);
	}
	return 0;
}
