#ifndef DECTABLES_H
#define DECTABLES_H

#include "obstacle.h"

extern int table_blitz[] = 
{
	0,  7, 15, 18, 26, 27, 32, 39, 45, 47,
	50, 58, 60, 62, 64, 66, 68, 70, 71, 72,
	-1
};

extern int table_vitesse_march[] = 
{
	2, 4, 6, 8
};

extern int table_vitesse_nage[] = 
{
	2, 1, 5, 10, 8, 6, 4
};

extern int table_vitesse_surf[] = 
{
	0, 2, 5, 8, 3, 0
};

extern int table_bulldozer_left[] = { 66, 66, 67, 67, 66, 66, 65, 65 };

extern int table_bulldozer_right[] = { 58, 58, 57, 57, 58, 58, 59, 59 };

extern int table_bulldozer_turn2l[] = 
{
	58, 59, 59, 59, 60, 60, 60, 61, 61, 62,
	62, 63, 63, 64, 64, 64, 65, 65, 65, 66,
	66, 66
};

extern int table_bulldozer_turn2r[] = 
{
	66, 65, 65, 65, 64, 64, 64, 63, 63, 62,
	62, 61, 61, 60, 60, 60, 59, 59, 59, 58,
	58, 58
};

extern int table_poisson_left[] = { 82, 82, 81, 81, 82, 82, 83, 83 };

extern int table_poisson_right[] = { 79, 79, 78, 78, 79, 79, 80, 80 };

extern int table_poisson_turn2l[] = 
{
	79, 79, 80, 80, 84, 84, 85, 85, 86, 86,
	87, 87, 88, 88, 83, 83, 82, 82, 83, 83,
	88, 88, 87, 87, 86, 86, 85, 85, 84, 84,
	79, 79, 79, 79, 80, 80, 84, 84, 85, 85,
	86, 86, 87, 87, 88, 88, 83, 83
};

extern int table_poisson_turn2r[] = 
{
	82, 82, 83, 83, 88, 88, 87, 87, 86, 86,
	85, 85, 84, 84, 79, 79, 79, 79, 80, 80,
	84, 84, 85, 85, 86, 86, 87, 87, 88, 88,
	83, 83, 82, 82, 83, 83, 88, 88, 87, 87,
	86, 86, 85, 85, 84, 84, 79, 79
};

extern int table_oiseau_left[] = { 98, 99, 100, 101, 102, 103, 104, 105 };

extern int table_oiseau_right[] = { 90, 91, 92, 93, 94, 95, 96, 97 };

extern int table_oiseau_turn2l[] = { 106, 107, 108, 109, 110, 111, 112, 113, 105, 105 };

extern int table_oiseau_turn2r[] = { 114, 115, 116, 117, 118, 119, 120, 121, 97, 97 };

extern int table_guepe_left[] = { 195, 196, 197, 198, 197, 196 };

extern int table_guepe_right[] = { 199, 200, 201, 202, 201, 200 };

extern int table_guepe_turn2l[] = { 5, 207, 206, 205, 204, 203 };

extern int table_guepe_turn2r[] = { 203, 204, 205, 206, 207 };

extern int table_creature_left[] = { 247, 248, 249, 250, 251, 250, 249, 248 };

extern int table_creature_right[] = { 247, 248, 249, 250, 251, 250, 249, 248 };

extern int table_creature_turn2[] = 
{
	244, 244, 244, 244, 244, 244, 244, 244, 243, 243,
	242, 242, 242, 242, 242, 242, 242, 242, 243, 243,
	244, 244, 245, 245, 246, 246, 246, 246, 246, 246,
	246, 246, 245, 245, 244, 244, 243, 243, 242, 242,
	242, 242, 242, 242, 243, 243, 244, 244, 245, 245,
	246, 246, 246, 246, 246, 246, 245, 245, 244, 244,
	243, 243, 242, 242, 242, 242, 243, 243, 244, 244,
	245, 245, 246, 246, 246, 246, 245, 245, 244, 244,
	243, 243, 242, 242, 243, 243, 244, 244, 245, 245,
	246, 246, 245, 245, 244, 244, 243, 243, 242, 242,
	242, 242, 243, 243, 244, 244, 245, 245, 246, 246,
	246, 246, 245, 245, 244, 244, 243, 243, 242, 242,
	242, 242, 242, 242, 243, 243, 244, 244, 245, 245,
	246, 246, 246, 246, 246, 246, 245, 245, 244, 244,
	244, 244, 244, 244, 244, 244, 244, 244, 244, 244,
	244, 244
};

extern int table_blupih_left[] = { 66, 67, 68, 67, 66, 69, 70, 69 };

extern int table_blupih_right[] = { 61, 62, 63, 62, 61, 64, 65, 64 };

extern int table_blupih_turn2l[] = 
{
	71, 71, 72, 72, 73, 73, 74, 74, 75, 75,
	68, 68, 275, 275, 271, 271, 271, 271, 272, 272,
	273, 273, 273, 273, 275, 275
};

extern int table_blupih_turn2r[] = 
{
	75, 75, 74, 74, 73, 73, 72, 72, 71, 71,
	63, 63, 274, 274, 271, 271, 271, 271, 272, 272,
	273, 273, 273, 273, 274, 274
};

extern int table_blupit_left[] = { 249, 249, 250, 250, 249, 249, 248, 248 };

extern int table_blupit_right[] = { 238, 238, 237, 237, 238, 238, 239, 239 };

extern int table_blupit_turn2l[] = 
{
	238, 238, 251, 251, 238, 238, 238, 239, 240, 241,
	242, 243, 244, 245, 246, 247, 248, 249, 249, 249,
	252, 252, 249, 249
};

extern int table_blupit_turn2r[] = 
{
	249, 249, 252, 252, 249, 249, 249, 248, 247, 246,
	245, 244, 243, 242, 241, 240, 239, 238, 238, 238,
	251, 251, 238, 238
};

extern int table_explo1[] = 
{
	0, 0, 1, 1, 2, 2, 3, 3, 4, 3,
	4, 4, 3, 4, 3, 3, 4, 4, 5, 5,
	4, 5, 6, 5, 6, 6, 5, 5, 6, 7,
	7, 8, 8, 9, 9, 10, 10, 11, 11
};

extern int table_explo2[] = 
{
	12, -1, 13, 14, -1, 15, 13, -1, 14, 15,
	12, -1, 13, 15, 14, 14, -1, 14, 15, 13
};

extern int table_explo3[] = 
{
	32, 32, 34, 34, 32, 32, 34, 34, 32, 32,
	34, 34, 32, 32, 35, 35, 32, 32, 35, 35
};

extern int table_explo4[] = { 12, 13, 14, 15, 7, 8, 9, 10, 11 };

extern int table_explo5[] = 
{
	54, -1, 55, -1, 56, -1, 57, -1, 58, -1,
	59, -1
};

extern int table_explo6[] = { 54, 55, 56, 57, 58, 59 };

extern int table_explo7[] = 
{
	60, 61, -1, 63, 64, 65, 62, 64, 62, 60,
	62, -1, 65, -1, 60, 65, 63, 61, 62, -1,
	64, 65, -1, 62, 64, 61, 62, 63, -1, 65,
	60, -1, 65, -1, 63, 65, -1, 61, 60, 65,
	62, 63, 64, -1, 62, 63, -1, 62, 62, 60,
	62, -1, 65, -1, 60, 65, 64, 61, 62, 63,
	-1, 65, 60, -1, 63, 61, 62, -1, 64, 65,
	-1, 62, 62, 60, 62, -1, 65, -1, 60, 65,
	60, 61, -1, 63, 64, 65, 62, 64, 63, 61,
	62, -1, 64, 65, -1, 62, 60, 61, -1, 63,
	64, 65, 62, 64, -1, 60, -1, -1, 65, -1,
	60, -1, 63, -1, 62, -1, -1, 65, -1, -1,
	-1, 61, -1, -1, -1, 60, -1, -1
};

extern int table_explo8[] = { 7, 8, 9, 10, 11 };

extern int table_sploutch1[] = { 90, 91, 92, 93, 94, 95, 96, 97, 98, 99 };

extern int table_sploutch2[] = 
{
	-1, -1, -1, 90, 91, 92, 93, 94, 95, 96,
	97, 98, 99
};

extern int table_sploutch3[] = 
{
	-1, -1, -1, -1, -1, -1, -1, -1, 90, 91,
	92, 93, 94, 95, 96, 97, 98, 99
};

extern int table_tentacule[] = 
{
	86, 85, 84, 83, 84, 85, 86, -1, 86, 85,
	84, 83, 82, 81, 80, 79, 78, 77, 76, 75,
	74, 73, 72, 71, 70, 70, 70, 70, 71, 72,
	73, 74, 75, 76, 77, 78, 79, 80, 81, 82,
	83, 84, 85, 86, -1
};

extern int table_bridge[] = 
{
	365, 366, 365, 366, 365, 366, 365, 366, 365, 366,
	365, 366, 365, 366, 365, 366, 367, 367, 368, 368,
	369, 369, 370, 370, 371, 371, 372, 372, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	372, 372, 371, 371, 370, 370, 369, 369, 368, 368,
	367, 367, 366, 366, 365, 365, 364
};

extern int table_pollution[] = { 179, 180, 181, 182, 183, 184, 185, 186 };

extern int table_invertstart[] = { 179, 180, 181, 182, 183, 184, 185, 186 };

extern int table_invertstop[] = { 186, 185, 184, 183, 182, 181, 180, 179 };

extern int table_invertpanel[] = { 187, 188, 189, 190, 191, 192, 193, 194 };

extern int table_plouf[] = { 99, 100, 101, 102, 101, 100, 99 };

extern int table_tiplouf[] = { 244, 99, 244 };

extern int table_blup[] = 
{
	103, 104, 105, 106, 104, 103, 106, 105, 103, 104,
	103, 105, 106, 103, 105, 106, 103, 104, 106, 105
};

extern int table_follow1[] = 
{
	256, 256, 256, 257, 257, 258, 259, 260, 261, 262,
	263, 264, 264, 265, 265, 265, 264, 264, 263, 262,
	261, 260, 259, 258, 257, 257
};

extern int table_follow2[] = { 256, 258, 260, 262, 264 };

extern int table_cle[] = 
{
	122, 123, 124, 125, 126, 127, 128, 127, 126, 125,
	124, 123
};

extern int table_cle1[] = 
{
	209, 210, 211, 212, 213, 214, 215, 214, 213, 212, 211, 210
};

extern int table_cle2[] = 
{
	220, 221, 222, 221, 220, 219, 218, 217, 216, 217, 218, 219
};

extern int table_cle3[] = 
{
	229, 228, 227, 226, 225, 224, 223, 224, 225, 226, 227, 228 
};

extern int table_decor_action[] = 
{
	1,32,
	-4,4, 4,-3, -4,2, 4,5, -4,-1, 4,2, -4,-4, 4,-3, -3,2, 3,2,
	-3,-5, 3,4, -3,5, 3,-2, -3,5, 3,4, -2,-2, 2,4, -2,-2, 2,-2,
	-2,-4, 2,2, -2,-2, 2,-3, -1,-3, 1,-2, -1,-1, 1,2, -1,-2, 1,-1,
	-1,1, 1,2,
	2,32,
	-4,0, 4,0, -4,0, 4,0, -4,0, 4,0, -4,0, 4,0, -3,0, 3,0,
	-3,0, 3,0, -3,0, 3,0, -3,0, 3,0, -2,0, 2,0, -2,0, 2,0,
	-2,0, 2,0, -2,0, 2,0, -1,0, 1,0, -1,0, 1,0, -1,0, 1,0,
	-1,0, 1,0,
	5,192,
	0,-32, 0,32, 0,-16, 0,6, 0,-8, 0,8, 0,-4, 0,4, 0,-2, 0,2,
	-7,0, -6,0, -5,0, -4,0, -2,0, 0,0, 2,0, 4,0, 5,0, 6,0,
	7,0, 7,0, 6,0, 5,0, 4,0, 2,0, 0,0, -2,0, -4,0, -5,0,
	-6,0, -7,0, -7,0, -6,0, -5,0, -4,0, -2,0, 0,0, 2,0, 4,0,
	5,0, 6,0, 7,0, 7,0, 6,0, 5,0, 4,0, 2,0, 0,0, -2,0, -4,0,
	-5,0, -6,0, -7,0, -7,0, -6,0, -5,0, -4,0, -2,0, 0,0, 2,0,
	4,0, 5,0, 6,0, 7,0, 7,0, 6,0, 5,0, 4,0, 2,0, 0,0,
	-2,0, -4,0, -5,0, -6,0, -7,0, -7,0, -6,0, -5,0, -4,0, -2,0,
	0,0, 2,0, 4,0, 5,0, 6,0, 7,0, 7,0, 6,0, 5,0, 4,0,
	2,0, 0,0, -2,0, -4,0, -5,0, -6,0, -7,0, -7,0, -6,0, -5,0,
	-4,0, -2,0, 0,0, 2,0, 4,0, 5,0, 6,0, 7,0, 7,0, 6,0,
	5,0, 4,0, 2,0, 0,0, -2,0, -4,0, -5,0, -6,0, -7,0, -7,0,
	-6,0, -5,0, -4,0, -2,0, 0,0, 2,0, 4,0, 5,0, 6,0, 7,0,
	7,0, 6,0, 5,0, 4,0, 2,0, 0,0, -2,0, -4,0, -5,0, -6,0,
	-7,0, -7,0, -6,0, -5,0, -4,0, -2,0, 0,0, 2,0, 4,0, 5,0,
	6,0, 7,0, 7,0, 6,0, 5,0, 4,0, 2,0, 0,0, -2,0, -4,0,
	-5,0, -6,0, -7,0, -7,0, -6,0, -5,0, -4,0, -2,0, 0,0, 2,0,
	4,0, 5,0, 6,0, 7,0, 7,0, 6,0, 5,0, 4,0, 2,0, 0,0,
	-2,0, -4,0, -5,0, -6,0, -7,0, -7,0, -6,0, -5,0, -4,0, -2,0,
	-1,0,
	0
};

extern int table_dynamitef[] = 
{
	253, 252, 254, 252, 252, 255, 252, 254, 253, 252,
	253, 254, 255, 252, 255, 253, 252, 254, 252, 255,
	253, 254, 252, 253, 255, 254, 255, 252, 253, 254,
	255, 252, 253, 254, 255, 254, 254, 253, 254, 255,
	253, 252, 255, 254, 255, 253, 252, 254, 253, 255,
	253, 254, 252, 253, 255, 254, 252, 255, 253, 254,
	255, 253, 252, 254, 255, 254, 252, 253, 254, 255,
	253, 254, 255, 254, 255, 253, 252, 254, 253, 255,
	253, 254, 255, 253, 255, 254, 255, 252, 253, 254,
	255, 253, 253, 254, 255, 254, 252, 253, 254, 255
};

extern int table_skate[] = 
{
	129, 129, 129, 129, 130, 130, 130, 131, 131, 132,
	132, 133, 133, 134, 134, 134, 135, 135, 135, 135,
	134, 134, 134, 133, 133, 132, 132, 131, 131, 131,
	130, 130, 130, 130
};

extern int table_glu[] = 
{
	168, 168, 169, 169, 170, 170, 171, 171, 170, 170,
	169, 169, 168, 168, 169, 169, 169, 168, 168, 169,
	169, 170, 170, 169, 168
};

extern int table_clear[] = 
{
	40, 40, 40, 40, 41, 41, 41, 41, 40, 40,
	40, 40, 40, 40, 40, 41, 41, 41, 40, 40,
	40, 40, 40, 40, 40, 41, 41, 41, 40, 40,
	42, 42, 42, 43, 43, 43, 44, 44, 44, 45,
	45, 45, 46, 46, 47, 47, 46, 46, 47, 47,
	46, 46, 47, 47, 46, 46, 47, 47, 46, 46,
	47, 47, 46, 46, 47, 47, 46, 46, 47, 47
};

extern int table_electro[] = 
{
	266, 267, 266, 267, 266, 267, 266, 267, 266, 267,
	266, 267, 266, 267, 266, 267, 266, 267, 266, 267,
	266, 267, 266, 267, 266, 267, 266, 267, 266, 267,
	40, 40, 40, 40, 41, 41, 41, 41, 40, 40,
	40, 40, 40, 40, 40, 41, 41, 41, 40, 40,
	40, 40, 40, 40, 40, 41, 41, 41, 40, 40,
	42, 42, 42, 43, 43, 43, 44, 44, 44, 45,
	45, 45, 46, 46, 47, 47, 46, 46, 47, 47,
	46, 46, 47, 47, 46, 46, 47, 47, 46, 46
};

extern int table_chenille[] = { 311, 312, 313, 314, 315, 316 };

extern int table_chenillei[] = { 316, 315, 314, 313, 312, 311 };

extern int table_adapt_decor[] = 
{
	153, 147, 148, 146, 40, 151, 150, 144, 39, 152,
	149, 145, 38, 36, 37, 35, 153, 147, 148, 146,
	40, 151, 150, 144, 39, 152, 149, 145, 38, 36,
	37, 156, 75, 75, 155, 155, 75, 75, 155, 155,
	74, 74, 154, 154, 75, 75, 155, 155, 157, 157,
	157, 157, 109, 109, 109, 109, 108, 108, 108, 108,
	107, 107, 107, 107, 202, 202, 138, 138, 202, 202,
	138, 138, 202, 202, 138, 138, 202, 202, 138, 138,
	283, 283, 283, 283, 262, 262, 262, 262, 263, 263,
	263, 263, 261, 261, 261, 261, 361, 359, 360, 352,
	357, 353, 355, 349, 358, 354, 356, 350, 351, 347,
	348, 341, 387, 387, 386, 386, 394, 394, 392, 392,
	395, 395, 393, 393, 397, 397, 396, 396, 251, 254,
	254, 254, 251, 258, 260, 258, 251, 257, 259, 257,
	251, 250, 256, 250
};

extern int table_adapt_fromage[] = 
{
	-1, 265, 264, 268, 267, 273, 271, 275, 266, 272,
	270, 274, 269, 277, 276, 278, -1, 286, 285, 289,
	288, 294, 292, 296, 287, 293, 291, 295, 290, 298,
	297, 299
};

extern int table_shield[] = 
{
	144, 145, 146, 147, 148, 149, 150, 151, 266, 267,
	268, 269, 270, 271, 272, 273
};

extern int table_shield_blupi[] = 
{
	144, 145, 146, 147, 148, 149, 150, 151, 266, 267,
	268, 269, 270, 271, 272, 273
};

extern int table_power[] = { 8, 136, 137, 138, 139, 140, 141, 142, 143 };

extern int table_invert[] = 
{
	187, 187, 187, 188, 189, 190, 191, 192, 193, 194,
	187, 187, 187, 194, 193, 192, 191, 190, 189, 188
};

extern int table_charge[] = { 238, 239, 240, 241, 242, 243 };

extern int table_magicloop[] = { 152, 153, 154, 155, 156 };

extern int table_magictrack[] = 
{
	152, 153, 154, 155, 156, 152, 153, 154, 155, 156,
	157, 158, 159, 160, 157, 158, 159, 160, 161, 162,
	163, 164, 165, 166
};

extern int table_shieldloop[] = { 274, 275, 276, 277, 278 };

extern int table_shieldtrack[] = 
{
	274, 275, 276, 277, 278, 274, 275, 276, 277, 278,
	279, 280, 281, 282, 283, 284, 285, 286, 287, 288
};

extern int table_drinkeffect[] = { 274, 275, 276, 277, 278 };

extern int table_drinkoffset[] = { 0, 7, 22 };

extern int table_tresortrack[] = 
{
	166, 165, 164, 163, 162, 161, 162, 163, 164, 165,
	166
};

extern int table_decor_piege1[] = 
{
	374, 374, 373, 347, 373, 374, 374, 374, 373, 347,
	347, 373, 374, 374, 374, 374
};

extern int table_decor_piege2[] = { 374, 373, 347, 373 };

extern int table_decor_goutte[] = 
{
	410, 409, 410, -1, -1, -1, -1, -1, -1, 410,
	409, 408, 409, 410, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, 410, 409, 408, 407, 406, 405,
	404, 405, 406, 407, 408, 409, 410, -1, -1, -1,
	-1, 410, 409, 410, -1, -1, -1, -1
};

extern int table_decor_ecraseur[] = { 317, 317, 318, 319, 320, 321, 322, 323, 323, 323 };

extern int table_decor_scie[] = { 378, 379, 380, 381, 382, 383 };

extern int table_decor_temp[] = 
{
	328, 328, 327, 327, 326, 326, 325, 325, 324, 324,
	325, 325, 326, 326, 327, 329, 328, 328, -1, -1
};

extern int table_decor_eau1[] = { 92, 93, 94, 95, 94, 93 };

extern int table_decor_eau2[] = { 91, 96, 97, 98, 97, 96 };



extern int table_decor_ventillod[] = { 129, 130, 131 };

extern int table_decor_ventilloh[] = { 132, 133, 134 };

extern int table_decor_ventillob[] = { 135, 136, 137 };



extern int table_decor_ventd[] = { 114, 115, 116, 117 };

extern int table_decor_venth[] = { 118, 119, 120, 121 };

extern int table_decor_ventb[] = { 122, 123, 124, 125 };

extern int table_marine[] = 
{
	0, 2, 5, 8, 3, 0
};

extern int table_36418[] = { 10, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11, 12, 13, 14 };
extern int table_36458[] = { 19, 20, 21, 23, 24, 25, 26, 27, 28, 29 };
extern int table_36488[] = { 15, 16, 17, 18 };
extern int table_364a0[] = { 73, 22 };
extern int table_364b0[] = { 78, 79, 80, 81, 82, 83, 84 };
extern int table_364d0[] = { 87, 88, 89, 90 };
extern int table_364e8[] = { 85, 86 };
extern int table_364f8[] = { 396, 388, 389, 390, 391 };
extern int table_36510[] = { 398, 399, 400 };
extern int table_36520[] = { 87, 88, 89 };
extern int table_36530[] = { 0x99 };
extern int table_36538[] = { 0x9a, 0x9b };
extern int table_36548[] = { 0xb9 };
extern int table_36550[] = { 0x29, 0x2a, 0x2b, 0x2c, 0x2d, 0x2e, 0x2f };
extern int table_36570[] = { 0xd7, 0xd8, 0xd9, 0xda, 0xdb, 0xdc, 0xdd, 0xde, 0xe6, 0xe7, 0xe9, 0xea };
extern int table_365a8[] = { 0xdf, 0xe0, 0xe1, 0xe2, 0xe3, 0xe4, 0xe5, 0xe8 };
extern int table_365d0[] = { 0x9d };
extern int table_365d8[] = { 0x8b, 0x8c, 0x8d, 0x8e, 0x8f };
extern int table_365f0[] = { 0xba, 0xbb, 0xbc, 0xbd, 0xbe, 0xbf, 0xc0 };
extern int table_36610[] = { 0xc1, 0xc2, 0xc3, 0xc4, 0xc5 };
extern int table_decor_lave[] = { 68, 69, 70, 71, 72, 71, 70, 69 };
extern int table_36630[] = { 0x5b, 0x5c };
extern int table_decor_ventillog[] = { 126, 127, 128 };
extern int table_decor_ventg[] = { 110, 111, 112, 113 };
extern int table_36670[] = { 0x4c, 0x4d, 0xc7, 0xc6, 0xc8, 0xc9, 0xeb, 0xec, 0x177, 0x178, 0x179 };
extern int table_366a0[] = { 0x193, 0x191, 0x192 };
extern int table_366b0[] = { 20, 21, 22 };
extern int table_366c0[] = { 16, 17, 18, 19 };
extern int table_366d8[] = { 23, 24, 25 };
extern int table_366e8[] = { 0x1a, 0x1b };
extern int table_366f8[] = { 0x1c, 0x1d, 0x1e, 0x1f };
extern int table_36710[] = { 0x2d, 0x2e, 0x2f, 0x24, 0x25, 0x26, 0x27, 0x28, 0x29, 0x2a, 0x2b, 0x2c};
extern int table_36748[] = { 0x42, 0x43, 0x44, 0x45 };

extern int table_mirror[] = {
	4, 3, 2, 1, 0, 11, 12, 13, 14, 15, 16, 5, 6, 7, 8, 9, 10, 20, 21, 22, 17, 18, 19, 24, 23, 25, 30, 31, 32, 29, 26, 27, 28, 36, 37, 38, 33, 34, 35, 40, 39, 41, 42, 43, 45, 44, 46, 47, 48, 55, 56, 57, 58, 59, 60, 49, 50, 51, 52, 53, 54, 66, 67, 68, 69, 70, 61, 62, 63, 64, 65, 75, 74, 73, 72, 71, 82, 83, 84, 85, 86, 87, 76, 77, 78, 79, 80, 81, 92, 91, 90, 89, 88, 99, 100, 101, 102, 103, 104, 93, 94, 95, 96, 97, 98, 109, 108, 107, 106, 105, 120, 119, 118, 117, 116, 115, 114, 113, 112, 111, 110, 127, 128, 129, 130, 131, 132, 121, 122, 123, 124, 125, 126, 134, 133, 139, 140, 141, 142, 135, 136, 137, 138, 147, 148, 149, 150, 143, 144, 145, 146, 155, 154, 153, 152, 151, 159, 160, 161, 156, 157, 158, 162, 163, 164, 167, 168, 165, 166, 173, 174, 175, 176, 169, 170, 171, 172, 181, 180, 179, 178, 177, 188, 189, 190, 191, 192, 193, 182, 183, 184, 185, 186, 187, 201, 202, 203, 204, 205, 206, 207, 194, 195, 196, 197, 198, 199, 200, 209, 208, 216, 217, 218, 219, 220, 221, 210, 211, 212, 213, 214, 215, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 250, 249, 248, 247, 246, 245, 244, 243, 242, 241, 240, 239, 238, 237, 252, 251, 255, 256, 253, 254, 257, 258, 259, 260, 261, 262, 285, 286, 287, 266, 267, 270, 269, 268, 271, 272, 273, 275, 274, 276, 277, 278, 279, 280, 281, 282, 283, 284, 263, 264, 265, 288, 289, 290, 291, 292, 293, 294, 295, 303, 304, 305, 306, 307, 308, 309, 296, 297, 298, 299, 300, 301, 302, 314, 313, 312, 311, 310, 316, 315, 323, 322, 321, 320, 319, 318, 317, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334
};

extern int table_ressort[] = 
{
	0xd1, 0xd2, 0xd3, 0xd4, 0xd5, 0xd4, 0xd3, 0xd2
};

extern int table_blupi[] = {
	35, 18, 0, 276, 276, 277, 277, 278, 278, 279, 279, 280, 280, 281, 281, 282, 282, 283, 283, 284, 284, 1, 330, 0, 0, 0, 0, 0, 0, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	23, 23, 23, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 23, 23, 23, 0, 0, 0, 23, 23, 23, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0
	, 0, 133, 133, 0, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0, 0, 0, 23, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 0, 0, 0, 0, 0, 23, 23, 23, 0, 0, 0, 135, 135, 136,
	136, 137, 137, 137, 137, 137, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 137, 137, 137, 136,
	136, 135, 135, 135, 0, 0, 0, 0, 0, 23, 23, 23, 0, 0, 133, 133, 0, 0, 0, 23, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0, 0, 0, 0,
	23, 23, 23, 23, 0, 0, 0, 135, 135, 136, 136, 137, 137, 137, 137, 137, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138,
	138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 138, 138, 137, 137,
	137, 138, 138, 137, 137, 137, 138, 138, 137, 137, 137, 137, 137, 137, 136, 136, 135, 135, 135, 0, 0, 0, 0, 0, 23, 23, 23, 0, 0, 133, 133, 0, 0, 0, 23, 23, 23, 23, 0, 0
	, 0, 0, 0, 0, 0, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0, 0, 0, 0, 23, 23, 23, 23, 0, 0, 0, 2, 6, 0, 5, 6, 7, 8, 9, 10, 60, 3, 0, 19, 18, 19, 3, 6, 0, 1, 1, 2,
	2, 3, 3, 4, 3, 0, 17, 18, 19, 5, 5, 4, 169, 26, 170, 170, 27, 59, 6, 0, 3, 3, 2, 2, 1, 1, 61, 5, 0, 34, 35, 34, 34, 33, 62, 2, 0, 35, 34, 6, 3, 2, 33, 34, 35, 7, 1, 0,
	44, 8, 8, 0, 0, 169, 26, 170, 27, 171, 28, 172, 9, 6, 0, 5, 6, 7, 8, 9, 10, 10, 6, 0, 5, 6, 7, 8, 9, 10, 13, 6, 0, 41, 41, 42, 42, 43, 43, 11, 70, 0, 40, 40, 40, 40,
	41, 41, 41, 41, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 40, 40, 42, 42, 42, 43, 43, 43, 44, 44, 44, 45, 45, 45, 46, 46, 47, 47,
	46, 46, 47, 47, 46, 46, 47, 47, 46, 46, 47, 47, 46, 46, 47, 47, 46, 46, 47, 47, 46, 46, 47, 47, 75, 1, 0, -1, 76, 70, 0, 40, 40, 40, 40, 41, 41, 41, 41, 40, 40, 40,
	40, 40, 40, 40, 41, 41, 41, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 40, 40, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
	-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
	, -1, -1, -1, -1, -1, 77, 110, 0, 324, 325, 324, 325, 324, 325, 324, 325, 324, 325, 324, 325, 324, 325, 324, 325, 324, 325, 324, 325, 324, 324, 325, 325, 326, 326, 327
	, 327, 328, 328, 329, 329, 330, 330, 331, 331, 332, 332, 333, 333, 334, 334, 333, 333, 332, 332, 331, 331, 330, 330, 329, 329, 329, 330, 330, 330, 331, 331, 331, 332,
	332, 332, 333, 333, 333, 334, 334, 334, 333, 333, 333, 332, 332, 332, 331, 331, 331, 330, 330, 330, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329,
	329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 329, 78, 1, 0, -1, 79, 1, 0, -1, 80, 1, 0, -1, 81, 1, 0, -1, 14, 6, 0, 49, 50, 51, 52,
	53, 54, 29, 6, 0, 126, 125, 124, 123, 122, 121, 28, 6, 0, 122, 122, 122, 125, 125, 125, 15, 1, 0, 61, 16, 8, 0, 61, 62, 63, 62, 61, 64, 65, 64, 17, 10, 0, 71, 71, 72,
	72, 73, 73, 74, 74, 75, 75, 67, 1, 0, 315, 68, 12, 0, 296, 297, 298, 299, 300, 301, 302, 301, 300, 299, 298, 297, 69, 7, 0, 296, 310, 311, 312, 313, 314, 303, 18, 10,
	0, 76, 76, 76, 76, 76, 76, 77, 77, 77, 77, 19, 14, 0, 76, 76, 77, 77, 78, 78, 79, 79, 80, 80, 81, 81, 39, 39, 20, 10, 0, 88, 88, 89, 89, 90, 90, 91, 91, 92, 92, 21, 12
	, 0, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 22, 12, 0, 93, 93, 94, 94, 95, 95, 96, 96, 97, 97, 98, 98, 23, 10, 0, 105, 105, 106, 106, 107, 107, 108, 108, 109,
	109, 24, 90, 0, 93, 96, 98, 94, 95, 93, 95, 98, 93, 94, 96, 96, 94, 94, 98, 98, 93, 93, 97, 97, 94, 94, 94, 96, 96, 96, 93, 93, 93, 93, 94, 94, 94, 94, 94, 97, 97, 97
	, 97, 97, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 79, 79, 76, 76, 76, 76, 79, 79, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76,
	76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 76, 25, 8, 0, 111, 111, 110, 110, 111, 111, 112, 112, 26, 8, 0, 111, 111, 110, 110, 111, 111, 112, 112, 27, 7, 0, 112, 113, 114
	, 115, 116, 117, 118, 30, 12, 0, 25, 25, 29, 29, 46, 46, 47, 47, 46, 46, 29, 29, 31, 328, 0, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157,
	157, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157,
	156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156,
	156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 144, 144,
	143, 143, 151, 151, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164,
	164, 163, 163, 162, 162, 151, 151, 143, 143, 144, 144, 157, 157, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156, 156, 156, 156,
	157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156, 156, 156, 156, 157, 157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 156, 156, 156, 156, 157,
	157, 157, 157, 158, 158, 158, 158, 157, 157, 157, 157, 144, 144, 143, 143, 151, 151, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163,
	162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 151, 151, 143, 143, 151, 151, 162, 162, 163, 163, 164, 164, 163, 163, 162,
	162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162, 163, 163, 164, 164, 163, 163, 162, 162,
	163, 163, 164, 164, 163, 163, 162, 162, 151, 151, 143, 143, 144, 144, 157, 157, 32, 12, 0, 144, 144, 145, 145, 146, 146, 145, 145, 144, 144, 143, 143, 33, 10, 0, 151,
	151, 152, 152, 153, 153, 154, 154, 155, 155, 34, 10, 0, 157, 157, 165, 165, 165, 165, 166, 166, 166, 166, 36, 32, 0, 135, 177, 177, 178, 178, 179, 179, 180, 180, 179,
	179, 178, 178, 179, 179, 180, 180, 179, 179, 178, 178, 179, 179, 180, 180, 179, 179, 178, 178, 177, 177, 135, 37, 140, 0, 182, 182, 182, 182, 208, 208, 208, 208, 208,
	182, 182, 182, 182, 182, 182, 208, 208, 208, 208, 208, 194, 194, 194, 182, 182, 182, 182, 208, 208, 208, 208, 208, 182, 182, 182, 182, 182, 182, 208, 208, 208, 208,
	182, 182, 182, 182, 182, 182, 182, 182, 194, 195, 196, 197, 198, 198, 197, 197, 196, 196, 197, 197, 198, 198, 197, 197, 196, 195, 194, 182, 182, 182, 208, 208, 208,
	208, 208, 208, 182, 182, 182, 182, 182, 208, 208, 208, 208, 208, 182, 182, 194, 195, 196, 197, 198, 198, 197, 197, 196, 196, 197, 197, 198, 198, 197, 197, 196, 196,
	197, 197, 198, 198, 197, 197, 196, 195, 194, 182, 182, 182, 182, 182, 182, 182, 208, 208, 208, 208, 208, 208, 210, 210, 211, 211, 211, 211, 211, 211, 210, 210, 38, 96,
	0, 182, 183, 184, 185, 186, 187, 182, 183, 184, 185, 186, 187, 182, 183, 184, 185, 186, 187, 182, 182, 182, 182, 182, 182, 182, 183, 184, 185, 186, 187, 182, 182, 182
	, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 183, 184, 185, 186, 187, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182,
	182, 183, 184, 185, 186, 187, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 182, 39, 7, 0, 194,
	195, 196, 197, 198, 199, 200, 40, 3, 0, 210, 211, 212, 41, 8, 0, 213, 213, 214, 214, 215, 215, 214, 214, 42, 20, 0, 17, 17, 18, 18, 19, 19, 1, 1, 215, 215, 214, 214,
	213, 213, 212, 212, 211, 211, 210, 210, 43, 20, 0, 210, 210, 211, 211, 212, 212, 213, 213, 214, 214, 215, 215, 1, 1, 19, 19, 18, 18, 17, 17, 44, 29, 0, 1, 1, 222, 222,
	222, 222, 223, 223, 224, 224, 225, 225, 225, 225, 225, 224, 223, 222, 222, 222, 223, 223, 224, 224, 225, 225, 225, 1, 1, 45, 29, 0, 1, 1, 222, 222, 222, 222, 223, 223
	, 224, 224, 225, 225, 225, 225, 225, 224, 223, 222, 222, 222, 223, 223, 224, 224, 225, 225, 225, 1, 1, 46, 32, 0, 1, 1, 227, 227, 228, 228, 229, 229, 228, 228, 227,
	227, 226, 226, 227, 227, 228, 228, 229, 229, 228, 228, 227, 227, 226, 226, 227, 227, 228, 228, 1, 1, 47, 34, 0, 135, 135, 136, 136, 137, 137, 231, 231, 231, 231, 230,
	230, 231, 231, 231, 231, 230, 230, 231, 231, 231, 231, 230, 230, 231, 231, 231, 231, 137, 137, 136, 136, 135, 135, 48, 40, 0, 0, 0, 135, 135, 136, 136, 137, 137, 232,
	233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 232, 233, 137, 137, 136, 136, 135, 135, 0, 0, 65, 44, 0, 1, 1,
	288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 289, 288,
	288, 289, 289, 290, 290, 290, 289, 1, 1, 49, 36, 0, 1, 1, 234, 234, 235, 235, 236, 236, 235, 235, 234, 234, 235, 235, 236, 236, 235, 235, 234, 234, 235, 235, 236, 236,
	235, 235, 234, 234, 235, 235, 236, 236, 235, 235, 1, 1, 50, 64, 0, 238, 238, 239, 239, 240, 240, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 240, 240, 241, 241,
	240, 240, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 241, 240, 240, 241, 241, 240, 240, 241, 241, 241, 241, 241, 241, 241, 241, 240, 240, 239, 239, 238,
	238, 238, 238, 238, 238, 237, 237, 238, 238, 237, 237, 51, 8, 0, 238, 238, 237, 237, 238, 238, 239, 239, 52, 12, 0, 238, 239, 240, 241, 242, 243, 244, 245, 246, 247,
	248, 249, 53, 6, 0, 251, 251, 238, 238, 238, 238, 54, 25, 0, 168, 168, 169, 169, 170, 170, 171, 171, 170, 170, 169, 169, 168, 168, 169, 169, 169, 168, 168, 169, 169,
	170, 170, 169, 168, 55, 4, 0, 253, 253, 254, 254, 56, 64, 0, 1, 3, 270, 268, 1, 3, 270, 268, 1, 3, 270, 268, 1, 3, 270, 268, 1, 3, 270, 268, 1, 3, 270, 268, 1, 3, 270,
	268, 1, 3, 270, 268, 1, 2, 3, 4, 270, 269, 268, 0, 1, 2, 3, 4, 270, 269, 268, 0, 1, 1, 2, 2, 3, 3, 4, 4, 270, 270, 269, 269, 268, 268, 0, 0, 57, 90, 0, 266, 267, 266,
	267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 266, 267, 40, 40, 40, 40, 41, 41, 41, 41,
	40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 40, 40, 40, 40, 40, 40, 40, 41, 41, 41, 40, 40, 42, 42, 42, 43, 43, 43, 44, 44, 44, 45, 45, 45, 46, 46, 47, 47, 46, 46, 47, 47
	, 46, 46, 47, 47, 46, 46, 47, 47, 46, 46, 82, 10, 0, 0, 268, 268, 269, 269, 269, 269, 268, 268, 0, 58, 14, 0, 274, 274, 271, 271, 271, 271, 272, 272, 273, 273, 273,
	273, 274, 274, 66, 16, 0, 291, 291, 292, 292, 293, 293, 294, 294, 295, 295, 294, 294, 293, 293, 292, 292, 72, 1, 0, 320, 73, 24, 0, 319, 319, 318, 318, 317, 317, 318,
	318, 319, 319, 320, 320, 321, 321, 322, 322, 323, 323, 322, 322, 321, 321, 320, 320, 74, 128, 0, 1, 1, 2, 2, 3, 3, 4, 4, 270, 270, 269, 269, 268, 268, 0, 0, 1, 2, 3, 4
	, 270, 269, 268, 0, 1, 2, 3, 4, 270, 269, 268, 0, 1, 3, 270, 268, 2, 4, 269, 0, 1, 3, 270, 268, 2, 4, 269, 0, -1, 3, 270, -1, 2, -1, 269, 0, 1, -1, -1, 268, -1, -1,
	269, -1, -1, -1, -1, 270, -1, -1, 2, -1, -1, -1, -1, -1, -1, 29, 46, 47, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
	, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 63, 92, 0, 263, 264, 265, 264, 263, 264, 265, 264, 263, 264, 265, 264
	, 263, 264, 265, 264, 263, 264, 265, 264, 263, 264, 265, 264, 263, 264, 265, 264, 263, 264, 265, 264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 23, 23, 0, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0, 0, 133, 133, 0, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0, 0, 0, 23, 23, 23, 23, 0, 0, 0, 0, 64, 104, 0, 1, 1, 2, 2, 3, 3,
	285, 286, 287, 286, 285, 286, 287, 286, 285, 286, 287, 286, 285, 286, 287, 286, 285, 286, 287, 286, 285, 286, 287, 286, 285, 286, 287, 286, 285, 286, 287, 286, 3, 3, 2
	, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 23, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 23, 23, 0, 0, 0, 0, 0, 0, 0, 133, 133, 0, 0, 0, 133, 133, 0, 0, 0, 0, 0, 0, 0, 133,
	133, 0, 0, 0, 0, 23, 23, 23, 23, 0, 0, 0, 0, 83, 60, 0, 1, 1, 288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290,
	290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 289, 288, 288, 289, 289, 290, 290, 290, 290, 290, 290, 290, 290, 290, 290,
	290, 290, 1, 1, 0
};

extern int table_tutorial[] = {
	0, 2, 0, 7, -1, 0x190,
	3, 3, 0, 7, 0, 0x191,
	3, 4, 0, 7, -1, 0x192,
	6, 8, 0, 7, -1, 0x193,
	12, 12, 0, 7, 1, 0x194,
	12, 13, 0, 7, -1, 0x195,
	14, 15, 0, 7, -1, 0x196,
	16, 17, 0, 1, -1, 0x197,
	22, 23, 0, 7, -1, 0x198,
	29, 30, 0, 7, -1, 0x199,
	41, 44, 0, 7, -1, 0x19a,
	54, 63, 0, 7, -1, 0x19b,
	69, 70, 0, 7, -1, 0x19c,
	-1
};

#endif