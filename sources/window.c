/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"
#include "./../includes/structs.h"

void manage_gohst(t_var *var)
{
    if (var->pos_gohst.x <= 0
    || var->hit == 1) {
        if (var->pos_gohst.x <= 0)
            var->score += 1;
        if (var->hit == 1)
            sfSound_play(var -> punch_sound);
        var->pos_gohst = ini_pos();
        sfSprite_setPosition(var -> character , var->pos_character);
        var->velocity_gohst.x = get_velocity(var->level);
    }
    sfSprite_setPosition(var->gohst, var->pos_gohst);
    sfSprite_move(var->gohst, var->velocity_gohst);
    var->pos_gohst = sfSprite_getPosition(var->gohst);
    sfRenderWindow_drawSprite(var->window, var->gohst, NULL);
    show_lives(var->window, var->lives, var->num_lives, var->video_mode);
    sfRenderWindow_display(var -> window);

    sfRenderWindow_drawText(var->window, var->textmsg, NULL);
    sfRenderWindow_drawText(var->window, var->text, NULL);
    sfRenderWindow_display(var -> window);
}

void my_runner_manage(t_var *var)
{
    if (var->num_lives >= 1) {
        var->hit = hit_the_character(var);
        var->num_lives -= hit_the_character(var);
        print_background1(var);
        print_background2(var);
        print_background3(var);
        if (var->hit == 0)
            print_character(var);
        manage_gohst(var);
    } else
        print_page_gameover(&var);
}

sfRenderWindow *my_window(t_var *var)
{
    srand(time(NULL));
    var->score = 0;
    while (sfRenderWindow_isOpen(var -> window))  {
        analayse_events(&var, 0);
        sfRenderWindow_setFramerateLimit(var -> window, 60);
        if (var->level == 0 && var->num_lives >= 1)
            print_page_menu(&var);
        else {
            sfText_setString(var->text, my_return_time(var->score));
            my_runner_manage(var);
        }
    }
}

void my_runner(void)
{
    t_var var;

    background_music(&var);
    var.video_mode = (sfVideoMode){1280, 769, 64};
    var.window = sfRenderWindow_create(var.video_mode,
    "My_Runner", sfDefaultStyle, NULL);
    create_clocks(&var);
    create_positions(&var);
    ini_var_struct(&var);
    create_msg(&var);
    sfSprite_scale(var.lives, (sfVector2f){0.1, 0.1});
    my_window(&var);
    sfRenderWindow_destroy(var.window);
    sfMusic_destroy(var.music);
}


int main (int argc, char **argv)
{
    char *buffer = malloc(sizeof(char) * 250);

    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        my_putchar("My_Runner:\n\0");
        my_putchar("  This game consist of a character that runing\n\0");
        my_putchar("  and trying to not crash against the gohsts\n\0");
        my_putchar("Controls:\n\0");
        my_putchar("  SPACE to jump\n\0");
        my_putchar("  Z to bend\n\0");
    } else if (argc == 1 )
        my_runner();
    else
        return (84);
    free(buffer);
    return (0);
}
