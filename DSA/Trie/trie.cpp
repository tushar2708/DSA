#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 26

class TrieNode{
		public:
				char value;
				int passes;
				TrieNode * children[ALPHABET_SIZE];
				TrieNode(){
						value = 0;
						passes = 0;
						for(int i=0; i<ALPHABET_SIZE; i++){
								children[i] = nullptr;
						}
				}
};

class Trie {
		public:
				TrieNode * root;
				int count;
				Trie(){
						count=0;
						root=new TrieNode();
				}
				void add(string partial);
				int find(string partial);
};

void Trie::add(string partial){

		int len = partial.length();

		TrieNode * temp = root;

		count++;

		for(int i=0;i<len;i++){
				char key = partial[i];
				char index = key - 'a';
				if(temp->children[index] == nullptr){
						temp->children[index] = new TrieNode();
				} 

				temp->children[index]->passes++;

				temp = temp->children[index];
		}

		temp->value = count;

}

int Trie::find(string partial){

		int len = partial.length();

		TrieNode * temp = root;

		for(int i=0;i<len;i++){
				char key = partial[i];
				char index = key - 'a';
				if(temp->children[index] == nullptr){
						return 0;
				}

				temp = temp->children[index];
		}

		return temp->passes;

}

int main() {
		int N;
		cin >> N;
		string instruction, pattern;

		Trie * contacts = new Trie();

		while(N--){
				cin >> instruction >> pattern;
				if(instruction.compare("add") == 0 ){
						contacts->add(pattern);
				}
				if(instruction.compare("find") == 0 ){
						cout << contacts->find(pattern) << endl;
				}
		}

		return 0;
}

