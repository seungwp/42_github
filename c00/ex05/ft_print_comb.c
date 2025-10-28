#include <unistd.h>

void ft_print_comb(void)
{
    char hundreds_place;
    char tens_place;
    char ones_place;

    hundreds_place = '0';
    while (hundreds_place <= '7')
    {
        tens_place = hundreds_place + 1;
        while (tens_place <= '8')
        {
            ones_place = tens_place + 1;
            while (ones_place <= '9')
            {
                write(1, &hundreds_place, 1);
                write(1, &tens_place, 1);
                write(1, &ones_place, 1);
                if (!(hundreds_place == '7' && tens_place == '8' && ones_place == '9'))
                    write(1, ", ", 2);
                ones_place++;
            }
            tens_place++;
        }
        hundreds_place++;
    }
}

// int main()
// {
//     ft_print_comb();

//      return 0;
// }
