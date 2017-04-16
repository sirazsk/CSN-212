#include <iostream>
#include <vector>
#include <utility>
#include <time.h>
using namespace std;

vector< pair<int, int> > points, answer;

int check(pair<int,int > p, pair<int,int> q, pair<int,int> r)
{
	int val = (q.second - p.second) * (r.first - q.first) - (q.first - p.first) * (r.second - q.second);
	if (val == 0) return 0;
	return (val > 0) ? 1 : 2;
}

void find_hull() {
	int n = points.size();
	int count = 0;
	int left_index;
	if (n < 3) return;
	int leftmost = points[0].first;
	for (int i = 1; i < n ; i++) {
		if (leftmost > points[i].first) {
			leftmost = points[i].first;
			left_index = i;
		}
	}

	int a, b;
	a = left_index;

	do {
		answer.push_back(points[a]);
		b = (a + 1) % n;

		for (int i = 0; i < n; i++) {
			if (check(points[a], points[i], points[b]) == 2) b = i;
		}

		a = b;
	} while (a != left_index);

	cout << " The required points are : " << endl;
	for (int i = 0; i < answer.size(); i++) {
		cout << "[" << answer[i].first << ", " << answer[i].second << "]\n";
	}
}

int main() {
	int n;
	cout << "Number of points: ";
	cin >> n;
	cout << "Enter the points\n";

	/*
	 * Taking the input of points and pushing into the points vector
	 */
	int x, y;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		points.push_back(make_pair(x, y));
	}

	/*
	 * Finding the convex hull
	 */
	clock_t t;
	t = clock();
	find_hull();
	t = clock() - t;
	printf ("It took %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
	return 0;
}