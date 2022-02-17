// countDucks.cpp 
// P. Conrad for CS16, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
  if (argc!=2) {
    // if argc is not 2, print an error message and exit
    cerr << "Usage: "<< argv[0] << " inputFile" << endl;
    exit(1); // defined in cstdlib
  }
  
  string fileName = argv[1];
  ifstream countDucksFS;
  countDucksFS.open(fileName);
  string animal;
  int duckcount = 0;
  int nonduckcount = 0;

  if(!countDucksFS.is_open()){
	  cout << "Could not open file " << fileName << endl;
  }else{
	getline(countDucksFS, animal);
  	while(!countDucksFS.fail()){
	    if(animal == "duck"){
	    	duckcount++;
	    }else{
	    	nonduckcount++;
	    }
	    getline(countDucksFS, animal);
	}
	countDucksFS.close();
  }

  cout << "Report for " << fileName << ":" << endl;
  cout << setfill(' ');
  cout << setw(16) << right << "Animal count:";
  cout << setw(5) << right << duckcount + nonduckcount << endl;
  cout << setw(14) << right << "Duck count:";
  cout << setw(7) << right << duckcount << endl;
  cout << setw(18) << right << "Non duck count:";
  cout << setw(3) << right << nonduckcount <<endl;
	
  return 0;
}
