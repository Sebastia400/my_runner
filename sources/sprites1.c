/*
** EPITECH PROJECT, 2021
** victor header
** File description:
** Exercise myhunt page 1
*/

#include "./../includes/library.h"
#include "./../includes/structs.h"

sfSprite *create_buttonlevel1(void)
{
    sfTexture *texturebuttonlevel1 = sfTexture_createFromFile
    ("./images/button1.png", NULL);
    sfSprite *Spritebuttonlevel1 = sfSprite_create();
    sfSprite_setTexture (Spritebuttonlevel1, texturebuttonlevel1, 0);
    return (Spritebuttonlevel1);
}

sfSprite *create_buttonlevel2(void)
{
    sfTexture *texturebuttonlevel2 = sfTexture_createFromFile
    ("./images/button2.png", NULL);
    sfSprite *Spritebuttonlevel2 = sfSprite_create();
    sfSprite_setTexture (Spritebuttonlevel2, texturebuttonlevel2, 0);
    return (Spritebuttonlevel2);
}

sfSprite *create_buttonlevel3(void)
{
    sfTexture *texturebutlevel3 = sfTexture_createFromFile
    ("./images/button3.png", NULL);
    sfSprite *Spritebutlevel3 = sfSprite_create();
    sfSprite_setTexture(Spritebutlevel3, texturebutlevel3, 0);
    return (Spritebutlevel3);
}

sfSprite *create_bend(void)
{
    sfTexture *texture_bend = sfTexture_createFromFile
    ("./images/bend.png", NULL);
    sfSprite *sprite_bend = sfSprite_create();
    sfSprite_setTexture(sprite_bend, texture_bend, 0);
    return (sprite_bend);
}

void background_music(t_var *var)
{
    var->music = sfMusic_createFromFile("./images/music.wav");
    var->punch_buffer = sfSoundBuffer_createFromFile("./images/punch.wav");
    var->punch_sound = sfSound_create();
    sfMusic_setLoop(var->music, sfTrue);
    sfMusic_play(var->music);
    sfSound_setBuffer(var->punch_sound, var->punch_buffer);
}
