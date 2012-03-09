#ifndef COMPLEX_H
#define COMPLEX_H
 
#include <sstream>
#include <string>
#include <cmath>

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

		//potêga: ujemna lub dodatnia, 
		// tylko liczby ca³kowite 
		Complex<TYP> power(unsigned times){
			if(times == 0){
				return 1;
			}else{
				//procedura podnoszenia do potegi przez wielokrotne mno¿enie 
				if(times > 0){
					Complex<TYP> res = Complex(re, im);
					for(int i=1; i<times; i++){
						res = *this * res;
					}
					return res;
				}else{
					//x^(-a) = (1/x)^a
					Complex one = new Complex(1,0);	//1 + 0i
					Complex cpl = one / *this;
					return cpl.power(-times);
				}
			}
		}

		Complex<TYP> power(float times){
			if(times == 0){
				return 1;
			}else{
				//procedura podnoszenia do potegi przez wielokrotne mno¿enie 
				if(times > 0){
					Complex<TYP> res = Complex(re, im);
					for(int i=1; i<times; i++){
						res = *this * res;
					}
					return res;
				}else{
					//x^(-a) = (1/x)^a
					Complex one = new Complex(1,0);	//1 + 0i
					Complex cpl = one / *this;
					return cpl.power(-times);
				}
			}
		}

		//wzór de Moivre
		Complex[] root(int n){
			Complex* arr = new (nothrow) Complex[n];
			double z = sqrt(pow(re,2.0) + pow(im,2.0));
			double _z = pow(abs(z), -i);

			for(int i=0; i<n; i++){	
				double _re = cos((fi() + 2*i*M_PI)/n);
				_re = _z * _re;

				double _im = sin((fi() + 2*i*M_PI)/n);
				_im = _z * _im;

				arr[i] = Complex(_re, _im);
			}
			return arr;
		}

		//znajduje wartoœæ fi
		double fi(){
			if( re>0 ){	
				return atan(im/re);
			}
			if( re<0 && im>=0 ){
				return atan(im/re) + M_PI;
			}
			if( re<0 && im<0 ){
				return atan(im/re) - M_PI;
			}
			if( re==0 && im>0 ){
				return M_PI/2;
			}
			if( re==0 && im<0 ){
				return -M_PI/2;
			}
			throw exception("Nie mo¿na obliczyæ fi");
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