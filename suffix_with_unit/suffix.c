#include <math.h>
#include <stdio.h>

/* SI unit suffix
 * Yotta 10^24
 * Zetta 10^21
 * Exa 10^18
 * Peta 10^15
 * Tera 10^12
 * Giga	10^9
 * Mega 10^6
 * Kilo 10^3
 *
 * milli 10^-3
 * micro 10^-6
 * nano 10^-9
 * pico 10^-12
 * femto 10^-15
 * atto 10^-18
 * zepto 10^-21
 * yocto 10^-24
 */
void suffixWithUnit(char *str, double number) {
    int count = 0;
    double temp = number;

    if (temp >= 1) {
        while (temp >= 1000. && count <= 8) {
            count++;
            temp /= 1000.;
        }
        switch (count) {
            case 0:
                sprintf(str, "%lf", number);
                break;
            case 1:
                sprintf(str, "%lf Kilo", temp);
                break;
            case 2:
                sprintf(str, "%lf Mega", temp);
                break;
            case 3:
                sprintf(str, "%lf Giga", temp);
                break;
            case 4:
                sprintf(str, "%lf Tera", temp);
                break;
            case 5:
                sprintf(str, "%lf Peta", temp);
                break;
            case 6:
                sprintf(str, "%lf Exa", temp);
                break;
            case 7:
                sprintf(str, "%lf Zetta", temp);
                break;
            case 8:
                sprintf(str, "%lf Yotta", temp);
                break;

            /* number too large */
            default:
                sprintf(str, "%lf Yotta", temp * 1000.);
                break;
            }
        return;
    }

    /*  */
    while (temp <= 1. && count <= 8) {
        count++;
        temp *= 1000.0;
    }
    switch (count) {
    case 1:
        sprintf(str, "%lf milli", temp);
        break;
    case 2:
        sprintf(str, "%lf micro", temp);
        break;
    case 3:
        sprintf(str, "%lf nano", temp);
        break;
    case 4:
        sprintf(str, "%lf pico", temp);
        break;
    case 5:
        sprintf(str, "%lf femto", temp);
        break;
    case 6:
        sprintf(str, "%lf atto", temp);
        break;
    case 7:
        sprintf(str, "%lf zepto", temp);
        break;
    case 8:
        sprintf(str, "%lf yocto", temp);
        break;

    /* number too small */
    default:
        sprintf(str, "%lf yocto", temp * 1e-3);
        break;
    }
}

int main() {
    char str[30];
    for (int i = -30; i <= 30; i += 3) {
        suffixWithUnit(str, 123.45 * pow(10., (double)i));
        printf("123.45e%d -> %s\n", i, str);
    }

    return 0;
}
