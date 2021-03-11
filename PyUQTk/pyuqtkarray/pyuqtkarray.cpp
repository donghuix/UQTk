#include <pybind11/pybind11.h>
#include <pybind11/operators.h>

#include "Array1D.h"
#include "Array2D.h"
#include "arrayio.h"
#include "arraytools.h"

namespace py=pybind11;

PYBIND11_MODULE(uqtkarray, m) {
    py::class_<Array1D<int>>(m, "Array1D<int>")
      .def(py::init<>())
      .def(py::init<const int&>())
      .def(py::init<const int&,const int&>())
      .def("Assign", &Array1D<int>::operator=)
      .def(py::init<const Array1D<int> &>())
      .def("Clear",&Array1D<int>::Clear)
      .def("XSize",&Array1D<int>::XSize)
      .def("Length",&Array1D<int>::Length)
      .def("Resize",static_cast<void (Array1D<int>::*)(const int&)>(&Array1D<int>::Resize))
      .def("Resize",static_cast<void (Array1D<int>::*)(const int&,const int&)>(&Array1D<int>::Resize))
      .def("SetValue",&Array1D<int>::SetValue)
      .def("PushBack",&Array1D<int>::PushBack)
      .def("GetArrayPointer",&Array1D<int>::GetArrayPointer)
      .def("GetConstArrayPointer",&Array1D<int>::GetConstArrayPointer)
      .def("__element__", [](Array1D<int> a, int b) {
        return a(b);
      }, py::is_operator())
      .def("insert",static_cast<void (Array1D<int>::*)(Array1D<int>&,int)>(&Array1D<int>::insert))
      .def("insert",static_cast<void (Array1D<int>::*)(const int&,int)>(&Array1D<int>::insert))
      .def("erase",&Array1D<int>::erase)
      .def("DumpBinary",static_cast<void (Array1D<int>::*)(FILE*) const>(&Array1D<int>::DumpBinary))
      .def("DumpBinary",static_cast<void (Array1D<int>::*)(char*)>(&Array1D<int>::DumpBinary))
      .def("ReadBinary",static_cast<void (Array1D<int>::*)(FILE*)>(&Array1D<int>::ReadBinary))
      .def("ReadBinary",static_cast<void (Array1D<int>::*)(char*)>(&Array1D<int>::ReadBinary))
      .def("pyElement",&Array1D<int>::operator[])
      .def("ReadBinary4py",&Array1D<int>::ReadBinary4py)
      .def("DumpBinary4py",&Array1D<int>::DumpBinary4py)
      .def("setArray",&Array1D<int>::setArray)
      .def("setnpintArray",&Array1D<int>::setnpintArray)
      .def("getnpintArray",&Array1D<int>::getnpintArray)
      .def("flatten",&Array1D<int>::flatten)
      .def("type",&Array1D<int>::type)
      ;

      py::class_<Array1D<double>>(m, "Array1D<double>")
        .def(py::init<>())
        .def(py::init<const int&>())
        .def(py::init<const int&,const int&>())
        .def("Assign", &Array1D<double>::operator=)
        .def(py::init<const Array1D<double> &>())
        .def("Clear",&Array1D<double>::Clear)
        .def("XSize",&Array1D<double>::XSize)
        .def("Length",&Array1D<double>::Length)
        .def("Resize",static_cast<void (Array1D<double>::*)(const int&)>(&Array1D<double>::Resize))
        .def("Resize",static_cast<void (Array1D<double>::*)(const int&,const double&)>(&Array1D<double>::Resize))
        .def("SetValue",&Array1D<double>::SetValue)
        .def("PushBack",&Array1D<double>::PushBack)
        .def("GetArrayPointer",&Array1D<double>::GetArrayPointer)
        .def("GetConstArrayPointer",&Array1D<double>::GetConstArrayPointer)
        .def("__element__", [](Array1D<double> a, int b) {
          return a(b);
        }, py::is_operator())
        .def("insert",static_cast<void (Array1D<double>::*)(Array1D<double>&,int)>(&Array1D<double>::insert))
        .def("insert",static_cast<void (Array1D<double>::*)(const double&,int)>(&Array1D<double>::insert))
        .def("erase",&Array1D<double>::erase)
        .def("DumpBinary",static_cast<void (Array1D<double>::*)(FILE*) const>(&Array1D<double>::DumpBinary))
        .def("DumpBinary",static_cast<void (Array1D<double>::*)(char*)>(&Array1D<double>::DumpBinary))
        .def("ReadBinary",static_cast<void (Array1D<double>::*)(FILE*)>(&Array1D<double>::ReadBinary))
        .def("ReadBinary",static_cast<void (Array1D<double>::*)(char*)>(&Array1D<double>::ReadBinary))
        .def("pyElement",&Array1D<double>::operator[])
        .def("ReadBinary4py",&Array1D<double>::ReadBinary4py)
        .def("DumpBinary4py",&Array1D<double>::DumpBinary4py)
        .def("setArray",&Array1D<double>::setArray)
        .def("setnpdblArray",&Array1D<double>::setnpdblArray)
        .def("getnpdblArray",&Array1D<double>::getnpdblArray)
        .def("flatten",&Array1D<double>::flatten)
        .def("type",&Array1D<double>::type)
        ;

      py::class_<Array2D<int>>(m,"Array2D")
        .def(py::init<>())
        .def(py::init<const int&,const int&>())
        .def(py::init<const int&,const int&,const int&>())
        .def(py::init<const Array2D<int> &>())
        .def("Clear",&Array2D<int>::Clear)
        .def("XSize",&Array2D<int>::XSize)
        .def("YSize",&Array2D<int>::YSize)
        .def("Resize",static_cast<void (Array2D<int>::*)(const int&,const int&)>(&Array2D<int>::Resize))
        .def("Resize",static_cast<void (Array2D<int>::*)(const int&,const int&,const int&)>(&Array2D<int>::Resize))
        .def("SetValue",&Array2D<int>::SetValue)
        .def("GetArrayPointer",&Array2D<int>::GetArrayPointer)
        .def("GetConstArrayPointer",&Array2D<int>::GetConstArrayPointer)
        .def("__element__", [](Array2D<int> a, int b,int c) {
          return a(b,c);
        }, py::is_operator())
        .def("insertRow",static_cast<void (Array2D<int>::*)(Array1D<int>&,int)>(&Array2D<int>::insertRow))
        .def("insertRow",static_cast<void (Array2D<int>::*)(Array2D<int>&,int)>(&Array2D<int>::insertRow))
        .def("eraseRow",&Array2D<int>::eraseRow)
        .def("insertCol",static_cast<void (Array2D<int>::*)(Array1D<int>&,int)>(&Array2D<int>::insertCol))
        .def("insertCol",static_cast<void (Array2D<int>::*)(Array2D<int>&,int)>(&Array2D<int>::insertCol))
        .def("eraseCol",&Array2D<int>::eraseCol)
        .def("DumpBinary",static_cast<void (Array2D<int>::*)(FILE*) const>(&Array2D<int>::DumpBinary))
        .def("DumpBinary",static_cast<void (Array2D<int>::*)(char*)>(&Array2D<int>::DumpBinary))
        .def("ReadBinary",static_cast<void (Array2D<int>::*)(FILE*)>(&Array2D<int>::ReadBinary))
        .def("ReadBinary",static_cast<void (Array2D<int>::*)(char*)>(&Array2D<int>::ReadBinary))
        .def("pyElement",&Array2D<int>::operator[])
        .def("getRow",&Array2D<int>::getRow)
        .def("ReadBinary4py",&Array2D<int>::ReadBinary4py)
        .def("DumpBinary4py",&Array2D<int>::DumpBinary4py)
        .def("setArray",&Array2D<int>::setArray)
        .def("flatten",&Array2D<int>::flatten)
        .def("type",&Array2D<int>::type)
        .def("setnpintArray",&Array2D<int>::setnpintArray)
        .def("getnpintArray",&Array2D<int>::getnpintArray)
        .def("setnpdblArray",&Array2D<int>::setnpdblArray)
        .def("getnpdblArray",&Array2D<int>::getnpdblArray)
        ;

      py::class_<Array2D<double>>(m,"Array2D")
        .def(py::init<>())
        .def(py::init<const int&,const int&>())
        .def(py::init<const int&,const int&,const int&>())
        .def(py::init<const Array2D<double> &>())
        .def("Clear",&Array2D<double>::Clear)
        .def("XSize",&Array2D<double>::XSize)
        .def("YSize",&Array2D<double>::YSize)
        .def("Resize",static_cast<void (Array2D<double>::*)(const int&,const int&)>(&Array2D<double>::Resize))
        .def("Resize",static_cast<void (Array2D<double>::*)(const int&,const int&,const double&)>(&Array2D<double>::Resize))
        .def("SetValue",&Array2D<double>::SetValue)
        .def("GetArrayPointer",&Array2D<double>::GetArrayPointer)
        .def("GetConstArrayPointer",&Array2D<double>::GetConstArrayPointer)
        .def("__element__", [](Array2D<double> a, int b,int c) {
          return a(b,c);
        }, py::is_operator())
        .def("insertRow",static_cast<void (Array2D<double>::*)(Array1D<double>&,int)>(&Array2D<double>::insertRow))
        .def("insertRow",static_cast<void (Array2D<double>::*)(Array2D<double>&,int)>(&Array2D<double>::insertRow))
        .def("eraseRow",&Array2D<double>::eraseRow)
        .def("insertCol",static_cast<void (Array2D<double>::*)(Array1D<double>&,int)>(&Array2D<double>::insertCol))
        .def("insertCol",static_cast<void (Array2D<double>::*)(Array2D<double>&,int)>(&Array2D<double>::insertCol))
        .def("eraseCol",&Array2D<double>::eraseCol)
        .def("DumpBinary",static_cast<void (Array2D<double>::*)(FILE*) const>(&Array2D<double>::DumpBinary))
        .def("DumpBinary",static_cast<void (Array2D<double>::*)(char*)>(&Array2D<double>::DumpBinary))
        .def("ReadBinary",static_cast<void (Array2D<double>::*)(FILE*)>(&Array2D<double>::ReadBinary))
        .def("ReadBinary",static_cast<void (Array2D<double>::*)(char*)>(&Array2D<double>::ReadBinary))
        .def("pyElement",&Array2D<double>::operator[])
        .def("getRow",&Array2D<double>::getRow)
        .def("ReadBinary4py",&Array2D<double>::ReadBinary4py)
        .def("DumpBinary4py",&Array2D<double>::DumpBinary4py)
        .def("setArray",&Array2D<double>::setArray)
        .def("flatten",&Array2D<double>::flatten)
        .def("type",&Array2D<double>::type)
        .def("setnpintArray",&Array2D<double>::setnpintArray)
        .def("getnpintArray",&Array2D<double>::getnpintArray)
        .def("setnpdblArray",&Array2D<double>::setnpdblArray)
        .def("getnpdblArray",&Array2D<double>::getnpdblArray)
        ;

      m.def("read_datafile",&read_datafile)
      m.def("read_datafileVS",&read_datafileVS)
      m.def("read_datafile_1d",&read_datafile_1d)
      m.def("write_datafile_size",&write_datafile_size)
      m.def("write_datafile",&write_datafile)
      m.def("write_datafile_1d",&write_datafile_1d)

      m.def("array1Dto2D",&array1Dto2D)
      m.def("array2Dto1D",&array2Dto1D)
      m.def("paste",&paste)
      m.def("generate_multigrid",&generate_multigrid)
      m.def("merge",&merge)
      m.def("append",&append)
      m.def("transpose",&transpose)
      m.def("flatten",&flatten)
      m.def("fold_1dto2d_rowfirst",&fold_1dto2d_rowfirst)
      m.def("fold_1dto2d_colfirst",&fold_1dto2d_colfirst)
      m.def("swap",&swap)
      m.def("access",&access)
      m.def("getRow",&getRow)
      m.def("getCol",&getCol)
      m.def("addVal",&addVal)
      m.def("subVector",&subVector)
      m.def("subMatrix_row",&subMatrix_row)
      m.def("subMatrix_col",&subMatrix_col)
      m.def("matPvec",&matPvec)
      m.def("maxVal",&maxVal)
      m.def("setdiff",&setdiff)
      m.def("setdiff_s",&setdiff_s)
      m.def("shell_sort",&shell_sort)
      m.def("shell_sort_col",&shell_sort_col)
      m.def("shell_sort_all",&shell_sort_all)
      m.def("quicksort3",&quicksort3)
      m.def("intersect",&intersect)
      m.def("find",&find)
      m.def("prodAlphaMatVec",&prodAlphaMatVec)
      m.def("prodAlphaMatTVec",&prodAlphaMatTVec)
      m.def("prodAlphaMatMat",&prodAlphaMatMat)
      m.def("prodAlphaMatTMat",&prodAlphaMatTMat)
      m.def("addVecAlphaVecPow",&addVecAlphaVecPow)
      m.def("prod_vecTmatvec",&prod_vecTmatvec)
      m.def("MatTMat",&MatTMat)
      m.def("delRow",&delRow)
      m.def("delCol",&delCol)
      m.def("paddMatRow",&paddMatRow)
      m.def("paddMatCol",&paddMatCol)
      m.def("paddMatRow",&paddMatColScal)
      m.def("is_equal",&is_equal)
      m.def("is_less",&is_less)
      m.def("vecIsInArray",&vecIsInArray)
      m.def("select_kth",&select_kth)
      m.def("logdeterm",&logdeterm)
      m.def("trace",&trace)
      m.def("evalLogMVN",&evalLogMVN)
      m.def("diag",&diag)
      m.def("copy",&copy)
      m.def("mtxdel",&mtxdel)
      m.def("add",&add)
      m.def("addinplace",&addinplace)
      m.def("subtract",&subtract)
      m.def("subtractinplace",&subtractinplace)
      m.def("scale",&scale)
      m.def("scaleinplace",&scaleinplace)
      m.def("dotdivide",&dotdivide)
      m.def("dotmult",&dotmult)
      m.def("norm",&norm)
      m.def("dist_sq",&dist_sq)
      m.def("Trans",&Trans)
      m.def("dot",&dot)
      m.def("dotT",&dotT)
      m.def("INV",&INV)
      m.def("AinvH",&AinvH)
      m.def("Ainvb",&Ainvb)
      m.def("LSTSQ",&LSTSQ)
      m.def("QR",&QR)
      m.def("SVD",&SVD)
      m.def("printarray",printarray)





}
