/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achansar <achansar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:10:30 by achansar          #+#    #+#             */
/*   Updated: 2023/06/27 15:25:29 by achansar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int load_textures(t_data *data, t_img *img, t_text *text)
{
    int fd;

    fd = open(text->texFiles, O_RDONLY);
    if (fd <= 0)
        return (1);
    close(fd);

    text->textures = mlx_png_file_to_image(data->mlx, text->texFiles, &text->texHeight, &text->texWidth);
    text->text_add = mlx_get_data_addr(text->textures, &img->bpp, &img->szline, &img->endian);
    return (0);
}
