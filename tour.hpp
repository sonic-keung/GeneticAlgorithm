#pragma once
#include <vector>
#include <map>
#include "city.hpp"

using namespace std;

class Tour {
private:
    double fitness;
    vector<City> tour;
public:
    Tour(vector<City>);
    Tour() = default;
    double get_tour_distance(vector<City>);
    double get_distance_between_cities(City a, City b);
    double getFitness();
    void shuffle_cities(vector<City> &);
    void printTour();
    vector<City> getTour();

};