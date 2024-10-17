// LeetCode 733: Flood Fill

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color){
            return image;
        }
            // check og color and save
            int ogColor = image[sr][sc];

            // check if index is target color.
            // if it isnt the target color, change it to target
            if(image[sr][sc] != color){
                image[sr][sc] = color;
            }

            // if up of index is within bounds &&
            // if up of index is og color -> floodFill with index to up.
            if(sr-1 >= 0 && image[sr-1][sc] == ogColor){
                floodFill(image, sr-1, sc, color);
            }

            // if down of index is within bounds &&
            // if down of index is og color -> floodFill with index to down.
            if(sr+1 < image.size() && image[sr+1][sc] == ogColor){
                floodFill(image, sr+1, sc, color);
            }

            // if left of index is within bounds &&
            // if left of index is og color -> floodFill with index to left.
            if(sc-1 >= 0 && image[sr][sc-1] == ogColor){
                floodFill(image, sr, sc-1, color);
            }

            // if right of index is within bounds &&
            // if right of index is og color -> floodfill with index to right.
            if(sc+1 < image[sr].size() && image[sr][sc+1] == ogColor){
                floodFill(image, sr, sc+1, color);
            }
            return image;
        }
    
};