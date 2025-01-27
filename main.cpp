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
        std::cout << "Succesfully added grade " << grade_str << std::endl;
    }

    std::unique_ptr<gpa> gpa_ptr = std::make_unique<gpa>( grades );

    if ( !gpa_ptr )
    {
        std::cout << "Error: Memory allocation failed ( gpa_ptr )" << std::endl;
        return 1;
    }

    double wam = 0.0;
    for ( int grade : grades )
    {
        wam += grade;
    }

    wam = wam / grades.size();

    std::cout << "Size of GPA object: " << sizeof( gpa ) << " Bytes" << std::endl;
    std::cout << "Memory Address of gpa_ptr: " << &gpa_ptr << std::endl;
    std::cout << "WAM is: " << wam << std::endl;
    std::cout << "GPA is: " << gpa_ptr->get_gpa() << " ( assuming 12.5 credit hours per unit ) " << std::endl;

    return 0;
}