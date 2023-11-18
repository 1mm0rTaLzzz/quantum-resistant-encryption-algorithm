#include "GenerateVectors.cpp"
#include <iostream>

void PrintVector(std::vector<double> a)    
{
    for (double i : a)
        std::cout << i << " ";
    std::cout << '\n';
}

int main()
{
    int dim = 10;   
    VectorPair conv_vectors = GenerateConvVectors(10);
    std::vector<double> a = conv_vectors.first, b = conv_vectors.second;
    PrintVector(a);
    PrintVector(b);
    VectorPair inconv_vectors = GenerateInconvVectors(PointerPair (&a, &b));
    PrintVector(inconv_vectors.first);
    PrintVector(inconv_vectors.second); 
}