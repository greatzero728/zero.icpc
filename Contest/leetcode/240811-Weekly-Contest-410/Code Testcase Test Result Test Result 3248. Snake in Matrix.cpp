class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for(string s : commands) {
            if(s == "UP") i--;
            if(s == "DOWN") i++;
            if(s == "LEFT") j--;
            if(s == "RIGHT") j++;
        }
        return i * n + j;
    }
};
