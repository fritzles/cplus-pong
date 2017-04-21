/*
    Jordan Guzak
    CS 120 Pong Project
    Crayola Color Data Structure
*/

#ifndef COLORS_H
#define COLORS_H

#include <string>

struct color {
    int r;
    int g;
    int b;
};


color BLACK{ 0, 0, 0 };
color WHITE{ 255, 255, 255 };

// crayola colors
const int NUM_CRAYOLA_COLORS = 60;

color CRAYOLA_COLOR[NUM_CRAYOLA_COLORS] = {
    color{ 204, 102, 102 }, color{ 255, 83, 73 }, color{ 253, 124, 110 },
    color{ 255, 110, 74 }, color{ 234, 126, 93 }, color{ 165, 105, 79 },
    color{ 255, 127, 73 }, color{ 255, 130, 67 }, color{ 159, 129, 112 },
    color{ 239, 205, 184 }, color{ 222, 170, 136 }, color{ 255, 207, 171 },
    color{ 253, 217, 181 }, color{ 239, 219, 197 }, color{ 231, 198, 151 },
    color{ 250, 231, 181 }, color{ 252, 217, 117 }, color{ 252, 232, 131 },
    color{ 236, 234, 190 }, color{ 253, 252, 116 }, color{ 255, 255, 153 },
    color{ 178, 236, 93 }, color{ 168, 228, 160 }, color{ 118, 255, 122 },
    color{ 109, 174, 129 }, color{ 28, 172, 120 }, color{ 69, 206, 162 },
    color{ 28, 211, 162 }, color{ 21, 128, 120 }, color{ 120, 219, 226 },
    color{ 128, 218, 235 }, color{ 25, 158, 189 }, color{ 29, 172, 214 },
    color{ 26, 72, 118 }, color{ 43, 108, 196 }, color{ 197, 208, 230 },
    color{ 93, 118, 203 }, color{ 151, 154, 170 }, color{ 115, 102, 189 },
    color{ 120, 81, 169 }, color{ 146, 110, 174 }, color{ 143, 80, 157 },
    color{ 251, 126, 253 }, color{ 142, 69, 133 }, color{ 255, 29, 206 },
    color{ 230, 168, 215 }, color{ 110, 81, 96 }, color{ 255, 67, 164 },
    color{ 252, 180, 213 }, color{ 247, 83, 148 }, color{ 227, 37, 107 },
    color{ 202, 55, 103 }, color{ 252, 137, 172 }, color{ 200, 56, 90 },
    color{ 255, 73, 108 }, color{ 252, 108, 133 }, color{ 255, 155, 170 },
    color{ 237, 237, 237 }, color{ 205, 197, 194 }, color{ 35, 35, 35 }
};

std::string COLOR_NAME[NUM_CRAYOLA_COLORS] = {
    "Fuzzy_Wuzzy_Brown", "Red_Orange", "Bittersweet",
    "Outrageous_Orange", "Burnt_Sienna", "Sepia",
    "Burnt_Orange", "Mango_Tango", "Beaver",
    "Desert_Sand", "Tumbleweed", "Peach",
    "Apricot", "Almond", "Gold",
    "Banana_Mania", "Goldenrod", "Yellow",
    "Spring_Green", "Laser_Lemon", "Canary",
    "Inch_Worm", "Granny_Smith_Apple", "Screamin_Green",
    "Forest_Green", "Green", "Shamrock",
    "Caribbean_Green", "Pine_Green", "Aquamarine",
    "Sky_Blue", "Blue_Green", "Cerulean",
    "Midnight_Blue", "Denim", "Periwinkle",
    "Indigo", "Manatee", "Blue_Violet",
    "Royal_Purple", "Violet", "Vivid_Violet",
    "Shocking_Pink", "Plum", "Purple_Pizzazz",
    "Orchid", "Eggplant", "Wild_Strawberry",
    "Lavender", "Violet_Red", "Razzmatazz",
    "Jazzberry_Jam", "Tickle_Me_Pink", "Maroon",
    "Radical_Red", "Wild_Watermelon", "Salmon",
    "White", "Silver", "Black"
};

#endif // !COLORS_H
