/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void serializeHelpers(TreeNode* root,string &results){
        if(root==NULL){
            results += "#,";
            return;
        }
        results += to_string(root->val) + ",";
        serializeHelpers(root->left,results);
        serializeHelpers(root->right,results);

    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string results;
        serializeHelpers(root,results);
        return results;
    }
    TreeNode* deserializeHelpers(vector<string>&values, int &index){
        if(values[index]=="#"){
            index++;
            return NULL;
        }
        int value =std::stoi(values[index]);
        index++;
        TreeNode* root = new TreeNode(value);
        root->left=deserializeHelpers(values,index);
        root->right=deserializeHelpers(values,index);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
    vector<string>values;
    string current;
    for(char c : data){
        if(c==','){
            values.push_back(current);
            current = "";
        }
        else
            current += c ;
    }        
    int index = 0;
    return deserializeHelpers(values,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));