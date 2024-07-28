#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
namespace dstl {
class Fraction
{
public:
  Fraction (int n=0, int d=1);

  int numerator() const;
  int denominator() const;
  Fraction reciprocal() const;
  double value() const;
  void invert();

  Fraction& operator += (const Fraction& other);
  Fraction& operator -= (const Fraction& other);
  Fraction& operator *= (const Fraction& other);
  Fraction& operator /= (const Fraction& other);

private:
  int numerator_val;
  int denomenator_val;
  void reduce();
};

Fraction operator + (const Fraction& a, const Fraction& b);
Fraction operator - (const Fraction& a, const Fraction& b);
Fraction operator * (const Fraction& a, const Fraction& b);
Fraction operator / (const Fraction& a, const Fraction& b);

bool operator == (const Fraction& a, const Fraction &b);
bool operator != (const Fraction& a, const Fraction &b);
bool operator < (const Fraction& a, const Fraction &b);
bool operator <= (const Fraction& a, const Fraction &b);
bool operator > (const Fraction& a, const Fraction &b);
bool operator >= (const Fraction& a, const Fraction &b);

std::ostream& operator << (std::ostream & out, const Fraction& f);

Fraction::Fraction(int a, int b): numerator_val{a}, denomenator_val {b}
{
  this->reduce(); 
};

void Fraction::reduce()
{
  if(denomenator_val == 0){
    throw std::range_error("Fraction cannot have "
        "Zero denominator");
  } else if(numerator_val == 0){
    denomenator_val = 1;
  }else {
    if(denomenator_val < 0) {
      numerator_val *= -1;
      denomenator_val *= -1;
    }

    int gcd {denomenator_val};
    int n = abs(numerator_val);

    while(n != 0){
      int temp = n;
      n = gcd % n;
      gcd = temp;
    }

    numerator_val /= gcd;
    denomenator_val /= gcd;
  }
};


int Fraction::numerator() const 
{
  return numerator_val;
}

int Fraction::denominator() const 
{
  return denomenator_val;
}

Fraction Fraction::reciprocal() const 
{
  return Fraction(denomenator_val, numerator_val);
}

double Fraction::value() const
{
  return (double) numerator_val / (double) denomenator_val;
}

void Fraction::invert()
{
  std::swap(numerator_val, denomenator_val);
  reduce();
}

Fraction& Fraction::operator+=(const Fraction &other)
{
  numerator_val = numerator_val * other.denomenator_val + denomenator_val * other.numerator_val; 
  denomenator_val = denomenator_val * other.denomenator_val;
  reduce();
  return *this;
}

Fraction& Fraction::operator-=(const Fraction &other)
{
  numerator_val = numerator_val * other.denomenator_val - other.numerator_val * denomenator_val;
  denomenator_val = denomenator_val * other.denomenator_val;
  reduce();
  return *this;
}

Fraction& Fraction::operator*=(const Fraction &other)
{
  numerator_val = numerator_val * other.numerator_val;
  denomenator_val = denomenator_val * other.denomenator_val;
  reduce();
  return *this;
}

Fraction& Fraction::operator/=(const Fraction &other)
{
  numerator_val = numerator_val * other.denomenator_val;
  denomenator_val = denomenator_val * other.numerator_val;
  reduce();
  return *this;
}

Fraction operator + (const Fraction& a, const Fraction& b)
{
  Fraction result = a;
  result += b;
  return result;
}

Fraction operator - (const Fraction& a, const Fraction& b)
{
  Fraction result = a;
  result -= b;
  return result;
}

Fraction operator * (const Fraction& a, const Fraction& b)
{
  Fraction result = a;
  result *= a;
  return result;
}

Fraction operator / (const Fraction& a, const Fraction& b)
{
  Fraction result = a;
  result /= a;
  return result;
}

bool operator==(const Fraction &a, const Fraction &b)
{
  return a.numerator() == b.numerator() and a.denominator() == b.denominator();
}
bool operator!=(const Fraction &a, const Fraction &b)
{
  return a.numerator() != b.numerator() or a.denominator() != b.denominator();
}
bool operator < (const Fraction& a, const Fraction& b)
{
  return a.numerator() * b.denominator()  < b.numerator() * a.denominator();
}
bool operator <= (const Fraction& a, const Fraction& b)
{
  return (a < b) or (a == b);
}
bool operator > (const Fraction& a, const Fraction& b)
{
  return b < a;
}
bool operator >= (const Fraction& a, const Fraction& b)
{
  return a > b or a == b;
}
std::ostream& operator << (std::ostream& out, const Fraction & fraction)
{
    out << fraction.numerator();
    if(fraction.denominator() != 1) out << "/" << fraction.denominator() << "\n";
    return out;
}
}

#endif
