#include <iostream>
#include "stdlib.h"
#include "../MachineLearningLib/export.h"

int main(int argc, char **argv)
{

    std::cout << "hello world!" << std::endl;
    
    ExportClass exporter;
    exporter.Print();

    return 0;
}