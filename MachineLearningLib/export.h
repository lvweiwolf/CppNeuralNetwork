#ifndef _EXPORT_H
#define _EXPORT_H

#include "Common/Matrix.h"

#ifdef EPXORT_DLL
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C" {
#endif
    EXPORT_API void print_from_dll();
#ifdef __cplusplus
}
#endif


class EXPORT_API ExportClass
{
public:
    ExportClass();

    virtual ~ExportClass();

    void Print();
};

#endif // _EXPORT_H