#include <vector>
#include <cmath>

typedef std::pair<std::vector<double>, std::vector<double>> VectorPair;

std::vector<double> operator-(std::vector<double> self, std::vector<double> another)
{
    if (self.size() != another.size())
        return std::vector<double>(); //TODO: raise exception or make it private method
    
    std::vector<double> res(self.size());
    for (int i = 0; i < self.size(); i++)
        res[i] = self[i] - another[i];

    return res;
}

double VectorMagnitude(std::vector<double> a)
{
    double sum = 0;
    for (double i : a)
        sum += i * i;
    return sqrt(sum);
}

std::vector<double> operator*(std::vector<double> self, double number)
{
    std::vector<double> res(self.size());
    for (int i = 0; i < res.size(); i++)
        res[i] = self[i] * number;
    return res;
}


VectorPair FindNearestPointForOneVector(std::vector<double> point, std::vector<double> vec)
{
    int counter = 0;
    for (;counter < point.size(); counter++)
    {
        if (vec[counter] != 0)
            break;
    }

    int multiplier = 0;
    std::vector<double> prev, cur;
    while (point[counter] < (vec*multiplier)[counter])
        multiplier++;

    prev = vec*(multiplier - 1);
    cur = vec*multiplier;
    return VectorPair(prev, cur);
}

std::vector<double> FindNearestPoint(std::vector<double> point, VectorPair conv_vecs) 
{
    std::vector<std::vector<double>> variants(4);
    std::vector<double> vec1 = conv_vecs.first, vec2 = conv_vecs.second;

    VectorPair res_for_vec1 = FindNearestPointForOneVector(point, vec1),  res_for_vec2 = FindNearestPointForOneVector(point, vec2);
    variants[0] = res_for_vec1.first;
    variants[1] = res_for_vec1.second;
    variants[2] = res_for_vec2.first;
    variants[3] = res_for_vec2.second;

    double min_magnitude = VectorMagnitude(variants[0] - point);
    std::vector<double> min_vec = variants[0];
    for (int i = 1; i < variants.size(); i++)
    {
        double cur_magnitude = VectorMagnitude(variants[i] - point);
        if (cur_magnitude < min_magnitude)
        {
            min_magnitude = cur_magnitude;
            min_vec = variants[i];
        }
    }
    
    return min_vec;
}