  Node* dfs(Node* current,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbours;

        // add node as new key to map
        Node* newNode=new Node(current->val);
        mp[current]=newNode;

            // add the map values for this key
            for(auto it:current->neighbors)
            {
                // if this neighbor is not in the map
                if(mp.find(it)!=mp.end())
                {
                    // add it to the map
                    neighbours.push_back(mp[it]);
                }
                else
                    // add its neighbors to the map
                    neighbours.push_back(dfs(it,mp));
            }
            newNode->neighbors=neighbours;
            return newNode;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;

        return dfs(node,mp);
    }

