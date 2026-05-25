#include "genesis.h"
#include "res/resources.h"

// posição simples do player
fix32 playerX = FIX32(160);
fix32 playerY = FIX32(120);

int main()
{
    // inicialização do VDP
    VDP_init();
    VDP_setScreenWidth320();
    VDP_setScreenHeight224();

    // limpa tela
    VDP_clearPlane(BG_A, TRUE);
    VDP_clearPlane(BG_B, TRUE);

    // desenha sprites (modo simples de debug)
    VDP_drawImage(BG_A,
                  &player,
                  TILE_ATTR_FULL(PAL0, FALSE, FALSE, FALSE, TILE_USER_INDEX),
                  10, 10, FALSE);

    VDP_drawImage(BG_A,
                  &enemy,
                  TILE_ATTR_FULL(PAL1, FALSE, FALSE, FALSE, TILE_USER_INDEX + 64),
                  20, 10, FALSE);

    // 🎵 inicia música XGM
    XGM_startPlay(music_actraiser);

    while (1)
    {
        u16 joy = JOY_read(JOY_1);

        // movimento básico
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