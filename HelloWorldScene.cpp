#include "HelloWorldScene.h"
#include "Functions.h"
#include <math.h>
#include <iostream>

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...
	
	makeRooms();
	
	room start = startroom;
	start.roomId = 10000;
	room_in = start;
	
	// Create the background
    sprite = cocos2d::Sprite::create(room_in.bkg);
    sprite->setPosition(Vec2(origin.x + sprite->getContentSize().width/2,origin.y + sprite->getContentSize().height/2));
    this->addChild(sprite, 0);

	// add "player"
	player = Sprite::create("red.png");

	// position the sprite on the center of the screen
	player->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

	// add the sprite as a child to this layer
	this->addChild(player, 0);
	
	
	
	

	//make a right button
	auto rightAttack = MenuItemImage::create(
                                           "purple.png",
                                           "purple.png",
                                           CC_CALLBACK_1(HelloWorld::AttackRight, this));
    
	rightAttack->setPosition(Vec2(player->getPosition().x + 64, player->getPosition().y));

	// create menu, it's an autorelease object
	auto Attacks = Menu::create(rightAttack, NULL);
	Attacks->setPosition(Vec2::ZERO);	
	Attackers[0] = rightAttack;
	this->addChild(Attacks, 1);
	
	//make a left button
	auto leftAttack = MenuItemImage::create(
                                           "purple.png",
                                           "purple.png",
                                           CC_CALLBACK_1(HelloWorld::AttackLeft, this));
    
	leftAttack->setPosition(Vec2(player->getPosition().x - 32, player->getPosition().y));

	// create menu, it's an autorelease object
	Attacks = Menu::create(leftAttack, NULL);
	Attacks->setPosition(Vec2::ZERO);	
	Attackers[1] = leftAttack;
	this->addChild(Attacks, 1);
	
	//make an up button
	auto upAttack = MenuItemImage::create(
                                           "purple.png",
                                           "purple.png",
                                           CC_CALLBACK_1(HelloWorld::AttackUp, this));
    
	upAttack->setPosition(Vec2(player->getPosition().x, player->getPosition().y + 32));

	// create menu, it's an autorelease object
	Attacks = Menu::create(upAttack, NULL);
	Attacks->setPosition(Vec2::ZERO);	
	Attackers[2] = upAttack;
	this->addChild(Attacks, 1);
	
	//make a down button
	auto downAttack = MenuItemImage::create(
                                           "purple.png",
                                           "purple.png",
                                           CC_CALLBACK_1(HelloWorld::AttackDown, this));
    
	downAttack->setPosition(Vec2(player->getPosition().x, player->getPosition().y - 32));

	// create menu, it's an autorelease object
	Attacks = Menu::create(downAttack, NULL);
	Attacks->setPosition(Vec2::ZERO);	
	Attackers[3] = downAttack;
	this->addChild(Attacks, 1);
	
	
	
	//make a right button
	auto rightMove = MenuItemImage::create(
                                           "square.png",
                                           "square.png",
                                           CC_CALLBACK_1(HelloWorld::moveRight, this));
    
	rightMove->setPosition(Vec2(player->getPosition().x + 64, player->getPosition().y));

	// create menu, it's an autorelease object
	auto moves = Menu::create(rightMove, NULL);
	moves->setPosition(Vec2::ZERO);	
	movers[0] = rightMove;
	this->addChild(moves, 1);
	
	//make a left button
	auto leftMove = MenuItemImage::create(
                                           "square.png",
                                           "square.png",
                                           CC_CALLBACK_1(HelloWorld::moveLeft, this));
    
	leftMove->setPosition(Vec2(player->getPosition().x - 32, player->getPosition().y));

	// create menu, it's an autorelease object
	moves = Menu::create(leftMove, NULL);
	moves->setPosition(Vec2::ZERO);	
	movers[1] = leftMove;
	this->addChild(moves, 1);
	
	//make an up button
	auto upMove = MenuItemImage::create(
                                           "square.png",
                                           "square.png",
                                           CC_CALLBACK_1(HelloWorld::moveUp, this));
    
	upMove->setPosition(Vec2(player->getPosition().x, player->getPosition().y + 32));

	// create menu, it's an autorelease object
	moves = Menu::create(upMove, NULL);
	moves->setPosition(Vec2::ZERO);	
	movers[2] = upMove;
	this->addChild(moves, 1);
	
	//make a down button
	auto downMove = MenuItemImage::create(
                                           "square.png",
                                           "square.png",
                                           CC_CALLBACK_1(HelloWorld::moveDown, this));
    
	downMove->setPosition(Vec2(player->getPosition().x, player->getPosition().y - 32));

	// create menu, it's an autorelease object
	moves = Menu::create(downMove, NULL);
	moves->setPosition(Vec2::ZERO);	
	movers[3] = downMove;
	this->addChild(moves, 1);
	


	this->scheduleUpdate();
	
	
	
	
	// add enemy
	for (int i = 0; i < 10; i += 1){
		auto enemy = Sprite::create("orange.jpeg");

		// position the sprite on the center of the screen
		enemy->setPosition(Vec2(visibleSize.width*2 + origin.x, visibleSize.height*2 + origin.y));

		// add the sprite as a child to this layer
		enemies_s.push_back(enemy);
		this->addChild(enemy, 0);
	}

    return true;
}


void HelloWorld::update(float dt) {
	player->setPosition(Vec2(room_in.player_loc.x * 32 + 16, room_in.player_loc.y * 32 + 16));

	for (int i = 0; i < 10; i += 1){
		if (i < room_in.enemies_loc.size()){
			enemies_s[i]->setPosition(Vec2(room_in.enemies_loc[i].my_loc.x * 32 + 16, room_in.enemies_loc[i].my_loc.y * 32 + 16));
		} else {
			enemies_s[i]->setPosition(Vec2(5000, 5000));
		}
	}
	
	// set directional buttons in correct spot
	move_buttons();
	
	//Update the room, when necessary
	if (room_in.update){	
		update_room();
		sprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(room_in.bkg));
	}
	
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}

void HelloWorld::moveRight(Ref* pSender)
{
	room_in.player_moveTo.x += 1;
	room_in.update = true;
}

void HelloWorld::moveLeft(Ref* pSender)
{
	room_in.player_moveTo.x -= 1;
	room_in.update = true;
}

void HelloWorld::moveDown(Ref* pSender)
{
	room_in.player_moveTo.y -= 1;
	room_in.update = true;
}

void HelloWorld::moveUp(Ref* pSender)
{
	room_in.player_moveTo.y += 1;
	room_in.update = true;
}

void HelloWorld::AttackRight(Ref* pSender)
{
	for (int i = 0; i < room_in.enemies_loc.size(); i += 1){
		if (room_in.enemies_loc[i].my_loc.x == room_in.player_loc.x+1 && room_in.enemies_loc[i].my_loc.y == room_in.player_loc.y){
			room_in.enemies_loc[i].hp -= 1;
			std::cerr << room_in.enemies_loc[i].hp;
		}
	}
}

void HelloWorld::AttackLeft(Ref* pSender)
{
	for (int i = 0; i < room_in.enemies_loc.size(); i += 1){
		if (room_in.enemies_loc[i].my_loc.x == room_in.player_loc.x-1 && room_in.enemies_loc[i].my_loc.y == room_in.player_loc.y){
			room_in.enemies_loc[i].hp -= 1;
			std::cerr << room_in.enemies_loc[i].hp;
		}
	}
}

void HelloWorld::AttackDown(Ref* pSender)
{
	for (int i = 0; i < room_in.enemies_loc.size(); i += 1){
		if (room_in.enemies_loc[i].my_loc.x == room_in.player_loc.x && room_in.enemies_loc[i].my_loc.y == room_in.player_loc.y-1){
			room_in.enemies_loc[i].hp -= 1;
			std::cerr << room_in.enemies_loc[i].hp;
		}
	}
}

void HelloWorld::AttackUp(Ref* pSender)
{
	for (int i = 0; i < room_in.enemies_loc.size(); i += 1){
		if (room_in.enemies_loc[i].my_loc.x == room_in.player_loc.x && room_in.enemies_loc[i].my_loc.y == room_in.player_loc.y+1){
			room_in.enemies_loc[i].hp -= 1;
			std::cerr << room_in.enemies_loc[i].hp;
		}
	}
}
