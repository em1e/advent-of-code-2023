/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkettune <vkettune@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:52:39 by vkettune          #+#    #+#             */
/*   Updated: 2023/12/05 18:07:23 by vkettune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int possible_games() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return -1;
    }

    int possible_games = 0;
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        char* game_id = strtok(line, " ");
        if (game_id == NULL) {
            continue;
        }
        char* cubes_ptr = strchr(line, ':');
        if (cubes_ptr == NULL) {
            continue;
        }
        char* cubes = cubes_ptr + 2;

        char* cube_set = strtok(cubes, ";");
        int valid_game = 1;
        while (cube_set != NULL) {
            char* color_ptr = strchr(cube_set, ' ');
            if (color_ptr == NULL) {
                continue;
            }
            char* color = color_ptr + 1;

            int count = atoi(cube_set);
            if ((strcmp(color, "red") == 0 && count > 12) ||
                (strcmp(color, "green") == 0 && count > 13) ||
                (strcmp(color, "blue") == 0 && count > 14)) {
                valid_game = 0;
                break;
            }
            cube_set = strtok(NULL, ";");
        }
        if (valid_game) {
            int game_id_num = atoi(game_id);
            possible_games += game_id_num;
        }
    }

    fclose(file);

    return possible_games;
}

int main() {
    int result = possible_games();
    printf("%d\n", result);

    return 0;
}