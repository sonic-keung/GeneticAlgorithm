#include <vector>
#include "tour.hpp"
#include "city.hpp"
class Population {
private:
    map<double, Tour> pTour;
    map<double, Tour> parentTour;
public:
    void addToPopulation(Tour);
    void printPopulation();
    void crossover(vector<Tour>);
    void mutate();
    void select_parents();
    void printElites();
    bool contains_city(City, int);
    Population() = default;

};