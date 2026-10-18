class Trie {
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
    Trie() {
        root = new Node;
    }
    

    void insert(string word) {
        Node* node = root;
        for(int ch : word){
            int index = ch -'a';
            if(node->links[index]==NULL){
                node->links[index]= new Node();
            }
            node = node->links[index];
        }
         node->isEnd = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for(int ch : word){
            int index = ch -'a';
            if(node->links[index]==NULL){
                return false;
            }
            node = node->links[index];
        }
        return node->isEnd; 
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for(int ch : prefix){
            int index = ch -'a';
            if(node->links[index]==NULL){
                return false;
            }
            node = node->links[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */