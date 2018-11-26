#include <vector>
#include "tour.hpp"
#include "city.hpp"

#define NUMBER_OF_PARENTS 2
#define PARENT_POOL_SIZE 5
#define POPULATION_SIZE 32
#define CITIES_IN_TOUR 32
#define NUMBER_OF_ELITES 1
#define MUTATION_RATE 0.15
#define MAP_BOUNDARY 1000

class Population {
private:
    map<double, Tour> pTour;
    map<double, Tour> parentTour;
    vector<Tour> parents;
public:
    void addToPopulation(Tour);
    void printPopulation();
    void crossover();
    void mutate();
    void select_parents();
    void printElites();
    bool contains_city(City);
    Population() = default;

};