/* CS211 Summer 2020 Project 2

Written May 21st, 2020 by Sean Kim for CS 211, Summer 2020

*/

#include <stdio.h>
#include <stdlib.h>


/* TODO: create Point3d and PointCloud data types using typedef */



/* TODO: uncomment these function prototypes.
     Functions appear below main, in the order listed here. */

/*
int addPointToCloud( PointCloud* cloud, Point3d point );
int intersection( PointCloud cloud, Point3d point );
*/

int main(int argc, char const *argv[])
{

    /* TODO: Global variable DebugMode: if -d argument is given, additional information should be printed out as the program runs. */
    /* Look at lab 4 for help on this */


    /* TODO: Read data for a series of points from standard input */
    /* Read data until a negative luminosity is encountered */


    /* TODO: Determine the upper and lower bounds of the bounding box, 
    as well as the average luminosity of the point cloud. Store these in the PointCloud structure.*/
    /* Report the bounds of the Point Cloud, the average luminosity, the number of points in the Point Cloud */


    /* TODO: Read data for a second set of points and for each point determine whether this point intersects with the PointCloud or not.*/
    /* Read data until a negative luminosity is encountered */


    /* TODO: Make sure you free any dynamically allocated memory before the program ends.  
Use Valgrind to check, because TAs will. */

    return 0;

}

/* TODO: function definitions */

/* int addPointToCloud( PointCloud* cloud, Point3d point )
   returns 0 if the point is successfully added to the cloud or -1 otherwise. */

/* int intersection( PointCloud cloud, Point3d point )
   Returns 0 ( false ) if the cloud has no points, otherwise check if the point's coordinates are
   within or equal to the bounds of the cloud.
   Return 1 ( true ) if there is an intersection and false otherwise */