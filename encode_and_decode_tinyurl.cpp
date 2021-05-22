class Solution {
    
private:
    string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    unordered_map<int, string> db;
    int id = 1;
    
public:
    string encode(string longUrl) {
          int x = id;
          string shortUrl;
          while(x) {
              shortUrl.push_back(x);
              x /= 62;
          }
          db[id++] = longUrl;
          sort(shortUrl.begin(), shortUrl.end());
          return shortUrl;
    }

    string decode(string shortUrl) {
        int x = 0;
        for(int i = 0; i < shortUrl.size(); ++i) {
            x *= 62;
            x += shortUrl[i];
        }
        return db[x];
    }
};
