#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <3ds.h>

int main()
{
	gfxInitDefault();
	consoleInit(GFX_TOP, NULL);

	printf("\x1b[16;20HGoldLeaf DevKit");
	printf("\x1b[24;12HPress X To Play MK7!, A Mii Maker");
	printf("\x1b[30;16HPress Start to exit.");

	// Main loop
	while (aptMainLoop())
	{
		gfxFlushBuffers();
		gfxSwapBuffers();
		gspWaitForVBlank();


		hidScanInput();

		u32 kDown = hidKeysDown();

		if (kDown & KEY_START) break;

		if (kDown & KEY_A)
		{
			aptSetChainloader(0x0004001000021700, 0);
			break;
		}
		if (kDown & KEY_X)
		{
			aptSetChainloader(0x0004000000030800, 0);
			break;
		}
	}

	gfxExit();
	return 0;
}
