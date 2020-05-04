#include <cblas.h>
#include <iostream>
#include "Memory.hpp"

#define MAX_UWORD  0xffffffffffffffff
#define MAX_UHWORD 0xffffffff

namespace lvweiML
{
    template<typename T>
    void Matrix<T>::init_cold()
    {
        if ((_row > MAX_UHWORD || _col > MAX_UHWORD) ? (_row * _col > double(MAX_UWORD)) : false)
        {
            std::cerr << "Matrix::init(): requested size is too large" << std::endl;
        }
        
        std::cout << "Matrix::init(): acquiring memory" << std::endl;
        _data = Memory::acquire<T>(_row * _col);
    }

    template<typename T>
    Matrix<T>::Matrix()
        : _data(0)
        , _row(0)
        , _col(0)
    {
    }

    template<typename T>
    Matrix<T>::Matrix(size_t row, size_t col)
        : _row(row)
        , _col(col)
    {
        init_cold();
    }

    template<typename T>
    Matrix<T>::Matrix(const std::vector< std::vector<T>>& data)
    {
        (*this).operator=(data);
    }

    template<typename T>
    Matrix<T>::Matrix(const std::initializer_list< std::initializer_list<T>>& data)
    {
        (*this).operator=(data);
    }

    template<typename T>
    Matrix<T>::Matrix(const Matrix& m)
        : _row(m._row)
        , _col(m._col)
    {
        init_cold();
        memcpy(_data, m._data, (m._row * m._col)*sizeof(T));
    }

    template<typename T>
    Matrix<T>::~Matrix()
    {
        Memory::release(_data);
        _data = nullptr;
    }

    template<typename T>
    Matrix<T>& 
    Matrix<T>::operator=(const std::vector<std::vector<T>>& data)
    {
        size_t n_rows = data.size();
        size_t n_cols = 0;
        bool x_n_cols_found = false;
        
        auto it = data.begin();
        auto it_end = data.end();

        for (; it != it_end; ++it)
        {
            if (!x_n_cols_found)
            {
                n_cols = (*it).size();
                x_n_cols_found = true;
            }
            else
                if ((*it).size() != n_cols)
                    std::cerr << "Mat::init(): inconsistent number of columns in vector" << std::endl;
        }
        
        _row = n_rows;
        _col = n_cols;
        init_cold();

        size_t row_num = 0;
        Matrix<T>& mat = *this;
        auto row_it = data.begin();
        auto row_it_end = data.end();
        
        for (; row_it != row_it_end; ++row_it)
        {
            size_t col_num = 0;
            auto col_it = (*row_it).begin();
            auto col_it_end = (*row_it).end();
            
            for(; col_it != col_it_end; ++col_it)
            {
                _data[row_num + col_num*n_rows] = (*col_it);
                ++col_num;
            }

            ++row_num;
        }    
    }

    template<typename T>
    Matrix<T>& 
    Matrix<T>::operator=(const std::initializer_list<std::initializer_list<T>>& data)
    {
        size_t n_rows = data.size();
        size_t n_cols = 0;
        bool x_n_cols_found = false;
        
        auto it = data.begin();
        auto it_end = data.end();

        for (; it != it_end; ++it)
        {
            if (!x_n_cols_found)
            {
                n_cols = (*it).size();
                x_n_cols_found = true;
            }
            else
                if ((*it).size() != n_cols)
                    std::cerr << "Mat::init(): inconsistent number of columns in initialiser list" << std::endl;
        }
        
        _row = n_rows;
        _col = n_cols;
        init_cold();

        size_t row_num = 0;
        Matrix<T>& mat = *this;
        auto row_it = data.begin();
        auto row_it_end = data.end();
        
        for (; row_it != row_it_end; ++row_it)
        {
            size_t col_num = 0;
            auto col_it = (*row_it).begin();
            auto col_it_end = (*row_it).end();
            
            for(; col_it != col_it_end; ++col_it)
            {
                _data[row_num + col_num*n_rows] = (*col_it);
                ++col_num;
            }

            ++row_num;
        }
    }

    template<typename T>
    Matrix<T>&
    Matrix<T>::operator=(const Matrix<T>& m)
    {
        _row = m._row;
        _col = m._col;
        init_cold();
        memcpy(_data, m._data, (m._row * m._col)*sizeof(T));

        return *this;
    }

    template<typename T>
    Matrix<T>&
    Matrix<T>::operator=(const T val)
    {
        _row = _col = 1;
        init_cold();
        _data[0] = val;
        return *this;
    }

    template<typename T>
    Matrix<T>&
    Matrix<T>::operator+=(const T val)
    {
        size_t n_elem = _row * _col;

        if (n_elem > 0)
        {
           
        }
    }
    
}