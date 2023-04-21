#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <cstdlib>
#include <algorithm>

std::vector<std::string> user_info = {};
std::vector<std::string> patient_info = {};
std::vector<std::string> compare_vector = {};
std::vector<std::string> compare_vector2 = {};
std::vector<int> cancer_average = {};
std::vector<int> diabetes_average = {};
std::vector<int> history_cancer_average = {};
bool main_loop = true, loop_two = true;
std::string saved_password,temp_username, temp_age, temp_password,temp_cancer, temp_smoking, temp_diabetes, temp_s_history, temp_c_history, temporary, username, password, name = "";
int staff_level = 0, access_level = 0, user_option = 0, age = 0, cancer = 0, cancer_level = 0, is_smoker = 0, smoking_quantity = 0, cancer_history = 0, smoking_history = 0, diabetes_type = 0, avg_age1 = 0 , avg_age2 = 0, avg_age3 = 0;
float shots = 0.00f, temp_cost = 0.00f, total_cost = 0.00f;
float gbp_convert = 1.24f;

//This function is used to decode what was read from the CSV file to the medical record the user can understand
void reading_medical() {

    temp_cost = 10000.00f;
    std::cout << "=============================" << std::endl;

    switch (std::stoi(user_info.at(4))) {
    case 0:
        std::cout << "You have not got any cancer" << std::endl;
        break;

    case 1:
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

    std::cout << "Total cost per day: " << total_cost / 28 << "$" << " or equivalent to GBP " << (total_cost / 28) / gbp_convert << std::endl;
    std::cout << "Total cost per week: " << total_cost / 4 << "$" << " or equivalent to GBP " << (total_cost / 4) / gbp_convert << std::endl;
    std::cout << "Total Cost for 28 days (a month): " << total_cost << "$" << " or equivalent to GBP " << total_cost / gbp_convert << std::endl;
    std::cout << "Total cost per year: " << total_cost * 12 << "$" << " or equivalent to GBP " << (total_cost * 12) / gbp_convert << std::endl;
}

//This function is used to decode what was read from the CSV file to the medical record the user can understand
void reading_history() {
    switch (std::stoi(user_info.at(7))) {
    case 0:
        std::cout << "You have no history of lung cancer." << std::endl;
        break;

    case 1:

        std::cout << "You've had lung cancer in the past, according to your medical history." << std::endl;
        break;
    }

    switch (std::stoi(user_info.at(8))) {
    case 0:
        std::cout << "You have no history of smoking." << std::endl;
        break;

    case 1:
        std::cout << "You have been smoking in the past, according to your medical history." << std::endl;
        break;
    }
}

//This function is firstly called so the user can input their login credentials
void login() {

    std::cout << "Login as:" << std::endl;
    std::cout << "1 - Patient" << std::endl;
    std::cout << "2 - Medical Professional" << std::endl;
    std::cout << "Your input: ";
    std::cin >> user_option;

    switch (user_option) {
        case 1:
            access_level = 0;
            break;
        case 2:
            access_level = 1;
            break;
        default:
            std::cout << "Error - Try again" << std::endl;
            break;
    }

    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    if (access_level == 1) {
        std::ifstream staff("staff.csv");
        while (getline(staff, temporary, ',')) {
            user_info.push_back(temporary);
        }
    }
    else {
        std::ifstream users("users.csv");
        while (getline(users, temporary, ',')) {
            user_info.push_back(temporary);
        }
    }
}

//This function takes care of what happens after a successful user login happens
//Things such as the password verification and username verification are happening here
//From here the user can access their medical history, see the current medical conditions and see the detailed medical report which includes the cost of their treatment
void loggedIn() {
    std::hash<std::string> hasher;
    size_t hash = hasher(password);
    saved_password = user_info.at(1);
    std::stringstream stream(saved_password);
    size_t saved_hash;
    stream >> saved_hash;
    if (hash == saved_hash) {
        while (loop_two) {
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

                std::cout << "Do you want to log out? " << std::endl;
                std::cout << "1 - Yes" << std::endl;
                std::cout << "2 - No" << std::endl;
                std::cout << "Your input: ";
                std::cin >> user_option;
                switch (user_option)
                {
                case 1:
                    user_info = {};
                    loop_two = false;
                    system("cls");
                    break;
                case 2:
                    loop_two = true;
                    break;
                default:
                    break;
                }

                break;
            case 2:
                reading_history();
                std::cout << "Do you want to log out? " << std::endl;
                std::cout << "1 - Yes" << std::endl;
                std::cout << "2 - No" << std::endl;
                std::cout << "Your input: ";
                std::cin >> user_option;
                switch (user_option)
                {
                case 1:
                    user_info = {};
                    loop_two = false;
                    system("cls");
                    break;
                case 2:
                    loop_two = true;
                    break;
                default:
                    break;
                }
                break;
            case 3:
                reading_medical();
                std::cout << "=============================" << std::endl;
                reading_history();
                std::cout << "Do you want to log out? " << std::endl;
                std::cout << "1 - Yes" << std::endl;
                std::cout << "2 - No" << std::endl;
                std::cout << "Your input: ";
                std::cin >> user_option;
                switch (user_option)
                {
                case 1:
                    user_info = {};
                    loop_two = false;
                    system("cls");
                    break;
                case 2:
                    loop_two = true;
                    break;
                default:
                    break;
                }
                break;
            default:
                std::cout << "Error - Try again" << std::endl;
                break;
            }
        }
    }
    else {
        std::cout << "Wrong Password" << std::endl;
    }
}


//This is the first part of the registration process where the user is asked details such as a username, password, their name and age
void register_user() {

    std::cout << "Registering new user..." << std::endl;

    std::cout << "Username: ";
    std::cin >> username;
    std::cin.sync();
    std::cin.get();

    std::cout << "Set password: ";
    std::cin >> password;

    std::cout << "Full Name: ";
    std::getline(std::cin, name, '\n');

    if (access_level == 0) {
        std::cout << "Age: ";
        std::cin >> age;
    }
}

//This is the part of the registration process where the user is asked if they smoke and if so how frequently
//The function in question is also used to modify the patient data by a pharmacist
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

//This is the part of the registration process where the user is asked if they have cancer and if so at what stage
//The function in question is also used to modify the patient data by a pharmacist
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
            while (loop_two) {
                std::cout << "What is the stage of the cancer?" << std::endl;
                std::cout << "Your input: ";
                std::cin >> cancer_level;
                if (cancer_level > 4) {
                    std::cout << "The stage of the cancer cannot be bigger than 4. Please try again." << std::endl;
                }
                else {
                    loop_two = false;
                }
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

//This is the part of the registration process where the user is asked if they had diabetes
//The function in question is also used to modify the patient data by a pharmacist
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

//This is the final part of the registration process a user needs to do.
//This is wehre the user is asked about their medical history (if they smoked/had cancer)
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

//This function is used to modify the patient data by a pharmacist account
void modify_patient_data() {
    loop_two = true;
    temporary = patient_info.at(0);
    std::ifstream users("users.csv");
        while (getline(users, temporary, ',')) {
            compare_vector.push_back(temporary);
        }
    
        std::string strToBeSearched = patient_info.at(0);

        if (std::find(compare_vector.begin(), compare_vector.end(), strToBeSearched) != compare_vector.end())
        {
            compare_vector.erase(std::remove(compare_vector.begin(), compare_vector.end(), strToBeSearched), compare_vector.end());
        }
        for (int i = 0; i < compare_vector.size(); i++) {
            if (i == 0) {
                std::ofstream users("users.csv", std::ios::out);
                users << compare_vector[i] << std::endl;
                users.close();
            }
            else {
                std::ofstream users("users.csv", std::ios::out | std::ios::app);
                users << compare_vector[i] << std::endl;
                            users.close();
            }
        }
        std::ofstream user("users.csv", std::ios::out | std::ios::app);
        user << patient_info.at(0) << "," << patient_info.at(1) << "," << patient_info.at(2) << "," << patient_info.at(3) << "," << patient_info.at(4) << "," << patient_info.at(5) << "," << patient_info.at(6) << "," << patient_info.at(7) << "," << patient_info.at(8) << std::endl;
        
}

//Function used to calculate te average age of people affected by cancer or diabetes and those who recovered from cancer
void calculate_averages() {
    std::ifstream users("users.csv");
     while (getline(users, temporary, ',')) {
        compare_vector2.push_back(temporary);
        std::cout << temporary;
     }
     //Current cancer patients
     if (stoi(compare_vector2.at(4)) > 0)
     {
         cancer_average.push_back(std::stoi(compare_vector2.at(3)));
     }
     //Diabetes
     if (stoi(compare_vector2.at(5)) >= 1) {
         diabetes_average.push_back(std::stoi(compare_vector2.at(3)));
     }
     //Treated cancer patients
     if (stoi(compare_vector2.at(7)) == 1) {
         history_cancer_average.push_back(std::stoi(compare_vector2.at(3)));
     }

     for (int i = 0; i < cancer_average.size(); i++) {
         avg_age1 = avg_age1 + cancer_average[i];
     }

     for (int i = 0; i < diabetes_average.size(); i++) {
         avg_age2 = avg_age2 + diabetes_average[i];
     }

     for (int i = 0; i < history_cancer_average.size(); i++) {
         avg_age3 = avg_age3 + history_cancer_average[i];
     }

     avg_age1 = avg_age1 / cancer_average.size();
     avg_age2 = avg_age2 / diabetes_average.size();
     if (history_cancer_average.size() == 0) {
         avg_age3 = 0;
     }
     else {
         avg_age3 = avg_age3 / history_cancer_average.size();
     }
     std::cout << "The average age for being diagnosed with cancer is: " << avg_age1 << std::endl;
     std::cout << "The average age for being cured from cancer is: " << avg_age3 << std::endl;
     std::cout << "The average age for being diagnosed with Type 1/2 diabetes is: " << avg_age2 << std::endl;
}


//This is the code taking care of what happens after a member of staff is logged in
void staffLoggedIn() {
    std::ifstream users("users.csv");
    std::hash<std::string> hasher;
    size_t hash = hasher(password);
    saved_password = user_info.at(1);
    std::stringstream stream(saved_password);
    size_t saved_hash;
    stream >> saved_hash;

    if (hash == saved_hash && user_info.at(0) == username) {
        switch (stoi(user_info.at(3)))
        {
        case 1:
            std::cout << "Welcome pharmacist " << user_info.at(2) << "!" << std::endl;
            std::cout << "What would you like to do?" << std::endl;
            std::cout << "1 - Create a pharmacist account" << std::endl;
            std::cout << "2 - Change prescriptions of a user" << std::endl;
            std::cout << "3 - See the averages" << std::endl;
            std::cout << "Your input: ";
            std::cin >> user_option;
            switch (user_option) {
            case 1:
                register_user();
                break;
            case 2:
                std::cout << "Input the username of the person in question: ";
                std::cin >> temp_username;
                while (getline(users, temporary, ',')) {
                    patient_info.push_back(temporary);
                }
                if (temp_username == patient_info.at(0)) {
                    std::cout << "What would you like to change?" << std::endl;
                    std::cout << "1 - Change the cancer stage" << std::endl;
                    std::cout << "2 - Change the diabetes type" << std::endl;
                    std::cout << "3 - Change the smoking status" << std::endl;
                    std::cout << "Your input: ";
                    std::cin >> user_option;
                    switch (user_option) {
                    case 1:
                        std::cout << "=== Remember: The prompt will appear as if you are the user ===" << std::endl;
                        set_cancer_stage();
                        patient_info.at(4) = std::to_string(cancer_level);
                        break;
                    case 2:
                        std::cout << "=== Remember: The prompt will appear as if you are the user ===" << std::endl;
                        set_diabetes_type();
                        patient_info.at(5) = std::to_string(diabetes_type);
                        break;
                    case 3:
                        std::cout << "=== Remember: The prompt will appear as if you are the user ===" << std::endl;
                        smoking_status();
                        patient_info.at(6) = std::to_string(smoking_quantity);
                        break;
                    }
                }
                modify_patient_data();
                break;

            case 3:
                calculate_averages();
                break;
            }
            break;

        case 2:
            std::cout << "Welcome nurse " << user_info.at(2) << "!" << std::endl;
            std::cout << "What would you like to do?" << std::endl;
            std::cout << "1 - See patient list" << std::endl;
            std::cout << "2 - See the averages" << std::endl;
            std::cout << "Your input: ";
            std::cin >> user_option;
            switch (user_option) {
            case 1:
                
                break;
            case 2:
                calculate_averages();
                break;
            }

            break;

        case 3:
            std::cout << "Welcome doctor " << user_info.at(2) << "!" << std::endl;
            std::cout << "What would you like to do?" << std::endl;
            std::cout << "1 - See patient list" << std::endl;
            std::cout << "2 - See the averages" << std::endl;
            std::cout << "Your input: ";
            std::cin >> user_option;
            switch (user_option) {
            case 1:

                break;
            case 2:
                calculate_averages();
                break;
            }

            break;

        default:
            std::cout << "Something went wrong! The login database may be corrupted." << std::endl;
            break;
        }
    }
}

//This function gets the variables populated in the registration process and saves them all into the users.csv file
//This is also where the hashing of the password happens
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
            if (access_level == 1) {
                staffLoggedIn();
            }
            else {
                loggedIn();
            }
            break;

        default:
            std::cout << "Error - Try again" << std::endl;
            break;
        }
    }
}
