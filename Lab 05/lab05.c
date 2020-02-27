
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. liang312@purdue.edu
*  2. liu2476@purdue.edu
*  3. jiang655@purdue.edu
*
*  Lab #:5
*
*  Academic Integrity Statement:
*
*  We have not used source code obtained from any other unauthorized source,
*  either modified or unmodified.  Neither have we provided access to our code
*  to another. The effort we are submitting is our own original work.
*
*  Day, Time, Location of Lab: Thursday, 3:30 pm, SC 231
*
*  Program Description:
*  Calculates the force on a particle by other two particles with user inputted values.
***************************************************************************/
#include <stdio.h>
#include <math.h>

#define K (8.99 * pow (10,9))   //coulomb's constant
#define PI 3.14159265358979323846264338327950 //pi

// Function declearation
double microC (double q);
double cm2meter (double coordinate);
double cForce(double q1, double q2, double radius);
double angle(double Fx,double Fy);
double angleD(double Fx,double Fy);
double resultForce(double Fx, double Fy);
double distance(double xCord, double yCord);
double orthogonalx(double angle);
double orthogonaly(double xCord);
double orthogonalForce(double,double,double,double);

//Main Program
int main ()
{
  double q1; //Input for point charge 1 (microCoulomb)
  double q2; //Input for point charge 2 (microCoulomb)
  double q3; //Input for point charge 3 (microCoulomb)
  double y2; //y-coordinate of the second charge (cm)
  double x2; //x-coordinate of the second charge (cm)
  double y3; //y-coordinate of the third charge (cm)
  double x3; //x-coordinate of the third charge (cm)
  double resultF; //Resultant force (N)
  double angleF; //Angle of force vector with x-axis (degrees)
  double distance12; //Distance from point 1 to point 2;
  double distance13; //Distance from point 1 to point 3;
  double orthogXComp2; //Orthogonal x direction for particle 2
  double orthogXComp3; //Orthogonal x direction for particle 3
  double orthogYComp2; //Orthogonal y direction for particle 2
  double orthogYComp3; //Orthogonal y direction for particle 3
  double angleRad12; //Angle of point 1 and point 2 in radians
  double angleRad13; //Angle of point 1 and point 3 in radians
  double angleDeg12; //Angle of point 1 and point 2 in degrees
  double angleDeg13; //Angle of point 1 and point 3 in degrees
  double orthogXCompF; //total orthogonal force component in x direction
  double orthogYCompF; //total orthogonal force component in y direction
  double force12; //Force between particel 1 and 2
  double force13; //Force between particel 1 and 3

  // INPUT/OUTPUT
  printf("Enter charge [micro-Coulomb] of point #1 -> ");
  scanf("%lf", &q1);
  printf("Enter charge [micro-Coulomb] of point #2 -> ");
  scanf("%lf", &q2);
  printf("Enter charge [micro-Coulomb] of point #3 -> ");
  scanf("%lf", &q3);
  printf("Enter X coordinate [cm] of point #2 -> ");
  scanf("%lf", &x2);
  printf("Enter Y coordinate [cm] of point #2 -> ");
  scanf("%lf", &y2);
  printf("Enter X coordinate [cm] of point #3 -> ");
  scanf("%lf", &x3);
  printf("Enter Y coordinate [cm] of point #3 -> ");
  scanf("%lf", &y3);

  // Unit conversion to SI units for calculations
  q1 = microC(q1);
  q2 = microC(q2);
  q3 = microC(q3);
  y2 = cm2meter(y2);
  x2 = cm2meter(x2);
  x3 = cm2meter(x3);
  y3 = cm2meter(y3);

  // Function call to calculate values
  distance12 = distance(x2,y2);
  distance13 = distance(x3,y3);
  angleRad12 = angle(x2,y2);
  angleRad13 = angle(x3,y3);
  angleDeg12 = angleD(x2,y2);
  angleDeg13 = angleD(x3,y3);

  force12 = cForce(q1 , q2, distance12);
  force13 = cForce(q1 , q3, distance13);

  orthogXComp2 = orthogonalx (angleRad12);
  orthogXComp3 = orthogonalx (angleRad13);
  orthogYComp2 = orthogonaly (angleRad12);
  orthogYComp3 = orthogonaly (angleRad13);

  orthogXCompF = orthogonalForce(orthogXComp2, orthogXComp3, force12, force13);
  orthogYCompF = orthogonalForce(orthogYComp2, orthogYComp3, force12, force13);

  resultF = resultForce(orthogXCompF, orthogYCompF);
  angleF = angleD(orthogXCompF, orthogYCompF);

  //OUTPUT
  printf("\nDistance [cm] and Angle [degrees] from point 1 to 2: %.1lf, %.1lf", distance12 * 100, angleDeg12);
  printf("\nDistance [cm] and Angle [degrees] from point 1 to 3: %.1lf, %.1lf", distance13 * 100, angleDeg13);

  printf("\n\nOrthogonal components point 1 to point 2 [x,y]: %.3lf, %.3lf", orthogXComp2, orthogYComp2);
  printf("\nOrthogonal components point 1 to point 3 [x,y]: %.3lf, %.3lf", orthogXComp3, orthogYComp3);

  printf("\n\nForce [N] of x and y direction: %.3lf, %.3lf", orthogXCompF, orthogYCompF);
  printf("\nNet force [N] and angle [degrees]: %.3lf, %.1lf\n", resultF, angleF);

  return(0);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: microC
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double, q, Input value of q (micro - Coulomb)
*
*  Function Description:
*  Convert the micro - Coulomb to Coulomb
***************************************************************************/
double microC (double q)
{
  return q * pow(10, -6);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: cm2meter
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, coordinate, Distance of point charge to origin
*
*  Function Description:
*  Converts the units of the point charge from cm to m
***************************************************************************/
double cm2meter (double coordinate)
{
  return coordinate / 100;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: cForce
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double q1, The first charge of a particle
*    2. double q2, The second charge of a particle
*    3. radius, the distance between particles
*
*  Function Description:
* Calculates the charge force between two particles.
***************************************************************************/
double cForce(double q1, double q2, double radius)
{
  return(K * (fabs(q1) * fabs(q2)) / pow(radius,2));
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: angle
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Fy, force due to the charge on the y-axis
*    2. double Fx, force due to the charge on the x-axis
*
*  Function Description:
*  Calculates the angle [radians] of of the resultant force on the origin point charge
*  as a result of Fx and Fy
***************************************************************************/
double angle(double Fy, double Fx)
{
  return atan(Fx / Fy);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: angleD
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Fy, force due to the charge on the y-axis
*    2. double Fx, force due to the charge on the x-axis
*
*  Function Description:
*  Calculates the angle [degrees] of of the resultant force on the origin point charge
*  as a result of Fx and Fy
***************************************************************************/
double angleD(double Fy, double Fx)
{
  return atan(Fx / Fy) * 180 / PI;
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: resultForce
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double Fx, Force due to charge on the x-axis
*    2. double Fy, Force due to charge on the y-axis
*
*  Function Description:
*  Claculates the magitude of the resultant force on the point charge
***************************************************************************/
double resultForce(double Fx, double Fy)
{
  return sqrt(pow(Fx,2) + pow(Fy,2));
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: distance
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1. double xCord, x-coordinate of the charge
*    2. double yCord, y-coordinate of the charge
*
*  Function Description:
*  Calculates the magitude of the resultant force on the point charge
***************************************************************************/
double distance(double xCord, double yCord)
{
  return sqrt(pow(xCord,2) + pow(yCord,2));
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthogonalx
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, angle, angle in radian
*
*  Function Description:
*  Finds the orthogonal components in the x direction.
***************************************************************************/
double orthogonalx(double angle)
{
  return cos(angle);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthogonaly
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*    1.double, angle, angle in radian
*
*  Function Description:
*  Finds the orthogonal components in the y direction.
***************************************************************************/
double orthogonaly(double angle)
{
  return sin(angle);
}

/***************************************************************************
*
*  Function Information
*
*  Name of Function: orthogonalForce
*
*  Function Return Type: double
*
*  Parameters (list data type, name, and comment one per line):
*     1.double, component12, the x/y component of the force bewteen particle 1 and 2
*     2.double, component13, the x/y component of the force bewteen particle 1 and 3
*     3.double, force, the x/y component of the resultant force
*
*  Function Description:
*  Finds the orthogonal force component using the given forces and components.
***************************************************************************/
double orthogonalForce(double component12, double component13, double force12, double force13)
{
  double force; //orthogonal force
  force = component12 * force12 + component13 * force13;
  return(force);
}
