#include <os.h>
#include <SDL\SDL.h>

#include "Winbox.h"
#include "AllWidgets.h"


wTHEME *NoteWriterDarkTheme();

extern wTHEME *Theme;

static unsigned short image_buttonScratchpad[] = {
    0x2a01,0x0020,0x0018,0x0000,0x2945,0x2124,0x2945,0x2945,0x2945,0x2945,
    0x2945,0x2124,0x2124,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2124,
    0x2124,0x2945,0x2945,0x2124,0x2945,0x2945,0x2124,0x2945,0x2945,0x2124,
    0x2945,0x2124,0x2124,0x2945,0x2945,0x2945,0x2965,0x3186,0x2965,0x3186,
    0x2965,0x2965,0x3186,0x3186,0x3186,0x3186,0x3186,0x2965,0x3186,0x2965,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x2965,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x2965,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x2965,0x2965,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x2965,0x2945,
    0x3186,0x2125,0x2945,0x3186,0x2125,0x2124,0x2124,0x2124,0x2124,0x2124,
    0x2124,0x2124,0x2124,0x2945,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x2965,0x3186,0x2965,0x2965,0x3186,0x3186,0x3166,0x2965,
    0x2965,0x5aab,0x39e7,0x4228,0x8c30,0x31a6,0x528a,0xc638,0xce38,0xce38,
    0xce38,0xce38,0xc638,0xce38,0xbdb6,0x4a49,0x2945,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x2965,0x3186,0x3186,0x3186,0x3186,0x2965,
    0x3186,0x20e3,0x630c,0x8431,0x3165,0xce79,0x8410,0x39e7,0xd69a,0xce59,
    0xb5b6,0xbdb7,0xbdf7,0xbdd7,0xbdb6,0xc618,0xe6fc,0xad55,0x18e3,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x2965,0x2104,0x9cd3,0x6b6d,0x4228,0xdeba,0x4a49,0x62ec,
    0xce59,0x2945,0x2145,0x2965,0x2965,0x2965,0x2945,0x3186,0xbdd7,0xad75,
    0x18e3,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x2965,0x3186,0x2145,0x3186,0xa4d3,0x4a49,0x7bcf,0xce59,
    0x39c7,0x9cd3,0x9cb2,0x18e3,0x3185,0x2965,0x2965,0x2965,0x2124,0x39e7,
    0xbdd7,0x5aeb,0x2104,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x2965,0x3186,0x3186,0x2104,0x4a49,0xa4f3,0x3186,
    0xbe17,0xbdd7,0x3186,0xc5f8,0x4a49,0x18e3,0x2944,0x2124,0x2124,0x2924,
    0x18c3,0x528a,0xce59,0x39c7,0x2945,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x2965,0x2965,0x2965,0x3186,0x3186,0x20e4,0x632c,
    0x9cd3,0x2965,0xd67a,0x8c10,0x39c7,0xd69a,0x5acb,0x2945,0x31a6,0x31a6,
    0x39a6,0x3186,0x31a6,0xb576,0xc638,0x2924,0x2985,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x2965,0x3186,0x3186,0x3186,0x2965,
    0x2124,0x840f,0x73ce,0x4208,0xd69a,0x5acb,0x528a,0xffdf,0xe71c,0xd67a,
    0xd69a,0xd69a,0xd69a,0xd69a,0xdeda,0xe71b,0x8410,0x2104,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x2945,0x3186,0x9472,0x528a,0x738e,0xce59,0x39e7,0x8c10,0xd699,
    0xbdf7,0xce79,0xce79,0xc618,0xd69a,0xce59,0xce59,0xdedb,0x52aa,0x2124,
    0x3186,0x3166,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x2965,0x3186,0x2124,0x4208,0xa4f3,0x3186,0xbdd7,0xc618,0x2986,
    0xce38,0x8c50,0x39c6,0x9492,0x6b2c,0x4208,0xad75,0x4a49,0x5acb,0xd679,
    0x4208,0x2145,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x2965,0x2965,0x2965,0x2124,0x5aaa,0xad34,0x2965,0xce59,
    0xa534,0x3186,0xd69a,0xc5f8,0xb575,0xd67a,0xb575,0xc618,0xce79,0xa534,
    0xce59,0xce38,0x2965,0x2965,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x2965,0x2124,0x6b4d,0x83ef,
    0x39e7,0xd659,0x632c,0x5269,0xce79,0x4a49,0x5aab,0xad35,0x39c7,0x8c31,
    0x8c30,0x39c7,0xbdb6,0xad55,0x2124,0x2965,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x2965,0x3186,0x3186,0x3186,0x2965,0x2965,
    0x8c31,0x528a,0x6b4d,0xd659,0x4208,0x8410,0xce79,0x9492,0xc618,0xce39,
    0x8c51,0xce59,0xbdd7,0xa4f4,0xdedb,0x630c,0x2104,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x2965,0x3186,0x3186,0x3186,
    0x2945,0x39e7,0xad35,0x31a6,0xad75,0xce39,0x2945,0xc618,0xad55,0x4228,
    0xa514,0x7bcf,0x4a69,0xbdb6,0x5acb,0x62ec,0xce79,0x4228,0x2945,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x2945,0x39c7,0x83cf,0x31a6,0x8430,0xb596,0x2945,0x9cb3,
    0xce79,0xce58,0xd699,0xce59,0xce59,0xd679,0xce59,0xce59,0x8c30,0x2945,
    0x2965,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x2965,0x3186,0x3186,0x2965,0x2965,0x31a6,0x31a6,0x3186,0x4208,
    0x3186,0x3186,0x630b,0x738e,0x630c,0x6b4d,0x738e,0x630c,0x738e,0x5acb,
    0x2945,0x2965,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x2985,0x2945,0x2965,
    0x2945,0x2124,0x3186,0x2945,0x18e3,0x18c3,0x18c3,0x18e3,0x18c3,0x18e3,
    0x18c3,0x18e3,0x2965,0x31a6,0x3186,0x2965,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x2965,0x3186,0x3186,0x3186,0x2965,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,
    0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x3186,0x2945,0x2945,
    0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,
    0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,
    0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,0x2945,
    0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,
    0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,
    0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,0x10a2,
    0x10a2,0x10a2
};

int main(void)
{
	SDL_Surface *scr = wInitSDL();
	DrawFillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));
	wInitTheme(NULL);
	
	
	nSDL_Font *font = nSDL_LoadFont(NSDL_FONT_VGA, 255, 255, 255);
	nSDL_DrawStringCF(scr, font, 5, 5, "Couco\45 u !");
	SDL_Flip(scr);
	wait_key_pressed();
	
	nSDL_FreeFont(font);
	
	
	/*
	// D�claration des widgets
	Widget *mainWidget = wWindow("Aide");
	Widget *tabs = wTab();
	
	// 1er onglet
	Widget *body1 = wBasicLayout(0);
	Widget *subody1 = wHorizontalLayout(0);
	Widget *im_tbtton = wPixmapNTI(image_buttonScratchpad);
	Widget *navigation = wText("Use the T-Button to navigate between tabs.\n\nIf you maintain this button while using RIGHT or LEFT buttons, you will be able to select your tab.\n\nMaintaining the T-Button plus pushing DEL will delete the selected tab from your work space.\n\nTo navigate faster in your texts, use CTRL+Directional Arrow.", 15);
	
	//2e onglet
	Widget *keys = wText("DOC - Quicksave the current file\nSHIFT + DOC - Quickave all files\n\nSHIFT + Directional Arrow - Select text\nCTRL + VAR - Copy selection\nVAR - Paste selection\n\nUse CTRL + (Character Button) or SHIFT + (Character Button) to get another character.\n\nHere are some useful examples :\nCTRL + ' , '  -->   ;\nCTRL + ' 0 '  -->   :\nCTRL + '.'  -->   !\nCTRL + '(-)'  -->   ?\nqu'est-ce qui bug au fond ??? Est-ce quand j'ai un wText avec progressbar mais non �ditable ???\nCTRL+'2' = '\"'\nCTRL+'/' '\%'\nCTRL+'(' = '['\nSHIFT+'(' = '{'\nSHIFT+1 = '<'\nSHIT+'2' = '_'\nSHIFT+'3' = '>'\netc...\n\nUse CTRL+'?!>' to get some special characters.	", 17);
// 
	// 3e onglet
	Widget *body3 = wGridLayout(1, 3,0);
	Widget *text1 = wText("Rename a file with '.py' or '.py.tns' extension to get Python's syntax highlights.", 3);
	Widget *text2 = wText("You can then click ENTER at any time to execute and test your program.", 3);
	Widget *text3 = wText("If you placed the Micropython executable into a specific location, indicate his path via the 'Options' dialog box.", 3);
	
	
	wText_SetUnEditable(navigation);
	wText_SetUnEditable(keys);
	wText_SetUnEditable(text1);
	wText_SetUnEditable(text2);
	wText_SetUnEditable(text3);
	wTab_AddTab(tabs, "Navigation", body1);
	wTab_AddTab(tabs, "Keys", keys);
	wTab_AddTab(tabs, "Python", body3);
	
	wAddWidget(mainWidget, tabs);
	
	wAddWidget(body1, subody1);
	wAddWidget(subody1, im_tbtton);
	wAddWidget(subody1, wExLabel("<--- This is the awesome T-BUTTON.", ALIGN_LEFT, nSDL_LoadFont(NSDL_FONT_VGA, 204,15,225)));
	wAddWidget(body1, navigation);
	
	wAddWidget(body3, text1);
	wAddWidget(body3, text2);
	wAddWidget(body3, text3);
	
	wSetHeight(subody1, 24);
	wSetWidth(mainWidget, 300);
	wSetHeight(mainWidget, 220);
		
	wExecConstruct(mainWidget);//*/

	wCloseTheme();
	SDL_Quit();
	return 1;
}




