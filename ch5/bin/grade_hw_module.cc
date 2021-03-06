#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;

using std::domain_error;

using std::max;
using std::sort;

using std::setprecision;
using std::streamsize;

using std::string;
using std::vector;


int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    vector<Student_info> fail = extract_fails(students);

    sort(students.begin(), students.end(), compare);

    cout << "pass:" << endl;
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i) {
        cout << students[i].name
             << string(maxlen + 1 - students[i].name.size(), ' ');

        try {
            double student_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << student_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << "fail:" << endl;
    //TODO refactor use extract method
    for (vector<Student_info>::size_type i = 0;
         i != fail.size(); ++i) {
        cout << fail[i].name
             << string(maxlen + 1 - fail[i].name.size(), ' ');

        try {
            double student_grade = grade(fail[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << student_grade
                 << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    return 0;
}
