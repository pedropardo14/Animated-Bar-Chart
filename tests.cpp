#include <iostream>
#include "barchartanimate.h"
using namespace std;


bool testBarDefaultConstructor() {
	Bar b;
    if (b.getName() != "") {
    	cout << "testBarDefaultConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 0) {
    	cout << "testBarDefaultConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "") {
    	cout << "testBarDefaultConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarParamConstructor() {
	Bar b("Chicago", 9234324, "US");
    if (b.getName() != "Chicago") {
    	cout << "testBarParamConstructor: getName failed" << endl;
    	return false;
    } else if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } else if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
    cout << "testBarParamConstructor: all passed!" << endl;
    return true;
}

bool testBarGetName(){
	Bar b("Chicago", 9234324, "US");
	if (b.getName() != "Chicago") {
		cout << "testBarParamConstructor: getName failed" << endl;
		return false;
	} 
	cout << "testBarGetName passed!" << endl;
	return true;
}

bool testBarGetName2(){
	Bar b("lmao", 9234324, "US");
	if (b.getName() != "lmao") {
		cout << "testBarParamConstructor: getName failed" << endl;
		return false;
	} 
	cout << "testBarGetName2 passed!" << endl;
	return true;
}

bool testBarGetValue(){
	Bar b("Chicago", 9234324, "US");
	if (b.getValue() != 9234324) {
    	cout << "testBarParamConstructor: getValue failed" << endl;
    	return false;
    } 
	cout << "testBarGetValue passed!" << endl;
	return true;
}

bool testBarGetValue2(){
	Bar b("Chicago", 1090, "US");
	if (b.getValue() != 1090) {
    	cout << "testBarParamConstructor2: getValue failed" << endl;
    	return false;
    } 
	cout << "testBarGetValue2 passed!" << endl;
	return true;
}

bool testBarGetCategory(){
	Bar b("Chicago", 9234324, "US");
	if (b.getCategory() != "US") {
    	cout << "testBarParamConstructor: getCategory failed" << endl;
    	return false;
    }
	cout << "testBarGetCategory passed!" << endl;
	return true;
}

bool testBarGetCategory2(){
	Bar b("Chicago", 9234324, "Adam");
	if (b.getCategory() != "Adam") {
    	cout << "testBarParamConstructor2: getCategory failed" << endl;
    	return false;
    }
	cout << "testBarGetCategory2 passed!" << endl;
	return true;
}

bool operatorLessThan(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	if(b1 < b2){	
		cout << "operatorLessThan passed!" << endl;
		return true;
	}
	else{
		cout << "operatorLessThan failed!" << endl;
		return false;
	}
}

bool operatorLessThan2(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 40, "cat");
	if(b1 < b2){	
		cout << "operatorLessThan2 passed!" << endl;
		return true;
	}
	else{
		cout << "operatorLessThan2 failed!" << endl;
		return false;
	}
}

bool operatorMoreThan(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	if(b2 > b1){	
		cout << "operatorMoreThan passed!" << endl;
		return true;
	}
	else{
		cout << "operatorMoreThan failed!" << endl;
		return false;
	}
}

bool operatorMoreThan2(){
	Bar b1("a", 600, "cat");
	Bar b2("b", 1, "cat");
	if(b1 > b2){	
		cout << "operatorMoreThan2 passed!" << endl;
		return true;
	}
	else{
		cout << "operatorMoreThan2 failed!" << endl;
		return false;
	}
}

bool operatorLessThanOrEqualTo(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	if(b1 <= b2){	
		cout << "operatorLessThanOrEqualTo passed!" << endl;
		return true;
	}
	else{
		cout << "operatorLessThanOrEqualTo failed!" << endl;
		return false;
	}
}

bool operatorLessThanOrEqualTo2(){
	Bar b1("a", 1, "cat");
	Bar b2("b", 40, "cat");
	if(b1 <= b2){	
		cout << "operatorLessThanOrEqualTo2 passed!" << endl;
		return true;
	}
	else{
		cout << "operatorLessThanOrEqualTo2 failed!" << endl;
		return false;
	}
}

bool operatorMoreThanOrEqualTo(){

	Bar b1("a", 1, "cat");
	Bar b2("b", 2, "cat");
	if(b2 >= b1){	
		cout << "operatorMoreThanOrEqualTo passed!" << endl;
		return true;
	}
	else
	{	
		cout << "operatorMoreThanOrEqualTo failed!" << endl;
		return false;
	}
}

bool operatorMoreThanOrEqualTo2(){

	Bar b1("a", 4, "cat");
	Bar b2("b", 2, "cat");
	if(b1 >= b2){	
		cout << "operatorMoreThanOrEqualTo2 passed!" << endl;
		return true;
	}
	else
	{	
		cout << "operatorMoreThanOrEqualTo2 failed!" << endl;
		return false;
	}
}
//////////////////////////////////////////////// end of bar.h tests

// barchart.h tests
bool testBarchartDefaultConstructor(){
	BarChart bc;
	if(bc.getFrame() != ""){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	else if (bc.getSize() != 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
    cout << "testBarchartDefaultConstructor: all passed!" << endl;
    return true;
}

bool testBarchartParamConstructor(){
	BarChart bc(3);
	if(bc.getFrame() != ""){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	else if(bc.getSize() != 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarchartParamConstructor: all passed!" << endl;
    return true;
}

bool testBarchartCopyConstructor(){
	BarChart bc(10);
	BarChart bcCopy(bc);
	if(bcCopy.getFrame() != bc.getFrame()){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	else if(bcCopy.getSize() != bc.getSize()){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarchartParamConstructor: all passed!" << endl;
    return true;
}

bool testBarchartSetFrame(){
	BarChart bc;
	bc.setFrame("1950");
	if(bc.getFrame() != "1950"){
		cout << "Barchart setFrame() failed!";
		return false;
	}
	cout << "testBarchartSetFrame passed!" << endl;
	return true;
}

bool testBarchartSetFrame2(){
	BarChart bc;
	bc.setFrame("2000000");
	if(bc.getFrame() != "2000000"){
		cout << "Barchart setFrame2() failed!";
		return false;
	}
	cout << "testBarchartSetFrame2 passed!" << endl;
	return true;
}

bool testBarchartGetFrame(){
	BarChart bc;
	if(bc.getFrame() != ""){
		cout << "Barchart getFrame() failed!";
		return false;
	}
	cout << "testBarchartGetFrame passed!" << endl;
	return true;
}

bool testBarchartGetFrame2(){
	BarChart bc;
	bc.setFrame("2000000");
	if(bc.getFrame() != "2000000"){
		cout << "Barchart getFrame2() failed!";
		return false;
	}
	cout << "testBarchartGetFrame2 passed!" << endl;
	return true;
}

bool testBarchartAddBar(){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	if(bc.getSize() == 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarchartAddBar passed!" << endl;
	return true;
}

bool testBarchartAddBar2(){
	BarChart bc(1);
	bc.addBar("Chicago", 1020, "US");
	if(bc.getSize() != 1){
		cout << "Barchart getSize2() failed!";
		return false;
	}
	cout << "testBarchartAddBar2 passed!" << endl;
	return true;
}

bool testBarchartAddBarPastCapacity(){
	BarChart bc(3);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("San Francisco", 1200, "US");

	if(bc.getSize() != 3){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarchartAddBarPastCapacity passed!" << endl;
	return true;
}

bool testBarchartAddBarPastCapacity2(){
	BarChart bc(1);
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");
	bc.addBar("San Francisco", 1200, "US");

	if(bc.getSize() != 1){
		cout << "Barchart testBarchartAddBarPastCapacity2() failed!" << endl;
		return false;
	}
	cout << "testBarchartAddBarPastCapacity2 passed!" << endl;
	return true;
}

bool testBarchartGetSize(){
	BarChart bc;
	if(bc.getSize() != 0){
		cout << "Barchart getSize() failed!";
		return false;
	}
	cout << "testBarchartGetSizepassed!" << endl;
	return true;
}

bool testBarchartGetSize2(){
	BarChart bca(3);
	bca.addBar("Chicago", 1020, "US");
	bca.addBar("NYC", 1300, "US");
	bca.addBar("Paris", 1200, "France");
	if(bca.getSize() != 3){
		cout << "Barchart getSize2() failed!" << endl;
		return false;
	}
	else{
		cout << "testBarchartGetSize2 passed!" << endl;
	}
	return true;
}

void testBarchartBracketOperator(){
	BarChart bc(3);
	bc.setFrame("1950");
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	int n = bc.getSize();
	for (int i = 0; i < n; i++) {
		cout << bc[i].getName() << " ";
		cout << bc[i].getValue() << " ";
		cout << bc[i].getCategory();
		cout << endl;
	}
}

void testBarchartBracketOperator2(){
	BarChart bc(3);
	bc.setFrame("2022");
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	int n = bc.getSize();
	for (int i = 0; i < n; i++) {
		cout << bc[i].getName() << " ";
		cout << bc[i].getValue() << " ";
		cout << bc[i].getCategory();
		cout << endl;
	}
}

void testDump(){
	BarChart bc(3);
	bc.setFrame("1950");
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.dump(cout);
}

void testDump2(){
	BarChart bc(8);
	bc.setFrame("1950");
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("Paris", 1200, "France");
	bc.addBar("Paris", 1200, "France");
	bc.dump(cout);
}

void testBarchartGraph(){
	BarChart bc(3);
	bc.setFrame("1950");
	bc.addBar("Chicago", 1020, "US");
	bc.addBar("NYC", 1300, "US");
	bc.addBar("Paris", 1200, "France");
	string GREEN("\033[1;32m");
	string PURPLE("\033[1;35m");
	map<string, string> colorMap;
	colorMap["US"] = GREEN;
	colorMap["France"] = PURPLE;
	bc.graph(cout, colorMap, 3);
}

void testBarchartGraph2(){
	BarChart bc(3);
	bc.setFrame("1950");
	bc.addBar("Pedro", 1020, "Mexico");
	bc.addBar("Adam", 1300, "US");
	bc.addBar("Cole", 1200, "Italy");
	string GOLD("\033[1;33m");
	string RED("\033[1;31m");
	string GREEN("\033[1;32m");
	map<string, string> colorMap;
	colorMap["Mexico"] = GREEN;
	colorMap["US"] = GOLD;
	colorMap["Italy"] = RED;
	bc.graph(cout, colorMap, 3);
}

//end of barchart.h
//////////////////////////////////////////////////////////////////////////////// 

void runApp(){
	string filename = "cit.txt";
	ifstream inFile(filename);
	string title;
	getline(inFile, title);
	string xlabel;
	getline(inFile, xlabel);
	string source;
	getline(inFile, source);
	BarChartAnimate bca(title, xlabel, source);
	// cout << "lol" << endl;
	while (!inFile.eof()) {
		bca.addFrame(inFile);
	}
}

int main() {
	testBarDefaultConstructor();
	testBarParamConstructor();
	testBarGetName();
	testBarGetName2();
	testBarGetValue();
	testBarGetValue2();
	testBarGetCategory();
	testBarGetCategory2();
	operatorLessThan();
	operatorLessThan2();
	operatorMoreThan();
	operatorMoreThan2();
	operatorLessThanOrEqualTo();
	operatorLessThanOrEqualTo2();
	operatorMoreThanOrEqualTo();
	operatorMoreThanOrEqualTo2();
	testBarchartDefaultConstructor();
	testBarchartParamConstructor();
	testBarchartCopyConstructor();
	testBarchartSetFrame();
	testBarchartSetFrame2();
	testBarchartGetFrame();
	testBarchartGetFrame2();
	testBarchartAddBar();
	testBarchartAddBar2();
	testBarchartAddBarPastCapacity();
	testBarchartAddBarPastCapacity2();
	testBarchartGetSize();
	testBarchartGetSize2();
	testBarchartBracketOperator();
	testBarchartBracketOperator2();
	testDump();
	testDump2();
	testBarchartGraph();
	testBarchartGraph2();
	runApp();
    return 0;
}