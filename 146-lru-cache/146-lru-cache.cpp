class LRUCache {
public:
   class node{
        public:
        int key;
       int val;
       node* prev;
       node* next;
      
       node( int key_,int val_){
           key=key_;
           val=val_;
       }
    };
    
    node* head=new node(-1,-1);
    node* tail=new node(-1,-1);
    int cap;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    unordered_map<int,node*>mpp;
    void addnode(node* newnode){
        node* temp=head->next;
        head->next=newnode;
        newnode->prev=head;
        newnode->next=temp;
        temp->prev=newnode;
    }
    
    void deletenode(node *delnode){
        node* delprev=delnode->prev;
        node* delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    
    
    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            node *valnode=mpp[key];
            int ans=valnode->val;
            mpp.erase(key);
            deletenode(valnode);
            addnode(valnode);
            mpp[key]=head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
      if(mpp.find(key)!=mpp.end()){
          node* delnode=mpp[key];
          mpp.erase(key);
          deletenode(delnode);
      }  
        if(mpp.size()==cap){
           mpp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key,value));
        mpp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */