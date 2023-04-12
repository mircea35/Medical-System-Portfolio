#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> user_info;
bool main_loop = true, loop_two = true;
string temporary, username, password, name = "";
size_t saved_hash;
int is_admin, user_option, age, cancer, cancer_level, is_smoker, smoking_quantity, cancer_history, smoking_history, diabetes_type = 0;



void login() {

    cout << "Login as:" << endl;
    cout << "1 - Patient" << endl;
    cout << "2 - Medical Professional" << endl;

    cin >> user_option;

    switch (user_option) {
        case 1:
            is_admin = 0;
            break;
        case 2:
            is_admin = 1;
            break;

        default:
            cout << "Error - Try again" << endl;
            break;
    }

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (is_admin == 1) {
        ifstream admins("admins.csv");
        while (getline(admins, temporary, ',')) {
            user_info.push_back(temporary);
        }
    }
    else {
        ifstream users("users.csv");
        while (getline(users, temporary, ',')) {
            user_info.push_back(temporary);
        }
    }

    std::hash<string> hasher;
    size_t hash = hasher(password);
    if (hash == saved_hash) {
        cout << "Right Password";
        switch (is_admin) {
            case 0:

                break;
            case 1:
                break;

            default:
                cout << "Error - Try again" << endl;
                break;
        }
    }
    else {
        cout << "Wrong Password" << endl;
    }
}

void smoking_status() {

    std::cout << "Are you smoking?" << endl;
    std::cout << "1 - Yes" << endl;
    std::cout << "2 - No" << endl;
    std::cin >> user_option;
    std::cin >> is_smoker;
    switch (is_smoker) {
    case 1:
        std::cout << "How much are you smoking?" << endl;
        std::cout << "1 - One pack per month" << endl;
        std::cout << "2 - One pack per week" << endl;
        std::cout << "3 - One pack per day" << endl;
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
    std::cout << "Registering new user..." << endl;

    std::cout << "Username: ";
    std::cin >> username;

    std::cout << "Full Name: ";
    std::cin >> name;

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Set password: ";
    std::cin >> password;

    std::cout << "Do you have Lung Cancer?" << endl;
    std::cout << "1 - Yes" << endl;
    std::cout << "2 - No" << endl;
    std::cin >> user_option;

    switch(user_option){
        case 1:
            user_option = 0;
            main_loop = false;
            cancer_level = 1;
                std::cout << "What is the stage of the cancer?" << endl;
                std::cin >> cancer_level;
                if (cancer_level > 4) {
                    cout << "The stage of the cancer cannot be bigger than 4. Please try again." << endl;
                }
            break;

        case 2:
            cancer_level = 0;
            std::cout << "Thanks for letting us know!" << endl;
            break;
        
        default:
            cout << "Error - Incorrect answer" << endl;
            break;
    }

    std::cout << "Do you have any type of diabetes?" << endl;
    std::cout << "1 - Yes" << endl;
    std::cout << "2 - No" << endl;
    std::cin >> user_option;
    switch (user_option) {
        case 1:
            std::cout << "Which type of diabetes you have?" << endl;
            std::cout << "1 - Type 1" << endl;
            std::cout << "2 - Type 2" << endl;
            std::cin >> diabetes_type;
            break;
        case 2:
            diabetes_type = 0;
            break;
        default:
            std::cout << "Error: Incorrect answer" << endl;
            break;
    }
    

    smoking_status();

    std::cout << "Now, let's ask some questions about your medical history." << endl;
    std::cout << "Did you had Lung Cancer before?" << endl;
    std::cout << "1 - Yes" << endl;
    std::cout << "2 - No" << endl;
    std::cin >> user_option;
    switch (user_option) {
    case 1:
        cancer_history = 1;
    case 2:
        cancer_history = 0;
        break;
    default:
        cout << "Error - Incorrect answer";
        break;
    }

    std::cout << "Did you smoked before?" << endl;
    std::cout << "1 - Yes" << endl;
    std::cout << "2 - No" << endl;
    std::cin >> user_option;
    switch (user_option) {
    case 1:
        smoking_history = 1;
    case 2:
        smoking_history = 0;
        break;
    default:
        cout << "Error - Incorrect answer" << endl;
        break;
    }


    std::hash<string> hasher;
    size_t hash = hasher(password);

    ofstream users("users.csv");
    users << username << "," << hash << "," << name << "," << age << "," << cancer_level << "," << diabetes_type << "," << smoking_quantity << "," << cancer_history << "," << smoking_history;
    users.close();
}


int main()
{
    while (main_loop) {
        std::cout << "Welcome to the NHS Command Line Program" << endl;
        std::cout << "What do you want to do?" << endl;
        std::cout << "1 - Register new patient" << endl;
        std::cout << "2 - Login as a patient or medical professional" << endl;
        std::cin >> user_option;

        switch (user_option) {
        case 1:
            register_user();
            break;
        case 2:
            login();
            break;

        default:
            std::cout << "Error - Try again" << endl;
            break;
        }
    }


}
