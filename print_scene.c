#include <stdio.h>

void print_scene(void)
{
    // Ambient and Camera
    printf("A 0.2 255,255,255\n");
    printf("C 0,2,10 0,0,0 90\n\n");

    // Lights
    printf("L -5,4,1 1 255,255,255\n");
    printf("L 5,4,1 1 255,255,255\n");
    printf("L 0,5,7 1 255,255,255\n\n");

    // Cone and Cylinder
    printf("cn  -5,1,3  0,0,1   1.0   5.42    241,250,238   0.7\n");
    printf("cy  -5,1,2    0,0,0    2.0   4.42  173,40,49  0.7\n\n");

    // Planes and Spheres
    printf("pl 0,0,-15 0,1,0 255,255,255 0,0,0 .6\n");
    printf("pl 0,0,0 0,0,0 255,255,255 0,0,0 2\n");
    printf("sp -5,0,-10  10 69,31,85  0.9\n");
    printf("sp -1,1,6 0.8  248,198,48 0.8\n");
    printf("sp 10,0,-6 4 99,159,171  0.5\n");
}

int main(void)
{
    print_scene();
    return (0);
}
