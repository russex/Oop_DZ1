#include<iostream>
using namespace std;


class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}

	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:" << this << endl;
	}

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		return *this;
	}

	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	Point& operator++() 
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this; 
		x++;
		y++;
		return old;
	}

	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

double distance(const Point& W, const Point& T);
double distance_2(const Point& A, const Point& B)
{
	return sqrt(pow(A.get_x() - B.get_x(), 2) + (pow(A.get_y() - B.get_y(), 2)));
}

Point operator+(const Point& left, const Point& right)
{
	Point result; 
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
Point operator-(const Point& left, const Point& right)
{
	Point result(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	return result;
}
Point operator*(const Point& left, const Point& right)
{
	return Point(left.get_x() * right.get_x(), left.get_y() * right.get_y());
}

ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X =" << obj.get_x() << "\tY = " << obj.get_y();
	return os;
}


void main()
{
	setlocale(LC_ALL, "Rus");

	int x;
	int y;
	
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	A += B;
	A.print();
	B = A++;

	cout << A << endl;
	cout << B << endl;

}
double distance(const Point& W, const Point& T)
{
	return sqrt((W.get_x() - T.get_x()) * (W.get_x() - T.get_x()) + (W.get_y() - T.get_y()) * (W.get_y() - T.get_y()));
}