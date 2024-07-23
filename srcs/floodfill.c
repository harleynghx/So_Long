/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:11:43 by hang              #+#    #+#             */
/*   Updated: 2024/07/21 01:48:52 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void valid_path_checker(data *list)
{
    
}

int main(void) {
    data list;
    list.map[0] = {1, 1, 1, 1, 1, 1};
    list.map[1] = {1, 0, 0, 1, 0, 1};
    list.map[2] = {1, 1, 1, 1, 1, 1};
    valid_path_checker(&list)
}

void    collectibles_reachable(data *list)
{
    int i;
    
    i = list->n_collectible;
    while(i < list->n_collectible)
    {
        search()
    }
    i++;
}

void    search(data *list)
{
    int x;
    int y;

    x = 0;
    y = 0;
    left_right()
    up_down()
    
    
}