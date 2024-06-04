#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <ctime>

#include <iostream>
#include <fstream>
#include <string>
#include <vector>



std::string LatPlayer = "";
std::string LongPlayer = "";

double doubleRand() {
   return sqrt((double)rand() / RAND_MAX);
}

    // le script couvre d'abord le fichier des posi player 
    //ensuite il essaye de chercher si dans les coord il y a un - ou une coord == un chiffre
    // ex -3. ou -0 ou -21 ou 9

int main() {
     std::ifstream playerPosition("player_position.txt");

    if (!playerPosition.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(playerPosition, line)) {
        size_t semicolonPos = line.find(';');
        if (semicolonPos != std::string::npos) {
            std::string LatPlayer = line.substr(0, 4);
            std::string LongPlayer = line.substr(semicolonPos + 1, 4);

            if (line.find('-') != std::string::npos || line.find('.') != std::string::npos) {
                if (line[0] == '-') {
                    LatPlayer = line.substr(0, 5);
                }

                if (line[0] == '.' || line[1] == '.') {
                    LatPlayer = line.substr(0, 3);
                }

                if (line[semicolonPos + 1] == '-') {
                    LongPlayer = line.substr(semicolonPos + 1, 5);
                }

                if (line[semicolonPos + 1] == '.' || line[semicolonPos + 2] == '.') {
                    LongPlayer = line.substr(semicolonPos + 1, 3);
                }
            }

            std::cout << LatPlayer << std::endl;
            std::cout << LongPlayer << std::endl;

            std::cout << "start" << std::endl;
            std::remove("quests.txt");

            std::ofstream file("quests.txt", std::ios::app);
            if (file.is_open()) {
                for (int x = 0; x < 400; x++) {
                    std::cout <<  "" << std::endl;
                    std::cout << doubleRand() << std::endl;
                    std::cout <<  "new line" << std::endl;
                    std::cout << "latitude: "<< LatPlayer << " longitude: " << LongPlayer << std::endl;
                    std::cout << "X= "<< LatPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << "   Y= " << LongPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << std::endl;
                    file << LatPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << ";" << LongPlayer + (std::to_string(doubleRand())).replace(0, 2, "")<< ";Quest;" << std::endl;

                    if (x % 5 == 0){
                        file << LatPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << ";" << LongPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << ";Ressource;" << std::endl;
                    }
                }
                    }
        
            file.close();
            playerPosition.close();
        }
    }


    
    std::cout << "process finished" << std::endl;
    return 0;
    }
