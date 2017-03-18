#include<iostream>
#include <stdio.h>
using namespace std;

int main()
{
    /// Read input and declare all variables
    string firstColorHex, secondColorHex;
    cin >> firstColorHex >> secondColorHex;
    int r1, g1, b1, r2, g2, b2, r, g, b;

    /// Parse hexadecimal color code to RGB channels
    sscanf(firstColorHex.c_str(), "#%02x%02x%02x", &r1, &g1, &b1);
    sscanf(secondColorHex.c_str(), "#%02x%02x%02x", &r2, &g2, &b2);

    /// Get averege value of two colors
    r = (r1 + r2) / 2;
    g = (g1 + g2) / 2;
    b = (b1 + b2) / 2;

    /// Print result
    printf("#%02x%02x%02x", r, g, b);

    return 0;
}

