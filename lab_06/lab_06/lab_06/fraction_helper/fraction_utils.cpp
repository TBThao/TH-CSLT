#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "fraction_utils.h"

using namespace std;

// TODO
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
Fraction reduce_fraction(const Fraction &fraction)
{
    Fraction ans;
    int gcd = GCD(fraction.numerator, fraction.denominator);

    ans.numerator = fraction.numerator / gcd;
    ans.denominator = fraction.denominator / gcd;
    return ans;
}
Fraction sum_fraction(const Fraction &first_fraction, const Fraction &second_fraction){
    int lcm =(first_fraction.denominator*second_fraction.denominator)/ GCD(first_fraction.denominator, second_fraction.denominator);
    Fraction ans = {(first_fraction.numerator* (lcm/first_fraction.denominator) + second_fraction.numerator * (lcm/second_fraction.denominator)), lcm};
    
    return reduce_fraction(ans);
}
Fraction minus_fraction(const Fraction &first_fraction, const Fraction &second_fraction){
    int lcm =(first_fraction.denominator*second_fraction.denominator)/ GCD(first_fraction.denominator, second_fraction.denominator);
    Fraction ans = {(first_fraction.numerator* (lcm/first_fraction.denominator) - second_fraction.numerator * (lcm/second_fraction.denominator)), lcm};
    
    return reduce_fraction(ans);
}
Fraction multiply_fraction(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction ans = {first_fraction.numerator * second_fraction.numerator, first_fraction.denominator * second_fraction.denominator};
    return reduce_fraction(ans);
}
Fraction divide_fraction(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction ans = {first_fraction.numerator * second_fraction.denominator, first_fraction.denominator * second_fraction.numerator};
    return reduce_fraction(ans);
}
bool is_equal(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction a = reduce_fraction(first_fraction), b = reduce_fraction(second_fraction);
    int lcm = (a.denominator*b.denominator)/ GCD(a.denominator, b.denominator);
    return (a.numerator * (lcm / a.numerator) == b.numerator*(lcm/b.numerator));
}
bool is_greater(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction a = reduce_fraction(first_fraction), b = reduce_fraction(second_fraction);
    int lcm = (a.denominator*b.denominator)/ GCD(a.denominator, b.denominator);
    return (a.numerator * (lcm / a.numerator) > b.numerator*(lcm/b.numerator));
}

bool is_less(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction a = reduce_fraction(first_fraction), b = reduce_fraction(second_fraction);
    int lcm = (a.denominator*b.denominator)/ GCD(a.denominator, b.denominator);
    return (a.numerator * (lcm / a.numerator) < b.numerator*(lcm/b.numerator));
}

void auto_test_fraction(std::string input_file_name, std::string output_file_name){
    ifstream fin(input_file_name);
    ofstream fout(output_file_name);
}
    // END TODO