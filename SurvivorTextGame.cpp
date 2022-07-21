//I wrote this game as a challenge while waiting for a final to be marked.
//I wanted to make a very simple survive game using a while loop and inputs from the user
//It's a basic game, but it was fun to create in the 7 days it took for the professor to respond.
//I limited myself to when I had completed the course. I hope you enjoy.


#include <iostream>
#include <iomanip>
#include <random>
#include <stdlib.h>
#include <time.h>
#include "character.h"

using namespace std;

int main() {
  # Basic character variables being init
  
    srand (time(NULL));
    int randNumber = 0;
    int food = 4;
    int wood = 4;
    int medicine = 2;
    int bullets = 8;
    int money = 0;
    int randomEncounter = 0;
    int hunt = 0;

    bool axe = false;
    int axeTemp = 0;
    int axeBonus = 0;
    int lumberTemp = 0;
    int lumber = 0;

    bool gun = false;
    int gunSearch;
    int gunTemp;
    int gunBonus = 0;
    int gunFind = 0;
//    int searches;
//    int searchesBonus;

    int farmFind = 0;
    int farmFood = 0;
    int farmSearch = 0;
    bool farm = false;
    string description;

    int foodTemp = 0;
    int woodTemp = 0;
    int medicineTemp = 0;
    int bulletsTemp = 0;
    int moneyTemp = 0;
    int huntTemp = 0;
    int huntSuccess = 0;
    char huntChoice;

    int encounterFood = 0;
    int encounterWood = 0;
    int encounterBullets = 0;
    int encounterMedicine = 0;
    int encounterHurt = 0;
    unsigned int encounterChoice = 0;

    int hurt = 0;
    int health = 3;
    int healthMax = 3;
    int days = 1;

    char action = '0';
    char pause = '1';
    char classChoice;
    char mainChoice;

    bool clown = true;
    int clownHealth = 5;
    char clownChoice;
    int yourShot = 0;
    int clownShot = 0;

    string place;
    //Food 1 per day per person. Can expand to include more people.
    //Fuel 1 per day, takes that much to stay warm even if fewer people
    //Medicine used one per wound
    //Bullets 1 to hunt, though can spend more to increase chance of success.
    //Days how many days that they have survied.
    //Health, everyone starts with three health. Good, okay, bad, dead.

    cout << "Which class would you like to play?"
         << "\ns: Stock boy (+8 food)"
         << "\nl: Lumberjack (+8 wood"
         << "\nn: Nurse (+4 medicine)"
         << "\ng: Gun Smith (+8 bullets)"
         << "\nb: Bouncer (+1 health)" << endl;

    cin >> classChoice;
    if (classChoice == 's'){
        food += 8;
    }
    else if (classChoice == 'l'){
        wood += 8;
    }
    else if (classChoice == 'n'){
        medicine += 4;
    }
    else if (classChoice == 'b'){
        bullets += 8;
    }
    else if (classChoice == 'l'){
        health += 1;
        healthMax +=1;
    }
    else {
        cout << "Improper selection made. No bonuses given.";
    }

    cout << "\nFood: " << food << " Wood: " << wood << " Medicine: " << medicine << " Bullets: " << bullets << " Health: " << health;

    while (health > 0){
        cout << "\nDay: " << days;
        cout << "\nFood: " << food
             << "\nWood: " << wood
             << "\nMedicine: " << medicine
             << "\nBullets: " << bullets
             << "\nHealth: " << health << endl;
        if (gun == true){
            cout << "Good gun acquired: " << endl;
        }
        if (axe == true){
            cout << "Axe acquired: " << endl;
        }

        if (food >= 1){
            food--;
        }

        if (wood >= 1){
            wood--;
        }

        if (food <= 0){
            health--;
            cout << "Health lost due to lack of food" << endl;
        }

        if (wood <= 0){
            if (food > 0){
                food--;
            }
            cout << "You are out of wood. It takes twice the amount of food to survive until you have fuel" << endl;
        }

        if (health < healthMax && medicine > 0){
            health++;
            medicine--;
            cout << "Health pack used to heal your character\nHealth : " << health << endl;
        }


        action = '0';
        cout << "\n1: Find food";
        if (bullets > 1){
            cout << "\n2: Go Hunting";
        }

        if (farm == false){
            cout << "\n3: Build a farm" << endl;
        }

        if (axe == true){
            cout << "4: Try to chop down some trees" << endl;
        }
        if (gun == false){
            cout << "5: Try to find a gun" << endl;
        }
        cout << "What's your action? ";
        cin >> action;

        if (action == '1'){
            //
            //Section for random sites to search.
            //
            //
                    randNumber = rand() % 150;
                    description = "";
                //Maybe + days at the end, and subtract some, so that they eventually run out of places to check.

if (randNumber >= 0 && randNumber < 2) { 
	place = "supermarket"; 
	foodTemp = (rand() % 4) + 1;
	woodTemp = (rand() % 2) + 0;
	bulletsTemp = (rand() % 2) + 0;
	medicineTemp = (rand() % 2) + 1;
	moneyTemp = (rand() % 5) + 5;
	}

if (randNumber >= 2 && randNumber < 4) { 
	place = "boat house"; 
	foodTemp = (rand() % 2) + 1;
	woodTemp = (rand() % 4) + 1;
	bulletsTemp = (rand() % 2) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 3) + 0;
	}

if (randNumber >= 4 && randNumber < 6) { 
	place = "shack"; 
	foodTemp = (rand() % 2) + 0;
	woodTemp = (rand() % 2) + 1;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 4) + 0;
	}

if (randNumber >= 6 && randNumber < 8) { 
	place = "corner store"; 
	foodTemp = (rand() % 4) + 4;
	woodTemp = (rand() % 3) + 1;
	bulletsTemp = (rand() % 3) + 0;
	medicineTemp = (rand() % 2) + 1;
	moneyTemp = (rand() % 6) + 10;
	}
	
if (randNumber >= 8 && randNumber < 10) { 
	place = "fancy house"; 
	foodTemp = (rand() % 4) + 1;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 5) + 0;
	}
	
if (randNumber >= 10 && randNumber < 12) {
	place = "burned out house"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 3) + 3;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 12 && randNumber < 14) { 
	place = "out house"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 2;
	bulletsTemp = (rand() % 1) + 1;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 14 && randNumber < 16) {
	place = "row boat"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 4;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 16 && randNumber < 18) { 
	place = "hunter lodge"; 
	foodTemp = (rand() % 3) + 2;
	woodTemp = (rand() % 3) + 2;
	bulletsTemp = (rand() % 3) + 10;
	medicineTemp = (rand() % 3) + 2;
	moneyTemp = (rand() % 1) + 5;
	}
	
if (randNumber >= 18 && randNumber < 20) { 
	place = "bunker"; 
	foodTemp = (rand() % 2) + 6;
	woodTemp = (rand() % 2) + 6;
	bulletsTemp = (rand() % 1) + 12;
	medicineTemp = (rand() % 1) + 1;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 20 && randNumber < 22) { 
	place = "cave"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 2) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 22 && randNumber < 24) { 
	place = "gas station"; 
	foodTemp = (rand() % 4) + 1;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 4) + 0;
	}
	
if (randNumber >= 24 && randNumber < 26) { 
	place = "department store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 10) + 0;
	}
	
if (randNumber >= 26 && randNumber < 28) { 
	place = "derpartment store";
	description = "Derp derp derp.";
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 5) + 0;
	}
	
if (randNumber >= 28 && randNumber < 30) { 
	place = "warehouse"; 
	foodTemp = (rand() % 1) + 1;
	woodTemp = (rand() % 2) + 4;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 30 && randNumber < 32) { 
	place = "werehouse"; 
	description = "You go to the werehouse. It growls at you. You shouldn't stay long.";
	foodTemp = (rand() % 1) + 3;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 32 && randNumber < 34) { 
	place = "wherehouse"; 
	description = "You go to the wherehouse, but you don't know where it is.";
	foodTemp = (rand() % 1) + 2;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 34 && randNumber < 36) { 
	place = "wearhouse";
	description = "You wear a house... You feel your humanities being eaten away. Take one damage.";
	foodTemp = (rand() % 1) + 3;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	health -= 1;
	}
	
if (randNumber >= 36 && randNumber < 38) { 
	place = "fabric store"; 
	description = "Bodies on isle four.";
	foodTemp = (rand() % 1) + 1;
	woodTemp = (rand() % 2) + 2;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 5) + 5;
	}
	
if (randNumber >= 38 && randNumber < 40) { 
	place = "clothing store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 3;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 40 && randNumber < 42) { 
	place = "patent office"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 3) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 2) + 15;
	}
	
if (randNumber >= 42 && randNumber < 44) { 
	place = "mayor's office"; 
	foodTemp = (rand() % 2) + 1;
	woodTemp = (rand() % 2) + 0;
	bulletsTemp = (rand() % 7) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 1) + 25;
	}
	
if (randNumber >= 44 && randNumber < 46) { 
	place = "fast food restaurant"; 
	foodTemp = (rand() % 4) + 6;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 5) + 12;
	}
	
if (randNumber >= 46 && randNumber < 48) { 
	place = "slow food restaurant";  
	foodTemp = (rand() % 7) + 4;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 12) + 4;
	}
	
if (randNumber >= 48 && randNumber < 50) { 
	place = "gun store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 6) + 10;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 5) + 10;
	}
	
if (randNumber >= 50 && randNumber < 52) { 
	place = "fun store"; 
	foodTemp = (rand() % 3) + 2;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 10) + 0;
	}
	
if (randNumber >= 52 && randNumber < 54) {
	place = "run store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 15) + 0;
	}
	
if (randNumber >= 54 && randNumber < 56) { 
	place = "pun store"; 
	foodTemp = (rand() % 2) + 2;
	woodTemp = (rand() % 2) + 2; 
	bulletsTemp = (rand() % 2) + 2;
	medicineTemp = (rand() % 2) + 2;
	moneyTemp = (rand() % 2) + 2;
	}
	
if (randNumber >= 56 && randNumber < 58) { 
	place = "phone store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 1;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 10) + 0;
	}
	
if (randNumber >= 58 && randNumber < 60) {
	place = "jewellery store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 15) + 0;
	}
	
if (randNumber >= 60 && randNumber < 62) { 
	place = "dollar store"; 
	foodTemp = (rand() % 3) + 0;
	woodTemp = (rand() % 3) + 1; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 3) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 62 && randNumber < 64) { 
	place = "footwear store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 5) + 10;
	}
	
if (randNumber >= 64 && randNumber < 66) { 
	place = "book store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 4) + 8; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 4) + 4;
	}
	
if (randNumber >= 66 && randNumber < 68) { 
	place = "CD store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 5) + 5;
	}
	
if (randNumber >= 68 && randNumber < 70) { 
	place = "electronics store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 2) + 8;
	}
	
if (randNumber >= 70 && randNumber < 72) { 
	place = "farm"; 
	foodTemp = (rand() % 4) + 8;
	woodTemp = (rand() % 4) + 8; 
	bulletsTemp = (rand() % 6) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
		if (gun == false){
			if (2 == rand() % 10){
			cout << "You found a gun!";
			gun = true;
			}
		}
	}
	
if (randNumber >= 72 && randNumber < 74) {
	place = "adult store"; 
	foodTemp = (rand() % 2) + 3;
	woodTemp = (rand() % 2) + 3; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 8) + 2;
	}
	
if (randNumber >= 74 && randNumber < 76) { 
	place = "medical equipment store"; 
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 2;
	moneyTemp = (rand() % 8) + 4;
	}
	
if (randNumber >= 76 && randNumber < 78) { 
	place = "jerk store"; 
	foodTemp = (rand() % 1) + 4;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 78 && randNumber < 80) { 
	place = "candy store"; 
	foodTemp = (rand() % 3) + 4;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 3) + 0;
	moneyTemp = (rand() % 4) + 2;
	}
	
if (randNumber >= 80 && randNumber < 82) { 
	place = "movie theatre"; 
	foodTemp = (rand() % 4) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 12) + 0;
	}
	
if (randNumber >= 82 && randNumber < 84) { 
	place = "court house";  
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 6) + 2;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 20) + 0;
	}
	
if (randNumber >= 84 && randNumber < 86) { 
	place = "subway station";  
	foodTemp = (rand() % 1) + 2;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 3) + 0;
	moneyTemp = (rand() % 24) + 0;
	}
	
if (randNumber >= 86 && randNumber < 88) { 
	place = "pet store";  
	foodTemp = (rand() % 4) + 4;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 4) + 0;
	moneyTemp = (rand() % 4) + 8;
	}
	
if (randNumber >= 88 && randNumber < 90) { 
	place = "small office";  
	foodTemp = (rand() % 2) + 2;
	woodTemp = (rand() % 1) + 1; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 2) + 0;
	}
	
if (randNumber >= 90 && randNumber < 92) { 
	place = "glasses store";  
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 8) + 4;
	}
	
if (randNumber >= 92 && randNumber < 94) { 
	place = "videogame store";  
	foodTemp = (rand() % 2) + 2;
	woodTemp = (rand() % 1) + 1; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 12) + 0;
	}
	
if (randNumber >= 94 && randNumber < 96) { 
	place = "barn";  
	foodTemp = (rand() % 4) + 4;
	woodTemp = (rand() % 4) + 4; 
	bulletsTemp = (rand() % 4) + 4;
	medicineTemp = (rand() % 2) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 96 && randNumber < 98) { 
	place = "army base";  
	foodTemp = (rand() % 4) + 2;
	woodTemp = (rand() % 4) + 1; 
	bulletsTemp = (rand() % 24) + 0;
	medicineTemp = (rand() % 3) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber == 99) { 
	place = "naval base";  
	foodTemp = (rand() % 4) + 2;
	woodTemp = (rand() % 1) + 1; 
	bulletsTemp = (rand() % 12) + 4;
	medicineTemp = (rand() % 3) + 0;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber == 100) { 
	place = "hospital";  
	foodTemp = (rand() % 3) + 0;
	woodTemp = (rand() % 1) + 1; 
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 12) + 2;
	moneyTemp = (rand() % 1) + 0;
	}
	
if (randNumber >= 101 && randNumber <= 102) { 
	place = "drug store";
	description = "Outside is a mess of pillbottles, and prescriptions.";
	foodTemp = (rand() % 3) + 1;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 1) + 0;
	medicineTemp = (rand() % 6) + 0;
	moneyTemp = (rand() % 12) + 0;
	}
	
	

if (randNumber >= 103 && randNumber <= 150) { 
	place = "nothing";
	description = "You have found nothing.";
	foodTemp = (rand() % 1) + 0;
	woodTemp = (rand() % 1) + 0;
	bulletsTemp = (rand() % 2) + 0;
	medicineTemp = (rand() % 1) + 0;
	moneyTemp = (rand() % 1) + 0;
	}

                cout << "You have come to the " << place << "." << endl;
                cout << description << endl;
                food += foodTemp;
                wood += woodTemp;
                bullets += bulletsTemp;
                medicine += medicineTemp;
                money += moneyTemp;

                if (foodTemp > 0)
                    cout << "You have found " << foodTemp << " food." << endl;
                if (woodTemp > 0)
                    cout << "You have found " << woodTemp << " wood." << endl;
                if (medicineTemp > 0)
                    cout << "You have found " << medicineTemp << " medicine." << endl;
                if (bulletsTemp > 0)
                    cout << "You have found " << bulletsTemp << " bullets." << endl;
                if (moneyTemp > 0)
                    cout << "You have found " << moneyTemp << " money." << endl;

                cout << "\nFood: " << food << " Wood: " << wood << " Medicine: " << medicine << " Bullets: " << bullets
                     << " Health: " << health << " Money: " << money;

            //End of search rooms.
        }
        if (action == '2' && bullets > 0){
            //
            //
            //Begin Hunting option

                hunt = 0;
                while (hunt == 0){
                    huntChoice = '0';
                    bullets -= 1;
                    cout << "Hunting costs 1 bullet." << endl;
                    huntTemp = (rand() % 10) - gunBonus;

                    if (huntTemp <= 2) {
                        huntSuccess = (rand() % 4) + 4;
                        cout << "You have acquired " << huntSuccess << " food";
                        food += huntSuccess;
                        hunt = 1;
                    }

                    if (huntTemp > 2 && bullets > 1){
                        cout << "You failed to find something. Y to spend another bullet - N to not: ";
                        cin >> huntChoice;
                        if (huntChoice == 'n' || huntChoice == 'N')
                            hunt = 1;
                    }

                    if (bullets == 0){
                        hunt = 1;
                    }
                }
            //End Hunting Option
            //
            //
        }

        if (action == '3' && farm == false){
            farmFind = (rand() % 30) - farmSearch;
            farmSearch++;
//            cout << "GunFind is " << gunFind;
            if (farmFind >= 1){
                cout << "You made a farm!" << endl;
                farm = true;
            }
        }

        if (action == '4' && axe == true){
            lumberTemp = rand() % 10;
            if (lumberTemp > 3){
                lumber = 3 + rand() % 4;
                cout << "You have found " << lumber << " wood";
                wood += lumber;
            }
        }

        if (action == '5' && gun == false){
            gunFind = (rand() % 30) - gunSearch;
            gunSearch++;
//            cout << "GunFind is " << gunFind;
            if (gunFind >= 1){
                cout << "You found a better gun!" << endl;
                gun = true;
            }
        }


//Random chance of being hurt in a day.
        hurt = rand() % 10;
        if (hurt == 1){
            health -= 1;
            cout << "\nYou were hurt in your travels." << endl;
        }

//Random encounter chance to see if they can gain additional items.
        encounterHurt = 0;
        randomEncounter = rand() % 8;
        if (randomEncounter == 1 && clown == true){
            cout << "\n\nYou were visited by a gifting clown. \nOn a scale of 0-10, how badly do you want a gift? ";
            cin >> encounterChoice;
            encounterFood += (rand() % 3) + encounterChoice / 2;
            encounterWood += (rand() % 3) + encounterChoice / 2;
            encounterMedicine += (rand() % 2);
            encounterBullets += (rand() % 2);

            if (encounterChoice > 0){
                encounterHurt = (rand() % 10) - encounterChoice;

                if (encounterHurt <= 1){
                    health -= 1;
                    cout << "The crazy clown stabs you, but still provides gifts.";
                }
            }
            if (encounterFood > 0) {
                cout << "\nYou were provided with " << encounterFood << " food." << endl;
                food += encounterFood;
            }
            if (encounterWood > 0) {
                cout << "\nYou were provided with " << encounterWood << " wood." << endl;
                wood += encounterWood;
            }
            if (encounterMedicine > 0) {
                cout << "\nYou were provided with " << encounterMedicine << " medicine." << endl;
                medicine += encounterMedicine;
            }
            if (encounterBullets > 0) {
                cout << "\nYou were provided with " << encounterBullets << " bullets." << endl;
                bullets += encounterBullets;
            }


//Option to attack clown
//
//
            if (bullets > 0){
                cout << "Would you like to try to murder the clown for their gifts (y for yes, n for no)? ";
                cin >> clownChoice;
                clownHealth = 5;
                    while ((clownChoice == 'y' || clownChoice == 'Y') && health > 0 && clown == true && bullets > 0){
                        cout << "Your health: " << health << "\tClown health: " << clownHealth << endl;
                        yourShot = (rand() % 10) - gunBonus;
                        clownShot = (rand() % 10);

                        bullets--;

                        if (yourShot <= 2){
                            clownHealth -= 1;
                            cout << "You hit! Clown loses one life.";
                        }

                        if (clownHealth > 0){
                            if (clownShot <= 2){
                                health -= 1;
                                cout << "You were hit. You lose one health." << endl;
                            }
                        }

                        if (clownHealth > 0){
                        cout << "Would you like to continue (y for yes): ";
                        cin >> clownChoice;
                        }

                        if (clownHealth < 1){
                            clown = false;
                            cout << "You beat the clown!" << endl;
                            cout << "You gain 8 food" << endl;
                            food += 8;
                            cout << "You gain 8 wood" << endl;
                            wood += 8;
                            cout << "You gain 3 medicine" << endl;
                            medicine += 3;
                            cout << "You gain 4 bullets";
                            bullets += 4;
                            if (gun == false){
                                gun = true;
                                cout << "You acquired a better gun." << endl;
                            }

                        }
                    }

            }//End of fighting clown.
        }
        //End of random encounter from the clown.

        //Player can find a better gun once, at 1 in 30 chance.
        if (gun == false){
            gunTemp = rand() % 30;
            if (gunTemp == 1){
                gun = true;
                cout << "You found a better gun.";
            }
        }

        //Player can find an axe to increase wood collection.

        if (axe == false){
            axeTemp = rand() % 30;
            if (axeTemp == 1){
                axe = true;
                axeBonus = 1;
                cout << "You found a better axe. This might be handy.";
            }
        }


        //Food from a farm
        if (farm == true){
            farmFood = rand() % 4;
            if (farmFood == 1 && wood > 0) {
                cout << "Your farm has converted one wood to two food" << endl;
                wood -= 1;
            }
        }

//Pause mechanic to prevent the game from cycling.
//            pause = 'b';
//            while (pause != 'a'){
//                cout << "\nEnter a to continue: ";
//                cin >> pause;
//            }


            cout << endl;
			days++;
		}
    cout << "You have died after " << days << " days" << endl;
}


