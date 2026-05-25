#include <genesis.h>

s16 x = 10;
s16 y = 13;

int main()
{
    VDP_init();

    while (1)
    {
        u16 joy = JOY_readJoypad(JOY_1);

        // apagar frame anterior
        VDP_clearTextArea(x, y, 11, 1);

        // controles
        if (joy & BUTTON_LEFT)  x--;
        if (joy & BUTTON_RIGHT) x++;
        if (joy & BUTTON_UP)    y--;
        if (joy & BUTTON_DOWN)  y++;

        // limites da tela (aprox 40x28 tiles)
        if (x < 0) x = 0;
        if (x > 30) x = 30;
        if (y < 0) y = 0;
        if (y > 27) y = 27;

        // desenhar texto
        VDP_drawText("HELLO WORLD", x, y);

        SYS_doVBlankProcess();
    }
}
