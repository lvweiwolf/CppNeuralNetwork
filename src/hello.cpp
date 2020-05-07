#include <iostream>
#include "stdlib.h"
#include "../MachineLearningLib/export.h"

typedef lvweiML::Matrix<float>  Mat;

int main(int argc, char **argv)
{
    std::cout << "hello world!" << std::endl;

    auto mat = Mat({{1.0, 2.0, 3.0},
                    {4.0, 5.0, 6.0},
                    {7.0, 8.0, 9.0}});
    
    std::cout << mat.str() << std::endl;
    int i = 0;
    double A[6] = {1.0, 2.0, 1.0, -3.0, 4.0, -1.0};
    double B[6] = {1.0, 2.0, 1.0, -3.0, 4.0, -1.0};
    double C[9] = {.5, .5, .5, .5, .5, .5, .5, .5, .5};
    cblas_dgemm(CblasColMajor, CblasNoTrans, CblasTrans, 3, 3, 2, 1, A, 3, B, 3, 2, C, 3);

    for (i = 0; i < 9; i++)
        printf("%lf ", C[i]);
    printf("\n");

    system("pause");
    return 0;
}