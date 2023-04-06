#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>

using namespace std;

vector<string> credentials;
bool main_loop = true;
string temporary, username, password, name = "";
size_t saved_hash;
int is_admin, user_option, age = 0;



void login() {
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
    }
    else {
        cout << "Wrong Password";
    }
}


void register_user() {
    std::cout << "Registering new user...";
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Full Name: ";
    std::cin >> name;
    std::cout << "Age: ";
    std::cin >> age;
    std::cout << "Set password: ";
    std::cin >> password;

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
        cout << "2 - Login as a patient" << endl;
        cout << "3 - Login as a medical professional" << endl;
        cin >> user_option;
        switch (user_option) {
        case 1:
            register_user();
            break;
        case 2:
            login();
            break;
        case 3:

            break;

        default:
            cout << "Error - Try again" << endl;
            break;
        }
    }


}
