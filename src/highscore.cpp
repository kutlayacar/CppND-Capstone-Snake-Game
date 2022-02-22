//
// Created by Kutlay Acar on 22.02.22.
//

#include "highscore.h"

// Write new highscores in highscore.txt
void HighScore::Write(void) {

    std::ofstream file;
    file.open ("../highscore.txt");
    for (std::vector<Player>::iterator it = _playerList.begin(); it != _playerList.end(); ++it){
        file << it -> getName() << " " << it->getScore() << "\n";
    }
    file.close();
}

// After finishing the game print first 5 highscores
void HighScore::Print(void) {
    int i = 0;
    std::cout << "HIGHSCORES:  \n";
    std::cout << "-----------\n";
    for (std::vector<Player>::iterator it = _playerList.begin(); it < _playerList.begin() + 5; ++it) {
        i++;
        std::cout << "Rank " << i << ":\t" << it->getName() << "\t" << it->getScore() << "\n";
    }
    std::cout << "\n";
}

// Update highscore.txt
int HighScore::Update(std::string playerName, int score) {
    Player player;
    player.setName(playerName);
    player.setScore(score);

    // put new score in highscore.txt and sort the list
    if (_playerList.back().getScore() < score){
        _playerList.emplace_back(player);
        std::sort(_playerList.begin(), _playerList.end(), Compare);
    }
    return score;
}
// Compare algorithm for sorting the list
bool Compare(Player p1, Player p2){
    return p1.getScore() > p2.getScore();
}