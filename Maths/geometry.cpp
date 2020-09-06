

double distance(PI a,PI b)
{
    return sqrt((a.ff - b.ff)*(a.ff - b.ff) + (a.ss - b.ss)*(a.ss - b.ss));
}


double arcdistance(PI a,PI b, double r)
{
    double tmp = (a.ff*b.ff + a.ss*b.ss)/(r*r);
    double theta = acos(tmp);
    return theta*r;
}

// y = m*x + c1
// y = m*x + c2
double parallel_line_dist(double m, double c1, double c2)
{
    double d = fabs(c2 - c1) / ((m * m) - 1);
    return d;
}
