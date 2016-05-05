#include <boost/python.hpp>
#include "GameAssetManager.h"
#include "Common.h"


using namespace boost::python;

PythonBindings::PythonBindings(){

}

BOOST_PYTHON_MODULE(libglex){

	//class_<GameAssetManager>("GameAssetManager")
	//		.def("AddAsset", &GameAssetManager::AddAsset)
	//		.def("UpdateCameraPosition", &GameAssetManager::UpdateCameraPosition)
	//;
}
