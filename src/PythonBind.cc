#include "PythonBind.h"

using namespace boost::python;

PythonBind::PythonBind(){

}
char const* greet() {
   return "hello, world";
}

BOOST_PYTHON_MODULE(libglex){


        boost::python::def("greet", greet);
        boost::python::class_<GameLoop>("GameLoop")
    	        .def("Run", &GameLoop::Run);
}
