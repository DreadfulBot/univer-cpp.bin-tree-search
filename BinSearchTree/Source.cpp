#include <iostream>
#include <windows.h>
using namespace std;

template <typename KeyType> 
class BinTree{
	struct Node{
		KeyType key;
		Node *left, *right;
		Node(const KeyType &k){
			key = k;
			left = right = NULL;
		}
		~Node(){
			if (left)
				delete left;
			if (right)
				delete right;
		}
	};
	Node *root;
public:
	void WriteToStream(ostream &os) {
		WriteToStream(os, root, 0);
	}
	int GetTreeHeight() {
		return GetTreeHeight(root);
	}
	BinTree();
	~BinTree();
	bool InsertKey(const KeyType &key);
	bool FindKey(const KeyType &key);
	//KeyType FindMax(const KeyType &key);
	//KeyType FindMin(const KeyType &key);
	//KeyType FindNext(const KeyType &key);
	//KeyType FindPrev(const KeyType &key);
	bool DeleteSubTree(const KeyType &key);
	//bool DeleteKey(const KeyType &key);
	//int TreeHeight();
private:
	int GetTreeHeight(Node* root);
	void WriteToStream(ostream &os, Node *node, int nTab);
};

template <typename KeyType>
int BinTree<KeyType>::GetTreeHeight(Node* node) {
	if (!node) return 0; 
	cout << node->key << endl;
	return max(GetTreeHeight(node->left), GetTreeHeight(node->right))+1;
}

template <typename KeyType>
void BinTree<KeyType>::WriteToStream(ostream &os, Node *node, int nTab) {
	if (!node) return;
	for (int i=0; i < nTab; i++) os << "\t";
		os << node->key << endl;
		WriteToStream(os, node->left, nTab+1);
		WriteToStream(os, node->right, nTab+1);
}

template <typename KeyType> 
BinTree<KeyType>::BinTree(){
	root = NULL;
}

template <typename KeyType> 
BinTree<KeyType>::~BinTree(){
	delete root;
}

template <typename KeyType> 
bool BinTree<KeyType>::InsertKey(const KeyType &key){
	if (!root){
		root = new Node(key);
		return true;
	}
	Node* tmp = root;
	Node* tmp2;
	while(true){
		if (tmp->key == key)
			return false;
		if (tmp->key < key)
			tmp2 = tmp->right;
		else tmp2 = tmp->left;
		if (tmp2){
			tmp = tmp2;
			continue;
		}
		if (tmp->key < key)
			tmp->right = new Node(key);
		else tmp->left = new Node(key);
		return true;
	}
}

template <typename KeyType> 
bool BinTree<KeyType>::FindKey(const KeyType &key){
	if (!root){
		return false;
	}
	Node* tmp = root;
	Node* tmp2;
	while(true){
		if (tmp->key == key)
			return true;
		if (tmp->key < key)
			tmp2 = tmp->right;
		else tmp2 = tmp->left;
		if (tmp2){
			tmp = tmp2;
			continue;
		}
		return false;
	}
}

template <typename KeyType> 
bool BinTree<KeyType>::DeleteSubTree(const KeyType &key){
	if (!root){
		return false;
	}
	Node* tmp = root;
	Node* tmp2;
	while(true){
		if (tmp->key == key){
			delete tmp;
			return true;
		}
		if (tmp->key < key)
			tmp2 = tmp->right;
		else tmp2 = tmp->left;
		if (tmp2){
			tmp = tmp2;
			continue;
		}
		return false;
	}

}
int main(){
	BinTree<int> T;
	for(int i = 0; i < 99; i++){
		//int a = rand();
		T.InsertKey(i);
		//cout << a << " " << T.InsertKey(a) << endl;
	}
	//cout << T.FindKey(128) << endl;
	//cout << T.FindKey(5138) << endl;
	//T.DeleteSubTree(41);
	/*for(int i = 0; i < 100; i++){
		int a = rand();
		T.InsertKey(a);
		//cout << a << " " << T.InsertKey(a) << endl;
	}*/
	//T.WriteToStream(cout);
	cout << T.GetTreeHeight() << endl;
	return 0;
}