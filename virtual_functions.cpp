#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
static int idProfessor = 0;
static int idStudent = 0;
class Person {
public:
	Person() {};
	~Person() {};
	virtual void getdata() = 0;
	virtual void putdata() = 0;
};
class Professor : public Person {

	string name;
	int age;
	int publications;
public:
	Professor() {};
	~Professor() {};
	void getdata() {
		cin >> name;
		cin >> age;
		cin >> publications;
	};
	void putdata() {
		cout << name << " " << age << " " << publications << " " << ++idProfessor << endl;
	}
};
class Student : public Person {
	string name;
	int age;
	int marks;
	int sumOfMarks = 0;
public:
	Student() {};
	~Student() {};
	void getdata() {
		cin >> name;
		cin >> age;
		for (int i = 0; i < 6; i++) {
			cin >> marks;
			sumOfMarks += marks;
		}
	};
	void putdata() {
		cout << name << " " << age << " " << sumOfMarks << " " << ++idStudent << endl;
	}
};
int main() {

	int n, val;
	cin >> n; //The number of objects that is going to be created.
	Person *per[n];

	for (int i = 0; i < n; i++) {

		cin >> val;
		if (val == 1) {
			// If val is 1 current object is of type Professor
			per[i] = new Professor;

		}
		else per[i] = new Student; // Else the current object is of type Student

		per[i]->getdata(); // Get the data from the user.

	}

	for (int i = 0; i < n; i++)
		per[i]->putdata(); // Print the required output for each object.

	return 0;

}