#define VIDMODE 0xA0000

#define WSCREEN 320
#define HSCREEN 200

void SetPixel(int x, int y, unsigned char color)
{
    unsigned char* VGA = (unsigned char*) VIDMODE;

    VGA[y * WSCREEN + x] = color;
}

void DrawLine(int x0, int y0, int x1, int y1, unsigned char color)
{
    /*
            A line has infinite squares...
            So a square has infinites lines
            Each line with infinite squares
            And this continues to infinity!
    */

    int dx =  abs(x1 - x0);
    int dy = -abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int error = dx + dy;

    while (true)
    {
        SetPixel(x0, y0, color);

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        int e2 = 2 * error;

        if (e2 >= dy)
        {
            if (x0 == x1)
            {
                break;
            }

            error += dy;
            x0 += sx;
        }

        if (e2 <= dx)
        {
            if (y0 == y1)
            {
                break;
            }

            error += dx;
            y0 += sy;
        }
    }
}
