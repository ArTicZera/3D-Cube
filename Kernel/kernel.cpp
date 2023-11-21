#include "math.h"
#include "graphics.h"
#include "3D.h"

void Delay(int time)
{
    for (int i = -time; i < time; i++)
    {
        //Best worst delayer lol  
    }
}

void main(void)
{
    //Size of the line
    float size = 80;

    //BASED ON MY CFG:
    //0.005 for qemu
    //0.001 for vmware
    float angleX = 0.001;
    float angleY = 0.001;
    float angleZ = 0.001;

    //Define our cube vertex
    VERTEX vtx[] =
    {
        {size,  0.0, 0.0}, //Vector 0
        {size, size, 0.0}, //Vector 1
        {0.0,  size, 0.0}, //Vector 2
        {0.0,   0.0, 0.0}, //Vector 3

        {size,  0.0, size}, //Vector 4
        {size, size, size}, //Vector 5
        {0.0,  size, size}, //Vector 6
        {0.0,   0.0, size}  //Vector 7
    };

    EDGE edges[] =
    {
        //Base
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        
        //Middle
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7},

        //Top
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4}
    };

    while (true)
    {
        //Instantly captures total edges and vtx. 
        //Best for developing future shapes.

        int totvtx = sizeof(vtx) / sizeof(vtx[0]);
        int totedges = sizeof(edges) / sizeof(edges[0]);

        for (int i = 0; i < totvtx; i++)
        {
            RotateX(&vtx[i], angleX);
            RotateY(&vtx[i], angleY);
            RotateZ(&vtx[i], angleZ);
        }

        DrawCube(vtx, edges, size, totedges, 0x0F);

        //Delay for the next cube position
        Delay(10000 * 100);

        //Clear the previous draw
        DrawCube(vtx, edges, size, totedges, 0x00);
    }
}
