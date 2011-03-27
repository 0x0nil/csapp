/* homework 3.34 */

int switch_prob(int x)
{
    int result = x;

    switch(x) {
    case 50:
    case 52:
        result = result >> 2;
        break;
    case 53:
        result = result << 2;
        break;
    case 54:
        result = result * 3;
    case 55:
        result = result * result;
    case 51:
    default:
        result = result + 10;
    }

    return result;
}
