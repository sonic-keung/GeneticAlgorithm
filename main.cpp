#include <iostream>
#include <random>
#include <algorithm>
#include "tour.hpp"
#include "city.hpp"
#include "population.hpp"

// populate 32 cities randomly
vector<City> createCity(int numOfCities) {
    vector<City> city;
    for (int i = 0; i < numOfCities; i++) {
        City newCity(i, (MAP_BOUNDARY + 1) * ((double)rand() / (double)RAND_MAX) ,
                (MAP_BOUNDARY + 1) * ((double)rand() / (double)RAND_MAX));
        city.push_back(newCity);
    }
    return city;
}

int main() {
    srand(time(NULL));
    vector<City> vector1 = createCity(CITIES_IN_TOUR);

    cout << "printing tours and cities" << endl;
    // determine the fitness of each tour, and determines which tour is the fittest
    Population population1;
    for (unsigned int i = 0; i < CITIES_IN_TOUR; i++) {
        Tour tour1(vector1);
        tour1.shuffle_cities(vector1);
        population1.addToPopulation(tour1);
    }
    population1.printPopulation();

    cout << "Elites: " << endl;
    population1.select_parents();
    population1.printElites();
    population1.crossover();

    cout << "k" << endl;
    return 0;
}