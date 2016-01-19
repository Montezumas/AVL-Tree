#include "AVL.h"

AVL::AVL(){
	head = NULL;
}

AVL::~AVL(){
	delete head;
}

//private functions
AVL::Node::Node(){
	word = "";
	height = 0;
	nSize = 0;
	left = NULL;
	right = NULL;
}

AVL::Node::Node(string s, int h, int iS, Node* l, Node* r){
	word = s;
	height = h;
	nSize = iS;
	left = l;
	right = r;
}

AVL::Node::~Node(){
	delete left;
	delete right;
}

void AVL::insert(string s, Node*& root){
	if(root == NULL){
		root = new Node(s,0,1,NULL,NULL);
		if(head==NULL){
			head = root;
		}
		return;
	}

	if(s < root->word){
		insert(s,root->left);

		if(abs(calcHeight(root->left) - calcHeight(root->right)) == 2){
			if(s < root->left->word){
				//case 1
				RR(root);
			}	else{
				//case 3
				LR(root->left);
				RR(root);
			}
		}

	}	else if(root->word < s){
		insert(s,root->right);

		if(abs(calcHeight(root->left) - calcHeight(root->right)) == 2){
			if(root->right->word < s){
				//case 2
				LR(root);
			}	else{
				//case 4
				RR(root->right);
				LR(root);
			}
		}

	}

	root->height = 1 + max(calcHeight(root->left), calcHeight(root->right));
	root->nSize = 1 + calcSize(root->left) + calcSize(root->right);
}

void AVL::RR(Node*& k2){
	Node* k1 = k2->left;
	k2->left = k1->right;
	k1->right = k2;
	k2->height = max(calcHeight(k2->left), calcHeight(k2->right)) + 1;
	k2->nSize = 1 + calcSize(k2->left) + calcSize(k2->right);
	k1->height = max(calcHeight(k1->left), calcHeight(k1->right)) + 1;
	k2 = k1;
	k1->nSize = 1 + calcSize(k1->left) + calcSize(k1->right);
}

void AVL::LR(Node*& k2){
	Node* k1 = k2->right;
	k2->right = k1->left;
	k1->left = k2;
	k2->height = max(calcHeight(k2->left), calcHeight(k2->right)) + 1;
	k2->nSize = 1 + calcSize(k2->left) + calcSize(k2->right);
	k1->height = max(calcHeight(k1->left), calcHeight(k1->right)) + 1;
	k2 = k1;
	k1->nSize = 1 + calcSize(k1->left) + calcSize(k1->right);
}

int AVL::calcHeight(Node* n){
	return n == nullptr ? (-1): n->height;
}

int AVL::calcSize(Node* n){
	return n == nullptr ? 0: n->nSize;
}

string AVL::inOrderString(Node* root){
	string s;

	if(root!=NULL){
		s+=inOrderString(root->left);
		string temp = root->word;
		s+=temp.append("\n");
		s+=inOrderString(root->right);
	}

	return s;
}

string AVL::getWord(int x, Node* root){
	int m = 1 + calcSize(root->left);

	if(m == x){
		return root->word;
	}

	if(m > x){
		return getWord(x,root->left);
	}	else{
		return getWord(x-m,root->right);
	}
}


//public functions
void AVL::addWord(string s){
	insert(s,head);
}

int AVL::getNumberOfWords(){
	return head->nSize;
}

string AVL::getWordOfDay(int x){
	int m = 1 + calcSize(head->left);

	if(m == x){
		return head->word;
	}

	if(m > x){
		return getWord(x,head->left);
	}	else{
		return getWord(x-m,head->right);
	}
 }

int AVL::getHeight(){
	return calcHeight(head);
}

string AVL::toString(){
	return inOrderString(head);
}