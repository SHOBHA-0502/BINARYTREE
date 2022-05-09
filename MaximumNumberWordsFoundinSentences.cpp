class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        
        vector<int>v;
        for(int i =0  ; i<sentences.size();i++){
            int k ;
            k = count(sentences[i].begin(), sentences[i].end(), ' ');
            v.push_back(k);
        }
        return *max_element(v.begin(), v.end())+1;
        
    }
};