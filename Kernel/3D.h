typedef struct
{
    float x;
    float y;
    float z;
} VERTEX;

typedef struct 
{
    int x; //vtx.x0 vtx.y0
    int y; //vtx.x1 vtx.y1
} EDGE;

void RotateX(VERTEX* vtx, float angle)
{
    //R * vec(x)
    vtx->y = cos(angle) * vtx->y - sin(angle) * vtx->z;
    vtx->z = sin(angle) * vtx->y + cos(angle) * vtx->z;
}

void RotateY(VERTEX* vtx, float angle)
{
    //R * vec(y)
    vtx->x =  cos(angle) * vtx->x + sin(angle) * vtx->z;
    vtx->z = -sin(angle) * vtx->x + cos(angle) * vtx->z;
}

void RotateZ(VERTEX* vtx, float angle)
{
    //R * vec(z)
    vtx->x = cos(angle) * vtx->x - sin(angle) * vtx->y;
    vtx->y = sin(angle) * vtx->x + cos(angle) * vtx->y;
}

void DrawCube(VERTEX* vtx, EDGE* edges, int size, int totedges, unsigned char color)
{
    int cx = (WSCREEN / 2) - (size / 2);
    int cy = (HSCREEN / 2) - (size / 2);

    for (int i = 0; i < totedges; i++)
    {
        DrawLine(vtx[edges[i].x].x + cx, vtx[edges[i].x].y + cy, vtx[edges[i].y].x + cx, vtx[edges[i].y].y + cy, color);
    }
}