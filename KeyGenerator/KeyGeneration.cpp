//
//  KeyGeneration.cpp
//  KeyGenerator
//
//  Created by Antoine Perrin on 4/18/21.
//
//#include <pybind11/pybind11.h>
#include <stdio.h>
#include <iostream>
#include "uECC.h"
#include <pybind11/pybind11.h>

using namespace std;

char version[]="0.0.1";

char const* getVersion() {
    return version;
}
class Key
{
    // Access specifier
    public:
  
    // Data Members
    string PrivateKey;
    string PublicKey;
    
    // Member Functions()
    void initialize(string key)
    {
        PrivateKey = key;
        cout << "Calculating public key with secp256k1 algorithm"<<endl;
        const int curve = uECC_curve_public_key_size(uECC_secp256k1());
        uint8_t *modPublicKey = new uint8_t(curve);
        PublicKey=uECC_compute_public_key(modPublicKey,modPublicKey,uECC_secp256k1());
        PublicKey=string( modPublicKey, modPublicKey+curve );
    }
    string getPrivateKey()
    {
        return PrivateKey;
    }
    string getPublicKey()
    {
        return PublicKey;
    }
};

namespace py = pybind11;

PYBIND11_MODULE(KeyGeneration, hab)
{
    hab.doc() = "KeyGeneration 1.0";
    hab.def("getVersion", &getVersion, "Version Getter");
    py::class_<KeyGeneration>(hab, "GenerateKey")
       .def(py::init())
       .def("initialize", &KeyGeneration::initialize)
       .def("getPrivateKey", &KeyGeneration::getPrivateKey)
       .def("getPublicKey", &KeyGeneration::getPublicKey);
}
