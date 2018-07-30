class Solution {
    
private:
    double radius;
    double x_center;
    double y_center;
    
public:
    Solution(double r, double x, double y) {
        radius = r;
        x_center = x;
        y_center = y;
    }
    
    vector<double> randPoint() {
        vector<double> v;
        double d = sqrt((double) rand() / RAND_MAX) * radius;
        double theta = ((double) rand() / RAND_MAX) * 2.0 * M_PI;
        v.push_back(x_center + d * cos(theta));
        v.push_back(y_center + d * sin(theta));  
        return v;
    }
};
