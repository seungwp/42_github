#include "libft.h"
// cc main_test.c -L. -lft -o check_all
// ./check_all

/* --- Helper for strmapi/striteri --- */
char	my_map_func(unsigned int i, char c)
{
	(void)i;
	return (c + 1); // 문자를 1씩 증가 (a -> b)
}

void	my_iter_func(unsigned int i, char *c)
{
	(void)i;
	*c = *c + 1; // 문자를 1씩 증가
}

/* --- Helper for bonus (lstmap) --- */
void	*my_lst_map_content(void *content)
{
	return ((void *)ft_strdup("Mapped Content"));
}

void	my_del(void *content)
{
	free(content);
}

void	print_list(t_list *lst)
{
	int i = 0;
	while (lst)
	{
		printf("Node %d: %s -> ", i++, (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	printf("========== PART 1 TEST ==========\n");

	// 1. Ctype & Conversion
	printf("[CTYPE & CONV]\n");
	printf("isalpha('A'): %d\n", ft_isalpha('A'));
	printf("isdigit('9'): %d\n", ft_isdigit('9'));
	printf("isalnum('Z'): %d\n", ft_isalnum('Z'));
	printf("isascii(127): %d\n", ft_isascii(127));
	printf("isprint(' '): %d\n", ft_isprint(' '));
	printf("toupper('a'): %c\n", ft_toupper('a'));
	printf("tolower('Z'): %c\n", ft_tolower('Z'));
	printf("atoi(\"   -12345\"): %d\n\n", ft_atoi("   -12345"));

	// 2. Memory
	printf("[MEMORY]\n");
	char mem1[50] = "Hello World";
	ft_memset(mem1, 'A', 5);
	printf("memset(5 'A'): %s\n", mem1);
	
	ft_bzero(mem1, 3);
	printf("bzero(3): (hidden nulls) %s (starting at index 3)\n", mem1 + 3);

	char src[] = "CopyMe";
	char dst[20];
	ft_memcpy(dst, src, 7);
	printf("memcpy: %s\n", dst);

	char mv_str[] = "1234567890";
	ft_memmove(mv_str + 4, mv_str, 5); // Overlap handling
	printf("memmove(overlap): %s\n", mv_str);

	printf("memchr('CopyMe', 'M'): %s\n", (char *)ft_memchr(src, 'M', 6));
	printf("memcmp(\"ABC\", \"ABD\"): %d\n", ft_memcmp("ABC", "ABD", 3));

	int *nums = (int *)ft_calloc(5, sizeof(int));
	printf("calloc(int array): %d %d (should be 0)\n", nums[0], nums[4]);
	free(nums);
	printf("\n");

	// 3. String
	printf("[STRING]\n");
	char *base = "Hello 42 Seoul";
	printf("strlen: %zu\n", ft_strlen(base));
	
	char lcpy[20];
	ft_strlcpy(lcpy, base, 6);
	printf("strlcpy(size 6): %s\n", lcpy);

	char lcat[20] = "Hello";
	ft_strlcat(lcat, " World", 20);
	printf("strlcat: %s\n", lcat);

	printf("strchr('l'): %s\n", ft_strchr(base, 'l'));
	printf("strrchr('l'): %s\n", ft_strrchr(base, 'l'));
	printf("strncmp(\"ABC\", \"ABD\", 2): %d\n", ft_strncmp("ABC", "ABD", 2));
	printf("strnstr: %s\n", ft_strnstr(base, "42", 15));
	printf("strdup: %s\n\n", ft_strdup("Duplicated String"));


	printf("========== PART 2 TEST ==========\n");

	char *sub = ft_substr("Hello 42 Student", 6, 2);
	printf("substr: %s\n", sub); free(sub);

	char *joined = ft_strjoin("Front", "Back");
	printf("strjoin: %s\n", joined); free(joined);

	char *trimmed = ft_strtrim("   xxHello Worldxx   ", " x");
	printf("strtrim: %s\n", trimmed); free(trimmed);

	printf("split(\"A-B-C-D\", '-'):\n");
	char **split_res = ft_split("A-B-C-D", '-');
	int k = 0;
	while (split_res[k])
	{
		printf("  [%d]: %s\n", k, split_res[k]);
		free(split_res[k]);
		k++;
	}
	free(split_res);

	char *itoa_res = ft_itoa(-2147483648LL);
	printf("itoa(INT_MIN): %s\n", itoa_res); free(itoa_res);

	char *mapi_str = ft_strmapi("abcde", my_map_func);
	printf("strmapi(+1): %s\n", mapi_str); free(mapi_str);

	char iter_str[] = "abcde";
	ft_striteri(iter_str, my_iter_func);
	printf("striteri(+1): %s\n", iter_str);

	printf("[FD OUTPUT] -> Check terminal below:\n");
	ft_putchar_fd('A', 1);
	ft_putstr_fd("BC ", 1);
	ft_putendl_fd("Line", 1);
	ft_putnbr_fd(-42, 1);
	printf("\n\n");


	printf("========== PART 3 TEST (Linked List) ==========\n");
	
	t_list *head = ft_lstnew(ft_strdup("Node 1"));
	t_list *node2 = ft_lstnew(ft_strdup("Node 2"));
	t_list *node3 = ft_lstnew(ft_strdup("Node 3"));

	ft_lstadd_front(&head, node2); // Node 2 -> Node 1
	ft_lstadd_back(&head, node3);  // Node 2 -> Node 1 -> Node 3

	printf("List size: %d\n", ft_lstsize(head));
	printf("Last content: %s\n", (char *)ft_lstlast(head)->content);
	printf("Current List: ");
	print_list(head);

	t_list *mapped_list = ft_lstmap(head, my_lst_map_content, my_del);
	printf("Mapped List: ");
	print_list(mapped_list);

	ft_lstclear(&head, my_del);
	ft_lstclear(&mapped_list, my_del);
	printf("List cleared successfully.\n");

	return (0);
}