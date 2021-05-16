#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

typedef struct TrieNode{
  struct TrieNode* children[ALPHABET_SIZE];
  char character;
  bool isEndofWord;
} TrieNode;

TrieNode* createTrieNode(){
  TrieNode* node;
  node = (malloc(sizeof(TrieNode)));
  node->isEndofWord = false;
  int i = 0;
  while(i < ALPHABET_SIZE){
      node->children[i] = NULL;
      i++;
  }
  return node;  
}

typedef struct Trie{
    TrieNode* root;
    char endSymbol;

    Trie(string str){
        this->root = new TrieNode();
        this->endsymbol = '*';
        this->populateTrie(str);
    }
} Trie;

void insert(TrieNode* root, char* word){
    TrieNode* node = this->root;
}

int main(){
    printf("hello world");
}
