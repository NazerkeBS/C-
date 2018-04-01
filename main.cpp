#include <iostream>

using namespace std;
// to use private variables of another class: friend

class Rational{
private:
    int num;
    int den;
public:
    Rational(int num=0, int den=1){    // default constructor
    this->num=num;
    if(den != 0){
    this->den=den;
    }
    }
    Rational(const Rational& other) : num(other.num),den(other.den){
    // copy constructor
    }
    Rational& operator=(const Rational& other){
    // assignment
    num=other.num;
    den=other.den;
    return *this;
    }

    Rational operator*(const Rational& right){
    Rational result(num*right.num, den*right.den);
    return result;
    }

    Rational operator+(const Rational&right){
    Rational result(num*right.den+den*right.num, den*right.den);
    return result;
    }

    Rational operator/(const Rational&right){
    Rational result(num*right.den, den*right.num);
    return result;
    }



   int getNum(){ return num;}
   int getDen(){ return den;}

};

void print( Rational& r){
cout << r.getNum() << "/" << r.getDen() << endl;
}
int main()
{
Rational r1(2,2);
Rational r2(1,2);
Rational r= r1 * r2;
cout << "multiplication: ";
 print(r);
r=r1/r2;
cout << "division: ";
 print(r);
r=r1+r2;
cout << "addition: ";
print(r);

    return 0;
}
