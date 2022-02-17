// countDucks.cpp 
// P. Conrad for CS16, Winter 2015
// Example program to read from file and count occurences

#include <iostream> // for printf()
#include <cstdlib> // for exit(), perror()
#include <fstream> // for ifstream

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
  int count = 0;

  if(!countDucksFS.is_open()){
	  cout << "Could not open file " << fileName << endl;
  }else{
	getline(countDucksFS, animal);
  	while(!countDucksFS.fail()){
	    if(animal == "duck"){
	    	count++;
	    }
	    getline(countDucksFS, animal);
	}
	countDucksFS.close();
  }

  cout << "There were " << count << " ducks in " << fileName << endl;
	
  return 0;
}
