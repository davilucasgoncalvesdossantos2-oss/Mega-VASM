#include <genesis.h>
#include "resources.h"

// Sprites
Sprite *sonic;
Sprite *enemy;

// posição simples
s16 sonicX = 80;
s16 enemyX = 200;
s16 speed = 2;

static void initGame()
{
    // cria sprites usando os nomes do .res
    sonic = SPR_addSprite(&sprite_sonic, sonicX, 120,
                          TILE_ATTR(PAL0, FALSE, FALSE, FALSE));

    enemy = SPR_addSprite(&sprite_enemy, enemyX, 120,
                          TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
}

static void updateGame()
{
    u16 joy = JOY_read(JOY_1);

    // movimento do player
    if (joy & BUTTON_LEFT)  sonicX -= speed;
    if (joy & BUTTON_RIGHT) sonicX += speed;

    // atualiza sprite
    SPR_setPosition(sonic, sonicX, 120);

    // inimigo anda sozinho
    enemyX -= 1;
    if (enemyX < -32) enemyX = 320;

    SPR_setPosition(enemy, enemyX, 120);

    // colisão simples
    if (abs(sonicX - enemyX) < 16)
    {
        VDP_drawText("HIT!", 10, 10);
    }

    SPR_update();
}

int main()
{
    VDP_init();
    VDP_clearPlane(BG_A, TRUE);

    JOY_init();
    SPR_init();

    initGame();

    while (1)
    {
        updateGame();
        SYS_doVBlankProcess();
    }

    return 0;
}        // movimento básico
        if (joy & BUTTON_LEFT)  playerX -= FIX32(1);
        if (joy & BUTTON_RIGHT) playerX += FIX32(1);
        if (joy & BUTTON_UP)    playerY -= FIX32(1);
        if (joy & BUTTON_DOWN)  playerY += FIX32(1);

        // limites simples de tela
        if (playerX < FIX32(0))   playerX = FIX32(0);
        if (playerX > FIX32(320)) playerX = FIX32(320);
        if (playerY < FIX32(0))   playerY = FIX32(0);
        if (playerY > FIX32(224)) playerY = FIX32(224);

        // sincroniza frame
        SYS_doVBlankProcess();
    }

    return 0;
}
