#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> credentials;
bool main_loop = true, loop_two = true;
string temporary, username, password, name = "";
size_t saved_hash;
int is_admin, user_option, age, cancer, cancer_level = 0;



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
        ifstream admins("admins.txt");
        getline(admins, temporary, ',');
    }
    else {
        ifstream users("users.txt");
        getline(users, temporary, ',');
    }

    hash<string> hasher;
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
        cout << "Wrong Password";
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
    std::cout << "Do you have Lung Cancer?";
    std::cout << "1 - Yes";
    std::cout << "2 - No";
    std::cin >> user_option;
    switch(user_option){
        case 1:
            cancer = 1;
            loop_two = true;
            while(loop_two){
                cout << "What is the stage of the cancer?";
                cin >> cancer_level;
            }
            if(cancer_level > 4){
                cout << "The stage of the cancer cannot be bigger than 4. Please try again.";
            }
            else{
                loop_two = false;
            }
            break;

        case 2:
            break;
        
        default:
            cout << "Error - Incorrect answer";
            break;
    }

    hash<string> hasher;
    size_t hash = hasher(password);

    ofstream users("users.txt");
    users << username << "," << hash << "," << name << "," << age;
    users.close();
}



int main()
{
    while (main_loop) {
        cout << "Welcome to the NHS Command Line Program" << endl;
        cout << "What do you want to do?" << endl;
        cout << "1 - Register new patient" << endl;
        cout << "2 - Login as a patient or medical professional" << endl;

        cin >> user_option;

        switch (user_option) {
        case 1:
            register_user();
            break;
        case 2:
            login();
            break;

        default:
            cout << "Error - Try again" << endl;
            break;
        }
    }


}
