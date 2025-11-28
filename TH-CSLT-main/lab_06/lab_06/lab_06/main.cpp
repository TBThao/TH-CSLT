#include <iostream>

#include "fraction_helper/fraction_utils.h"
#include "student_helper/student_utils.h"

using namespace std;

// TODO

// END TODO

int main()
{
    // TODO
    Student a[100];
    int n = 10;
    read_students(a, n, "student_helper/data/input_student.txt");
    write_students(a, n, "student_helper/data/output_student.txt");
    // END TODO
    return 0;
}