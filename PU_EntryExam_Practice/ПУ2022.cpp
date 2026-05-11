#include <iostream>
#include <vector>
#include <ctime>

int main () {

    // food struct
    struct Food {
        // max length 5
        std::string code;
        // max length 60
        std::string name;
        // positive whole number
        int kg;
        // positive whole number
        int expiry_date;
        // either G for normal food or S for special food
        char food_group;
        std::string arrival_date;
        std::string placement;
        
    };
    // initiate foods vector
    std::vector <Food> foods;
    // take user input for amount of food 0 < N < 500
    int foods_N;
    std::cin >> foods_N;
    std::cin.clear();

    // check if foods_N is between 0 and 1000
    if (!(0 < foods_N && foods_N < 1000)) {
        std::cout << "Number must be between 0 and 1000\n";
        return 0;
    }

    // input login
    while (foods_N) {
        Food f;

        while(true) {
            std::cout << "Food code(1-5 chars): \n";
            std::cin >> f.code;
            if (!f.code.empty() && f.code.size() <= 5) {
                break;
            }
            std::cout << "Invalid code. Please choose a code between 1 and 5 chars\n";
        }

        while(true) {
            std::cout << "Food name(1-60 chars): \n";
            std::getline(std::cin >> std::ws, f.name);
            if (!f.name.empty() && f.name.size() <= 60) {
                break;
            }
            std::cout << "Invalid name. Please choose a name between 1 and 60 chars\n";
        }

        while(true) {
            std::cout << "Food weight(positive whole number): \n";
            std::cin >> f.kg;
            if (!f.kg <= 0) {
                break;
            }
            std::cout << "Invalid weight.\n";
        }

        while(true) {
            std::cout << "Food expiry date(positive whole number): \n";
            std::cin >> f.expiry_date;
            if (!f.expiry_date <= 0) {
                break;
            }
            std::cout << "Invalid expiry date.\n";
        }

        while(true) {
            std::cout << "Food group(G or S, G for normal, S for special): \n";
            std::cin >> f.food_group;
            if (!f.food_group == 'G' || !f.food_group == 'S') {
                break;
            }
            std::cout << "Invalid food group.Choose 'S' or 'G'.\n";
        }

        while(true) {
            std::cout << "Food arrival date(in the format DD.MM.YYYY): \n";
            std::cin >> f.arrival_date;
            if (f.arrival_date.size() == 10) {
                std::string day = f.arrival_date.substr(0, 2);
                char sep1 = f.arrival_date[2];
                std::string month = f.arrival_date.substr(3, 2);
                char sep2 = f.arrival_date[5];
                std::string year = f.arrival_date.substr(6, 4);
                time_t t = time(nullptr);
                tm* now = localtime(&t);
                int current_year = now->tm_year + 1900;
                if (0 < std::stoi(day) <= 31 && sep1 == '.' && 0 < std::stoi(month) <= 12 && sep2 == '.' && 0 < std::stoi(year) <= current_year) {
                    break;
                }
            }
            std::cout << "Invalid arrival date.Choose a date in the format (DD.MM.YYYY).\n";
        }
        if (f.food_group == 'S') {
            while(true) {
                std::cout << "Food group(G or S, G for normal, S for special): \n";
                std::cin >> f.food_group;
                if (!f.food_group == 'G' || !f.food_group == 'S') {
                    break;
                }
                std::cout << "Invalid food group.Choose 'S' or 'G'.\n";
            }
        }
        
        foods_N -= 1;
    }





    return 0;
}