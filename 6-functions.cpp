#include <iostream>
#include <cstdio>
using namespace std;

int max_of_four(int a, int b, int c, int d) {
	int max = a;
	if (max < b)
		max = b;
	if (max < c)
		max = c;
	if (max < d)
		max = d;
	return max;
}
int main() {
	int a, b, c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	int ans = max_of_four(a, b, c, d);
	cout << ans;

	system("pause");
}

