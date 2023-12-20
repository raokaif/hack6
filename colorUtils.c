#include <stdio.h>
int rgbToCMYK(int r, int g, int b, double *c, double *m, double *y, double *k)
{
    int r2, g2, b2;
    int c1, m1, y1, k1;
    int max;
    if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
    {
        r2 = r / 255;
        g2 = g / 255;
        b2 = b / 255;

        max = r2 > g2 ? r2 : g2;
        max = max > b2 ? max : b2;
        k1 = 1 - max;

        c1 = ((1 - r2 - k1) / (1 - k1));
        m1 = ((1 - b2 - k1) / (1 - k1));
        y1 = ((1 - g2 - k1) / (1 - k1));

        *c = c1;
        *m = m1;
        *y = y1;
        *k = k1;
        
        return 0;
    }
    else
    {
        return 1;
    }
}

int cmykToRGB(double c, double m, double y, double k, int *r, int *g, int *b)
{
    int r1, g1, b1;
    if (c >= 0 && c <= 1 && m >= 0 && m <= 1 && y >= 0 && y <= 1 && k >= 0 && k <= 1)
    {
        r1 = (255 * (1 - c) * (1 - k));
        g1 = (255 * (1 - m) * (1 - k));
        b1 = (255 * (1 - k) * (1 - k));

        return 0;
    }
    else
    {
        return 1;
    }
}
