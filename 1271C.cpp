#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <map>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#define N 200020
#define inf 1000000000
using namespace std;
int a,b,c,d,e,f;
typedef long long ll;
int n;
int sx, sy;
int main() {
	cin>>n>>sx>>sy;
	vector<int> xs;
	vector<int> ys;
	xs.clear();
	ys.clear();
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin>>x>>y;
		xs.push_back(x);
		ys.push_back(y);
	}
	int cnt=0;
	int ax, ay;
	for (int i = -1; i <= 1; ++i) {
		for (int j = -1; j <= 1; ++j) {
			int nx = sx+i;
			int ny = sy+j;
			if (nx == sx && ny == sy) continue;
			if (nx <0 || nx > 1000000000 || ny < 0 || ny > 1000000000) continue;
			int tot=0;
			for (int k = 0; k < n; ++k) {
				if ((nx >= sx && nx <= xs[k]) || (nx >= xs[k] && nx <= sx)) {
					if ((ny >= sy && ny <= ys[k]) || (ny >= ys[k] && ny <= sy)) {
						tot++;
					}
				}
			}
			if (tot >= cnt) {
				cnt = tot;
				ax = nx;
				ay = ny;
			}
		}
	}
	cout<<cnt<<endl;
	cout<<ax<<" "<<ay<<endl;
	return 0;
}
