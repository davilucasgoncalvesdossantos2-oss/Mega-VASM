#include "genesis.h"

Sprite *sonic;
Sprite *enemy;

s16 sonicX = 160;
s16 enemyX = 80;

s16 sonicHP = 10;
s16 enemyHP = 20;

u8 state = 0; // 0 normal, 1 boss, 2 end

void initGame()
{
    SPR_init();

    sonic = SPR_addSprite(&sprite_sonic, sonicX, 120,
        TILE_ATTR(PAL0, FALSE, FALSE, FALSE));

    enemy = SPR_addSprite(&sprite_enemy, enemyX, 120,
        TILE_ATTR(PAL1, FALSE, FALSE, FALSE));
}

void updateGame()
{
    u16 joy = JOY_readJoypad(JOY_1);

    // =====================
    // MOVIMENTO SONIC
    // =====================
    if (joy & BUTTON_RIGHT) sonicX += 2;
    if (joy & BUTTON_LEFT)  sonicX -= 2;

    SPR_setPosition(sonic, sonicX, 120);

    // =====================
    // COLISÃO
    // =====================
    if (abs(sonicX - enemyX) < 10)
    {
        enemyHP--;
        sonicHP--;

        VDP_drawText("HIT!", 10, 10);
    }

    // =====================
    // BOSS TRANSITION
    // =====================
    if (enemyHP <= 0 && state == 0)
    {
        state = 1;
        enemyX = 120;
        enemyHP = 50;

        VDP_drawText("BOSS BATTLE!", 10, 12);
    }

    // =====================
    // END GAME
    // =====================
    if (sonicHP <= 0)
    {
        state = 2;
        VDP_drawText("GAME OVER", 10, 14);
    }

    if (enemyHP <= 0 && state == 1)
    {
        state = 2;
        VDP_drawText("YOU WIN DEMO", 10, 14);
    }

    SPR_setPosition(enemy, enemyX, 120);
}

int main()
{
    VDP_setScreenWidth320();

    initGame();

    while (1)
    {
        updateGame();
        SPR_update();
        SYS_doVBlankProcess();
    }

    return 0;
}