#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;

public:
	Fraction operator+(const Fraction& fract) {
		Fraction result;
			cout << this->numerator << "/" << this->denominator << " + " << fract.numerator << "/" << fract.denominator << endl;
			
		if (this->denominator == fract.denominator) {
			result.numerator = fract.numerator + this->numerator;
			result.denominator = this->denominator;
		}
		else {
			int com_denom = this->denominator*fract.denominator;
			this->numerator *= com_denom / this->denominator;
			result.numerator = fract.numerator*(com_denom / fract.denominator);
			result.denominator = com_denom;
			result.numerator += this->numerator;
			this->numerator /= com_denom / this->denominator;
		}
		return result;
	}

//the subtact method simply calls the add method but passes in a negetave value for the second operand
	Fraction operator-(const Fraction& fract) {
		Fraction temp1, temp2, result;
		temp1.setValues(this->numerator, this->denominator);
		temp2.setValues(-(fract.numerator), fract.denominator);
		result = temp1 + temp2;
		return result;
	}

	//makes the fraction negetave
	void negate() {
		this->numerator = -this->numerator;
	}

	Fraction operator*(const Fraction& fract) {
		cout << this->numerator << "/" << this->denominator << " * " << fract.numerator << "/" << fract.denominator << endl;
		Fraction result;
		result.numerator = this->numerator * fract.numerator;
		result.denominator = this->denominator * fract.denominator;
		return result;
	}

//calls the multiply method but with the numerator and denominatlor switched arround t devide
//Code is more efficiently reused
	void divide(int n, int d) {
		//multiply(d, n);
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

	void print(Fraction result) {
		int com_denom = gcd(result.numerator, result.denominator);
		result.numerator /= com_denom;
		result.denominator /= com_denom;
		cout << result. numerator << "/" << result.denominator << endl;
	}
};

int main() {
	Fraction fraction1, fraction2, fractionResult;
	fraction1.setValues(1, 2);
	fraction2.setValues(1, 4);
	fractionResult = fraction1 - fraction2;
	fractionResult.print(fractionResult);
	return 0;
}
