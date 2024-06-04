#include <iostream>
#include <fstream>
#include <string>
#include <vector>

std::tuple<std::string, double, double, double, double> ennemy_level(int player_level, std::string ennemy_id) {
    std::ifstream file("ennemy.txt");
    std::string line;
    std::vector<std::string> lines;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    std::string ennemy_name;
    double ennemy_life;
    double ennemy_dmg;
    double ennemy_crit;
    double ennemy_defense;

    for (int i = 0; i < lines.size(); i++) {
        std::vector<std::string> val;
        std::string delimiter = ";";
        size_t pos = 0;
        while ((pos = lines[i].find(delimiter)) != std::string::npos) {
            std::string token = lines[i].substr(0, pos);
            val.push_back(token);
            lines[i].erase(0, pos + delimiter.length());
        }
        val.push_back(lines[i]);

        if (val[0] == ennemy_id) {
            ennemy_name = val[1];
            ennemy_life = std::stod(val[2]) * player_level * 0.40;
            ennemy_dmg = std::stod(val[3]) * player_level * 0.30;
            ennemy_crit = std::stod(val[4]) * player_level * 0.20;
            ennemy_defense = std::stod(val[5]) * player_level * 0.30;
            break;
        }
    }

    return std::make_tuple(ennemy_name, ennemy_life, ennemy_dmg, ennemy_crit, ennemy_defense);
}

