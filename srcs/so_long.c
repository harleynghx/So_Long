/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hang <hang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 19:05:40 by hang              #+#    #+#             */
/*   Updated: 2024/07/16 15:26:16 by hang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int exit_point(data)
{
    //TODO
}

int main(int ac, char **av)
{
    data list;

    if(ac != 2) 
        return (0);

    //ft_memset(&list, 0, sizeof(data));
    map_from_file(&list, &av[1]);
    error_checker(&list);
    
}
