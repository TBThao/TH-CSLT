#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "fraction_utils.h"

using namespace std;

// TODO
int GCD(int a, int b){
    if (b == 0)
        return a;
    return GCD(b, a % b);
}
Fraction reduce_fraction(const Fraction &fraction){
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
    return (a.numerator * (lcm / a.denominator) == b.numerator*(lcm/b.denominator));
}
bool is_greater(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction a = reduce_fraction(first_fraction), b = reduce_fraction(second_fraction);
    int lcm = (a.denominator*b.denominator)/ GCD(a.denominator, b.denominator);
    return (a.numerator * (lcm / a.denominator) > b.numerator*(lcm/b.denominator));
}

bool is_less(const Fraction& first_fraction, const Fraction& second_fraction){
    Fraction a = reduce_fraction(first_fraction), b = reduce_fraction(second_fraction);
    int lcm = (a.denominator*b.denominator)/ GCD(a.denominator, b.denominator);
    return (a.numerator * (lcm / a.denominator) < b.numerator*(lcm/b.denominator));
}
int pow(int x, int y){
    int ans = 1;
    for(int i = 1; i <= y; i++){
        ans *= x;
    }
    return ans;
}
int cv(string s){
    int ans = 0;
    if(s[0] == ' ') s.erase(0, 1);
    int n = s.size();
    for(int i = 0; i < n; i++){
        ans += (s[i] - '0') * pow(10, n-i-1);
    }
    return ans;
}
void auto_test_fraction(std::string input_file_name, std::string output_file_name){
    ifstream fin(input_file_name);
    ofstream fout(output_file_name);
    int t;
    fin >> t;
    while(t--){
        Fraction a[10006];
        int p = 0;
        char c;
        fin >> c;
        string s = "", x = "";
        fin.ignore();
        getline(fin, s);
        stringstream fraction_ss(s);
        while(getline(fraction_ss, x, ',')){
            stringstream tumau_ss(x);
            string tmp = "";
            getline(tumau_ss, tmp, '/');
            a[p].numerator = cv(tmp);
            getline(tumau_ss, tmp);
            a[p].denominator = cv(tmp);
            p++;
            // fout << p << endl;
        }
        if(c == '+'){
            for(int i = 1; i < p; i++){
                // fout << a[i].numerator << " " << a[i].denominator << endl;
                a[i] = sum_fraction(a[i], a[i-1]);
            }
        }
        if(c == '-'){
            for(int i = 1; i < p; i++){
                // fout << a[i].numerator << " " << a[i].denominator << endl;
                a[i] = minus_fraction(a[i-1], a[i]);
            }
        }
        if(c == '*'){
            for(int i = 1; i < p; i++){
                // fout << a[i].numerator << " " << a[i].denominator << endl;
                a[i] = multiply_fraction(a[i-1], a[i]);
            }
        }
        if(c == '/'){
            for(int i = 1; i < p; i++){
                // fout << a[i].numerator << " " << a[i].denominator << endl;
                a[i] = divide_fraction(a[i-1], a[i]);
            }
        }
        if(c == '>'){
            // fout << a[0].numerator << " " << a[0].denominator << endl;
            // fout << a[1].numerator << " " << a[1].denominator;
            fout << is_greater(a[0], a[1]);
            continue;
        }
        if(c == '<'){
            fout << is_less(a[0], a[1]);
            continue;
        }
        if(c == '='){
            fout << is_equal(a[0], a[1]);
            continue;
        }
        fout << a[p-1].numerator;
        if(a[p-1].denominator != 1){
            fout << "/" << a[p-1].denominator << endl;
            continue;
        }
        fout << endl;
    }
    return;
}
    // END TODO