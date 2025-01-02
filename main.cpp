#include <iostream>
#include <memory>
#include <vector>
#include "cgpa.h"

int main() {
    std::vector<int> grades = { 55, 60, 80 };
    // Create unique pointer, cgpaPtr and point it to a cgpa object on the heap
    std::unique_ptr<cgpa> cgpaPtr = std::make_unique<cgpa>("Dylan Armstrong", grades, 37.5);

    // Print the cgpa from the cgpaPtr pointer
    std::cout << cgpaPtr->getcgpa() << std::endl;
    // Print the address of the object on the heap, that the pointer is pointing to
    std::cout << cgpaPtr << std::endl;
    // Print the size of a cgpa object
    std::cout << sizeof(cgpa) << " Bytes" << std::endl;
    
    return 0;
}