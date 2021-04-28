#define MOD 1000000007
#define ull unsigned long long int

class Fancy {

private:
    vector<int> v;
    vector<pair<ull, ull>> ops;
    ull cm = 1;
    ull cinc = 0;

public:
    
    ull power(unsigned long long x , ull n){
        if(n == 0)  return 1;
        if(n == 1)  return x;
        ull root = power(x,n/2)%MOD;
        return (((root*root)%MOD)*((n%2) ? x : 1))%MOD;
    }
    
    Fancy() {    
    }
    
    void append(int val) {
        v.push_back(val);
        ops.push_back(make_pair(cinc, cm));
    }
    
    void addAll(int inc) {
        cinc = (cinc + inc) % MOD;
    }
    
    void multAll(int m) {
        cm = (cm * m) % MOD;
        cinc = (cinc * m) % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size())    return -1;
        ull result = v[idx];
        pair<ull, ull> op = ops[idx];
        ull inc = op.first;
        ull m = op.second;
        ull mult = (cm*power(m,MOD-2)) % MOD;
        ull sum = (cinc - ((mult * inc) % MOD) + MOD) % MOD;
        return ((result*mult) + sum) % MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
