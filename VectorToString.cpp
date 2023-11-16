#include <iostream>
#include <vector>
#include <string>

std::string VectorToString(std::vector <double>& pointCoords);

int main() {
	std::vector<double> pointCoords = { 1.566666, 4.53333, 6.76766767 };
	std::string shaCoords;
	
	shaCoords = VectorToString(pointCoords);

	std::cout << shaCoords;
}

std::string VectorToString(std::vector<double>& pointCoords)
{
	std::string result;

	for (const double& point : pointCoords)
		result += std::to_string(point) + " ";

	return result;
}
