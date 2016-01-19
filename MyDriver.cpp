#include "AVL.h"
#include <iostream>
#include <fstream>

using namespace std;
int main(int argc,char *argv[]){
	AVL avl;
	ifstream f;
	f.open("english.0", ifstream::in);
	
	string temp;
	while(!f.eof()){
		//temp string from file
		f >> temp;
		
		//remove punc and change to lowercase
		for (int i = 0; i < temp.size(); i++)
    	{
        	if (ispunct(temp[i]))
        	{
            	temp.erase(i--, 1);
        	}	else if(!islower(temp[i])){
        		temp[i] = tolower(temp[i]);
        	}
    	}

		avl.addWord(temp);
	}

	//print to file
	string filename = "final-tree.txt";
	ofstream fout;
	fout.open(filename.c_str());
	fout << avl.toString() << "Height is: " << avl.getHeight() 
		<< "\nNumber of words counted: " << avl.getNumberOfWords()
		<< endl;

	//menu prompting
	int size = avl.getNumberOfWords();
	bool flag = true;
	int iRank = 0;
	string input;
	string wod;

	std::srand(time(NULL));

	while(flag){
		cout << "Enter R to input a specific rank for a word in the tree\nEnter W to get the word of the day" << endl;

		cin >> input;
		if(input.length() > 1){
			cout << "Please enter a correct input tag" << endl;
		}	else if(input == "W" || input == "w"){
			iRank = rand() % size;
			wod = avl.getWordOfDay(iRank);
			cout << "Your word of the day is: " << wod << endl;
		}	else if(input == "R" || input == "r"){
			cout << "What rank? (from 1-" << size << ")" << endl;
			cin >> iRank;
			while(cin.fail() || iRank < 1 || iRank > size){
				cout << "That is not a possible rank. Please enter a rank form 1-" << size << endl;
				cin.clear();
        		cin.ignore(256,'\n');
				cin >> iRank;
			}
			cout << "The word of rank " << iRank << " is: " << avl.getWordOfDay(iRank) << endl;
		}	else{
			cout << "Please enter a correct input tag" << endl;
		}

	}
}