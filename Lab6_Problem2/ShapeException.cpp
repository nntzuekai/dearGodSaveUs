#include <ShapeException.h>

using namespace std;

const string ShapeOffPageException::info="Shape off page exception: A shape has been moved";

const string ShapeXPartOffPageException::info="“Shape partially off page in X exception: A shape has been truncated in X";

const string ShapeYPartOffPageException::info="“Shape partially off page in Y exception: A shape has been truncated in Y";


ShapeOffPageException::ShapeOffPageException(unsigned int x0, unsigned int y0):
    out_of_range(info),
    x0(x0),
    y0(y0)
{
}

ShapeXPartOffPageException::ShapeXPartOffPageException(unsigned int x0, unsigned int y0, unsigned int dimension1_before, unsigned int dimension1_new):
    out_of_range(info),
    x0(x0),
    y0(y0),
    dimension1_0(dimension1_before),
    dimension1_1(dimension1_new)
{
}

ShapeYPartOffPageException::ShapeYPartOffPageException(unsigned int x0, unsigned int y0, unsigned int dimension1_before, unsigned int dimension1_new, unsigned int height0, unsigned int height):
    out_of_range(info),
    x0(x0),
    y0(y0),
    dimension1_0(dimension1_before),
    height0(height0),
    dimension1_1(dimension1_new),
    height(height)
{
}