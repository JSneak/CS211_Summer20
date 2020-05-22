/* CS211 Summer 2020 Project 2

Written May 21st, 2020 by Sean Kim for CS 211, Summer 2020

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int debugMode;
int readFile;
/* typical C boolean set-up */
#define TRUE 1
#define FALSE 0


/* TODO: create Point3d and PointCloud data types using typedef */
typedef struct POINT_3D
{
  int ID;
  double x, y, z;
  double luminosity; /* 0.0 to 1.0 */
} Point3d;

typedef struct PointCloud
{
  Point3d * points; /* dynamic array holding points in PointCloud */
  int allocated; /* Keeps track of allocated space */
  int nPoints; /* Keeps track of how many points currently exist in the points array */
  double luminosity; /* Avg luminosity of points in points */
  double xMin, xMax, yMin, yMax, zMin, zMax; /* Keeps track of bounds of box */
} PointCloud;


/* TODO: uncomment these function prototypes.
     Functions appear below main, in the order listed here. */


int addPointToCloud( PointCloud* cloud, Point3d point );
int intersection( PointCloud cloud, Point3d point );
void initPointCloud(PointCloud *cloud);
void initPoint3d(Point3d *pt, double x, double y, double z, double lumin, int pointId);

int main(int argc, char const *argv[])
{

    /* TODO: Global variable DebugMode: if -d argument is given, additional information should be printed out as the program runs. */
    /* Look at lab 4 for help on this */
    // Debug Setup
    debugMode = FALSE; 
    int i;
    for ( i = 0 ; i < argc ; i++ ) 
    if ( strcmp (argv[i], "-d") == 0 ) 
        debugMode = TRUE;

    if ( debugMode == TRUE ) 
        printf (" Debugging is on! \n");

    /* Check to see if you read in a file */
    readFile = FALSE;
    for (i = 0 ; i < argc ; i++ ) 
    if ( strcmp (argv[i], "-r") == 0 ) 
        readFile = TRUE;

    if ( readFile == TRUE ) 
        printf (" Reading file in! \n");

    /* TODO: Read data for a series of points from standard input */
    /* Read data until a negative luminosity is encountered */
    
    /* Init the PointCloud */
    PointCloud* cloud;
    initPointCloud(cloud);

    if(readFile) /* Reading in file */ {

    } else /* Reading in standard input */ {
        /* PSUEDOCODE */
        /*
            while val != -999 {
                Check if array needs to be expanded
                Ask for X coord, Ask for Y Coord, Ask for Z Coord
            }
        */
        Point3d* point;
        double tmpx, tmpy, tmpz, tmpLumin;
        double val;
        printf ("Enter in a list of Points to be stored in a dynamic array.\n");
        printf ("Enter the X Coordinate.\n");
        scanf ("%lf", &val);
        if(val != -999)
            tmpx = val;
        printf ("Enter the Y Coordinate.\n");
        scanf ("%lf", &val);
        if(val != -999)
            tmpy = val;
        printf ("Enter the Z Coordinate.\n");
        scanf ("%lf", &val);
        if(val != -999)
            tmpz = val;
        printf ("Enter the luminosity.\n");
        scanf ("%lf", &val);
        if(val != -999)
            tmpLumin = val;
        printf("Get's here");
        initPoint3d(point, tmpx, tmpy, tmpz, tmpLumin, cloud->nPoints);
        cloud->points[cloud->nPoints] = *point;
        cloud->nPoints++;
        
        scanf ("%lf", &val);
        while (val != -999) {
            /* store the value into an array, growing array if needed. */
            if(cloud->allocated == cloud->nPoints) /* Need to allocate more memory */ {
                /* Creates a temporary pointer to point to allocated heap space of numArray */
                Point3d *temp = cloud->points;
                /* Double the size of the array */
                cloud->allocated  *= 2;
                /* Malloc more memory */
                cloud->points = (Point3d*)malloc(sizeof(Point3d) * cloud->allocated);
                for(int i = 0; i < cloud->nPoints; i++) {
                    cloud->points[i] = temp[i];
                }
                /* Free allocated memory */
                free(temp);
            }
            /* Has enough allocated memory */
            /* Set point to position nPoints for numArray */
            printf ("Enter the X Coordinate.\n");
            if(val != -999)
                tmpx = val;
            printf ("Enter the Y Coordinate.\n");
            scanf ("%lf", &val);
            if(val != -999)
                tmpy = val;
            printf ("Enter the Z Coordinate.\n");
            scanf ("%lf", &val);
            if(val != -999)
                tmpz = val;
            printf ("Enter the luminosity.\n");
            scanf ("%lf", &val);
            if(val != -999)
                tmpLumin = val;
            initPoint3d(point, tmpx, tmpy, tmpz, tmpLumin, cloud->nPoints);
            cloud->points[cloud->nPoints] = *point;
            /* Increase value of nPoints by one */
            cloud->nPoints++;
            
            /* get next value */
            scanf("%lf", &val);
        }
    }

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
int addPointToCloud( PointCloud* cloud, Point3d point ) {
    // returns 0 if the point is successfully added to the cloud or -1 otherwise.
}

int intersection( PointCloud cloud, Point3d point ) {
//    Returns 0 ( false ) if the cloud has no points, otherwise check if the point's coordinates are
//    within or equal to the bounds of the cloud.
//    Return 1 ( true ) if there is an intersection and false otherwise
}

void initPointCloud(PointCloud *cloud) {
    cloud->allocated = 5;
    cloud->nPoints = 0;
    cloud->luminosity = 0.0;
    cloud->xMin = cloud->xMax = cloud->yMin = cloud->yMax = cloud->zMin = cloud->zMax = 0;
    cloud->points = (Point3d*)malloc(sizeof(Point3d) * cloud->allocated);
}

void initPoint3d(Point3d *pt, double x, double y, double z, double lumin, int pointId) {
    pt->ID = pointId;
    pt->x = x;
    pt->y = y;
    pt->z = z;
    pt->luminosity = lumin;
}