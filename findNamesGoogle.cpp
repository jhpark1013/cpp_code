// text = "It was the first ever time that...."
//                ^
//                      "st eve"

// names = ["jennifer", "steve", .... ]

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    string word = "";
};

class Trie
{
public:
    TrieNode *root;
    Trie();
    void add(string str);
};

Trie::Trie()
{
    this->root = new TrieNode();
}

// {s:{];:{e:{v:
void Trie::add(string str)
{
    TrieNode *node = this->root;
    for (char letter : str)
    {
        if (node->children.find(letter) == node->children.end())
        {
            TrieNode *newNode = new TrieNode();
            node->children.insert({letter, newNode});
        }
        node = node->children[letter];
    }
    node->children.insert({'*', nullptr});
    node->word = str;
}


///////////////////////////////////////////////////////////////////// printing
template<typename K, typename V>
void print_map(unordered_map<K,V> const &m)
{
    // specify a lambda expression
    for_each(m.begin(),
                m.end(),
                [](const pair<char, TrieNode*> &p) {
                    cout << "{" << p.first << ": " << p.second << "}\n";
                });
 
    // or pass object of a class overloading the ()operator
    // std::for_each(m.begin(), m.end(), ob);
 
    // or specify a function
    // std::for_each(m.begin(), m.end(), print<K,V>);
}
//////////////////////////////////////////////////////////////////////


             //  5        14
//  text = "It was the first ever time that...."
//                                          ^
//                      "st eve"

//    orig_trie = {s: [t: [e: []]] , j:[]

void traverseTrie(string text, vector<string> names, Trie orig_trie, vector<string> &res)
{
    int i=0;

    //nested while loop
    TrieNode* trie = orig_trie.root;

    while (i < text.size())
    {

        while (trie->children.find(text[i]) != trie->children.end())
        {
            cout << i << " "<< "inner while loop !!!!!!!" << endl;
            trie = trie->children[text[i]];
            print_map(trie->children);
            cout << i << endl;
            if (trie->children.find('*') != trie->children.end())
            {
                res.push_back(trie->word);
                TrieNode* trie = orig_trie.root;
                print_map(trie->children);
                break; // why did i break here... oh because i want it to go to outer while loop to find jessica
            }

            //could not find next word in trie
            if (trie->children.find(text[i]) == trie->children.end())
            {
                TrieNode* trie = orig_trie.root;
            }

            i++;
            cout << i << " , " <<  text[i] << endl;
        }
        cout << i << " " << text[i]<< " " << "outer while loop !!!!!!!" << endl;
        print_map(trie->children);
        i++;
    }
}

vector<string> findNames()
{ //string text, vector<string> names
    Trie trie;
    string text = "It was the firstever time that..jessica..";
    // string text = "steve";
    vector<string> names = {"steve", "jessica"};
    for (string name : names)
    {
        trie.add(name);
    }

    print_map(trie.root->children);


    vector<string> res;
    traverseTrie(text, names, trie, res); //&res oops
    for(string n:res){
        cout << n << endl;
    }
    return res;
}

int main()
{
    findNames();
    return 0;
}