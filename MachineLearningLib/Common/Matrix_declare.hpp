#ifndef _MATRIX_H
#define _MATRIX_H

#include <vector>
#include <string>
#include <initializer_list>

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
#if (__cplusplus >= 201103L)
        Matrix(const std::initializer_list< std::initializer_list<T>>& init_data);
#endif
        Matrix(const Matrix& m);
        
        virtual ~Matrix();
        
        std::string str() const;

        // 赋值操作
        Matrix& operator=(const std::vector<std::vector<T>>& data);
#if (__cplusplus >= 201103L)
        Matrix& operator=(const std::initializer_list<std::initializer_list<T>>& init_data);
#endif
        Matrix& operator=(const Matrix& m);
        Matrix& operator=(const T val);

        Matrix& operator+=(const T val);
        Matrix& operator-=(const T val);
        Matrix& operator*=(const T val);
        Matrix& operator/=(const T val); 

        Matrix& operator+=(const Matrix& m);
        Matrix& operator-=(const Matrix& m);
        Matrix& operator*=(const Matrix& m);
        Matrix& operator/=(const Matrix& m); 
        // 舒尔积：两个对象的逐元素乘法
        Matrix& operator%=(const Matrix& m); 
       
    private:
        void init_cold();

        T       *_data;
        size_t  _row;
        size_t  _col;
    };

    template<typename T> Matrix<T> operator+(const Matrix<T>&, const T);
    template<typename T> Matrix<T> operator-(const Matrix<T>&, const T);
    template<typename T> Matrix<T> operator*(const Matrix<T>&, const T);
    template<typename T> Matrix<T> operator/(const Matrix<T>&, const T);
    
    template<typename T> Matrix<T> operator+(const Matrix<T>&, const Matrix<T>&);
    template<typename T> Matrix<T> operator-(const Matrix<T>&, const Matrix<T>&);
    template<typename T> Matrix<T> operator*(const Matrix<T>&, const Matrix<T>&);
    template<typename T> Matrix<T> operator/(const Matrix<T>&, const Matrix<T>&);
}

#endif // _MATRIX_H