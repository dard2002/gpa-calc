#include "gpa.h"

gpa::gpa(const std::vector<int> &grades) : _grades(grades), _creditHours(12.5) 
{

}

double gpa::getGpa() const noexcept
{
    double totalGradePoints = 0.0;

    // Iterate over the list of grades, and calculate the cgpa accordingly
    for (int grade : _grades)
    {
        if (grade >= 80)
        {
            // If grade is a high distinction
            totalGradePoints += 4 * _creditHours;
        }
        else if (grade >= 70 && grade <= 79)
        {
            // If grade is a distinction
            totalGradePoints += 3 * _creditHours;
        }
        else if (grade >= 60 && grade <= 69)
        {
            // If grade is a credit
            totalGradePoints += 2 * _creditHours;
        }
        else if (grade >= 50 && grade <= 59)
        {
            // If grade is a pass
            totalGradePoints += _creditHours;
        }
        else
        {
            // If grade is a fail
            totalGradePoints += 0;
        }
    }

    // Return the cgpa as a double
    return totalGradePoints / (_grades.size() * _creditHours);
}