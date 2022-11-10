// Copyright (c) 2022 Spencer Scarlett All rights reserved.
// .
// Created by: Spencer Scarlett
// Created on: Nov 9, 2022
// Guessing game program with a loop used when the incorrect answer is picked

#include <iostream>
#include <random>

int main() {
    // Declaring variables
    int userNumberInt, wait;
    std::string userNumberStr;

    // Created random number
    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 9);
    const int numberGen{idist(rgen)};


    do {
        // Gets the user's guess
        std::cout << "Enter a number between 0-9: ";
        std::cin >> userNumberStr;

        // Try's to cast input to int
        try {
            userNumberInt = std::stoi(userNumberStr);

            // If input is not valid
        } catch (const std::exception) {
            std::cout << "Enter a number guess from 0-9 only!: \n";
            std::cin >> wait;
        }

        // Breaks the loop once correct answer is found
        if (userNumberInt == numberGen) {
            break;

        // Repeats loop until correct answer is found
        } else {
            std::cout << "Number incorrect, try again.\n\n";
        }
    } while (userNumberInt != numberGen);

    // End message for correct answer
    std::cout << "Number is correct!\n";
}
