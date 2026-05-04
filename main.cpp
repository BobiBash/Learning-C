#include <iostream>
#include <sstream>
#include <cmath>
#include <vector>
#include <thread>
#include <chrono>
#include <limits>

void TestingDeclaration() {
    int x;
    x = 5;

    std::cout << x << '\n';
}

double CalculateHypotenuse () {
    int opposite;
    int adjacent;

    std::cout << "Whats the length of the opposite side: ";
    std::cin >> opposite;
    std::cout << "Whats the length of the adjacent side: ";
    std::cin >> adjacent;

    double hypotenuse = hypot(opposite, adjacent);
    std::ostringstream oss;
    oss << "The hypotenuse squared is: " << hypotenuse;
    std::string msg = oss.str();

    std::cout << msg << '\n';

    return hypotenuse;
}

std::string ageCheck() {

    try {
        int x;
        std::cout << "Type your age: " << '\n';
        std::cin >> x;

        if (x > 18) {
            // std::cout << "Access granted." << '\n';
            return "Access granted.";
        } else {
            throw (x);
        }
    }   catch (int age) {
            // std::cout << "Access denied." << '\n';
            // std::cout << "Age is: " << age << '\n';
            // std::cout << "Age required is at least 18" << '\n';
            std::ostringstream oss;
            oss << "Access is denied.\nAge is: " << age << "\nAge required is at least 18.";
            return oss.str();
            }
}

int add() {
    int x;
    x = 10;
    int y;
    y = 15;

    return x + y;
}
void Balance(double user_balance) {
    std::cout << "Your balance is: " << user_balance << '\n';
}

void Withdraw(double user_balance) {
    double amount_to_withdraw;
    std::cout << "Amount to withdraw: ";
    std::cin >> amount_to_withdraw;

    user_balance -= amount_to_withdraw;
    std::cout << "New balance is: " << user_balance << '\n';
}

void Deposit(double user_balance) {
    double amount_to_deposit;
    std::cout << "Amount to deposit: ";
    std::cin >> amount_to_deposit;

    user_balance += amount_to_deposit;
    std::cout << "New balance is: " << user_balance << '\n';
}

void BankProgram(double user_balance) {
    int chosen_option;

    do {
        std::cout << "Choose an option\n";
        std::cout << "1. View balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Type a number: ";
        std::cin >> chosen_option;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 

        switch(chosen_option) {
            case 1:
                Balance(user_balance);
                break;
            case 2:
                Deposit(user_balance);
                break;
            case 3:
                Withdraw(user_balance);
                break;
            case 4:
                std::cout << "Exiting.." << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                std::cout << "Thank you for using our app.\n";
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    } while (chosen_option != 4);
}

void swap(std::string x, std::string y) {
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

int main () {
    // double balance = 5554.23;


    // BankProgram(balance);

    // std::cout << add() << '\n';
    // TestingDeclaration();

    // std::string name;
    // std::cout << "What's your fullname?: ";
    // std::getline(std::cin, name);

    // int age;
    // std::cout << "What's your age?: ";
    // std::cin >> age;

    // std::cout << ageCheck() << '\n';

    // std::cout << CalculateHypotenuse() << '\n';

    // int x = 0;

    // x ? std::cout << "True\n" : std::cout << "False\n";

    // struct Car {
    //     int id;
    //     std::string name;
    //     int year_of_prod;
    //     int price;
    // };

    // std::vector<Car> cars;
    
    // int car_N;
    // std::cin >> car_N;
    
    // for (int i = 1; i <= car_N; i++) {
    //     std::string id = std::to_string(i);
    //     Car car;
    //     car.id = i;
    //     std::cin >> car.name;
    //     std::cin >> car.year_of_prod;
    //     std::cin >> car.price;
    //     cars.push_back(car);
    // }

    // for (const Car& car: cars) {
    //     std::cout << car.name << car.year_of_prod << car.price;
    // }

    // std::string arr[] = {"hello", "test", "test2"};
    // std::string test = "Hello";
    // std::cout << sizeof(arr) << '\n';
    // std::cout << sizeof(std::string) << '\n';
    // std::cout << sizeof(arr)/sizeof(std::string) << '\n';


    // std::string arr[3] = {"hello", "test", "test2"};

    // std::cout << arr;

    std::string x = "hi";
    std::string y = "test";

    swap(x, y);

    std::cout << x << '\n';
    std::cout << y << '\n';

    return 0;

}
