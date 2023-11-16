#include "GenerateVectors.cpp"
#include <iostream>

void print_vector(std::vector<double> a)    
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
    print_vector(a);
    print_vector(b);
    VectorPair inconv_vectors = GenerateInconvVectors(PointerPair (&a, &b));
    print_vector(inconv_vectors.first);
    print_vector(inconv_vectors.second); 
}