#include "gpa.h"

gpa::gpa( const std::vector<int>& grades ) : _grades( grades ), _credit_hours( 12.5 ) 
{
     
}

double gpa::get_gpa() const noexcept
{
    double total_grade_points = 0.0;

    // Iterate over the list of grades, and calculate the cgpa accordingly
    for ( const int& grade : _grades )
    {
        if ( grade >= 80 )
        {
            // If grade is a high distinction
            total_grade_points += 4 * _credit_hours;
        }
        else if ( grade >= 70 && grade <= 79 )
        {
            // If grade is a distinction
            total_grade_points += 3 * _credit_hours;
        }
        else if ( grade >= 60 && grade <= 69 )
        {
            // If grade is a credit
            total_grade_points += 2 * _credit_hours;
        }
        else if ( grade >= 50 && grade <= 59 )
        {
            // If grade is a pass
            total_grade_points += _credit_hours;
        }
        else
        {
            // If grade is a fail
            total_grade_points += 0;
        }
    }

    // Return the cgpa as a double
    return total_grade_points / ( _grades.size() * _credit_hours );
}

double gpa::get_wam() const noexcept
{
    double wam = 0.0;

    for ( const int& grade : _grades )
    {
        wam += grade;
    }

    return wam / _grades.size();
}

double gpa::get_credit_hours() const noexcept
{
    return _grades.size() * _credit_hours;
}

double gpa::get_gpa_7() const noexcept
{
    return get_gpa() * 1.75;
}