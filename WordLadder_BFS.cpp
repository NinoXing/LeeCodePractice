/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/
//这是一个BFS问题

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if(wordSet.count(endWord) == 0)return 0;
        queue<string> q;
        q.push(beginWord);
        int res = 0;
        while(!q.empty()){
        	for(int k = q.size(); k > 0; --k){
        		string curWord = q.front();
        		q.pop();
        		if(curWord == endWord) return res + 1;
        		for(int i = 0; i < curWord.size(); ++i){
        			string newWord = curWord;
        			for(char a = 'a'; a <= 'z'; ++a){
        				newWord[i] = a;
        				if(wordSet.count(newWord) && newWord != curWord){
        					q.push(newWord);
        					wordSet.erase(newWord);
        				}
        			}
        		}
        	}
        	++res;
        }
        return 0;
    }
};

//输出全部结果,BFS的是path，不是word
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	vector<vector<string>> res;
    	unordered_set<string> dict(wordList.begin(), wordList.end());
    	vector<string> path{beginWord};
    	queue<vector<string>> paths;
    	paths.push(path);
    	int level = 1; int minLevel = INT_MAX;
    	unordered_set<string> visited;

    	while(!paths.empty()){
    		vector<string> curPath = paths.front(); paths.pop();

    		if(curPath.size() > level){
    			for(string w : visited)dict.erase(w);
    			visited.clear();
    			level = curPath.size();
    			if(level > minLevel)break;
    		}

    		string last = curPath.back();
    		for(int i = 0; i < last.size(); ++i){
    			string newLast = last;
    			for(char a = 'a'; a < 'z'; ++a){
    				newLast[i] = a;
    				if(!dict.count(newLast))continue;
    				visited.insert(newLast);
    				vector<string> nextPath = curPath;
    				nextPath.push_back(newLast);
    				if(newLast == endWord){
    					res.push_back(nextPath);
    					minLevel = level;
    				}else paths.push(nextPath);
    			}
    		}
    	}
		return res;		        
    }
};































