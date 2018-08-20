////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/// @project        Library/Mathematics
/// @file           LibraryMathematicsPy.cxx
/// @author         Lucas Brémond <lucas@loftorbital.com>
/// @license        TBD

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <boost/python.hpp>
#include <boost/python/numpy.hpp>

#include <eigen_numpy.h>
// or https://github.com/ethz-asl/kalibr/blob/master/Schweizer-Messer/numpy_eigen/include/numpy_eigen/NumpyEigenConverter.hpp ?

#include <LibraryMathematicsPy/Objects.cpp>
#include <LibraryMathematicsPy/Geometry.cpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BOOST_PYTHON_MODULE (LibraryMathematicsPy)
{

    // Py_Initialize() ;
    // boost::python::numpy::initialize() ;

    // boost::numpy::initialize() ;
    // boost::python::numeric::array::set_module_and_type("numpy", "ndarray") ;

    SetupEigenConverters() ;

    boost::python::object package = boost::python::scope() ;
    
    package.attr("__path__") = "Library" ;

    LibraryMathematicsPy_Objects() ;
    LibraryMathematicsPy_Geometry() ;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////