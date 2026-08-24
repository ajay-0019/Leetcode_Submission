    /*
    // Definition for a Node.
    class Node {
    public:
        int val;
        vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = vector<Node*>();
        }
        Node(int _val, vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
    };
    */

    class Solution {
    public:
        Node* cloneGraph(Node* node) {
            if(node==nullptr){
                return node;
            }
            Node* newnode=new Node(node->val);
            unordered_map<Node*,Node*> map;
            map[node]=newnode;
            queue<Node*> q;
            q.push(node);
            while(!q.empty()){
                Node* front=q.front();
                q.pop();
                for(auto it:front->neighbors){
                    if(map.find(it)==map.end()){
                        Node* nn=new Node(it->val);
                        map[it]=nn;
                        q.push(it);
                    }
                    map[front]->neighbors.push_back(map[it]);
                }
            }
            return newnode;
        }
    };