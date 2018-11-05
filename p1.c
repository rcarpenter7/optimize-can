/**
 * Program #1
 * CS 320- Optimization of Can
 * 8/31/18
 * @author Robert Carpenter cssc0504
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float PI= 3.14159265358979323846;
    float sidecost;
    float endcost;
    float volume;
    float ratioOfCosts; //essential to calculus formula used later
    float calculusproduct;
    float radius1; // for calc method
    float height1,height2; // for calc method
    float calccost;
    float bfcost;


    printf("Program #1 cssc0504 Robert Carpenter \n");
    printf("Enter the cost of end material per square cm: \n");
    scanf ("%f" ,  &endcost);
    printf("Enter the cost of the side material per square cm: \n");
    scanf("%f", &sidecost);
    printf("Enter the desired volume in milliliters: \n");
    scanf("%f", &volume);


    // CALCULUS METHOD
    //TO GET RADIUS, TAKE CUBE ROOT OF SIDE COST OVER END COST AND MULTIPLY BY VOL/PI
    ratioOfCosts = sidecost / endcost ;
    calculusproduct = (ratioOfCosts * volume) / (2 * PI);
    radius1 = cbrt(calculusproduct);
    height1 = volume / (PI*radius1 *radius1);
    calccost = (endcost*2*PI*radius1*radius1) + (sidecost*2*PI*radius1*height1);


    // BRUTE FORCE
    // USING GRAPHICAL APPROACH WITH h(r) function h(r) = volume / pi * r ^2

    float r = 0.001;
    height2 = volume / (PI*r*r);


    float newcost =0;

    do
    {
        bfcost = (endcost*2*PI*r*r) + (sidecost*2*PI*r*height2);
        r= r + 0.001;
        height2 = volume / (PI*r*r);
        newcost = (endcost*2*PI*r*r) + (sidecost*2*PI*r*height2);

    }
    while (bfcost > newcost);

    printf("Brute Force Answer: \n");
    printf("Can Cost: %.2f \n" ,newcost);
    printf("Diameter: %.2f \n", (r*2));
    printf("Height: %.2f \n", height2);
    printf("-----------------------\n");
    printf("-----------------------\n");
    printf("Calculus Answer: \n");
    printf("Can Cost: %.2f \n" ,calccost);
    printf("Diameter: %.2f \n", (radius1*2));
    printf("Height: %.2f \n", height1);












    return 0;
}
