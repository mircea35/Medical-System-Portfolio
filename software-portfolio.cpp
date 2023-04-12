#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

std::vector<std::string> user_info;
bool main_loop = true, loop_two = true;
std::string temporary, username, password, name = "";
size_t saved_hash;
int is_admin, user_option, age, cancer, cancer_level, is_smoker, smoking_quantity, cancer_history, smoking_history, diabetes_type = 0;



void login() {

    std::cout << "Login as:" << std::endl;
    std::cout << "1 - Patient" << std::endl;
    std::cout << "2 - Medical Professional" << std::endl;

    std::cin >> user_option;

    switch (user_option) {
        case 1:
            is_admin = 0;
            break;
        case 2:
            is_admin = 1;
            break;

        default:
            std::cout << "Error - Try again" << std::endl;
            break;
    }

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (is_admin == 1) {
        std::ifstream admins("admins.csv");
        while (getline(admins, temporary, ',')) {
            user_info.push_back(temporary);
        }
    }
    else {
        std::ifstream users("users.csv");
        while (getline(users, temporary, ',')) {
            user_info.push_back(temporary);
        }
    }

    std::hash<std::string> hasher;
    size_t hash = hasher(password);
    if (hash == saved_hash) {
        std::cout << "Right Password";
        switch (is_admin) {
            case 0:

                break;
            case 1:
                break;

            default:
                std::cout << "Error - Try again" << std::endl;
                break;
        }
    }
    else {
        std::cout << "Wrong Password" << std::endl;
    }
}

void smoking_status() {

    std::cout << "Are you smoking?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cin >> user_option;
    std::cin >> is_smoker;
    switch (is_smoker) {
    case 1:
        std::cout << "How much are you smoking?" << std::endl;
        std::cout << "1 - One pack per month" << std::endl;
        std::cout << "2 - One pack per week" << std::endl;
        std::cout << "3 - One pack per day" << std::endl;
        std::cin >> smoking_quantity;
        break;

    case 2:
        smoking_quantity = 0;
        std::cout << "Thanks for letting us know!";
        break;

    default:
        std::cout << "Error: You have inputted a wrong answer.";
        break;
    }
}


void register_user() {
    std::cout << "Registering new user..." << std::endl;

    std::cout << "Username: ";
    std::cin >> username;
    std::cin.sync();
    std::cin.get();

    std::cout << "Full Name: ";
    std::getline(std::cin, name, '\n');

    std::cout << name << username;

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Set password: ";
    std::cin >> password;

    std::cout << "Do you have Lung Cancer?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cin >> user_option;

    switch(user_option){
        case 1:
            user_option = 0;
            main_loop = false;
            cancer_level = 1;
                std::cout << "What is the stage of the cancer?" << std::endl;
                std::cin >> cancer_level;
                if (cancer_level > 4) {
                    std::cout << "The stage of the cancer cannot be bigger than 4. Please try again." << std::endl;
                }
            break;

        case 2:
            cancer_level = 0;
            std::cout << "Thanks for letting us know!" << std::endl;
            break;
        
        default:
            std::cout << "Error - Incorrect answer" << std::endl;
            break;
    }

    std::cout << "Do you have any type of diabetes?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cin >> user_option;
    switch (user_option) {
        case 1:
            std::cout << "Which type of diabetes you have?" << std::endl;
            std::cout << "1 - Type 1" << std::endl;
            std::cout << "2 - Type 2" << std::endl;
            std::cin >> diabetes_type;
            break;
        case 2:
            diabetes_type = 0;
            break;
        default:
            std::cout << "Error: Incorrect answer" << std::endl;
            break;
    }
    

    smoking_status();

    std::cout << "Now, let's ask some questions about your medical history." << std::endl;
    std::cout << "Did you had Lung Cancer before?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cin >> user_option;
    switch (user_option) {
    case 1:
        cancer_history = 1;
    case 2:
        cancer_history = 0;
        break;
    default:
        std::cout << "Error - Incorrect answer";
        break;
    }

    std::cout << "Did you smoked before?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cin >> user_option;
    switch (user_option) {
    case 1:
        smoking_history = 1;
    case 2:
        smoking_history = 0;
        break;
    default:
        std::cout << "Error - Incorrect answer" << std::endl;
        break;
    }


    std::hash<std::string> hasher;
    size_t hash = hasher(password);

    std::ofstream users("users.csv");
    users << username << "," << hash << "," << name << "," << age << "," << cancer_level << "," << diabetes_type << "," << smoking_quantity << "," << cancer_history << "," << smoking_history << std::endl;
    users.close();
}


int main()
{
    while (main_loop) {
        std::cout << "Welcome to the NHS Command Line Program" << std::endl;
        std::cout << "What do you want to do?" << std::endl;
        std::cout << "1 - Register new patient" << std::endl;
        std::cout << "2 - Login as a patient or medical professional" << std::endl;
        std::cin >> user_option;

        switch (user_option) {
        case 1:
            register_user();
            break;
        case 2:
            login();
            break;

        default:
            std::cout << "Error - Try again" << std::endl;
            break;
        }
    }


}
