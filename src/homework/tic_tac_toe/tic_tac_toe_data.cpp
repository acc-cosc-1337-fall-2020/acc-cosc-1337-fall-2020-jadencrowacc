//cpp

#include <fstream>
#include "tic_tac_toe_data.h"
#include "tic_tac_toe_3.h"
#include "tic_tac_toe_4.h"
#include <tic_tac_toe.h>

void tic_tac_toe_data::save_games(const std::vector<std::unique_ptr<tic_tac_toe>> &games) {
    std::ofstream file("games.dat");
    for (auto &game : games) {
        file << *game;
    }
    file.close();
}

std::vector<std::unique_ptr<tic_tac_toe>> tic_tac_toe_data::get_games() {
    std::vector<std::unique_ptr<tic_tac_toe>> games;

    std::ifstream file("games.dat");


    std::string line;

    while (std::getline(file, line)) {
        if (line.length() == 10) {
            std::vector<string> pegs(9);
            for (int i = 0; i < 9; i++) {
                pegs[i] = line[i];
            }
            games.push_back(std::make_unique<tic_tac_toe_3>(pegs, string(1, line[9])));
        } else {
            std::vector<string> pegs(16);
            for (int i = 0; i < 16; i++) {
                pegs[i] = line[i];
            }
            games.push_back(std::make_unique<tic_tac_toe_4>(pegs, string(1, line[16])));
        }
    }
    return games;
}

