#include "HelloWorldScene.h"

//	0 = empty
//	1 = wall
//	2 = player
//	3 = enemy 

void HelloWorld::makeRooms(){
	//initialize door dummy
	door d1;

	// border walls
	room2.tiles[0][0] = 1;
	room2.tiles[0][1] = 1;
	room2.tiles[0][2] = 1;
	room2.tiles[0][3] = 1;
	room2.tiles[0][4] = 1;
	room2.tiles[0][5] = 1;
	room2.tiles[0][6] = 1;
	room2.tiles[0][9] = 1;
	room2.tiles[0][10] = 1;
	room2.tiles[0][11] = 1;
	room2.tiles[0][12] = 1;
	room2.tiles[0][13] = 1;
	room2.tiles[0][14] = 1;
	room2.tiles[0][15] = 1;
	room2.tiles[15][0] = 1;
	room2.tiles[15][1] = 1;
	room2.tiles[15][2] = 1;
	room2.tiles[15][3] = 1;
	room2.tiles[15][4] = 1;
	room2.tiles[15][5] = 1;
	room2.tiles[15][6] = 1;
	room2.tiles[15][9] = 1;
	room2.tiles[15][10] = 1;
	room2.tiles[15][11] = 1;
	room2.tiles[15][12] = 1;
	room2.tiles[15][13] = 1;
	room2.tiles[15][14] = 1;
	room2.tiles[15][15] = 1;
	
	room2.tiles[1][0] = 1;
	room2.tiles[2][0] = 1;
	room2.tiles[3][0] = 1;
	room2.tiles[4][0] = 1;
	room2.tiles[5][0] = 1;
	room2.tiles[6][0] = 1;
	room2.tiles[9][0] = 1;
	room2.tiles[10][0] = 1;
	room2.tiles[11][0] = 1;
	room2.tiles[12][0] = 1;
	room2.tiles[13][0] = 1;
	room2.tiles[14][0] = 1;
	room2.tiles[15][0] = 1;
	room2.tiles[1][15] = 1;
	room2.tiles[2][15] = 1;
	room2.tiles[3][15] = 1;
	room2.tiles[4][15] = 1;
	room2.tiles[5][15] = 1;
	room2.tiles[6][15] = 1;
	room2.tiles[9][15] = 1;
	room2.tiles[10][15] = 1;
	room2.tiles[11][15] = 1;
	room2.tiles[12][15] = 1;
	room2.tiles[13][15] = 1;
	room2.tiles[14][15] = 1;
	room2.tiles[15][15] = 1;
	
	// obstacles
	room2.tiles[6][6] = 1;
	room2.tiles[7][6] = 1;
	room2.tiles[8][6] = 1;
	room2.tiles[9][6] = 1;
	
	room2.tiles[6][7] = 1;
	room2.tiles[7][7] = 1;
	room2.tiles[8][7] = 1;
	room2.tiles[9][7] = 1;
	
	room2.tiles[6][8] = 1;
	room2.tiles[7][8] = 1;
	room2.tiles[8][8] = 1;
	room2.tiles[9][8] = 1;
	
	room2.tiles[6][9] = 1;
	room2.tiles[7][9] = 1;
	room2.tiles[8][9] = 1;
	room2.tiles[9][9] = 1;
	
	room2.tiles[5][5] = 2;
	room2.player_loc.x = 5;
	room2.player_loc.y = 5;
	room2.player_moveTo = room2.player_loc;
	room2.enemies_loc.push_back(enemy_c(group(11,14)));
	
	d1.clean();
	d1.my_loc.push_back(group(0,7));
	d1.my_loc.push_back(group(0,8));
	d1.goTo_loc.push_back(group(14,7));
	d1.goTo_loc.push_back(group(14,8));
	d1.connects_to.push_back(group(15,7));
	d1.connects_to.push_back(group(15,8));
	d1.direction = "right";
	room2.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(15,7));
	d1.my_loc.push_back(group(15,8));
	d1.goTo_loc.push_back(group(1,7));
	d1.goTo_loc.push_back(group(1,8));
	d1.connects_to.push_back(group(0,7));
	d1.connects_to.push_back(group(0,8));
	d1.direction = "left";
	room2.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,0));
	d1.my_loc.push_back(group(8,0));
	d1.goTo_loc.push_back(group(7,14));
	d1.goTo_loc.push_back(group(8,14));
	d1.connects_to.push_back(group(7,15));
	d1.connects_to.push_back(group(8,15));
	d1.direction = "down";
	room2.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,15));
	d1.my_loc.push_back(group(8,15));
	d1.goTo_loc.push_back(group(7,1));
	d1.goTo_loc.push_back(group(8,1));
	d1.connects_to.push_back(group(7,0));
	d1.connects_to.push_back(group(8,0));
	d1.direction = "up";
	room2.doors.push_back(d1);

	room2.bkg = "room2.png";
	
	baseRooms.push_back(room2);
	
	
	
	
	// border walls
	room3.tiles[6][0] = 1;
	room3.tiles[5][0] = 1;
	room3.tiles[5][1] = 1;
	room3.tiles[4][1] = 1;
	room3.tiles[4][2] = 1;
	room3.tiles[3][2] = 1;
	room3.tiles[3][3] = 1;
	room3.tiles[2][3] = 1;
	room3.tiles[2][4] = 1;
	room3.tiles[1][4] = 1;
	room3.tiles[1][5] = 1;
	room3.tiles[0][5] = 1;
	room3.tiles[0][6] = 1;
	
	room3.tiles[6][15] = 1;
	room3.tiles[5][15] = 1;
	room3.tiles[5][14] = 1;
	room3.tiles[4][14] = 1;
	room3.tiles[4][13] = 1;
	room3.tiles[3][13] = 1;
	room3.tiles[3][12] = 1;
	room3.tiles[2][12] = 1;
	room3.tiles[2][11] = 1;
	room3.tiles[1][11] = 1;
	room3.tiles[1][10] = 1;
	room3.tiles[0][10] = 1;
	room3.tiles[0][9] = 1;
	
	room3.tiles[9][15] = 1;
	room3.tiles[10][15] = 1;
	room3.tiles[10][14] = 1;
	room3.tiles[11][14] = 1;
	room3.tiles[11][13] = 1;
	room3.tiles[12][13] = 1;
	room3.tiles[12][12] = 1;
	room3.tiles[13][12] = 1;
	room3.tiles[13][11] = 1;
	room3.tiles[14][11] = 1;
	room3.tiles[14][10] = 1;
	room3.tiles[15][10] = 1;
	room3.tiles[15][9] = 1;
	
	room3.tiles[9][0] = 1;
	room3.tiles[10][0] = 1;
	room3.tiles[10][1] = 1;
	room3.tiles[11][1] = 1;
	room3.tiles[11][2] = 1;
	room3.tiles[12][2] = 1;
	room3.tiles[12][3] = 1;
	room3.tiles[13][3] = 1;
	room3.tiles[13][4] = 1;
	room3.tiles[14][4] = 1;
	room3.tiles[14][5] = 1;
	room3.tiles[15][5] = 1;
	room3.tiles[15][6] = 1;
	
	
	room3.tiles[5][5] = 2;
	room3.player_loc.x = 5;
	room3.player_loc.y = 5;
	room3.player_moveTo = room3.player_loc;
	room3.enemies_loc.push_back(enemy_c(group(10,10)));

	d1.clean();
	d1.my_loc.push_back(group(0,7));
	d1.my_loc.push_back(group(0,8));
	d1.goTo_loc.push_back(group(14,7));
	d1.goTo_loc.push_back(group(14,8));
	d1.connects_to.push_back(group(15,7));
	d1.connects_to.push_back(group(15,8));
	d1.direction = "right";
	room3.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(15,7));
	d1.my_loc.push_back(group(15,8));
	d1.goTo_loc.push_back(group(1,7));
	d1.goTo_loc.push_back(group(1,8));
	d1.connects_to.push_back(group(0,7));
	d1.connects_to.push_back(group(0,8));
	d1.direction = "left";
	room3.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,0));
	d1.my_loc.push_back(group(8,0));
	d1.goTo_loc.push_back(group(7,14));
	d1.goTo_loc.push_back(group(8,14));
	d1.connects_to.push_back(group(7,15));
	d1.connects_to.push_back(group(8,15));
	d1.direction = "down";
	room3.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,15));
	d1.my_loc.push_back(group(8,15));
	d1.goTo_loc.push_back(group(7,1));
	d1.goTo_loc.push_back(group(8,1));
	d1.connects_to.push_back(group(7,0));
	d1.connects_to.push_back(group(8,0));
	d1.direction = "up";
	room3.doors.push_back(d1);

	room3.bkg = "room3.png";
	
	baseRooms.push_back(room3);
	
	
	
	
	
	// border walls
	room4.tiles[0][0] = 1;
	room4.tiles[0][1] = 1;
	room4.tiles[0][2] = 1;
	room4.tiles[0][3] = 1;
	room4.tiles[0][4] = 1;
	room4.tiles[0][5] = 1;
	room4.tiles[0][6] = 1;
	room4.tiles[0][9] = 1;
	room4.tiles[0][10] = 1;
	room4.tiles[0][11] = 1;
	room4.tiles[0][12] = 1;
	room4.tiles[0][13] = 1;
	room4.tiles[0][14] = 1;
	room4.tiles[0][15] = 1;
	room4.tiles[15][0] = 1;
	room4.tiles[15][1] = 1;
	room4.tiles[15][2] = 1;
	room4.tiles[15][3] = 1;
	room4.tiles[15][4] = 1;
	room4.tiles[15][5] = 1;
	room4.tiles[15][6] = 1;
	room4.tiles[15][9] = 1;
	room4.tiles[15][10] = 1;
	room4.tiles[15][11] = 1;
	room4.tiles[15][12] = 1;
	room4.tiles[15][13] = 1;
	room4.tiles[15][14] = 1;
	room4.tiles[15][15] = 1;
	
	room4.tiles[1][0] = 1;
	room4.tiles[2][0] = 1;
	room4.tiles[3][0] = 1;
	room4.tiles[4][0] = 1;
	room4.tiles[5][0] = 1;
	room4.tiles[6][0] = 1;
	room4.tiles[9][0] = 1;
	room4.tiles[10][0] = 1;
	room4.tiles[11][0] = 1;
	room4.tiles[12][0] = 1;
	room4.tiles[13][0] = 1;
	room4.tiles[14][0] = 1;
	room4.tiles[15][0] = 1;
	room4.tiles[1][15] = 1;
	room4.tiles[2][15] = 1;
	room4.tiles[3][15] = 1;
	room4.tiles[4][15] = 1;
	room4.tiles[5][15] = 1;
	room4.tiles[6][15] = 1;
	room4.tiles[9][15] = 1;
	room4.tiles[10][15] = 1;
	room4.tiles[11][15] = 1;
	room4.tiles[12][15] = 1;
	room4.tiles[13][15] = 1;
	room4.tiles[14][15] = 1;
	room4.tiles[15][15] = 1;
	
	
	// obstacles
	room4.tiles[6][7] = 1;
	room4.tiles[7][6] = 1;
	room4.tiles[5][7] = 1;
	room4.tiles[5][8] = 1;
	
	room4.tiles[5][9] = 1;
	room4.tiles[6][9] = 1;
	room4.tiles[7][9] = 1;
	room4.tiles[8][9] = 1;
	
	room4.tiles[9][8] = 1;
	room4.tiles[10][8] = 1;
	room4.tiles[10][7] = 1;
	room4.tiles[9][7] = 1;
	
	room4.tiles[8][6] = 1;
	room4.tiles[8][5] = 1;
	room4.tiles[7][5] = 1;
	
	room4.tiles[5][5] = 2;
	room4.player_loc.x = 5;
	room4.player_loc.y = 5;
	room4.player_moveTo = room4.player_loc;
	room4.enemies_loc.push_back(enemy_c(group(10,10)));

	d1.clean();
	d1.my_loc.push_back(group(0,7));
	d1.my_loc.push_back(group(0,8));
	d1.goTo_loc.push_back(group(14,7));
	d1.goTo_loc.push_back(group(14,8));
	d1.connects_to.push_back(group(15,7));
	d1.connects_to.push_back(group(15,8));
	d1.direction = "right";
	room4.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(15,7));
	d1.my_loc.push_back(group(15,8));
	d1.goTo_loc.push_back(group(1,7));
	d1.goTo_loc.push_back(group(1,8));
	d1.connects_to.push_back(group(0,7));
	d1.connects_to.push_back(group(0,8));
	d1.direction = "left";
	room4.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,0));
	d1.my_loc.push_back(group(8,0));
	d1.goTo_loc.push_back(group(7,14));
	d1.goTo_loc.push_back(group(8,14));
	d1.connects_to.push_back(group(7,15));
	d1.connects_to.push_back(group(8,15));
	d1.direction = "down";
	room4.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,15));
	d1.my_loc.push_back(group(8,15));
	d1.goTo_loc.push_back(group(7,1));
	d1.goTo_loc.push_back(group(8,1));
	d1.connects_to.push_back(group(7,0));
	d1.connects_to.push_back(group(8,0));
	d1.direction = "up";
	room4.doors.push_back(d1);

	room4.bkg = "room4.png";
	
	baseRooms.push_back(room4);
	
	
	
	
	
	
	
	
	// border walls
	room1.tiles[0][0] = 1;
	room1.tiles[0][1] = 1;
	room1.tiles[0][2] = 1;
	room1.tiles[0][3] = 1;
	room1.tiles[0][4] = 1;
	room1.tiles[0][5] = 1;
	room1.tiles[0][6] = 1;
	room1.tiles[0][9] = 1;
	room1.tiles[0][10] = 1;
	room1.tiles[0][11] = 1;
	room1.tiles[0][12] = 1;
	room1.tiles[0][13] = 1;
	room1.tiles[0][14] = 1;
	room1.tiles[0][15] = 1;
	room1.tiles[15][0] = 1;
	room1.tiles[15][1] = 1;
	room1.tiles[15][2] = 1;
	room1.tiles[15][3] = 1;
	room1.tiles[15][4] = 1;
	room1.tiles[15][5] = 1;
	room1.tiles[15][6] = 1;
	room1.tiles[15][9] = 1;
	room1.tiles[15][10] = 1;
	room1.tiles[15][11] = 1;
	room1.tiles[15][12] = 1;
	room1.tiles[15][13] = 1;
	room1.tiles[15][14] = 1;
	room1.tiles[15][15] = 1;
	
	room1.tiles[1][0] = 1;
	room1.tiles[2][0] = 1;
	room1.tiles[3][0] = 1;
	room1.tiles[4][0] = 1;
	room1.tiles[5][0] = 1;
	room1.tiles[6][0] = 1;
	room1.tiles[9][0] = 1;
	room1.tiles[10][0] = 1;
	room1.tiles[11][0] = 1;
	room1.tiles[12][0] = 1;
	room1.tiles[13][0] = 1;
	room1.tiles[14][0] = 1;
	room1.tiles[15][0] = 1;
	room1.tiles[1][15] = 1;
	room1.tiles[2][15] = 1;
	room1.tiles[3][15] = 1;
	room1.tiles[4][15] = 1;
	room1.tiles[5][15] = 1;
	room1.tiles[6][15] = 1;
	room1.tiles[9][15] = 1;
	room1.tiles[10][15] = 1;
	room1.tiles[11][15] = 1;
	room1.tiles[12][15] = 1;
	room1.tiles[13][15] = 1;
	room1.tiles[14][15] = 1;
	room1.tiles[15][15] = 1;
	
	
	// obstacles
	room1.tiles[3][3] = 1;
	room1.tiles[4][3] = 1;
	room1.tiles[3][2] = 1;
	room1.tiles[4][2] = 1;
	
	room1.tiles[9][5] = 1;
	room1.tiles[10][5] = 1;
	room1.tiles[9][4] = 1;
	room1.tiles[10][4] = 1;
	
	room1.tiles[5][9] = 1;
	room1.tiles[6][9] = 1;
	room1.tiles[5][8] = 1;
	room1.tiles[6][8] = 1;
	
	room1.tiles[10][12] = 1;
	room1.tiles[11][12] = 1;
	room1.tiles[10][11] = 1;
	room1.tiles[11][11] = 1;
	
	room1.tiles[5][5] = 2;
	room1.player_loc.x = 5;
	room1.player_loc.y = 5;
	room1.player_moveTo = room1.player_loc;
	room1.enemies_loc.push_back(enemy_c(group(10,10)));

	d1.clean();
	d1.my_loc.push_back(group(0,7));
	d1.my_loc.push_back(group(0,8));
	d1.goTo_loc.push_back(group(14,7));
	d1.goTo_loc.push_back(group(14,8));
	d1.connects_to.push_back(group(15,7));
	d1.connects_to.push_back(group(15,8));
	d1.direction = "right";
	room1.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(15,7));
	d1.my_loc.push_back(group(15,8));
	d1.goTo_loc.push_back(group(1,7));
	d1.goTo_loc.push_back(group(1,8));
	d1.connects_to.push_back(group(0,7));
	d1.connects_to.push_back(group(0,8));
	d1.direction = "left";
	room1.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,0));
	d1.my_loc.push_back(group(8,0));
	d1.goTo_loc.push_back(group(7,14));
	d1.goTo_loc.push_back(group(8,14));
	d1.connects_to.push_back(group(7,15));
	d1.connects_to.push_back(group(8,15));
	d1.direction = "down";
	room1.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,15));
	d1.my_loc.push_back(group(8,15));
	d1.goTo_loc.push_back(group(7,1));
	d1.goTo_loc.push_back(group(8,1));
	d1.connects_to.push_back(group(7,0));
	d1.connects_to.push_back(group(8,0));
	d1.direction = "up";
	room1.doors.push_back(d1);

	room1.bkg = "untitled.png";
	
	baseRooms.push_back(room1);
	
	
	
	
	
	
	
	
	
	// Special Rooms
	
	// border walls
	bossroom.tiles[0][0] = 1;
	bossroom.tiles[0][1] = 1;
	bossroom.tiles[0][2] = 1;
	bossroom.tiles[0][3] = 1;
	bossroom.tiles[0][4] = 1;
	bossroom.tiles[0][5] = 1;
	bossroom.tiles[0][6] = 1;
	bossroom.tiles[0][9] = 1;
	bossroom.tiles[0][10] = 1;
	bossroom.tiles[0][11] = 1;
	bossroom.tiles[0][12] = 1;
	bossroom.tiles[0][13] = 1;
	bossroom.tiles[0][14] = 1;
	bossroom.tiles[0][15] = 1;
	bossroom.tiles[15][0] = 1;
	bossroom.tiles[15][1] = 1;
	bossroom.tiles[15][2] = 1;
	bossroom.tiles[15][3] = 1;
	bossroom.tiles[15][4] = 1;
	bossroom.tiles[15][5] = 1;
	bossroom.tiles[15][6] = 1;
	bossroom.tiles[15][9] = 1;
	bossroom.tiles[15][10] = 1;
	bossroom.tiles[15][11] = 1;
	bossroom.tiles[15][12] = 1;
	bossroom.tiles[15][13] = 1;
	bossroom.tiles[15][14] = 1;
	bossroom.tiles[15][15] = 1;
	
	bossroom.tiles[1][0] = 1;
	bossroom.tiles[2][0] = 1;
	bossroom.tiles[3][0] = 1;
	bossroom.tiles[4][0] = 1;
	bossroom.tiles[5][0] = 1;
	bossroom.tiles[6][0] = 1;
	bossroom.tiles[9][0] = 1;
	bossroom.tiles[10][0] = 1;
	bossroom.tiles[11][0] = 1;
	bossroom.tiles[12][0] = 1;
	bossroom.tiles[13][0] = 1;
	bossroom.tiles[14][0] = 1;
	bossroom.tiles[15][0] = 1;
	bossroom.tiles[1][15] = 1;
	bossroom.tiles[2][15] = 1;
	bossroom.tiles[3][15] = 1;
	bossroom.tiles[4][15] = 1;
	bossroom.tiles[5][15] = 1;
	bossroom.tiles[6][15] = 1;
	bossroom.tiles[9][15] = 1;
	bossroom.tiles[10][15] = 1;
	bossroom.tiles[11][15] = 1;
	bossroom.tiles[12][15] = 1;
	bossroom.tiles[13][15] = 1;
	bossroom.tiles[14][15] = 1;
	bossroom.tiles[15][15] = 1;
	
	bossroom.tiles[5][5] = 2;
	bossroom.player_loc.x = 5;
	bossroom.player_loc.y = 5;
	bossroom.player_moveTo = bossroom.player_loc;
	bossroom.enemies_loc.push_back(enemy_c(group(10,10)));

	d1.clean();
	d1.my_loc.push_back(group(0,7));
	d1.my_loc.push_back(group(0,8));
	d1.goTo_loc.push_back(group(14,7));
	d1.goTo_loc.push_back(group(14,8));
	d1.connects_to.push_back(group(15,7));
	d1.connects_to.push_back(group(15,8));
	d1.direction = "right";
	bossroom.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(15,7));
	d1.my_loc.push_back(group(15,8));
	d1.goTo_loc.push_back(group(1,7));
	d1.goTo_loc.push_back(group(1,8));
	d1.connects_to.push_back(group(0,7));
	d1.connects_to.push_back(group(0,8));
	d1.direction = "left";
	bossroom.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,0));
	d1.my_loc.push_back(group(8,0));
	d1.goTo_loc.push_back(group(7,14));
	d1.goTo_loc.push_back(group(8,14));
	d1.connects_to.push_back(group(7,15));
	d1.connects_to.push_back(group(8,15));
	d1.direction = "down";
	bossroom.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,15));
	d1.my_loc.push_back(group(8,15));
	d1.goTo_loc.push_back(group(7,1));
	d1.goTo_loc.push_back(group(8,1));
	d1.connects_to.push_back(group(7,0));
	d1.connects_to.push_back(group(8,0));
	d1.direction = "up";
	bossroom.doors.push_back(d1);

	bossroom.bkg = "bossroom.png";
	
	specialRooms.push_back(bossroom);
	
	
	
	
	
	// border walls
	startroom.tiles[0][0] = 1;
	startroom.tiles[0][1] = 1;
	startroom.tiles[0][2] = 1;
	startroom.tiles[0][3] = 1;
	startroom.tiles[0][4] = 1;
	startroom.tiles[0][5] = 1;
	startroom.tiles[0][6] = 1;
	startroom.tiles[0][9] = 1;
	startroom.tiles[0][10] = 1;
	startroom.tiles[0][11] = 1;
	startroom.tiles[0][12] = 1;
	startroom.tiles[0][13] = 1;
	startroom.tiles[0][14] = 1;
	startroom.tiles[0][15] = 1;
	startroom.tiles[15][0] = 1;
	startroom.tiles[15][1] = 1;
	startroom.tiles[15][2] = 1;
	startroom.tiles[15][3] = 1;
	startroom.tiles[15][4] = 1;
	startroom.tiles[15][5] = 1;
	startroom.tiles[15][6] = 1;
	startroom.tiles[15][9] = 1;
	startroom.tiles[15][10] = 1;
	startroom.tiles[15][11] = 1;
	startroom.tiles[15][12] = 1;
	startroom.tiles[15][13] = 1;
	startroom.tiles[15][14] = 1;
	startroom.tiles[15][15] = 1;
	
	startroom.tiles[1][0] = 1;
	startroom.tiles[2][0] = 1;
	startroom.tiles[3][0] = 1;
	startroom.tiles[4][0] = 1;
	startroom.tiles[5][0] = 1;
	startroom.tiles[6][0] = 1;
	startroom.tiles[9][0] = 1;
	startroom.tiles[10][0] = 1;
	startroom.tiles[11][0] = 1;
	startroom.tiles[12][0] = 1;
	startroom.tiles[13][0] = 1;
	startroom.tiles[14][0] = 1;
	startroom.tiles[15][0] = 1;
	startroom.tiles[1][15] = 1;
	startroom.tiles[2][15] = 1;
	startroom.tiles[3][15] = 1;
	startroom.tiles[4][15] = 1;
	startroom.tiles[5][15] = 1;
	startroom.tiles[6][15] = 1;
	startroom.tiles[9][15] = 1;
	startroom.tiles[10][15] = 1;
	startroom.tiles[11][15] = 1;
	startroom.tiles[12][15] = 1;
	startroom.tiles[13][15] = 1;
	startroom.tiles[14][15] = 1;
	startroom.tiles[15][15] = 1;
	
	startroom.tiles[5][5] = 2;
	startroom.player_loc.x = 8;
	startroom.player_loc.y = 10;
	startroom.player_moveTo = startroom.player_loc;
	startroom.enemies_loc.push_back(enemy_c(group(10,10)));
	startroom.enemies_loc.push_back(enemy_c(group(3,3)));

	d1.clean();
	d1.my_loc.push_back(group(0,7));
	d1.my_loc.push_back(group(0,8));
	d1.goTo_loc.push_back(group(14,7));
	d1.goTo_loc.push_back(group(14,8));
	d1.connects_to.push_back(group(15,7));
	d1.connects_to.push_back(group(15,8));
	d1.direction = "right";
	startroom.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(15,7));
	d1.my_loc.push_back(group(15,8));
	d1.goTo_loc.push_back(group(1,7));
	d1.goTo_loc.push_back(group(1,8));
	d1.connects_to.push_back(group(0,7));
	d1.connects_to.push_back(group(0,8));
	d1.direction = "left";
	startroom.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,0));
	d1.my_loc.push_back(group(8,0));
	d1.goTo_loc.push_back(group(7,14));
	d1.goTo_loc.push_back(group(8,14));
	d1.connects_to.push_back(group(7,15));
	d1.connects_to.push_back(group(8,15));
	d1.direction = "down";
	startroom.doors.push_back(d1);
	
	d1.clean();
	d1.my_loc.push_back(group(7,15));
	d1.my_loc.push_back(group(8,15));
	d1.goTo_loc.push_back(group(7,1));
	d1.goTo_loc.push_back(group(8,1));
	d1.connects_to.push_back(group(7,0));
	d1.connects_to.push_back(group(8,0));
	d1.direction = "up";
	startroom.doors.push_back(d1);

	startroom.bkg = "startroom.png";
	
	specialRooms.push_back(startroom);
}
