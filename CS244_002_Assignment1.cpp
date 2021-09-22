// CS244_002_Assignment1.cpp : Assignment 1 of Data Structures, using a vector and dynamic array to input info from a file and output into another file
// Created by Preston on 9/18/2021
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;


struct Player {
	string name;
	string team;
	double rating;
	int jerseyNum;
};

/*prototypes*/
void printToFile(Player*, int);
void printingList(Player*, int);
void sortingList(Player*, int);
//void printToFile(const vector<Player> people);
//void printingList(const vector<Player> people);
//void sortingList(vector<Player> people, int);

/*main method*/
int main()
{

	ifstream inFile;
	inFile.open("xboxfifa.txt");
	if (inFile.fail()) exit(1);

	int numberOfPlayers;
	/*reading the numer of the records from the file.*/
	inFile >> numberOfPlayers;

	//vector<Player> people;

	Player* people = new Player[numberOfPlayers];
	int index = 0;

	Player temp;
	
	while (getline(inFile, temp.name)) {
		
		getline(inFile, temp.name);
		getline(inFile, temp.team);
		inFile >> temp.rating;
		inFile >> temp.jerseyNum;
		//people.push_back(temp);
		people[index] = temp;
		++index;
	}
	

	inFile.close();

	//printingList(people);
	printingList(people, numberOfPlayers);
	sortingList(people, numberOfPlayers);
	printingList(people, numberOfPlayers);
	/*
	sort(people.begin(), people.end(), [](Player a, Player b) {
		return a.rating > b.rating;
		});
		*/

	cout << "\nAfter sorting the information." << endl;
	//printingList(people);
	//printToFile(people);
	delete[] people;
	return 0;
}

/*
void sortingList(vector<Player> people, int listSize) {
	/*
	for (int i = 0; i < listSize; ++i)
		for (int j = i + 1; j < listSize; ++j)
			if (people[j].rating > people[i].rating) {
				Player tmpRecord = people[i];
				people[i] = people[j];
				people[j] = tmpRecord;
			}
			*/
	/*
	sort(people.begin(), people.end(), [](Player a, Player b) {
		return a.rating < b.rating;
		});
		
}


void printingList(const vector<Player> people) {
	for (int i = 0; i < people.size(); ++i) {
		cout << "Name   : " << people[i].name << endl;
		cout << "Team   : " << people[i].team << endl;
		cout << "Rating : " << people[i].rating << endl;
		cout << "Number : " << people[i].jerseyNum << endl;
	}
}

void printToFile(const vector<Player> people) {
	ofstream outfile;
	outfile.open("report1.txt");
	int average = 0;
	if (outfile.fail()) {
		exit(2);
	}
	for (int i = 0; i < people.size(); ++i) {
		outfile << i+1 << ") " << people[i].name << "\t\t % " << people[i].rating << endl;
		average += people[i].rating;
	}
	average /= people.size();
	outfile << "---------------------------------------" << endl;
	outfile << "Average: \t\t%" << average << endl;
	cout << "\nData output to file!" << endl;
}

*/


void sortingList(Player* people, int listSize) {
	
	for (int i = 0; i < listSize; ++i)
		for (int j = i + 1; j < listSize; ++j)
			if (people[j].rating > people[i].rating) {
				Player tmpRecord = people[i];
				people[i] = people[j];
				people[j] = tmpRecord;
			}
}

void printingList(Player* people, int listSize) {
	for (int i = 0; i < listSize; ++i){
		cout << "Name   : " << people[i].name << endl;
		cout << "Team   : " << people[i].team << endl;
		cout << "Rating : " << people[i].rating << endl;
		cout << "Number : " << people[i].jerseyNum << endl;
	}
}

void printToFile(Player* people,int recNo) {
	ofstream outfile;
	outfile.open("report1.txt");
	int average = 0;
	if (outfile.fail()) {
		exit(2);
	}
	for (int i = 0; i < recNo; ++i) {
		outfile << i+1 << ") " << people[i].name << "\t\t % " << people[i].rating << endl;
		average += people[i].rating;
	}
	average /= recNo;
	outfile << "---------------------------------------" << endl;
	outfile << "Average: \t\t%" << average << endl;
	cout << "\nData output to file!" << endl;
}

