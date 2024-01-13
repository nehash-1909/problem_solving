/*********************************************************************************************************************************
1. Verifying an Alien Dictionary

In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order.
The order of the alphabet is some permutation of lowercase letters.

Given a sequence of words written in the alien language, and the order of the alphabet, 
return true if and only if the given words are sorted lexicographically in this alien language.
*********************************************************************************************************************************/

// Solution

class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        /*
          order = "hlabcdefgijkmnopqrstuvwxyz"
          words = ["hello","leetcode"]

          Store the order in map of size 26, where map[i] tells the order of 'i' char in order string

          1. Check each word with the next one i.e order[i] with order[i+1]
          2. if len(order[i+1])<len(order[i]), return false, e.g. "he" should be before "hello"
          3. if order[i][j] != order[i+1][j], then if map[order[i][j]] > map[order[i+1][j]] then return false, i.e., 
             "hello" should be before "leetcode" if h < l in order.
        */
        vector<int> map(26,0);
        for(int i=0;i<order.length();i++)
        {
            map[order[i]-'a'] = i;
        }

        for(int i=0;i<words.size()-1;i++)
        {
            string w1 = words[i];
            string w2 = words[i+1];
            for(int j=0;j<w1.length();j++)
            {
                if(j == w2.length())
                {
                    return false;
                }
                
                if(w1[j] != w2[j])
                {
                    if(map[w1[j]-'a'] > map[w2[j]-'a'])
                    {
                        return false;
                    }
                    break;
                }
                
            }
        }

        return true;
        
    }
};

