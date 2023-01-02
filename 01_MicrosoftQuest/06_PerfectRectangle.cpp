#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pp pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        ll n = rectangles.size();
        // We have to find, if the entire area is covered (exactly once)
        // Means.. only 4-corners of covered area exists
        // And, total area on addition == area formed by the 4-corners
        // So, operating on corners :-
        set<pp> corners; // Total unique corners
        // If a corner comes twice.. remove it-as it isn't the corner anymore
        // Either a duplicate area.. or an enlarged area (in duplicate corners)
        ll area=0; // Total area covered
        for(ll i=0; i<n; i++) {
        	ll x1=rectangles[i][0], y1=rectangles[i][1], x2=rectangles[i][2], y2=rectangles[i][3];
        	// Also, keep adding areas of current-rectangles.
        	area += ((abs(x2-x1)) * (abs(y2-y1)));
        	pp p1=mp(x1,y1), p2=mp(x2,y2), p3=mp(x1,y2), p4=mp(x2,y1);
        	vector<pp> points(4);
        	points[0]=p1, points[1]=p2, points[2]=p3, points[3]=p4;
        	for(int j=0; j<4; j++) {
        		pp curr = points[j];
        		if(corners.count(curr) != 0) {
	        		corners.erase(curr); // duplicate corner
	        	}
	        	else{ // Not counted before
	        		corners.insert(curr);
	        	}
        	}
        	
        }
        if(corners.size() == 4) {
        	// In sorted-set --> corners
        	// 1st entry .. smallest point
        	// last entry .. largest point (2 diagonal points)
        	pp p1 = *corners.begin(), p2 = *corners.rbegin();
        	ll x1=p1.fi, y1=p1.se, x2=p2.fi, y2=p2.se;
        	ll area2 = ((abs(x2-x1)) * (abs(y2-y1)));
        	// cout << area2 << " " << area << "\n";
        	return (area2 == area); // Corner-area == Summed-area
        }
        else {
        	return false;
        }
    }
};

int main() {
	int n;
	cin >> n;
	vector<vector<int>> rectangles(n, vector<int>(4,0));
	for(int i=0; i<n; i++) {
		for(int j=0; j<4; j++) {
			cin >> rectangles[i][j];
		}
	}
	Solution solve;
	bool ans = solve.isRectangleCover(rectangles);
	cout << (ans == true ? "true" : "false") << "\n";
	return 0;
}