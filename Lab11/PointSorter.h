#pragma once

class PointSorter {
public:
    //enter 2 value tuple and store them
    void add_point(double x, double y) {
        if (x < 0 || y < 0) {   //checks for x > 0 and y > 0
            printf("Please enter positive numbers only");
            exit(1);
        }

        pointX.push_back(x);
        pointY.push_back(y);
    }//add_point

    //sort stored points based on their distance to coordinate (x, y)
    void print_sorted_closest_to(double x, double y) {
        double currSqDistance, nextSqDistance;
        int size = (int) pointX.size(), currIndex = 0;
        //currIndex: stores value of index of smallest distance
        //currSqDistance: stores value of smallest distance
        currSqDistance = (x - pointX[0])*(x - pointX[0]) + (y - pointY[0])*(y - pointY[0]);

        for (int i = 0; i < (size - 1); i++) {
            for(int j = i + 1; j < size; j++) {
                nextSqDistance = (x - pointX[j])*(x - pointX[j]) + (y - pointY[j])*(y - pointY[j]);
                if (currSqDistance > nextSqDistance) {
                    currIndex = j;
                    currSqDistance = nextSqDistance;
                }
            }

            //coordinates are swapped with the first value of the
            //subarray(i to size) and then i is incremented to remove the
            //first value for next iteration
            double tmp = pointX[currIndex];
            pointX[currIndex] = pointX[i];
            pointX[i] = tmp;
            tmp = pointY[currIndex];
            pointY[currIndex] = pointY[i];
            pointY[i] = tmp;

            //currIndex and currSqDistance changed for next iteration
            currIndex = i + 1;
            currSqDistance = (x - pointX[currIndex])*(x - pointX[currIndex]) + (y - pointY[currIndex])*(y - pointY[currIndex]);
        }

        for (int k = 0; k < size; k++)
            std::cout << pointX[k] << " " << pointY[k] << std::endl;
    }//print_sorted_closest_to

private:
    std::vector<double> pointX, pointY;
};
