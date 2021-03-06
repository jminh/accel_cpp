#include <list>

#include "Student_info.h"
#include "grade.h"

using std::istream;
using std::vector;
using std::list;

istream& read(istream& is, Student_info& s)
{
    is >> s.name >> s.midterm >> s.final_grade;

    read_hw(is, s.homework);
    return is;
}


bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}


istream& read_hw(istream& in , vector<double>& hw)
{
    if (in) {
        hw.clear();

        double x;
        while (in >>x)
            hw.push_back(x);
        in.clear();
    }
    return in;
}


vector<Student_info> extract_fails(vector<Student_info>& students)
{
    vector<Student_info> fail;

    vector<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}


list<Student_info> extract_fails(list<Student_info>& students)
{
    list<Student_info> fail;

    list<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else
            ++iter;
    }
    return fail;
}


