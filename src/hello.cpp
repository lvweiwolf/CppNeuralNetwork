#include <iostream>
#include "stdlib.h"
#include "../MachineLearningLib/export.h"

typedef lvweiML::Matrix<float>  Mat;

int main(int argc, char **argv)
{
    std::cout << "hello world!" << std::endl;

    auto A = Mat({{1.0, 2.0, 3.0},
                  {4.0, 5.0, 6.0},
                  {7.0, 8.0, 9.0}});

    auto B = Mat({{2.0, 1.0, 2.0},
                  {3.0, 2.0, 1.0},
                  {4.0, 5.0, 1.0}});

    // auto B = Mat({{2.0, 1.0}, 
    //               {1.0, 1.0}, 
    //               {2.0, 1.0}});

    auto C = A * B;
    std::cout << C.str() << std::endl;
    return 0;
}