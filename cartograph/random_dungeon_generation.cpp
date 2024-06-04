#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <random>
#include <algorithm>

int ran(int lower, int higher){
    std::srand(std::time(nullptr)); // use current time as seed for random generator
    return rand() % ((higher-lower) + 1) + lower;
}

int ran2(std::default_random_engine& generator){
    std::uniform_real_distribution<double> distribution(0.0, 3.0);
    return distribution(generator);
}


bool presence(const std::string& proba) {
    std::string cleaned_proba = "";
    for (char c : proba) {
        if (c != ' ' && c != '\n' && c != '\t') {
            cleaned_proba += c;
        }
    }
    double probability = std::stod(cleaned_proba);
    return static_cast<double>(std::rand()) / RAND_MAX < probability;
}

//int second(int number1, intnumber2, vector array){
    
//}

int main() {
    std::remove("generation.flagd");
    std::ifstream file("json/entity.txt");
    std::string line;
    std::vector<std::string> lines;
    
    if (file.is_open()) {
        while (std::getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
        return 1;
    }

    
    std::ofstream f("generation.flagd", std::ios_base::app);
    int max_ennemy = 0;
    int max_object = 0;
    
    if (f.is_open()) {
        for (int i=0; i< ran(3, 7); i++){
            while(true){            
                std::vector<std::string> enemies = {};
                std::random_device rd;
                std::default_random_engine generator(rd());
                int matrice1 = ran2(generator);
                int matrice2 = ran2(generator);

                if (("[" + matrice1 + "]" + "[" + matrice2 + "]") not in ){

                }

                f << "[" << matrice1 << "]" << "[" << matrice2 << "]" << std::endl; 
                //if(matrice1 in ennemies and matrices2 in ennemies){
                //    break;
                //}else{
                //    pass
                //}
            //} }
            }


            for (const auto& nv_l : lines) {
                if (max_ennemy >= 3 or max_object >= 4){
                    max_ennemy = 0;
                    max_object = 0;
                    break; //nouvelle salle 
                    }
                std::cout << nv_l[0] << std::endl;
                if (nv_l[0] == '$') {
                    std::cout << "ENNEMY" << std::endl;
                    std::cout << nv_l << std::endl;
                    std::string temp = nv_l.substr(nv_l.find(',') + 1);
                    temp = temp.substr(temp.find(',') + 1);
                    temp = temp.substr(temp.find(',') + 1);
                    temp = temp.substr(0, temp.find(','));
                    if (presence(temp)) {
                        f << nv_l << std::endl;
                        std::cout << "presence ennemy" << std::endl;
                        max_ennemy += 1;
                    }
                } else if (nv_l[0] == '%') {
                    std::cout << "OBJECT" << std::endl;
                    std::cout << nv_l << std::endl;
                    std::string temp = nv_l.substr(nv_l.find(',') + 1);
                    temp = temp.substr(temp.find(',') + 1);
                    temp = temp.substr(temp.find(',') + 1);
                    temp = temp.substr(temp.find(',') + 1);
                    temp = temp.substr(temp.find(',') + 1);
                    temp = temp.substr(0, temp.find(','));
                    if (presence(temp)) {
                        f << nv_l << std::endl;
                        std::cout << "presence object" << std::endl;
                        max_object += 1;

                    }
                }
            }
        }
        f.close();
    } else {
        std::cerr << "Unable to open file for appending" << std::endl;
        return 1;
    }
    
    return 0;
}
