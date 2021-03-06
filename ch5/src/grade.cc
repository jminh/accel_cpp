#include <stdexcept>
#include <vector>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;


double grade(double midterm, double final_grade, double homework)
{
    return 0.2 * midterm + 0.4 * final_grade + 0.4 * homework;
}


double grade(double midterm, double final_grade, const vector<double>& hw)
{
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final_grade, median(hw));
}


double grade(const Student_info& s)
{
    return grade(s.midterm, s.final_grade, s.homework);
}


bool fgrade(const Student_info& s)
{
    return grade(s) < 60;
}
