#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>

#include "student_utils.h"

using namespace std;

float round_to_decimal(float var, int decimal_places) {
    float factor = pow(10.0f, decimal_places);
    return round(var * factor) / factor;
}

// TODO
void read_students(Student students[], int& num_students, std::string file_name = "input_student.txt"){
    ifstream fin(file_name);
    for(int i = 0; i < num_students; i++){
        string s = "", x = "";
        getline(fin, s);
        stringstream student_ss(s);
        getline(student_ss, x, ',');
        students[i].name = x;
        getline(student_ss, x, ',');
        students[i].student_code = stoi(x);
        getline(student_ss, x);
        students[i].score = stof(x);
        fin.ignore();
    }
}
void write_students(Student students[], int& num_students, std::string out_file_name = "output_student.txt"){
    ofstream fout(out_file_name);
    for(int i = 0; i < num_students; i++){
        fout << students[i].name << ", " << students[i].student_code << ", " << students[i].score << endl;
    }
}

// END TODO