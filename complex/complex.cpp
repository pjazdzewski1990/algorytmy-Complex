// complex.cpp : Defines the entry point for the console application.
//

//by uruchomiæ na sigmie nale¿y wykomentowaæ
#include "stdafx.h"

#include "complex.h"
#include <iostream>

using namespace std;

int main()
{
	float a,b;
	char command;
	Complex<float> res(1.0, 1.0);

	while(true){
		cin >> a >> b;
		Complex<float> c1(a, b);
		cout << c1.toString() <<endl;

		cin >> a >> b;
		Complex<float> c2(a, b);
		cout << c2.toString() <<endl;

		cout << "Podaj znak operacji" <<endl;
		cin >> command;
		switch(command){
			case '+':
				res = c1 + c2;
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '-':
				res = c1 - c2;
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '*':
				res = c1 * c2;
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			case '^':
				res = c1.power(c2);
				cout << res.toString() << " " << res.toTrigonometric() << endl;
				break;
			default:
				cout << "Nie poprawny operator" << endl;
		}
	}

	return 0;
}

