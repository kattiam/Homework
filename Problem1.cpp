//Написать программу, высчитывающую корни квадратного уравнения вида ax^2 + bx + c, где a, b, c вещественные числа.

#include <iostream>

using namespace std;


int main()
{
	double a, b, c, d;
	double x, x1, x2;
	cin >> a >> b >> c;
  if (a == 0) { cout << "No solution"; }
	double k = b * b;
	double l = 4 * a * c;
	d = k - l;
	if (d = 0) {
		d = sqrt(d);
		x = (-b) / (2 * a);
		cout << x;
	}
	if (d < 0) {
		cout << "No solution";
	}
	else {
		d = sqrt(d);
		x1 = (-b + d) / (2 * a);
		x2 = (-b - d) / (2 * a);
		cout << x1 << " " << x2;
	}

	return 0;
}
