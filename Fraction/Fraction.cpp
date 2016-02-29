#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	void add(int n, int d) {
		if (denominator == d) {
				numerator += n;
		}
		else {
			int com_denom = denominator*d;
			numerator *= com_denom / denominator;
			n *= com_denom / d;
			denominator = com_denom;
			numerator += n;
		}
	}

//the subtact method simply calls the add method but passes in false to the third argument to tell teh add method to
//subtract. Code is more efficiently reused
	void subtract(int n, int d) {
		add(-n, d);
	}

	void multiply(int n, int d) {
		numerator *= n;
		denominator *= d;
	}

//calls the multiply method but with the numerator and denominatlor switched arround t devide
//Code is more efficiently reused
	void divide(int n, int d) {
		multiply(d, n);
	}

//calculates the greatest common divisor to simplify the final answer
	int gcd(int a, int b) {
		int remainder = a % b;
		if (remainder == 0)
			return b;
		else
			return gcd(b, remainder);
	}

	void getValues(int &n, int &d) {
		n = numerator;
		d = denominator;
	}

	void setValues(int n, int d) {
		numerator = n;
		denominator = d;
	}

	void print() {
		int com_denom = gcd(numerator, denominator);
		numerator /= com_denom;
		denominator /= com_denom;
		cout << numerator << "/" << denominator << endl;
	}
};

int main() {
	Fraction fraction;
	fraction.setValues(5, 6);
	fraction.add(1, 2);
	fraction.print();
	return 0;
}
