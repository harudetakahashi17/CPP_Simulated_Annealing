#include "header.h"

double randomizer(){
    double x;
    unsigned seed = rand() % 10;  // Seed for random 0-9
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(-10,10);
    x = distribution(generator);  // Generate a double number
    return x;
}

double randr(){
    double x;
    unsigned seed = rand() % 10;  // Seed for random 0-9
    std::default_random_engine generator (seed);
    std::uniform_real_distribution<double> distribution(0,1);
    x = distribution(generator);  // Generate a double number
    return x;
}

double neighbour(double x){
    double c,s,temp;
    temp = x;   // Temporary variable if condition not met
    s = randomizer();
    c = rand() % 2;  // Random for addition or subtraction
    if (c == 0){
        double d = (x + s);
        if (d >= -10 && d <= 10){
            return d;
        } else {
            return temp*0.3;  // return if d is out of range
        }
    } else {
        double d = (x - s);
        if (d >= -10 && d <= 10){
            return d;
        } else {
            return temp*0.3;  // return if d is out of range
        }
    }
}

double calculate(double x, double y){
    double result = 0.0;
    result = (4 - (2.1 * (pow(x,2))) + (pow(x,4) / 3 )) * pow(x,2) + (x*y) + (-4 + (4 * pow(y,2))) * pow(y,2); // Given Formula
    return result;
}
