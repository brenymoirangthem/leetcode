class WordDictionary {
public:
    struct Node{
        Node* links[26];
        bool isEnd;
        Node(){
            for(int i =0;i<26;i++){
                links[i]=NULL;
            }
            isEnd = false;
        }
    };
    Node* root;
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch : word ){
            int index = ch - 'a';
            if(node->links[index]==NULL){
                 node->links[index]=new Node();
            }
            node = node->links[index];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        return searchHelper(word,0,root);
    }
    bool searchHelper(string word,int pos,Node* node){
        if(pos==word.size()){
            return node->isEnd;
        }
        char ch = word[pos];
        if(ch == '.'){
            for(int i = 0;i<26;i++){
                if(node->links[i]!=NULL){
                    if(searchHelper(word,pos+1,node->links[i])){
                        return true;
                    }
                }
            }
            return false;
        }
        int index = ch - 'a';
        if(node->links[index]==NULL){
            return false;
        }
        return searchHelper(word,pos+1,node->links[index]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */