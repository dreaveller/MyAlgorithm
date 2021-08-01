class Solution {
    public int uniquePathsWithObstacles(int[][] obstacleGrid) {
        int height = obstacleGrid.length; int width = obstacleGrid[0].length;
        if(obstacleGrid[0][0] != 1) {
            obstacleGrid[0][0] = -1;
        }
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (j > 0 && obstacleGrid[i][j] != 1) {
                    obstacleGrid[i][j] += obstacleGrid[i][j - 1] == 1 ? 0 : obstacleGrid[i][j - 1];
                    
                }
                if (i > 0 && obstacleGrid[i][j] != 1) {
                    obstacleGrid[i][j] += obstacleGrid[i - 1][j] == 1 ? 0 : obstacleGrid[i - 1][j];
                }
            }
        }
        return obstacleGrid[height - 1][width - 1] == 1 ? 0 : -obstacleGrid[height - 1][width - 1];
    }
}