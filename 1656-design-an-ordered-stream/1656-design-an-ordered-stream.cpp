class OrderedStream {
public:
    vector<string> s;
    int counter = 1;
    OrderedStream(int n){
      s = vector<string> (n+1,"");
    } 
    vector<string> insert(int id, string value) {
        s[id] = value;
        vector<string> res;
        while (counter < s.size() && !s[counter].empty())
            res.push_back(s[counter++]);
        return res;
    }
};



/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */