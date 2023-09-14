// barchartanimate.h
// TO DO:  This file will take the info from barchart to graph each frame one by one clearing the 
//         previous one. With colors assinged based of the file reading.
//         


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map> 
#include <vector>
#include <unistd.h>
#include "myrandom.h" // used by graders, do not remove
#include "barchart.h"
  
using namespace std;
// const string CYAN("\033[1;36m");
// const string GREEN("\033[1;32m");
// const string GOLD("\033[1;33m");
// const string RED("\033[1;31m");
// const string PURPLE("\033[1;35m");
// const string BLUE("\033[1;34m");
// const string WHITE("\033[1;37m");
// const string RESET("\033[0m");
// const vector<string> COLORS = {CYAN, GREEN, GOLD, RED, PURPLE, BLUE, WHITE};

//
// BarChartAnimate
//
class BarChartAnimate {
 private:
    //
    // Private member variables for the abstraction.
    // This implementation uses a low-level C array, bars, to store a list of
    // BarCharts.  As a result, you must also keep track of the number of
    // elements stored (size) and the capacity of the array (capacity).
    // This IS dynamic array, so it must expand automatically, as needed.
    //
    BarChart* barcharts;  // pointer to a C-style array
    int size;
    int capacity;
    string title;
    string xlabel;
    string source;
    map<string, string> colorMap;

 public:

    // a parameterized constructor:
    // Like the ourvector, the barcharts C-array should be constructed here
    // with a capacity of 4.
    BarChartAnimate(string title, string xlabel, string source) {
        this->title = title;
        this->xlabel = xlabel;
        this->source = source;
        capacity = 4;
        size = 0;
        barcharts = new BarChart[capacity];
    }

    //
    // destructor:
    //
    // Called automatically by C++ to free the memory associated
    // by BarChartAnimate.
    //
    virtual ~BarChartAnimate() {
        if (barcharts != nullptr){
            delete[] barcharts;  // since we new'd an array, we delete[] the same array
        }        
    }

    // addFrame:
    // adds a new BarChart to the BarChartAnimate object from the file stream.
    // if the barcharts has run out of space, double the capacity (see
    // ourvector.h for how to double the capacity).
    // See application.cpp and handout for pre and post conditions.
    void addFrame(ifstream &file) {
        BarChart bars;
        string name = "", categoryOf = "", word, space, year = "";
        int valueOf = 0, capac, count = 0, colorCount = 0;
        vector<string> objects;
        if (size == capacity){ //this is checking to see if size is equal to capacity to increase the capacity
            int newCapacity = capacity * 2;
            BarChart* newA = new BarChart[newCapacity];
            for (int i = 0; i < size; ++i)
            {
                newA[i] = barcharts[i];
                newA[i].setFrame(barcharts[i].getFrame());
            }
            delete[] barcharts;
            barcharts = newA;
            capacity = newCapacity;
        }
        getline(file, word); //skips first line
        if(word == ""){
            return;
        }
        capac = stoi(word); //stores thr capacity fo the frame
        BarChart barsOf(capac); //allocates memory
        while(getline(file, word)){ //if valid
            if(word == ""){
                break;
            }
            stringstream ss(word);
            while(ss.good()){
                getline(ss,space,',');
                objects.push_back(space); //checks for words befroe commas
            }
            //assigns them to the barchart values
            year = objects[0];
            name = objects[1];
            categoryOf = objects[4];
            valueOf = stoi(objects[3]);
            if(colorMap.count(categoryOf) == 0){ //asignes colors to categories
                colorMap.insert({categoryOf, COLORS[colorCount]});
                colorCount += 1;
            }
            if(colorCount == 6){
                colorCount = 0;
            }
            barsOf.addBar(name, valueOf, categoryOf);//inserts the line to the barchart
            objects.clear();
        }
        barcharts[size] = barsOf; //pushes them into the barchart in the struct
        barcharts[size].setFrame(year); //sets the year of it to the number 
        size++;
    }

    // animate:
    // this function plays each frame stored in barcharts.  In order to see the
    // animation in the terminal, you must pause between each frame.  To do so,
    // type:  usleep(3 * microsecond);
    // Additionally, in order for each frame to print in the same spot in the
    // terminal (at the bottom), you will need to type: output << CLEARCONSOLE;
    // in between each frame.
	void animate(ostream &output, int top, int endIter) {
		unsigned int microsecond = 50000;
        if(endIter == -1){
            endIter = this->size;
        }
        for (int i = 0; i < endIter; i++){
            // cout << barcharts[i].getSize() << endl;
            usleep(3 * microsecond);
            output << CLEARCONSOLE;
            output << this->title << WHITE << endl;
            output << this->source << WHITE << endl;
            if(top > barcharts[i].getSize()){ //checks if the amount of frames is less then the amount in top
                int newTop = barcharts[i].getSize();
                barcharts[i].graph(output, colorMap, newTop);
            }
            else{
                barcharts[i].graph(output, colorMap, top);
            }
            output << WHITE << this->xlabel << endl;
            output << WHITE << "Frame: " << barcharts[i].getFrame() <<endl;
        }
	}

    //UNCOMMENT FOR CREATIVE COMPONENT

    // void animate(ostream &output, int top, int startIter, int endIter) {
	// 	unsigned int microsecond = 50000;
    //     float playBack = 0.0;
    //     cout << "Please Enter a PlayBack Speed (in halfsecond intervals)" << endl;
    //     cin >> playBack;

    //     if(endIter == -1){
    //         endIter = this->size;
    //     }
    //     for (int i = startIter; i < endIter+1; i++){
    //         // cout << barcharts[i].getSize() << endl;
    //         usleep(3 * (playBack*1000000));
    //         output << CLEARCONSOLE;
    //         output << this->title << WHITE << endl;
    //         output << this->source << WHITE << endl;
    //         if(top > barcharts[i].getSize()){
    //             int newTop = barcharts[i].getSize();
    //             barcharts[i].graph(output, colorMap, newTop);
    //         }
    //         else{
    //             barcharts[i].graph(output, colorMap, top);
    //         }
    //         output << WHITE << this->xlabel << endl;
    //         output << WHITE << "Frame: " << barcharts[i].getFrame() <<endl;
    //     }
	// }

    // END OF CREATIVE COMPONENT



    //
    // Public member function.
    // Returns the size of the BarChartAnimate object.
    //
    int getSize(){
        
        return size;  // TO DO:  update this, it is only here so code compiles.
    }

    //
    // Public member function.
    // Returns BarChart element in BarChartAnimate.
    // This gives public access to BarChart stored in the BarChartAnimate.
    // If i is out of bounds, throw an out_of_range error message:
    // "BarChartAnimate: i out of bounds"
    //
    BarChart& operator[](int i){
        if (i < 0 || i > this->size){
            throw out_of_range("BarChart: i out of bounds");
        }
        else{
            return barcharts[i];
        }
    }
};
