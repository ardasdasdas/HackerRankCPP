#include<bits/stdc++.h>

using namespace std;
#include<iostream>
//Implement the class Box  
//l,b,h are integers representing the dimensions of the box
class Box {
private:
	int l;
	int b;
	int h;
public:
	int getLength()
	{
		return l;
	}
	int getBreadth()
	{
		return b;
	}
	int getHeight()
	{
		return h;
	}
	long long CalculateVolume()
	{
		return (long long)l*b*h;
	}
	Box()
	{
		this->l = 0;
		this->b = 0;
		this->h = 0;
	}
	Box(int l, int b, int h)
	{
		this->l = l;
		this->b = b;
		this->h = h;
	}
	Box(Box& B)
	{
		l = B.getLength();
		h = B.getHeight();
		b = B.getBreadth();
	}
	bool operator<(Box& b)
	{
		if (this->l < b.getLength() || (this->b < b.getBreadth() && this->l == b.getLength()) || (h < b.getHeight() && this->b == b.getBreadth() && this->l == b.getLength()))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& out, Box& B)
	{
		int l = B.getLength();
		int b = B.getBreadth();
		int h = B.getHeight();
		return out << l << ' ' << b << ' ' << h;
	}

};
//Overload operator < as specified
//bool operator<(Box& b)

//Overload operator << as specified
//ostream& operator<<(ostream& out, Box& B)

