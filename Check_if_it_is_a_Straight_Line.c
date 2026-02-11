You are given an integer array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

#include <stdbool.h>

bool checkStraightLine(int** coordinates,int coordinatesSize,int* coordinatesColSize){
    int x0=coordinates[0][0],y0=coordinates[0][1];
    int x1=coordinates[1][0],y1=coordinates[1][1];
    int dx=x1-x0,dy=y1-y0;

    for(int i=2;i<coordinatesSize;i++){
        int xi=coordinates[i][0],yi=coordinates[i][1];
        if((yi-y0)*(dx)!=(xi-x0)*(dy)) 
          return false;
    }
    return true;
}


