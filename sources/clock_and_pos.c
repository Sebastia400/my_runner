/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"
#include "./../includes/structs.h"

void create_clocks(t_var *var)
{
    var -> clock = sfClock_create();
    var -> clock2 = sfClock_create();
}

void create_msg (t_var *var)
{
    var->font = sfFont_createFromFile("./fonts/arial.ttf");
    var->text = sfText_create();
    var->textmsg = sfText_create();
    sfText_setFont(var->text, var->font);
    sfText_setCharacterSize(var->text, 50);
    sfText_setColor(var->text, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(var->text, var->pos_text);
    sfText_setString(var->textmsg, "Score:");
    sfText_setFont(var->textmsg, var->font);
    sfText_setCharacterSize(var->textmsg, 50);
    sfText_setColor(var->textmsg, sfColor_fromRGB(255, 255, 255));
    sfText_setPosition(var->textmsg, var->pos_textmsg);
}

void create_positions(t_var *var)
{
    var -> pos_errase = (sfVector2f) {0, 0};
    var -> select_character = (sfIntRect) {0, 0, 70, 115};
    var -> pos_character = (sfVector2f) {300, 566};
    var -> pos_textmsg = (sfVector2f) {900, 20};
    var -> pos_text = (sfVector2f) {1100, 20};
    var -> velocity_character_up = (sfVector2f) {0, -8};
    var -> velocity_character_down = (sfVector2f) {0, 8};
    var -> pos_background = (sfVector2f) {0, 0};
    var -> pos_background_2 = (sfVector2f) {1280, 0};
    var -> velocity_background = (sfVector2f) {-0.5, 0};
    var -> pos_background2 = (sfVector2f) {0, 190};
    var -> pos_background2_2 = (sfVector2f) {1280, 190};
    var -> velocity_background2 = (sfVector2f) {-1, 0};
    var -> pos_background3 = (sfVector2f) {0, 450};
    var -> pos_background3_2 = (sfVector2f) {1290, 450};
    var -> velocity_background3 = (sfVector2f) {-2, 0};
    var -> pos_gohst = (sfVector2f) {1300, 500};
    var -> velocity_gohst = (sfVector2f) {-6, 0};
    var -> velocity = (sfVector2f) {5, 0};
    var -> posbuttons = (sfVector2f) {(var -> video_mode.width / 2) - 190, 50};
}
