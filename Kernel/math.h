#define abs(a) (((a) > 0) ? a : -(a))

#define SUMLIM 50

double sin(double x)
{
    double sum = 0.0;

    double a  = 1.0; //Num. 
    double b  = 1.0; //Den.
    double expx = x; //X exp.

    for (int i = 1; i <= SUMLIM; i++)
    {
        sum += (a / b) * expx;
        
        expx *= x * x;

        a *= -1.0;
        b *= 4 * i * i + 2 * i;
    }

    return sum;
}

double cos(double x)
{
    double sum = 0.0;

    double a  = 1.0; //Num. 
    double b  = 1.0; //Den.
    double expx = 1; //X exp.

    for (int i = 1; i <= SUMLIM; i++)
    {
        sum += (a / b) * expx;
        
        expx *= x * x;

        a *= -1.0;
        b *= 4 * i * i - 2 * i;
    }

    return sum;
}