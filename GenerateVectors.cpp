#include <vector>
#include <ctime>
#include <random>

typedef std::pair<std::vector<double>, std::vector<double>> vector_pair;
typedef std::pair<std::vector<double>*, std::vector<double>*> pointer_pair;

vector_pair generate_conv_vectors(int dimension, int max_cord_value = 1000, int signs_after_point = 3)
{
    std::vector<double> a(dimension), b(dimension);
    std::vector<bool> a_cord(dimension), b_cord(dimension);
    srand(time(0));

    for (int i = 0; i < dimension; i++)
    {
        a_cord[i] = rand() % 2;
        if (!a_cord[i])
            b_cord[i] = rand() % 2;
    }

    for (int i = 0; i < dimension; i++)
    {
        if (a_cord[i])
            a[i] = double(rand() % (max_cord_value*int(pow(10, signs_after_point))))/ pow(10, signs_after_point);
        if (b_cord[i])
            b[i] = double(rand() % (max_cord_value*int(pow(10, signs_after_point)))) / pow(10, signs_after_point);   
    }

    return vector_pair (a, b);
}


vector_pair generate_inconv_vectors(pointer_pair conv_vectors)
{
    std::vector<double>* a = conv_vectors.first, *b = conv_vectors.second;
    srand(time(0));
    int mult_a_1 = rand() % 100 + 1;
    int mult_a_2 = rand() % 100 + 1;
    int mult_b_1 = rand() % 100 + 1;
    int mult_b_2 = rand() % 100 + 1;

    std::vector<double> a_inconv(a->size()), b_inconv(a->size());

    for (int i = 0; i < a->size(); i++)
    {
        a_inconv[i] = mult_a_1 * a->operator[](i) + mult_b_1 * b->operator[](i);
        b_inconv[i] = mult_a_2 * a->operator[](i) + mult_b_2 * b->operator[](i);
    }

    return vector_pair (a_inconv, b_inconv);
}
