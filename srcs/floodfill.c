/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:11:43 by hang              #+#    #+#             */
/*   Updated: 2024/07/17 18:30:53 by hang             ###   ########.fr       */
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