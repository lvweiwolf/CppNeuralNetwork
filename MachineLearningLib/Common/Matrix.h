#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>

namespace lvweiML
{
    template<typename T> 
    class Matrix
    {
    public:
        // 构造函数
        Matrix();
        Matrix(size_t row, size_t col);
        Matrix(const std::vector<std::vector<T>>& data);
        Matrix(const std::Matrix<T>& data);
        Matrix(Matrix<T>&& other)
        
        virtual ~Matrix()

        // 赋值操作
        Matrix& operator=(const Matrix<T>& other);
        Matrix& operator=(Matrix<T>&& other);
       
        

    private:
        T       *_data;
        size_t  _row;
        size_t  _col;
    }
}

#endif // _MATRIX_H