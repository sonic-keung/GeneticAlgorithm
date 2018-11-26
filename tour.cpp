#include "tour.hpp"
#include "city.hpp"
#include <cmath>
#include <random>
#include <algorithm>

Tour::Tour(vector<City> _tour) {
    this->tour = _tour;
    fitness = get_tour_distance(_tour);
}

double Tour::get_tour_distance(vector<City> city) {
    double totalDist = 0.0;
    for (int i = 0; i < city.size() - 1; i++) {
        totalDist += get_distance_between_cities(city[i], city[i + 1]);
    }
    totalDist += get_distance_between_cities(city[city.size() - 1], city[0]);
    fitness = totalDist;
    return fitness;
}

double Tour::get_distance_between_cities(City a, City b) {
    return sqrt(pow((a.getX() - b.getX()), 2.0) +
                 pow((a.getY() - b.getY()), 2.0));
}

void Tour::printTour() {
    for (unsigned int i = 0; i < tour.size(); i++) {
        cout << "City: " << tour[i].getName() << " x: " << tour[i].getX() << " y: " << tour[i].getY() << endl;
    }
}

double Tour::getFitness() {
    return fitness;
}

void Tour::shuffle_cities(vector<City> &cities) {
    random_device rd;
    mt19937 g(rd());
    shuffle(cities.begin(), cities.end(), g);
}

vector<City> Tour::getTour() {
    return tour;
}