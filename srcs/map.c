/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 12:24:47 by achansar          #+#    #+#             */
/*   Updated: 2023/06/26 15:33:38 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

//function that duplicate every int of the 1D array x times
int		*ft_dup_line(int *map, int size, int mult)
{
    int i;
    int j;
    int c;
    int *new_line;
    // printf("map[i] = %d\n", map[1]);
    new_line = (int *)malloc(sizeof(int) * size * mult + 1);// prevoir un free array si crash au milieu
    if (!new_line)
        return (NULL);
    i = 0;
    j = 0;
    while (i < size)
    {
        c = 0;
        while (c < mult)
        {
            new_line[j] = map[i];
            c++;
            j++;
        }
        i++;
    }
    // new_line[j] = -1;
    return (new_line);
}

int		**ft_upscale(int size, int mult)
{
	int		**new_map;
	int		i;
	int		j;
	int		c;
	int map[24][24]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

	i = 0;
    j = 0;
    (void)mult;
	if (!(new_map = (int **)malloc(sizeof(int *) * (size /** mult + 1*/))))
		return (NULL);
    while (i < size)
    {
        new_map[i] = malloc(sizeof(int) * size);
        j = 0;
        while (j < size)
        {
            new_map[i][j] = map[i][j];
            j++;
        }
        i++;
    }
    // new_map[i] = NULL;
    // printf("Before everything : map[8][1] in init = %d\n", new_map[8][1]);
	return (new_map);
}

//function to print the 2D array in the terminal
void print_map(int **map)
{
    int i;
    int j;

    i = 0;
    while (i < 24)
    {
        j = 0;
        while (j < 24)
        {
            printf("%d ", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
}

