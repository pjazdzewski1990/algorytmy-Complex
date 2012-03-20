// complex.cpp : Defines the entry point for the console application.
//

//by uruchomiæ na sigmie nale¿y wykomentowaæ
#include "stdafx.h"

#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
	double a,b;
	char command;
	Complex<double> res(1.0, 1.0);
	while(true){
		cout << "Podaj liczbe (re im) ";
		cin >> a >> b;
		Complex<double> c1(a, b);
		cout << c1.toString() <<endl;

		cout << "Podaj liczbe (re im) ";
		cin >> a >> b;
		Complex<double> c2(a, b);
		cout << c2.toString() <<endl;

		cout << "Podaj znak operacji: + - * / ^(dodatnia potega) &(pierwiastkowanie)" <<endl;
		cin >> command;

		switch(command){
			case '+':
				res = c1.add(c2);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '-':
				res = c1.substract(c2);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '*':
				res = c1.multiply(c2);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '/':
				res = c1.divide(c2);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '^':
				res = c1.power((float)a);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '&':
				//Complex<double> *roots = c1.root(a);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			default:
				cout << "Nie poprawny operator" << endl;
		}
	}

	return 0;
}

