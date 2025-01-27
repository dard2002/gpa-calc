#include <iostream>
#include <memory>
#include <vector>
#include <fstream>
#include <string>

#include "gpa.h"

int main( int argc, char *argv[] )
{
    if ( argv[1] == NULL )
    {
        std::cout << "GPA Calculator Syntax:\ngpa.exe <path_to_file>" << std::endl;
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

    std::cout << "WAM is: " << gpa_ptr->get_wam() << std::endl;
    std::cout << "GPA is: " << gpa_ptr->get_gpa() << " ( assuming 12.5 credit hours per unit ) " << std::endl;

    return 0;
}