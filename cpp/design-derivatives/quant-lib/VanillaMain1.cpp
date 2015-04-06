/*
requires DoubleDigital.cpp
	PayOff2.cpp
	Random1.cpp
	SimpleMC3.cpp
*/
#include "SimpleMC3.h"
#include "DoubleDigital.h"
#include<iostream>
using namespace std;
#include "Vanilla1.h"

int main()
{
	double Expiry;
	double Low, Up;
	double Spot;
	double Vol;
	double r;
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry\n";
	cin >> Expiry;

	cout << "\nEnter Low Barrier\n";
	cin >> Low;

	cout << "\nEnter Up Barrier\n";
	cin >> Up;

	cout << "\nEnter vol\n";
	cin >> Vol;

	cout << "\nr\n";
	cin >> r;

	cout << "\nNumber of Paths\n";
	cin >> NumberOfPaths;

	PayOffDoubleDigital thePayOff(Low, Up);
	VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption
		Spot,
		Vol,
		r,
		NumberOfPaths);

	cout << "the price is " << result << "\n";
	double tmp;
	cin >> tmp;

	return 0;
}
