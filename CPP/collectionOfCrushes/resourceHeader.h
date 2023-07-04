#ifndef RES_H
#define RES_H

#define RESOURCES_PATH_AUX

#define RESOURCES_PATH (std::string("RESOURCES_PATH_AUX"))

#define MENU_PATH (RESOURCES_PATH +std::string("menus/"))
#define STD_PERSONALITY_PATH (RESOURCES_PATH+std::string("stdPersonalities/"))
#define STD_PERSONALITY_MENU_PATH (MENU_PATH+std::string("personalities"))


namespace ResourceParsing{


Inclination parseInclination(std::string filePath);

Crush* parseCrush(std::string filePath);

Interest* parseInterest(std::string filePath);

optionList parseMenu(std::string filePath);

}

#endif
