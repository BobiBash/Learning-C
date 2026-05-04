#include <iostream>
#include <vector>
#include <sstream>

int main() {

    struct Car {
        int id;
        std::string brand;
        int year_of_prod;
        double price;
        std::string currency;
    };

    std::vector<Car> cars;

    // input where 10<=N<=500
    int car_N = 15;

    // for loop with length N
    for (int i = 1; i <= car_N; i++) {
        Car car;
    //     car_number int
        car.id = i;
    //     car_brand using getline where car_brand <= 30 and split names by " "
        std::getline(std::cin, car.brand);
    //     car_year_of_prod
        std::cin >> car.year_of_prod;
    //     car_price
        std::cin >> car.price;
    //     car_currency - either euro or lev
        std::cin >> car.currency;

        cars.push_back(car);
    }
    
    std::ostringstream oss;
    oss << 

    // ask user to input budget(double)

    // int total_car_price
    // for loop iterating through all created cars
    // for car in cars:
    //     if car_currency = euro
    //         car_price = car_price * 1.96
    //         car_currency = bgn
    //     print all cars
    //     if car_price <= price_limit: 
    //         print car
    //     combined price of all cars:
    //     total_car_price += car_price
    //     if (car_currency < 6000 && car_year_of_prod > 2000)
    //         print car

    return 0;
}

/*
    1, Audi A4, 2020, 45000, lev
    2, BMW 320d, 2018, 38000, lev
    3, BMW X5, 2022, 120000, lev
    4, Citroen C3, 2005, 2500, euro
    5, Fiat Punto, 2001, 1800, euro
    6, Ford Focus, 1999, 3000, lev
    7, Honda Civic, 2008, 8500, lev
    8, Mercedes C180, 2015, 22000, euro
    9, Nissan Micra, 2003, 2800, euro
    10, Opel Astra, 2007, 4500, lev
    11, Opel Corsa, 2002, 1900, euro
    12, Peugeot 206, 1998, 1500, lev
    13, Renault Clio, 2010, 5500, lev
    14, Toyota Yaris, 2004, 3200, euro
    15, Volkswagen Golf, 2017, 18000, lev
*/