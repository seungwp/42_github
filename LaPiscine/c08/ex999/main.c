#include <stdlib.h>
#include "ft_stock_str.h"


struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void	ft_show_tab(struct s_stock_str *par);

int	main(void)
{
	char *strs[] = {"Hello", "42Seoul", "Piscine", "C08", "Good luck!"};
	int size = 5;


	t_stock_str *tab = ft_strs_to_tab(size, strs);		// 구조체 배열 동적할당 후 리턴


	ft_show_tab(tab); 		// 반환한거 받아서 출력


	for (int i = 0; i < size; i++)
		free(tab[i].copy);
	free(tab); 				// 동적 메모리 할당 해제 과정

	return (0);
}