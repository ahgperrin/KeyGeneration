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
        const uint8_t* castIntPrivateKey=reinterpret_cast<const uint8_t*>(PrivateKey.c_str());
        const int publicKeySize=uECC_curve_public_key_size(uECC_secp256k1());
        uint8_t *varIntPublicKey = new uint8_t(publicKeySize);
        uECC_compute_public_key(castIntPrivateKey,varIntPublicKey,uECC_secp256k1());
        PublicKey=std::string( varIntPublicKey, varIntPublicKey+publicKeySize );
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

//int main(int argc, const char * argv[]) {
 //   Key testKey;
//    testKey.initialize("4b8e29b9b0dddd58a709edba7d6df6c07ebdaf5653e325114bc5318c238f87f0");
//    cout << "Private key is: "<<testKey.getPrivateKey()<<endl;
//    cout << "Public key is: "<<testKey.getPublicKey()<<endl;
//    return 0;
//}
