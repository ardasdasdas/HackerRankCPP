#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
	int size;
	cin >> size;
	int *A = new int[size];

	for (int i = 0; i < size; i++)
	{
		cin >> A[i];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		cout << A[i] << " ";
	}
	system("pause");
}
