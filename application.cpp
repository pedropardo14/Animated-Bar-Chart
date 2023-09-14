// Bar Chart Animation
//
// This application uses BarChartAnimate (which uses BarChart, which uses Bar)
// to produce an animated bar chart.
//
// Once your three class/abstraction files are completed and tested, run with
// this application to see your final creation.
//
// TO DO: Nothing for the standard application, just compile and run! However,
// before submitting you need to add your creative component.
//
// Adam Koehler
// U. of Illinois, Chicago
// Fall 2022
//
// Original iteration of program developed by:
// Shanon Reckinger
// U. of Illinois, Chicago 
//
// Pedro Pardo
// U. of Illinois, Chicago
// Fall 2022

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "barchartanimate.h"
using namespace std;


int main() {
	string filename = "";
	int start = 0;
	int end = 0;
	ifstream file;
	cout << endl << "Please enter a valid filename to begin." << endl;
	cin >> filename;
	filename = filename;
	file.open(filename); //checks if file is valid 
	if(file.is_open()){ //opens file 
		ifstream inFile(filename);
		string title;
		getline(inFile, title);
		string xlabel;
		getline(inFile, xlabel);
		string source;
		getline(inFile, source);

		BarChartAnimate bca(title, xlabel, source);
		
		while (!inFile.eof()) {
			bca.addFrame(inFile);
		}
		
		bca.animate(cout, 12, -1);
	}
	else{
		cout << "Could not find, exiting. \n";
	}

	// UNCOMMENT BELLOW FOR CREATIVE COMPONENT

	// cout << endl << "Please pick a timespan you want to see starting with the start followed by an end." << endl;
	// cout << "If you would like it end normally enter -1 for the end" << endl;
	// cin >> start >> end;
	// bca.animate(cout, 12, start, end);

	//END OF CREATIVE

    return 0;
}
