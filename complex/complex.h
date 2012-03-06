#ifndef COMPLEX_H
#define COMPLEX_H
 
#include <sstream>
#include <string>

using namespace std;

template <class TYP> class Complex {
	private:
		//liczba zespolona w postaci Z=re + im*i
		TYP re;
		TYP im;

	public:
		Complex(TYP _re, TYP _im){
			re= _re;
			im =_im;
		}

		string toString(){
			stringstream ss;
			ss << '(';
			ss << re;
			if(im>=0){
				ss << '+';
			}
			ss << im;
			ss << 'i';
			ss << ')';
			return ss.str();
		}

		string toTrigonometric(){
			TYP z = sqrt(pow(re,(TYP)2.0) + pow(im,(TYP)2.0));
			TYP cos = re/z;
			TYP sin = im/z;

			stringstream ss;
			ss << '|';
			ss << z;
			ss << '|';
			ss << '(';
			ss << cos;
			ss << '+';
			ss << sin; 
			ss << ')';
			return ss.str();
		}

		Complex<TYP> power(unsigned times){
			//procedura podnoszenia do potegi przez wielokrotne mno¿enie 
			if(times == 0){
				return 1;
			}else{
				Complex<TYP> res = Complex(re, im);
				for(int i=1; i<times; i++){
					res = *this * res;
				}
				return res;
			}
		}

		//OPERATORY
		inline Complex<TYP> operator+(Complex<TYP> second){
			return Complex(re + second.re, im + second.im);
		}
		
		inline Complex<TYP> operator-(Complex<TYP> second){
			return Complex(re - second.re, im - second.im);
		}

		inline Complex<TYP> operator*(Complex<TYP> second){
			return Complex(re*second.re - im*second.im, im*second.re + re*second.im);
		}

		inline Complex<TYP> operator/(Complex<TYP> second){
			float div = second.re * second.re + second.im * second.im;
			return Complex((re*second.re + im*second.im)/div, (im*second.re - re*second.re)/div);
		}
};
 
#endif