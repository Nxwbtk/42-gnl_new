/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:06:19 by bsirikam          #+#    #+#             */
/*   Updated: 2022/12/03 21:05:38 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *s;

    fd = open("gnlTester/files/empty", O_RDONLY);
    // fd = open("nl", O_RDONLY);
    // printf("%d\n",fd);
    // printf("%d\n", read(fd, NULL,1));
    s = get_next_line(fd);
    printf("%s", s);
    free(s);
    s = get_next_line(fd);
    printf("%s", s);
    free(s);

    close(fd);
    // s = get_next_line(fd);
    // printf("%s", s);
    // if (s)
    // free(s);
    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
    // s = get_next_line(fd);
    // printf("%s", s);
    // free(s);
}