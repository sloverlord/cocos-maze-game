#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

struct group {
	int x;
	int y;
	
	group(){}
	
	group(int a, int b){
		x = a;
		y = b;
	}
};

struct enemy_c {
	group my_loc;
	int hp;
	
	enemy_c (group loc_in){
		my_loc = loc_in;
		hp = 10;
	}
	
	enemy_c (group loc_in, int setHp){
		my_loc = loc_in;
		hp = setHp;
	}
};

struct door {
	std::vector<group> my_loc;
	std::vector<group> goTo_loc;
	std::vector<group> connects_to;
	std::string direction;   // side of room moved into
	// up = -100
	// down = +100
	// left = -1
	// right = +1
	
	int goesToRoom = -1;
	
	void clean(){
		my_loc.clear();
		goTo_loc.clear();
		connects_to.clear();
		
		direction = "dunno";
	}
	
	door (std::vector<group> my_in, std::vector<group> goTo_in, std::vector<group> connects_in){
		my_loc = my_in;
		goTo_loc = goTo_in;
		connects_to = connects_in;
		
		direction = "dunno";
	}
	
	door (){
		direction = "dunno";
	}
};

struct room {
	int tiles[16][16];
	group player_loc;
	group player_moveTo;
	bool update = false;
	bool beenTo = false;
	int roomId;
	std::string bkg;
	
	std::vector<enemy_c> enemies_loc;
	std::vector<door> doors;
	
	room(){
		for (int i = 0; i < 16; i += 1){
			for (int j = 0; j < 16; j += 1){
				tiles[i][j] = 0;
			}
		}
	}
};

struct Myfloor {
	std::vector<room> rooms;
	
	bool bossroom = false;
	int maxfloors = 0;
};

class HelloWorld : public cocos2d::Layer
{
private:
  	cocos2d::TMXTiledMap *_tileMap;
	cocos2d::TMXLayer *_background;
	cocos2d::TMXLayer *_walls;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void moveRight(cocos2d::Ref* pSender);
	void moveUp(cocos2d::Ref* pSender);
	void moveLeft(cocos2d::Ref* pSender);
	void moveDown(cocos2d::Ref* pSender);
	
	void AttackRight(cocos2d::Ref* pSender);
	void AttackUp(cocos2d::Ref* pSender);
	void AttackLeft(cocos2d::Ref* pSender);
	void AttackDown(cocos2d::Ref* pSender);
	
	void makeRooms();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void update(float dt);
	void update_room(void);
	void move_buttons(void);
	group move_enemy(group enemy);
	
	
	cocos2d::Sprite* sprite;
	cocos2d::Sprite* player;
	std::vector<cocos2d::Sprite*> enemies_s;
	cocos2d::MenuItem* movers[4];
	cocos2d::MenuItem* Attackers[4];
	
	int room_count = 0;
	int current_room = 0;
	int currentFloor = 0;
	std::vector<room> rooms;
	std::vector<room> specialRooms;
	std::vector<Myfloor> floors;
	std::vector<room>baseRooms;
	room room_in;
	
	room room1;
	room room2;
	room room3;
	room room4;
	room bossroom;
	room startroom;
};

#endif // __HELLOWORLD_SCENE_H__
