/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 20:32:21 by hang              #+#    #+#             */
/*   Updated: 2024/08/19 13:35:40 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static  int valid_move(t_data *list, int x, int y)
{
    if (list->map[y][x] == 'E')
    {
        if (list->c_counter < list->n_collectible)
            return (0);
        ft_printf("\nYou Have Won, Congrats!\n");
        exit_point(list);
    }
    if (list->map[y][x] == '0')
    {
        list->map[y][x] = 'P';
        list->playerpos_x = x;
        list->playerpos_y = y;
        list->steps_counter++;
    }
    if (list->map[y][x] == 'C')
    {
        list->map[y][x] = 'P';
        list->playerpos_x = x;
        list->playerpos_y = y;
        list->steps_counter++;
        list->c_counter++;
    }
    ft_printf("%i steps taken\n", list->steps_counter);
    return (1);
}

static  int up_movement(t_data *list)
{
    int y;

    y = list->playerpos_y - 1;
    
    if (list->map[y][list->playerpos_x] == '1')
        return (0);
    if(valid_move(list, list->playerpos_x, y) == 0)
        return (0);
    list->map[y + 1][list->playerpos_x] = '0';
    return (1); 
}

static  int down_movement(t_data *list)
{
    int y;

    y = list->playerpos_y + 1;
    
    if (list->map[y][list->playerpos_x] == '1')
        return (0);
    if(valid_move(list, list->playerpos_x, y) == 0)
        return (0);
    list->map[y - 1][list->playerpos_x] = '0';
    return (1); 
}

static  int left_movement(t_data *list)
{
    int x;

    x = list->playerpos_x - 1;
    
    if(list->map[list->playerpos_y][x] == '1')
        return (0);
    if (valid_move(list, x, list->playerpos_y) == 0)
        return (0);
    list->map[list->playerpos_y][x + 1] = '0';
    return (1);
}

static  int right_movement(t_data *list)
{
    int x;

    x = list->playerpos_x + 1;
    
    if(list->map[list->playerpos_y][x] == '1')
        return (0);
    if (valid_move(list, x, list->playerpos_y) == 0)
        return (0);
    list->map[list->playerpos_y][x - 1] = '0';
    return (1);
}

int    controls(int keycode, t_data *list)
{
    int     istrue;
    
    istrue = 0;

    // ft_printf("%i\n", keycode);
    if (keycode == 53 || keycode == 65307)
        exit_point(list);
    else if (keycode == 13 || keycode == 119)
        istrue = up_movement(list);
    else if (keycode == 1 || keycode == 115)
        istrue = down_movement(list);
    else if (keycode == 0 || keycode == 97)
        istrue = left_movement(list);
    else if (keycode == 2 || keycode == 100)
        istrue = right_movement(list);
    if(istrue)
        load_images(list);
    return(1);
}
