#include "HelloWorldScene.h"
#include "Functions.h"
#include <math.h>
#include <iostream>


//Update the rooms/go through doors and stuff
//NOTE: Room's ID is based on location; moving up/down/left/right between rooms
//      adds/subtracts 100/1 depending on direction moved
//      starting from "position" (ID) 10000.
void HelloWorld::update_room(){
		room_in.update = false;
			
		room_in.tiles[room_in.player_loc.x][room_in.player_loc.y] = 0;
		room_in.player_loc = room_in.player_moveTo;
		room_in.tiles[room_in.player_loc.x][room_in.player_loc.y] = 2;
		
		
		for (int i = 0; i < room_in.doors.size(); i += 1){
		for (int k = 0; k < room_in.doors[i].my_loc.size(); k += 1){
			
			if (room_in.player_loc.x == room_in.doors[i].my_loc[k].x && room_in.player_loc.y == room_in.doors[i].my_loc[k].y){
				room next_room;
				int tocheck = 0;
				
				if (room_in.doors[i].direction == "up"){
					for(int j = 0; j < rooms.size(); j += 1){
						if (rooms[j].roomId == room_in.roomId - 100 && tocheck == 0){
							// go to room roomId - 100
							next_room = rooms[j];
							tocheck = 1;
						}
					}
					
					if (tocheck == 0){
						next_room = baseRooms[rand() % baseRooms.size()];
						next_room.roomId = room_in.roomId - 100;
					}
				} else if (room_in.doors[i].direction == "down"){
					for(int j = 0; j < rooms.size(); j += 1){
						if (rooms[j].roomId == room_in.roomId + 100 && tocheck == 0){
							// go to room roomId + 100
							next_room = rooms[j];
							tocheck = 1;
						}
					}
					
					if (tocheck == 0){
						next_room = baseRooms[rand() % baseRooms.size()];
						next_room.roomId = room_in.roomId + 100;
					}
				} else if (room_in.doors[i].direction == "right"){
					for(int j = 0; j < rooms.size(); j += 1){
						if (rooms[j].roomId == room_in.roomId + 1 && tocheck == 0){
							// go to room roomId + 1
							next_room = rooms[j];
							tocheck = 1;
						}
					}
					
					if (tocheck == 0){
						next_room = baseRooms[rand() % baseRooms.size()];
						next_room.roomId = room_in.roomId + 1;
					}
				} else if (room_in.doors[i].direction == "left"){
					for(int j = 0; j < rooms.size(); j += 1){
						if (rooms[j].roomId == room_in.roomId - 1 && tocheck == 0){
							// go to room roomId + 1
							next_room = rooms[j];
							tocheck = 1;
						}
					}
					
					if (tocheck == 0){
						next_room = baseRooms[rand() % baseRooms.size()];
						next_room.roomId = room_in.roomId - 1;
					}
				}
				
				if (room_in.beenTo == false){
					room_in.beenTo = true;
					rooms.push_back(room_in);
				} else {
					for(int j = 0; j < rooms.size(); j += 1){
						if(rooms[j].roomId == room_in.roomId){
							rooms[j] = room_in;
						}
					}
				}
					
				next_room.tiles[next_room.player_loc.x][next_room.player_loc.y] = 0;
				next_room.player_loc = room_in.doors[i].goTo_loc[k];
				next_room.player_moveTo = room_in.doors[i].goTo_loc[k];
				
				room_in = next_room;
			}
		}
		}
		
		for (int i = 0; i < room_in.enemies_loc.size(); i += 1){
			room_in.tiles[room_in.enemies_loc[i].my_loc.x][room_in.enemies_loc[i].my_loc.y] = 0;
			room_in.enemies_loc[i].my_loc = move_enemy(room_in.enemies_loc[i].my_loc);
			room_in.tiles[room_in.enemies_loc[i].my_loc.x][room_in.enemies_loc[i].my_loc.y] = 3;
		}
}


//Have the buttons move with the player's sprite
void HelloWorld::move_buttons(){
if (room_in.tiles[room_in.player_loc.x+1][room_in.player_loc.y] == 0){
		movers[0]->setPosition(cocos2d::Vec2(player->getPosition().x + 32, player->getPosition().y));
		Attackers[0]->setPosition(cocos2d::Vec2(5000, 5000));
	} else if (room_in.tiles[room_in.player_loc.x+1][room_in.player_loc.y] == 3){
		movers[0]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[0]->setPosition(cocos2d::Vec2(player->getPosition().x + 32, player->getPosition().y));
	} else {
		movers[0]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[0]->setPosition(cocos2d::Vec2(5000, 5000));
	}
	
	if (room_in.tiles[room_in.player_loc.x-1][room_in.player_loc.y] == 0){
		movers[1]->setPosition(cocos2d::Vec2(player->getPosition().x - 32, player->getPosition().y));
		Attackers[1]->setPosition(cocos2d::Vec2(5000, 5000));
	} else if (room_in.tiles[room_in.player_loc.x-1][room_in.player_loc.y] == 3){
		movers[1]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[1]->setPosition(cocos2d::Vec2(player->getPosition().x - 32, player->getPosition().y));
	} else {
		movers[1]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[1]->setPosition(cocos2d::Vec2(5000, 5000));
	}
	
	if (room_in.tiles[room_in.player_loc.x][room_in.player_loc.y+1] == 0){
		movers[2]->setPosition(cocos2d::Vec2(player->getPosition().x, player->getPosition().y + 32));
		Attackers[2]->setPosition(cocos2d::Vec2(5000, 5000));
	} else if (room_in.tiles[room_in.player_loc.x][room_in.player_loc.y+1] == 3){
		movers[2]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[2]->setPosition(cocos2d::Vec2(player->getPosition().x, player->getPosition().y + 32));
	} else {
		movers[2]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[2]->setPosition(cocos2d::Vec2(5000, 5000));
	}
	
	if (room_in.tiles[room_in.player_loc.x][room_in.player_loc.y-1] == 0){
		movers[3]->setPosition(cocos2d::Vec2(player->getPosition().x, player->getPosition().y - 32));
		Attackers[3]->setPosition(cocos2d::Vec2(5000, 5000));
	} else if (room_in.tiles[room_in.player_loc.x][room_in.player_loc.y-1] == 3){
		movers[3]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[3]->setPosition(cocos2d::Vec2(player->getPosition().x, player->getPosition().y - 32));
	} else {
		movers[3]->setPosition(cocos2d::Vec2(5000, 5000));
		Attackers[3]->setPosition(cocos2d::Vec2(5000, 5000));
	}
}


//Calculate pathfinding for the enemy (in the crappiest possible way)
group HelloWorld::move_enemy(group enemy){
	double dist = sqrt((room_in.player_loc.x-enemy.x)*(room_in.player_loc.x-enemy.x) + (room_in.player_loc.y-enemy.y)*(room_in.player_loc.y-enemy.y));
	double min_dist = dist;
	group e1target(enemy.x, enemy.y);

	dist = sqrt((room_in.player_loc.x-enemy.x+1)*(room_in.player_loc.x-enemy.x+1) + (room_in.player_loc.y-enemy.y)*(room_in.player_loc.y-enemy.y));
	if (dist > min_dist && room_in.tiles[enemy.x+1][enemy.y] == 0){
		min_dist = dist;
		e1target.x = enemy.x+1;
		e1target.y = enemy.y;
	}

	dist = sqrt((room_in.player_loc.x-enemy.x-1)*(room_in.player_loc.x-enemy.x-1) + (room_in.player_loc.y-enemy.y)*(room_in.player_loc.y-enemy.y));
	if (dist > min_dist && room_in.tiles[enemy.x-1][enemy.y] == 0){
		min_dist = dist;
		e1target.x = enemy.x-1;
		e1target.y = enemy.y;
	}

	dist = sqrt((room_in.player_loc.x-enemy.x)*(room_in.player_loc.x-enemy.x) + (room_in.player_loc.y-enemy.y+1)*(room_in.player_loc.y-enemy.y+1));
	if (dist > min_dist && room_in.tiles[enemy.x][enemy.y+1] == 0){
		min_dist = dist;
		e1target.x = enemy.x;
		e1target.y = enemy.y+1;
	}

	dist = sqrt((room_in.player_loc.x-enemy.x)*(room_in.player_loc.x-enemy.x) + (room_in.player_loc.y-enemy.y-1)*(room_in.player_loc.y-enemy.y-1));
	if (dist > min_dist && room_in.tiles[enemy.x][enemy.y-1] == 0){
		min_dist = dist;
		e1target.x = enemy.x;
		e1target.y = enemy.y-1;
	}

	return e1target;
}

