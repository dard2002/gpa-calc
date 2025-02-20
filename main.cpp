#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

#include "gpa.h"

int main( int argc, char* argv[] )
{
    if ( argv[1] == NULL )
    {
        std::cout << "No txt file entered!\nPlease refer to the readme: https://github.com/dard2002/gpa-calc/blob/main/README.md" << std::endl;
        return 1;
    }

    std::string grade_str;
    std::ifstream grades_file( argv[1] );
    std::vector<int> grades;

    while ( std::getline ( grades_file, grade_str ) ) 
    {
        grades.push_back( std::stoi( grade_str ) );

        if ( grades.back() == std::stoi( grade_str ) )
        {
            std::cout << "Succesfully added grade " << grade_str << std::endl;
        }
        else
        {
            std::cout << "Failed to add grade" << grade_str << std::endl;
        }    
    }

    std::unique_ptr<gpa> gpa_ptr = std::make_unique<gpa>( grades );
    
    if ( !gpa_ptr )
    {
        std::cout << "Error: Memory allocation failed ( gpa_ptr )" << std::endl;
        return 1;
    }

    std::cout << "WAM is: " << std::fixed << std::setprecision(2) << gpa_ptr->get_wam() << std::endl;
    std::cout << "GPA (4 Scale) is: " << std::fixed << std::setprecision(2) << gpa_ptr->get_gpa() << " ( assuming 12.5 credit hours per unit ) " << std::endl;
    std::cout << "Total Credit Points: " << std::fixed << std::setprecision(2) << gpa_ptr->get_credit_hours() << std::endl;
    std::cout << "GPA (7 Scale) is: " << std::fixed << std::setprecision(2) << gpa_ptr->get_gpa_7() << " ( assuming 12.5 credit hours per unit ) " << std::endl;

    return 0;
}