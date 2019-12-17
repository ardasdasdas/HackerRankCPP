#include <iostream>
#include<cmath>
using namespace std;
void update(int *a, int *b) {
	int a1 = *a, a2 = *b;
	*a = a1 + a2;
	*b = abs(a1 - a2);
}
int main() {
	int a, b;
	int *pa = &a, *pb = &b;
	cin >> a;
	cin >> b;
	update(pa, pb);
	cout << *pa << endl;
	cout << *pb << endl;
	system("pause");
}

