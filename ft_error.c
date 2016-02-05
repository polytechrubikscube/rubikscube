#include "rubikscube.h"

void	*ft_error(int e)
{
	printf ("Error\t");
	switch (e)
	{
		case 1:
			printf("File Reading Error\n");
			break ;
		case 2:	
			printf("File Reading Error. Not found or corrupt.");
			break ;
		case 3:
			printf("File Reading Error [2]\n");
			printf("Please control the format of your file.\n");
			printf("\'bbb.bbb.bbb.\\n\' for each face ");
			printf("without any\nspace");
			printf(" (78 char, do not miss the last \\n).\n");
			break ;
		case 4:
			printf("File Reading Error [bad color]");
			break ;
		case 5:
			printf("File Reading Error [2]\n");
			printf("Please control the format of your file.\n");
			printf("\'bbb.bbb.bbb.\\n\' for each face ");
			printf("without any space");
			printf(" or new line.\n");
			break ;
		case 10:
			printf("Memory Error [Can't store the last element in memory]\n");
			break ;
		default :
			printf("Error\n");
	}
	return (NULL);
}

