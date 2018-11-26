#include <map>
#include <algorithm>
#include <random>
#include "population.hpp"

// add each tour to population
void Population::addToPopulation(Tour tour) {
    pTour.insert(make_pair(tour.getFitness(), tour));
}

// print the tour and fitness of each population
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
    int parentB = rand() % CITIES_IN_TOUR;
    int index = 0;
    for (auto it = pTour.begin(); it != pTour.end(); it++) {
        vector<City> tempCity = it->second.getTour();
        if (index == 0) {
            //Need to fill in up to and including this index
            for (int i = 0; i < parentA; i++) {
                child.push_back(tempCity.at(i));
                index++;
            }
        } else {
            for (unsigned int j = 0; j < tempCity.size() && index < parentB + NUMBER_OF_PARENTS; j++) {
                for (unsigned int i = 0; i < child.size(); i++) {
                    if (!contains_city(child[i])) {
                        child.push_back(tempCity[j]);
                    }
                }
            }
        }

        cout << "\nPrinting child tour" << endl;
        for (auto it = child.begin(); it != child.end(); it++) {
            cout << "City: " << it->getName() << " X: " << it->getX() << " Y: " << it->getY() << endl;
        }
    }
}

// mutate a city
void Population::mutate() {
    vector<City> city;
    int random = 0;
    double mutates = 0;
    for (int i = 0 + NUMBER_OF_ELITES; i < POPULATION_SIZE; i++) {
        for (int j = 0; j < CITIES_IN_TOUR; j++) {
            mutates = rand() / (double) RAND_MAX;
            if (mutates < MUTATION_RATE) {
                random = rand() % CITIES_IN_TOUR;
                swap(j, random);
            }
        }
    }
    cout << "Mutating city" << endl;
}

// select 2 parents for a new tour from a population randomly
void Population::select_parents() {
    int random = 0;
    double parent_index = 0;

    for (int i = 0; i < NUMBER_OF_PARENTS; i++) {
        vector<Tour> parentPool;
        for (int j = 0; j < PARENT_POOL_SIZE; j++) {
            random = rand() % POPULATION_SIZE;
            parentPool.push_back(parentTour[random]);
            parentPool.clear();
        }
        auto it = parentTour.begin();
        advance(it, random);
        Tour tempTour = it->second;
        parent_index = tempTour.getFitness();
        parents.push_back(parentPool[parent_index]);
        parentTour.insert(make_pair(parent_index, tempTour));

        cout << "Parent " << i << ": " << parents[random].getFitness() << endl;
    }
}

// print the elites
void Population::printElites() {
    for (auto it = parentTour.begin(); it != parentTour.end(); it++) {
        cout << "fitness: " << it->first << endl;
        it->second.printTour();
    }
}

// check if city contains a specified city
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
