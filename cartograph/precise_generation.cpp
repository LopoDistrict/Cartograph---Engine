#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <ctime> 
#include <string>
#include <vector>
#include <windows.h>


std::string LatPlayer = "";
std::string LongPlayer = "";


double doubleRand(std::default_random_engine& generator) {
    std::uniform_real_distribution<double> distribution(0.0, 1.0);
    return distribution(generator);
}

    // le script couvre d'abord le fichier des posi player 
    //ensuite il essaye de chercher si dans les coord il y a un - ou une coord == un chiffre
    // ex -3. ou -0 ou -21 ou 9
    
int main() {
     
     std::remove("quests.txt");
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

            std::string LatPlayer2 = line.substr(0, 4);
            std::string LongPlayer2 = line.substr(semicolonPos + 1, 5);

            if (line.find('-') != std::string::npos || line.find('.') != std::string::npos) {
                if (line[0] == '-') {
                    LatPlayer = line.substr(0, 5);
                    LatPlayer2 = line.substr(0, 5);
                }

                if (line[0] == '.' || line[1] == '.') {
                    LatPlayer = line.substr(0, 3);
                    LatPlayer2 = line.substr(0, 3);
                }

                if (line[semicolonPos + 1] == '-') {
                    LongPlayer = line.substr(semicolonPos + 1, 5);
                    LongPlayer2 = line.substr(semicolonPos + 1, 6);
                }

                if (line[semicolonPos + 1] == '.' || line[semicolonPos + 2] == '.') {
                    LongPlayer = line.substr(semicolonPos + 1, 3);
                    LongPlayer2 = line.substr(semicolonPos + 1, 5);
                }
            }
            
            std::cout << "coordonnates" << std::endl;
            std::cout << LatPlayer << std::endl;
            std::cout << LongPlayer << std::endl;
        

            std::cout << LatPlayer2 << std::endl;
            std::cout << LongPlayer2 << std::endl;


            //std::vector<std::string> enemies = {"irradie", "immoral", "revenant", "hell_dog"};

            std::cout << "start" << std::endl;
            std::ofstream file("quests.txt", std::ios::app);
            if (file.is_open()) {
                for (int x = 0; x < 60; x++) {
                    std::cout <<  "" << std::endl;
                    std::random_device rd;
                    std::default_random_engine generator(rd());
                    
                    std::cout <<  "new line" << std::endl;
                    std::cout << "latitude: "<< LatPlayer << " longitude: " << LongPlayer << std::endl;
                    std::cout << "X= "<< LatPlayer + std::to_string(doubleRand(generator)).substr(2) << "   Y= " << LongPlayer + std::to_string(doubleRand(generator)).substr(2) << std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< ";Quest;" << std::endl;
  
                    // pour la creation de ressource
                    


                    // pour la creation d'entité
                    //else if (x >= 400 and x <= 415){
                    //    std::srand(std::time(0));
                        //file << LatPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << ";" << LongPlayer + (std::to_string(doubleRand())).replace(0, 2, "") << ";"<<enemies[std::rand() % enemies.size()] << ";" <<std::endl;
                    //}   
                }
                for (int h=0; h<20; h++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());
                    std::cout << "forrest area" << std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2) << ";Ressource;"<<"forrest area;" << std::endl;
                }
                for (int h=0; h<10; h++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());
                    std::cout << "wheat field" << std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2) << ";Ressource;"<<"wheat field;" << std::endl;
                }

                for (int l=0 ; l <10; l++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());

                    std::cout << "creating the dungeons." << std::endl;
                    std::cout << "X= "<< LatPlayer + std::to_string(doubleRand(generator)).substr(2) << "   Y= " << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< ";Dungeon;"<< "Abandonned Building;"<< "!LV691;" << std::endl;
                    //il faudra faire une liste comme dans ennemy generation pour implementer plusieurs batiments.

                }
                for (int c=0 ; c <10; c++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());

                    std::cout << "creating gas station." << std::endl;
                    std::cout << "X= "<< LatPlayer + std::to_string(doubleRand(generator)).substr(2) << "   Y= " << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< ";Dungeon;"<< "Gas Station;"<< "!KC348;" << std::endl;
                    //il faudra faire une liste comme dans ennemy generation pour implementer plusieurs batiments.

                }
                for (int c=0 ; c <7; c++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());

                    std::cout << "creating building shops" << std::endl;
                    std::cout << "X= "<< LatPlayer + std::to_string(doubleRand(generator)).substr(2) << "   Y= " << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< ";Dungeon;"<< "Shops;"<< "!OE225;" << std::endl;
                    //il faudra faire une liste comme dans ennemy generation pour implementer plusieurs batiments.

                }
                for (int c=0 ; c <7; c++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());

                    std::cout << "creating building shops" << std::endl;
                    std::cout << "X= "<< LatPlayer + std::to_string(doubleRand(generator)).substr(2) << "   Y= " << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< ";Dungeon;"<< "Shops;"<< "!OE225;" << std::endl;
                    //il faudra faire une liste comme dans ennemy generation pour implementer plusieurs batiments.

                }
                for (int c=0 ; c <3; c++){
                    std::random_device rd;
                    std::default_random_engine generator(rd());

                    std::cout << "creating the military outpost" << std::endl;
                    std::cout << "X= "<< LatPlayer + std::to_string(doubleRand(generator)).substr(2) << "   Y= " << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< std::endl;
                    file << LatPlayer + std::to_string(doubleRand(generator)).substr(2) << ";" << LongPlayer + std::to_string(doubleRand(generator)).substr(2)<< ";Dungeon;"<< "Military_outpost;"<< "!0F388;" << std::endl;
                    //il faudra faire une liste comme dans ennemy generation pour implementer plusieurs batiments.

                }
                    }
        
            file.close();
            playerPosition.close();
        }
    }

   
    


    
    
    std::cout << "process finished" << std::endl;
    return 0;
    }
