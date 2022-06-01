#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#endif // PASSWORDGENERATOR_H

#include <iostream>
#include <time.h>
using namespace std;


// all data
static string small_letters = "abcdefghijklmnopqrstuvwxyz";
static string big_letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
static string numbers = "0987654321";
static string special_characters = "~`!@#$%^&*()_+-={}|[]:>?<;.,";

void standart_pass_gen(const unsigned short& PassLen, const string& UseData, string& CreatedPassword)
{
    for (short i = 1; i <= PassLen; i++)
    {
        CreatedPassword += UseData[rand() % UseData.size()];    // getting character randomly
    }
}

void special_pass_gen(const unsigned short& PassLen, const string& UseData, string& CreatedPassword)
{
    int characters_id = rand() % UseData.size();
    int id_excluded_characters[UseData.size()];
    for (short i = 1; i <= PassLen; i++)
    {
        for (auto i : id_excluded_characters){
            while (characters_id == i){
                characters_id = rand() % UseData.size();
            }
        }
        CreatedPassword += UseData[characters_id];    // getting character randomly
        id_excluded_characters[i-1] += characters_id;
    }
}


void passgen(){

    srand(time(nullptr));    // seeding for rand()

    string pass;
    string use_data;
    bool use_sl = true;
    bool use_bl = true;
    bool use_num = true;
    bool use_sc = true;
    if (use_sl) use_data += small_letters;
    if (use_bl) use_data += big_letters;
    if (use_num) use_data += numbers;
    if (use_sc) use_data += special_characters;

    unsigned short passLen = 0;
    std::cout << "Enter the password length: ";
    std::cin >> passLen;
    standart_pass_gen(passLen, use_data, pass);
    std::cout << use_data << std::endl;
    std::cout << "Your password: " << pass;    // displaying password

}
