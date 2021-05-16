#include <stdio.h>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

class TrieNode{
    public:
    unordered_map<char, TrieNode*> children;
    string word = "";
};
class Trie{
    public:
    TrieNode* root;
    string endsymbol;
    Trie();
    void add(string str);
};
Trie::Trie(){
    this->root = new TrieNode();
    this->endsymbol = '*';
}
void Trie::add(string str){
    TrieNode* node = this->root;
    for(char letter:str){
        if(node->children.find(letter) == node->children.end()){
            TrieNode* newNode = new TrieNode();
            node->children.insert({letter, newNode});
        }
        node = node->children[letter];
    }
    node->children.insert({'*', nullptr});
    node->word = str;
}

vector<string> bogglBoard(vector<vector<char>> board, vector<string> words){
    Trie trie; //instantiate object
    for(string word : words){
        trie.add(word);
    }
    vector<string> foundWords;
    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[i].size(); j++){
            if (trie.root->children.find(board[i][j]) != trie.root->children.end()){
                explore(i, j, board, words, trie, &foundWords);
            }
        }
    }
    return foundWords;
    
}

vector<int> explore(int i, int j, vector<vector<char>> board, vector<string> words, Trie trie, vector<string>* foundWords){
    vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
    TrieNode currLetter = trie.root[board[i][j]];
    vector<pair<int, int>> neighbors;
    for(auto dir : directions){
        char dx = dir[0], dy = dir[1];
        if(dx+i>=0 && dx+i<board.size() && dy+j<board[0].size() & dy+j>=0)
            neighbors.push_back({dx+i, dy+j});
    }
    
    for(auto neighbor: neighbors){
        int x = neighbor.first, y = neighbor.second;
        if(trie.root->children.find(board[x][y]) != trie.root->children.end()){
            continue;
        }
        explore(x, y, board, words, currLetter, foundWords);
    }
    if(curr'*')
    
}

vector<string> main(){
    vector<vector<char>> board = {
  {"t", "h", "i", "s", "i", "s", "a"},
  {"s", "i", "m", "p", "l", "e", "x"},
  {"b", "x", "x", "x", "x", "e", "b"},
  {"x", "o", "g", "g", "l", "x", "o"},
  {"x", "x", "x", "D", "T", "r", "a"},
  {"R", "E", "P", "E", "A", "d", "x"},
  {"x", "x", "x", "x", "x", "x", "x"},
  {"N", "O", "T", "R", "E", "-", "P"},
  {"x", "x", "D", "E", "T", "A", "E"}
    };  

    vector<string> words = {
  "this",
  "is",
  "not",
  "a",
  "simple",
  "boggle",
  "board",
  "test",
  "REPEATED",
  "NOTRE-PEATED"
};
    return bogglBoard(board, words);
}