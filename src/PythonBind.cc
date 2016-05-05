#include <boost/python.hpp>
#include "GameAssetManager.h"
#include "Common.h"


using namespace boost::python;

PythonBindings::PythonBindings(){

}

BOOST_PYTHON_MODULE(libglex){
	//class <Example>("Example"), init <>())
	//		.def("get", &Example::getString )
	//		.def("set", &Example::setString )
	//;

	class_<GameAssetManager>("GameAssetManager")
			.def("AddAsset", &GameAssetManager::AddAsset)
			.def("UpdateCameraPosition", &GameAssetManager::UpdateCameraPosition)
	;
}
