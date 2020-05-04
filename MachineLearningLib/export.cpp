
#define EPXORT_DLL
#include "export.h"
#include <iostream>



void print_from_dll()
{
    std::cout << "hello world(from dll)!" << std::endl;
}


ExportClass::ExportClass()
{}

ExportClass::~ExportClass()
{}

void ExportClass::Print()
{
    std::cout << "hello world(from export class)!" << std::endl;
}