#include <map>
#include <algorithm>
#include <random>
#include "population.hpp"

#define NUMBER_OF_PARENTS 2
#define PARENT_POOL_SIZE 5
#define POPULATION_SIZE 32
#define NUMBER_OF_ELITES 1

void Population::addToPopulation(Tour tour) {
    pTour.insert(make_pair(tour.getFitness(), tour));
}

void Population::printPopulation() {
    int count = 0;

    for (auto it : pTour) {
        cout << "\nTour: " << count++ << endl;
        cout << "Fitness: " << it.first <<endl;
        it.second.printTour();
    }
}

void Population::crossover(vector<Tour> parents) {
        // Randomly select 2 different parents
//    unsigned long A = 0;
//    unsigned long B = 0;
//    while ( A == B) {   // 2 different numbers
//        A = randInt(parents.size());
//        B = randInt(parents.size());
//    }
//    // Crossover - Copy first half of parent A, then add remaining cities in the order they appear in parent B
//    unsigned long mid = randInt(pTour.size()-1);
//    pTour.clear();
//    for(int k = 0; k < mid; mid++) {
//        pTour.push_back(parents[A].getTour()[k]);
//    }
//    for(int j = mid; j < parents[B].getTour().size(); j++) {
//        if(!contains_city(parents[B].getTour()[j])) {
//            pTour.push_back(parents[B].getTour()[j]);
//        }
//    }
//    getFitness();    // calculates the new fitness/distance
}

void Population::mutate() {

}

void Population::select_parents() {
    int k = 0;
    double parent_index = 0;

    vector<Tour> parents;

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
    }
}

void Population::printElites() {
    for (auto it = parentTour.begin(); it != parentTour.end(); it++) {
        cout << "fitness: " << it->first << endl;
        it->second.printTour();
    }
}

bool Population::contains_city(City myCity, int length) {
    Tour myTour;
    for (int i = 0; i < length; i++) {
        if (myTour.getTour()[i].getName() == myCity.getName() &&
            myTour.getTour()[i].getX() == myCity.getX() &&
            myTour.getTour()[i].getY() == myCity.getY()) {
                return true;
        }
    }
    return false;
}
