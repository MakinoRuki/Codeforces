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
#define N 2002
using namespace std;
typedef long long ll;
int n, k;
int  dp[N][N][3];
vector<string> ds;
int mp2[130][12];
int main() {
	cin>>n>>k;
	memset(dp, -1, sizeof(dp));
	ds.clear();
	for (int i = 1; i <= n; ++i) {
		char s[8];
		scanf("%s", s);
		ds.push_back(string(s));
	}
	map<string, int> mp1;
	mp1.clear();
	memset(mp2, -1, sizeof(mp2));
	mp1["0000000"] = 10;
	mp1["1110111"] = 0;
	mp1["0010010"] = 1;
	mp1["1011101"] = 2;
	mp1["1011011"] = 3;
	mp1["0111010"] = 4;
	mp1["1101011"] = 5;
	mp1["1101111"] = 6;
	mp1["1010010"] = 7;
	mp1["1111111"] = 8;
	mp1["1111011"] = 9;
	for (int i = 0; i < (1<<7); ++i) {
		string s1 = "";
		for (int j= 0; j < 7; ++j) {
			if ((1<<(6-j))&i) s1.push_back('1');
			else s1.push_back('0');
		}
		for (int j = 0; j < (1<<7); ++j) {
			string s2 = "";
			for (int j2 = 0; j2 < 7; ++j2) {
				if ((1<<(6-j2))&j) s2.push_back('1');
				else s2.push_back('0');
			}
			//if (i==0 && j==127) cout<<"xxx"<<(i&j)<<" "<<i<<" "<<s1<<" "<<s2<<" "<<mp1[s2]<<endl;
			if (mp1.find(s2)!=mp1.end() && mp1[s2]>=0 && mp1[s2]<=9 && (i&j)==i) {
				int det=__builtin_popcount(j)-__builtin_popcount(i);
				mp2[i][det] = max(mp2[i][det], mp1[s2]);
			}
		}
	}
	//cout<<"###"<<mp2[make_pair("0000000", 7)]<<endl;
	dp[n+1][0][0] = 0;
	for (int i = n+1; i > 1; --i) {
		int st = 0;
		for (int j = 0; j < 7; ++j) {
			st = st*2 + ds[i-2][j]-'0';
		}
		for (int j = 0; j <= k; ++j) {
			for (int x=0; x<2; ++x) {
				if (dp[i][j][x]>=0) {
					if (mp1.find(ds[i-2]) != mp1.end()) {
						int d = mp1[ds[i-2]];
						if (d==10) {
							if (x==0) {
								dp[i-1][j][x] = 0;
							}
							for (int d2 = 1; d2<=7; ++d2) {
							//	if (i==2 && j==0 && x==0 && d2==7) cout<<"***"<<ds[i-2]<<" "<<mp2[make_pair(ds[i-2],d2)]<<endl;
								if (mp2[st][d2] >= 0 && j+d2<=k) {
									dp[i-1][j+d2][1] = max(dp[i-1][j+d2][1], dp[i][j][x]+1);
								}
							}
						} else {
							for (int d2 = 0; d2 <= 5;++d2) {
								if (mp2[st][d2]>=0 && j+d2<=k) {
									dp[i-1][j+d2][1] = max(dp[i-1][j+d2][1], dp[i][j][x]+1);
								}
							}
						}
					} else {
						for (int d2=1; d2<=6; ++d2) {
							if (mp2[st][d2]>=0 && j+d2<=k) {
								dp[i-1][j+d2][1] = max(dp[i-1][j+d2][1], dp[i][j][x]+1);
							}
						}
					}
				}
			}
		}
	}
//	cout<<dp[1][k][1]<<endl;
//	cout<<dp[2][1][1]<<" "<<dp[1][5][1]<<endl;
	bool ok = true;
	bool found=false;
	int id=n;
	for (int i = 1; i <= n; ++i) {
		if (ds[i-1]=="0000000") {
			if (dp[i][k][1]>0) {
				found=true;
			}
		} else {
			if (dp[i][k][1]>0) {
				found=true;
				id=i;
			} else {
				ok = false;
			}
			break;
		}
	}
	if (!found || !ok) {
		cout<<-1<<endl;
	} else {
		string ans="";
		for (int i = 1 ; i <= id; ++i) {
			if (dp[i][k][1]>0) {
				string res="";
				int cur=k;
				int len=dp[i][k][1];
				for (int j=1; j<=len; ++j) {
					int maxd=0;
					int id=-1;
					int st=0;
					for (int d2=0; d2<7; ++d2) {
						st=st*2+ds[i+j-2][d2]-'0';
					}
					for (int d2 = 0; d2 <= 7; ++d2) {
						int x2 = (j<len? 1 : 0);
						// if (i==1 && j==2 && d2==1) {
						// 	cout<<"xxx"<<endl;
						// 	cout<<mp2[make_pair(ds[i+j-2],d2)]<<" "<<dp[i+j][cur-d2][x2]<<" "<<dp[i+j-1][cur][1]<<endl;
						// }
						if (mp2[st][d2]>=0 && d2<=cur && dp[i+j][cur-d2][x2]+1==dp[i+j-1][cur][1]) {
							int d3 = mp2[st][d2];
							//if (i==1 && j==2 && d2==1) cout<<"d3="<<d3<<endl;
							if (id<0) {
								maxd=d3;
								id = d2;
							} else {
								if (d3 > maxd) {
									maxd = d3;
									id = d2;
								}
							}
						}
					}
					res.push_back('0'+maxd);
					cur-=id;
				//	cout<<"i="<<i<<" "<<cur<<endl;
				}
				if (res.size()>ans.size()) ans=res;
				else if (res.size()==ans.size()) ans = max(ans, res);
			}
		}
		cout<<ans<<endl;
	}
	// if (mp1[ds[0]]==10) {
	// 	if (dp[1][k][1] || dp[1][k][2]) {
	// 		string ans = "";
	// 		for (int x = 1; x < 3; ++x) {
	// 			if (dp[1][k][x]) {
	// 				string res="";
	// 				int cur=k;
	// 				for (int i = 1; i <= n; ++i) {
	// 					int d = mp1[ds[i-1]];
	// 					int maxd= d;
	// 					int id =0;
	// 					for (int d2 = 0; )
	// 				}
	// 			}
	// 		}
	// 	} else {
	// 		cout<<-1<<endl;
	// 	}
	// } else {
	// 	if (dp[1][k][2]) {

	// 	} else {
	// 		cout<<-1<<endl;
	// 	}
	// }
	// if (dp[1][k]) {
	// 	string ans="";
	// 	int cur=k;
	// 	for (int i = 1; i <= n; ++i) {
	// 		int d = mp1[ds[i-1]];
	// 		int maxd = d;
	// 		int id = 0;
	// 		for (int d2 = 0;d2 <= 5; ++d2) {
	// 			if (mp2[d][d2]>=0 && d2<=cur && dp[i+1][cur-d2]) {
	// 				if (mp2[d][d2] > maxd) {
	// 					maxd = mp2[d][d2];
	// 					id = d2;
	// 				}
	// 			}
	// 		}
	// 		ans.push_back('0'+maxd);
	// 		cur -= id;
	// 	}
	// 	cout<<ans<<endl;
	// } else {
	// 	cout<<-1<<endl;
	// }
	return 0;
}
