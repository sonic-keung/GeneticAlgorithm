#include <map>
#include <algorithm>
#include <random>
#include "population.hpp"

#define NUMBER_OF_PARENTS 2
#define PARENT_POOL_SIZE 5
#define POPULATION_SIZE 32
#define CITIES_IN_TOUR 32
#define NUMBER_OF_ELITES 1

void Population::addToPopulation(Tour tour) {
    pTour.insert(make_pair(tour.getFitness(), tour));
}

void Population::printPopulation() {
    int count = 0;
    for (auto it = pTour.begin(); it != pTour.end(); it++) {
        cout << "\nTour: " << count++ << endl;
        cout << "Fitness: " << it->first <<endl;
        it->second.printTour();
    }
}

void Population::crossover() {
    vector<City> child;
    int parentA = rand() % CITIES_IN_TOUR;
    for (auto it = pTour.begin(); it != pTour.end(); it++) {
        vector<City> tempCity = it->second.getTour();
        //Need to fill in up to and including this index
        for (int i = 0; i < parentA; i++) {
            // add to first parent
            child.push_back(tempCity.at(i));
        }
        cout << "Adding to first index: " << parentA << endl;

        while (parentA < CITIES_IN_TOUR) {
            for (int i = 0 ; i < CITIES_IN_TOUR; i++) {
                if (!contains_city(tempCity[i])) {
                    // add rest to second parent
                    child.push_back(tempCity[i]);
                    parentA++;
                }
            }
        }
        cout << "Adding to second index: " << parentA << endl;
    }
}

void Population::mutate() {

}

void Population::select_parents() {
    int k = 0;
    double parent_index = 0;

    for (int i = 0; i < NUMBER_OF_PARENTS; i++) {
        vector<Tour> parentPool;
        for (int j = 0; j < PARENT_POOL_SIZE; j++) {
            k = rand() % POPULATION_SIZE;
            parentPool.push_back(parentTour[k]);
            parentPool.clear();
        }
        auto it = parentTour.begin();
        advance(it, k);
        Tour tempTour = it->second;
        parent_index = tempTour.getFitness();
        parents.push_back(parentPool[parent_index]);
        parentTour.insert(make_pair(parent_index, tempTour));

        cout << "Parent " << i << ": " << parents[k].getFitness() << endl;
    }
}

void Population::printElites() {
    for (auto it = parentTour.begin(); it != parentTour.end(); it++) {
        cout << "fitness: " << it->first << endl;
        it->second.printTour();
    }
}

bool Population::contains_city(City myCity) {
    Tour myTour;
    int length;
    for (int i = 0; i < length; i++) {
        if (myTour.getTour()[i].getName() == myCity.getName() &&
            myTour.getTour()[i].getX() == myCity.getX() &&
            myTour.getTour()[i].getY() == myCity.getY()) {
                return true;
        }
    }
    return false;
}
