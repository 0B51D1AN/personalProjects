#include <iostream>
using namespace std;


double convert(double value); //function prototype

int main()
{
	float ans;

	cout << "Please enter a Celsius value: ";
	
	cin >> ans;

	
	cout<< ans << " degrees Celsius is: "<<convert(ans)<< " degrees Fahrenheit";


	return 0;
}

double convert(double value)
{
	return (value*1.8)+32.0;

}

// 2.
// a.
// b.
// c.O(n^2)
// d.
// e.On(^2)
// f.
// g.
//
//3.
//
//
//4.
//a. O(n)
//T(n)= 5(n-2))
