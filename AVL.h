#ifndef Asg4_AVL_h
#define Asg4_AVL_h

#include <string>
#include <stdlib.h>

using namespace std;
class AVL{
	private:
		class Node{
			public:
				Node();
				~Node();
				Node(string s, int h, int iS, Node* l, Node* r);
				string word;
				int height;
				int nSize;
				Node* left;
				Node* right;
		};
		void insert (string data, Node*& root);
		void RR(Node*& k2);
		void LR(Node*& k2);
		int calcHeight(Node* n);
		int calcSize(Node* n);
		string inOrderString(Node* root);
		string getWord(int x, Node* root);
		Node* head;
	public:
		AVL();
		~AVL();
		void addWord(string word);
		int getNumberOfWords();
		string getWordOfDay(int x);
		int getHeight();
		string toString();
};
#endif