#include "Level_Four.h"


/*

*/

Level_Four::Level_Four()
{

}

void Level_Four::loadTextures()
{
	//Load the background texture. 
	if (!TheTextureManager::Instance()->load("assets/5-DarkBlocks.png", "background", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}

	//Load the platform texture.
	if (!TheTextureManager::Instance()->load("assets/GreenFloor.png", "platform", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}
	if (!TheTextureManager::Instance()->load("assets/BlueBox.png", "bluebox", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}
	if (!TheTextureManager::Instance()->load("assets/GreenBox.png", "greenbox", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}

	// Load the hazard textures.
	if (!TheTextureManager::Instance()->load("assets/hazard.png", "hazard", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}
	if (!TheTextureManager::Instance()->load("assets/hazard2.png", "hazard2", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}
	if (!TheTextureManager::Instance()->load("assets/hazard3.png", "hazard3", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}
	if (!TheTextureManager::Instance()->load("assets/hazard4.png", "hazard4", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}

	// Load the finish line texture.
	if (!TheTextureManager::Instance()->load("assets/checker.png", "finish", TheGame::Instance()->getRenderer()))
	{
		std::cout << "Error: " << SDL_GetError();
	}
}

void Level_Four::createObjects(std::vector<SDLGameObject* >* gameObjects, std::vector<SDLGameObject*>* platforms, std::vector<SDLGameObject*>* hazards)
{
	// This level will be composed primarily of three

	SDLGameObject* background = new Platform(new LoaderParams(0, 0, 3840, 2160, "background"));

	/*
	//Player* player = new Player(new LoaderParams(500, 500, 71, 65, "player")); // Player start location
	SDLGameObject* startplat = new Platform(new LoaderParams(100, 2000, 3000, 100, "platform")); // Starting location
	(500, 500, 71, 65, "player")
	(100, 2000, 3000, 100, "platform")
	(600, 300, 300, 40, "finish"))

	A bit of manual testing..+400, -1400 will work.
	Tested more. Reduce by 1400 on X, for -800 net change.
	*/

	SDLGameObject* startplat = new Platform(new LoaderParams(0, 600, 1000, 100, "platform")); // Starting location

	SDLGameObject* mplat1 = new Platform(new LoaderParams(0, -500, 2000, 200, "platform")); // Main platforms
	SDLGameObject* mplat2 = new Platform(new LoaderParams(2000, -500, 2000, 200, "platform")); 
	SDLGameObject* mplat3 = new Platform(new LoaderParams(4000, -500, 2000, 200, "platform"));
	SDLGameObject* mplat4 = new Platform(new LoaderParams(6000, -500, 2000, 200, "platform"));
	SDLGameObject* mplat5 = new Platform(new LoaderParams(8000, -500, 1700, 200, "platform"));

	SDLGameObject* bplat1 = new Platform(new LoaderParams(1000, 220, 200, 100, "platform")); // Bottom platforms
	SDLGameObject* bplat2 = new Platform(new LoaderParams(2400, -300, 40, 800, "platform"));
	SDLGameObject* bplat3 = new Platform(new LoaderParams(2300, 800, 1000, 100, "platform")); 
	SDLGameObject* bplat4 = new Platform(new LoaderParams(3400, -300, 40, 200, "platform"));
	SDLGameObject* bplat5 = new Platform(new LoaderParams(5000, 500, 400, 100, "platform"));
	SDLGameObject* bplat6 = new Platform(new LoaderParams(5400, 400, 10, 200, "platform"));
	SDLGameObject* bplat7 = new Platform(new LoaderParams(9600, 500, 400, 400, "bluebox"));
	SDLGameObject* bplat8 = new Platform(new LoaderParams(10000, -2000, 200, 2000, "platform")); 
	SDLGameObject* bplat9 = new Platform(new LoaderParams(10000, 0, 200, 2000, "platform")); 
	SDLGameObject* bplat10 = new Platform(new LoaderParams(10000, 2000, 200, 2000, "platform")); 
	SDLGameObject* bplat11 = new Platform(new LoaderParams(10000, 4000, 200, 2000, "platform")); 
	SDLGameObject* tplat1 = new Platform(new LoaderParams(8000, -1600, 2000, 100, "platform")); // Top platforms
	SDLGameObject* tplat2 = new Platform(new LoaderParams(6000, -1600, 2000, 100, "platform"));
	SDLGameObject* tplat3 = new Platform(new LoaderParams(2400, -2000, 40, 500, "platform"));
	SDLGameObject* tplat4 = new Platform(new LoaderParams(2400, -1500, 40, 500, "platform"));
	SDLGameObject* tplat5 = new Platform(new LoaderParams(2400, -1000, 40, 500, "platform"));

	SDLGameObject* bhaz1 = new Hazard(new LoaderParams(-150, -500, 100, 100, "hazard")); // Hazards
	SDLGameObject* bhaz2 = new Hazard(new LoaderParams(1000, -100, 120, 120, "hazard3"));
	SDLGameObject* bhaz3 = new Hazard(new LoaderParams(1300, 600, 64, 28, "hazard4")); // Fire
	SDLGameObject* bhaz4 = new Hazard(new LoaderParams(1364, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz5 = new Hazard(new LoaderParams(1428, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz6 = new Hazard(new LoaderParams(1492, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz7 = new Hazard(new LoaderParams(1556, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz8 = new Hazard(new LoaderParams(1620, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz9 = new Hazard(new LoaderParams(1684, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz10 = new Hazard(new LoaderParams(1748, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz11 = new Hazard(new LoaderParams(1812, 600, 64, 28, "hazard4"));
	SDLGameObject* bhaz12 = new Hazard(new LoaderParams(1100, 400, 120, 120, "hazard3")); // Diamonds
	SDLGameObject* bhaz13 = new Hazard(new LoaderParams(2150, 0, 120, 120, "hazard3"));
	SDLGameObject* bhaz14 = new Hazard(new LoaderParams(2150, 200, 120, 120, "hazard3"));
	SDLGameObject* bhaz15 = new Hazard(new LoaderParams(2150, 400, 120, 120, "hazard3"));
	SDLGameObject* bhaz16 = new Hazard(new LoaderParams(5500, 300, 192, 84, "hazard4")); // Fire
	SDLGameObject* bhaz17 = new Hazard(new LoaderParams(5692, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz18 = new Hazard(new LoaderParams(5884, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz19 = new Hazard(new LoaderParams(6076, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz20 = new Hazard(new LoaderParams(6268, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz21 = new Hazard(new LoaderParams(6460, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz22 = new Hazard(new LoaderParams(6652, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz23 = new Hazard(new LoaderParams(6844, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz24 = new Hazard(new LoaderParams(7036, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz25 = new Hazard(new LoaderParams(7228, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz26 = new Hazard(new LoaderParams(7420, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz27 = new Hazard(new LoaderParams(7612, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz28 = new Hazard(new LoaderParams(7804, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz29 = new Hazard(new LoaderParams(7996, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz30 = new Hazard(new LoaderParams(8188, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz31 = new Hazard(new LoaderParams(8380, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz32 = new Hazard(new LoaderParams(8572, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz33 = new Hazard(new LoaderParams(8764, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz34 = new Hazard(new LoaderParams(8956, 300, 192, 84, "hazard4"));
	SDLGameObject* bhaz35 = new Hazard(new LoaderParams(9148, 300, 192, 84, "hazard4"));

	SDLGameObject* thaz1 = new Hazard(new LoaderParams(9600, -600, 74, 85, "hazard2")); // Top Hazards
	SDLGameObject* thaz2 = new Hazard(new LoaderParams(9600, -900, 74, 85, "hazard2"));
	SDLGameObject* thaz3 = new Hazard(new LoaderParams(9600, -1200, 74, 85, "hazard2"));
	SDLGameObject* thaz4 = new Hazard(new LoaderParams(8000, -800, 74, 85, "hazard2")); 
	SDLGameObject* thaz5 = new Hazard(new LoaderParams(7000, -600, 74, 85, "hazard2"));
	SDLGameObject* thaz6 = new Hazard(new LoaderParams(6000, -800, 74, 85, "hazard2"));
	SDLGameObject* thaz7 = new Hazard(new LoaderParams(8000, -1050, 74, 85, "hazard2"));
	SDLGameObject* thaz8 = new Hazard(new LoaderParams(7000, -750, 74, 85, "hazard2"));
	SDLGameObject* thaz9 = new Hazard(new LoaderParams(6000, -850, 74, 85, "hazard2"));
	SDLGameObject* thaz10 = new Hazard(new LoaderParams(5000, -800, 74, 85, "hazard2"));
	SDLGameObject* thaz11 = new Hazard(new LoaderParams(5000, -600, 74, 85, "hazard2"));
	SDLGameObject* thaz12 = new Hazard(new LoaderParams(700, -1000, 74, 85, "hazard2")); // Crystal field
	SDLGameObject* thaz13 = new Hazard(new LoaderParams(1000, -900, 74, 85, "hazard2"));
	SDLGameObject* thaz14 = new Hazard(new LoaderParams(1200, -800, 74, 85, "hazard2"));
	SDLGameObject* thaz15 = new Hazard(new LoaderParams(1100, -600, 74, 85, "hazard2"));
	SDLGameObject* thaz16 = new Hazard(new LoaderParams(1400, -800, 74, 85, "hazard2"));
	SDLGameObject* thaz17 = new Hazard(new LoaderParams(1300, -1050, 74, 85, "hazard2"));
	SDLGameObject* thaz18 = new Hazard(new LoaderParams(1200, -950, 74, 85, "hazard2"));
	SDLGameObject* thaz19 = new Hazard(new LoaderParams(1300, -1050, 74, 85, "hazard2"));
	SDLGameObject* thaz20 = new Hazard(new LoaderParams(1450, -1000, 74, 85, "hazard2"));
	SDLGameObject* thaz21 = new Hazard(new LoaderParams(1550, -800, 74, 85, "hazard2"));
	SDLGameObject* thaz22 = new Hazard(new LoaderParams(1650, -1000, 74, 85, "hazard2"));


	/*
	SDLGameObject* haz2 = new Hazard(new LoaderParams(4143, -700, 74, 85, "hazard2"));
	SDLGameObject* haz3 = new Hazard(new LoaderParams(6050, -1320, 60, 60, "hazard3"));
	SDLGameObject* haz4 = new Hazard(new LoaderParams(1716, 1000, 64, 28, "hazard4"));
	*/
	// This class type may change, if we make an actual winning zone class. 
	SDLGameObject* winPlat = new Platform(new LoaderParams(600, -600, 300, 40, "finish"));

	gameObjects->push_back(background);
	gameObjects->push_back(startplat);
	gameObjects->push_back(winPlat);

	gameObjects->push_back(mplat1); // Main platforms
	gameObjects->push_back(mplat2);
	gameObjects->push_back(mplat3);
	gameObjects->push_back(mplat4);
	gameObjects->push_back(mplat5);

	gameObjects->push_back(bplat1); // Bottom platforms
	gameObjects->push_back(bplat2);
	gameObjects->push_back(bplat3);
	gameObjects->push_back(bplat4);
	gameObjects->push_back(bplat5);
	gameObjects->push_back(bplat6);
	gameObjects->push_back(bplat7);
	gameObjects->push_back(bplat8);
	gameObjects->push_back(bplat9);
	gameObjects->push_back(bplat10);
	gameObjects->push_back(bplat11);

	gameObjects->push_back(tplat1); // Top platforms
	gameObjects->push_back(tplat2);
	gameObjects->push_back(tplat3);
	gameObjects->push_back(tplat4);
	gameObjects->push_back(tplat5);

	gameObjects->push_back(bhaz1); // Hazards
	gameObjects->push_back(bhaz2);
	gameObjects->push_back(bhaz3);
	gameObjects->push_back(bhaz4);
	gameObjects->push_back(bhaz5);
	gameObjects->push_back(bhaz6);
	gameObjects->push_back(bhaz7);
	gameObjects->push_back(bhaz8);
	gameObjects->push_back(bhaz9);
	gameObjects->push_back(bhaz10);
	gameObjects->push_back(bhaz11);
	gameObjects->push_back(bhaz12);
	gameObjects->push_back(bhaz13);	
	gameObjects->push_back(bhaz14);
	gameObjects->push_back(bhaz15);	
	gameObjects->push_back(bhaz16); // Fire
	gameObjects->push_back(bhaz17);
	gameObjects->push_back(bhaz18);
	gameObjects->push_back(bhaz19);
	gameObjects->push_back(bhaz20);
	gameObjects->push_back(bhaz21);
	gameObjects->push_back(bhaz22);
	gameObjects->push_back(bhaz23);
	gameObjects->push_back(bhaz24);
	gameObjects->push_back(bhaz25);
	gameObjects->push_back(bhaz26);
	gameObjects->push_back(bhaz27);
	gameObjects->push_back(bhaz28);
	gameObjects->push_back(bhaz29);
	gameObjects->push_back(bhaz30);
	gameObjects->push_back(bhaz31);
	gameObjects->push_back(bhaz32);
	gameObjects->push_back(bhaz33);
	gameObjects->push_back(bhaz34);
	gameObjects->push_back(bhaz35);
	gameObjects->push_back(thaz1); // Top Hazards
	gameObjects->push_back(thaz2);
	gameObjects->push_back(thaz3);
	gameObjects->push_back(thaz4);
	gameObjects->push_back(thaz5);
	gameObjects->push_back(thaz6);
	gameObjects->push_back(thaz7);
	gameObjects->push_back(thaz8);
	gameObjects->push_back(thaz9);
	gameObjects->push_back(thaz10);
	gameObjects->push_back(thaz11);
	gameObjects->push_back(thaz12);
	gameObjects->push_back(thaz13);
	gameObjects->push_back(thaz14);
	gameObjects->push_back(thaz15);
	gameObjects->push_back(thaz16);
	gameObjects->push_back(thaz17);
	gameObjects->push_back(thaz18);
	gameObjects->push_back(thaz19);
	gameObjects->push_back(thaz20);
	gameObjects->push_back(thaz21);
	gameObjects->push_back(thaz22);

	platforms->push_back(startplat);

	platforms->push_back(mplat1); // Main platforms
	platforms->push_back(mplat2);
	platforms->push_back(mplat3);
	platforms->push_back(mplat4);
	platforms->push_back(mplat5);

	platforms->push_back(bplat1); // Bottom platforms
	platforms->push_back(bplat2);
	platforms->push_back(bplat3);
	platforms->push_back(bplat4);
	platforms->push_back(bplat5);
	platforms->push_back(bplat6);
	platforms->push_back(bplat7);
	platforms->push_back(bplat8);
	platforms->push_back(bplat9);
	platforms->push_back(bplat10);
	platforms->push_back(bplat11);

	platforms->push_back(tplat1); // Top platforms
	platforms->push_back(tplat2);
	platforms->push_back(tplat3);
	platforms->push_back(tplat4);
	platforms->push_back(tplat5);

	platforms->push_back(winPlat);

	//Adding the hazards to the hazard vector
	hazards->push_back(bhaz1);
	hazards->push_back(bhaz2);
	hazards->push_back(bhaz3);
	hazards->push_back(bhaz4);
	hazards->push_back(bhaz5);
	hazards->push_back(bhaz6);
	hazards->push_back(bhaz7);
	hazards->push_back(bhaz8);
	hazards->push_back(bhaz9);
	hazards->push_back(bhaz10);
	hazards->push_back(bhaz11);
	hazards->push_back(bhaz12);
	hazards->push_back(bhaz13);	
	hazards->push_back(bhaz14);
	hazards->push_back(bhaz15);
	hazards->push_back(bhaz16); // Fire
	hazards->push_back(bhaz17);
	hazards->push_back(bhaz18);
	hazards->push_back(bhaz19);
	hazards->push_back(bhaz20);
	hazards->push_back(bhaz21);
	hazards->push_back(bhaz22);
	hazards->push_back(bhaz23);
	hazards->push_back(bhaz24);
	hazards->push_back(bhaz25);
	hazards->push_back(bhaz26);
	hazards->push_back(bhaz27);
	hazards->push_back(bhaz28);
	hazards->push_back(bhaz29);
	hazards->push_back(bhaz30);
	hazards->push_back(bhaz31);
	hazards->push_back(bhaz32);
	hazards->push_back(bhaz33);
	hazards->push_back(bhaz34);
	hazards->push_back(bhaz35);
	hazards->push_back(thaz1); // Top Hazards
	hazards->push_back(thaz2);
	hazards->push_back(thaz3);
	hazards->push_back(thaz4);
	hazards->push_back(thaz5);
	hazards->push_back(thaz6);
	hazards->push_back(thaz7);
	hazards->push_back(thaz8);
	hazards->push_back(thaz9);
	hazards->push_back(thaz10);
	hazards->push_back(thaz11);
	hazards->push_back(thaz12);
	hazards->push_back(thaz13);
	hazards->push_back(thaz14);
	hazards->push_back(thaz15);
	hazards->push_back(thaz16);
	hazards->push_back(thaz17);
	hazards->push_back(thaz18);
	hazards->push_back(thaz19);
	hazards->push_back(thaz20);
	hazards->push_back(thaz21);
	hazards->push_back(thaz22);

}
void Level_Four::setWinLocation(int x, int y, int width, int height)
{
	p_winLocation.x = x;
	p_winLocation.y = y;
	p_winLocation.w = width;
	p_winLocation.h = height;
}

SDL_Rect Level_Four::getWinLocation()
{
	return p_winLocation;
}