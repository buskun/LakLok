#include <iostream>
#include "../includes/Game.h"

Game::Game(int initMoney, int initSeeds, int initItems, int initScore) {
    money = initMoney;
    seeds = initSeeds;
    items = initItems;
    score = initScore;
}
void Game::setItem(int itemX) {
    items = itemX;
}

void Game::setMoney(int moneyX) {
    money = moneyX;
}

void Game::setScore(int scoreX) {
    score = scoreX;
}

void Game::setSeed(int seedX) {
    seeds = seedX;
}

int Game::getMoney() {
    return money;
}

int Game::getSeed() {
    return seeds;
}

int Game::getItem() {
    return items;
}

int Game::getScore() {
    return score;
}
