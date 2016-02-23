#include <iostream>

using namespace std;

class Fraction{
private:
	int numerator;
	int denominator;

public:
	Fraction(){
	}

	void add(int n, int d, bool add = true){
		if (denominator == d){
			if (add)
				numerator += n;
			else
				numerator -= n;
		}
		else{
			int com_denom = denominator*d;
			numerator *= com_denom / denominator;
			n *= com_denom / d;
			denominator = com_denom;
			if (add)
				numerator += n;
			else
				numerator -= n;

		}
	}

	void subtract(int n, int d){
		add(n, d, false);
	}

	void multiply(int n, int d){
		numerator *= n;
		denominator *= d;
	}

	void divide(int n, int d){
		multiply(d, n);
	}

	void getValues(int &n, int &d){
		n = numerator;
		d = denominator;
	}

	void setValues(int n, int d){
		numerator = n;
		denominator = d;
	}

	void print(){
		cout << numerator << "/" << denominator << endl;
	}
};

int main(){
	Fraction fraction;
	fraction.setValues(5, 6);
	fraction.add(1, 2);
	fraction.print();
	return 0;
}