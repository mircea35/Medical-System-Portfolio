#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdlib>


std::vector<std::string> user_info;
bool main_loop = true, loop_two = true;
std::string saved_password, temporary, username, password, name = "";

int is_admin, user_option, age, cancer, cancer_level, is_smoker, smoking_quantity, cancer_history, smoking_history, diabetes_type = 0;

float shots, temp_cost, total_cost = 0.00f;


void reading_medical() {

    temp_cost = 10000.00f;
    std::cout << "=============================" << std::endl;

    switch (std::stoi(user_info.at(4))) {
    case 0:
        std::cout << "You have not got any cancer" << std::endl;
        break;

    case 1:
        //start from here the coding session doing the calculation for 28 days
        total_cost = total_cost + temp_cost;
        std::cout << "You are diagnosed with stage 1 Lung cancer" << std::endl;
        std::cout << "Your treatment is: 1 session of chemotherapy every 4 weeks." << std::endl;
        break;

    case 2:
        total_cost = total_cost + (temp_cost * 2) * 28;
        std::cout << "You are diagnosed with stage 2 Lung cancer" << std::endl;
        std::cout << "Your treatment is: 1 session of chemotherapy every 2 weeks." << std::endl;
        break;

    case 3:
        total_cost = total_cost + (temp_cost * 4);
        std::cout << "You are diagnosed with stage 3 Lung cancer" << std::endl;
        std::cout << "Your treatment is: 1 session of chemotherapy every week." << std::endl;
        break;

    case 4:
        std::cout << "You are diagnosed with stage 4 Lung cancer" << std::endl;
        std::cout << "There is no treatment due to being in the terminal stage." << std::endl;
        break;
    }

    temp_cost = 7.52f;
    std::cout << "=============================" << std::endl;

    switch (std::stoi(user_info.at(5))) {
    case 0:
        std::cout << "You have not got any diabetes" << std::endl;
        break;

    case 1:
        total_cost = total_cost + (temp_cost * 2) * 28;
        std::cout << "You are diagnosed with Type 1 diabetes" << std::endl;
        std::cout << "Your treatment is: 2 shots per day of insulin" << std::endl;
        break;

    case 2:
        total_cost = total_cost + (temp_cost * 1) * 28;
        std::cout << "You are diagnosed with Type 2 diabetes" << std::endl;
        std::cout << "Your treatment is: 1 shots per day of insulin" << std::endl;
        break;
    }

    temp_cost = 5.63f;
    std::cout << "=============================" << std::endl;

    switch (std::stoi(user_info.at(6))) {
    case 0:
        std::cout << "Your records show that you're not smoking." << std::endl;
        break;

    case 1:
        total_cost = total_cost + (temp_cost / 8) * 28;
        std::cout << "Your records show that you're smoking a pack per month." << std::endl;
        std::cout << "Your treatment is: 1 x 100mg pill per day of nicotine tablets" << std::endl;
        break;

    case 2:
        total_cost = total_cost + (temp_cost / 8 * 2) * 28;
        std::cout << "Your records show that you're smoking a pack per week." << std::endl;
        std::cout << "Your treatment is: 2 x 500mg pill per day of nicotine tablets" << std::endl;
        break;

    case 3:
        temp_cost = 3.64f;
        total_cost = total_cost + temp_cost * 28;
        std::cout << "Your records show that you're smoking a pack per day." << std::endl;
        std::cout << "Your treatment is: 1 nicotine patch for every 24 hours" << std::endl;
        break;
    }
    std::cout << "=============================" << std::endl;
    std::cout << "Total Cost for 28 days (a month): " << total_cost << std::endl;
}


void login() {

    std::cout << "Login as:" << std::endl;
    std::cout << "1 - Patient" << std::endl;
    std::cout << "2 - Medical Professional" << std::endl;
    std::cout << "Your input: ";
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

    saved_password = user_info.at(1);
    std::stringstream stream(saved_password);
    size_t saved_hash;
    stream >> saved_hash;
    if (hash == saved_hash) {
        std::cout << "Welcome " << user_info.at(0) << "!" << std::endl;
        std::cout << "What would you like to do?" << std::endl;
        std::cout << "1 - See current medical conditions" << std::endl;
        std::cout << "2 - See medical history" << std::endl;
        std::cout << "3 - See the whole medical report" << std::endl;
        std::cout << "Your input: ";
        std::cin >> user_option;
        switch (user_option) {
            case 1:
                reading_medical();
                while (loop_two) {
                    std::cout << "Do you want to log out? "<< std::endl;
                    std::cout << "1 - Yes" << std::endl;
                    std::cout << "2 - No" << std::endl;

                    switch (user_option)
                    {
                    case 1:
                        break;
                    case 2:
                        break;
                    default:
                        break;
                    }
                }
                break;
            case 2:

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
    std::cout << "Your input: ";
    std::cin >> is_smoker;
    switch (is_smoker) {
    case 1:
        std::cout << "How much are you smoking?" << std::endl;
        std::cout << "1 - One pack per month" << std::endl;
        std::cout << "2 - One pack per week" << std::endl;
        std::cout << "3 - One pack per day" << std::endl;
        std::cout << "Your input: ";
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

    std::cout << "Age: ";
    std::cin >> age;

    std::cout << "Set password: ";
    std::cin >> password;
}



void set_cancer_stage(){
    std::cout << "Do you have Lung Cancer?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cout << "Your input: ";
    std::cin >> user_option;

    switch(user_option){
        case 1:
            user_option = 0;
            main_loop = false;
            cancer_level = 1;
                std::cout << "What is the stage of the cancer?" << std::endl;
                std::cout << "Your input: ";
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
}

void set_diabetes_type(){
    std::cout << "Do you have any type of diabetes?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cout << "Your input: ";
    std::cin >> user_option;
    switch (user_option) {
        case 1:
            std::cout << "Which type of diabetes you have?" << std::endl;
            std::cout << "1 - Type 1" << std::endl;
            std::cout << "2 - Type 2" << std::endl;
            std::cout << "Your input: ";
            std::cin >> diabetes_type;
            break;
        case 2:
            diabetes_type = 0;
            break;
        default:
            std::cout << "Error: Incorrect answer" << std::endl;
            break;
    }
}

void set_medical_history(){
    std::cout << "Now, let's ask some questions about your medical history." << std::endl;
    std::cout << "Did you had Lung Cancer before?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cout << "Your input: ";
    std::cin >> user_option;
    switch (user_option) {
    case 1:
        cancer_history = 1;
        std::cout << cancer_history;
        break;
    case 2:
        cancer_history = 0;
        std::cout << cancer_history;
        break;
    default:
        std::cout << "Error - Incorrect answer";
        break;
    }

    std::cout << "Did you smoked before?" << std::endl;
    std::cout << "1 - Yes" << std::endl;
    std::cout << "2 - No" << std::endl;
    std::cout << "Your input: ";
    std::cin >> user_option;
    switch (user_option) {
    case 1:
        smoking_history = 1;
        std::cout << smoking_history;
        break;
    case 2:
        smoking_history = 0;
        std::cout << smoking_history;
        break;
    default:
        std::cout << "Error - Incorrect answer" << std::endl;
        break;
    }
}

void writing_new_user(){
    std::hash<std::string> hasher;
    size_t hash = hasher(password);

    std::ofstream users("users.csv", std::ios::out | std::ios::app);
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
        std::cout << "Your input: ";
        std::cin >> user_option;

        switch (user_option) {
        case 1:
            register_user();
            set_cancer_stage();
            set_diabetes_type();
            smoking_status();
            set_medical_history();
            writing_new_user();
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
