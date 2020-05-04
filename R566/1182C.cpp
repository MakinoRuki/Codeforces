#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#define N 1000002
using namespace std;
typedef long long ll;
int n;
vector<string> st[5][N];
vector<string> st2[N];
vector<pair<int, string>> st3[2];
int main() {
  cin>>n;
  for (int i = 0; i < n; ++i) {
  	string s;
  	cin>>s;
  	int cnt=0;
  	int last=-1;
  	for (int j = 0; j < s.size(); ++j) {
  		if (s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u') {
  			cnt++;
  			if (s[j]=='a') last=0;
  			if (s[j]=='e') last=1;
  			if (s[j]=='i') last=2;
  			if (s[j]=='o') last=3;
  			if (s[j]=='u') last=4;
  		}
  	}
  	st[last][cnt].push_back(s);
  	st2[cnt].push_back(s);
  }
  int tot=0;
  for (int i = 1; i < N; ++i) {
  	tot += st2[i].size()/2;
  }
  int sum=0;
  for (int i = 0; i < 5; ++i) {
  	int j;
  	for (j = 0; j < N; ++j) {
  		int k;
  		for (k = 1; k <= st[i][j].size()/2; ++k) {
  			if (sum+1<=tot-sum-1) {
  				sum++;
  			} else {
  				break;
  			}
  		}
  		for (int k2 = 1; k2 < k; ++k2) {
  			st3[0].push_back(make_pair(j, st[i][j][2*k2-2]));
  			st3[0].push_back(make_pair(j, st[i][j][2*k2-1]));
  		}
  		for (int k2=2*k-2; k2 < st[i][j].size(); ++k2) {
  			st3[1].push_back(make_pair(j, st[i][j][k2]));
  		}
  		//if (k <= st[i][j].size()/2) break;
  	}
  	//if (j < N) break;
  }
  sort(st3[1].begin(), st3[1].end());
  cout<<sum<<endl;
  int j = 0;
  for (int i = 1; i <= sum; ++i) {
  	while(j < st3[1].size() && st3[1][j].first != st3[1][j+1].first) j++;
  	cout<<st3[1][j].second<<" "<<st3[0][2*i-2].second<<endl;
  	cout<<st3[1][j+1].second<<" "<<st3[0][2*i-1].second<<endl;
  	j += 2;
  }
  return 0;
}
