#ifndef RES_H
#define RES_H

#define RESOURCES_PATH_AUX
#define PROGRAM_SETTINGS_PATH (std::string("/home/k/oar-apps1/CPP/collectionOfCrushes/settings"))

//#define RESOURCES_PATH (std::string(RESOURCES_PATH_AUX)+std::string("/"))
#define RESOURCES_PATH (std::string("/home/k/oar-apps1/CPP/collectionOfCrushes/resources/"))

#define MENU_PATH (RESOURCES_PATH +std::string("menus/"))
#define STD_PERSONALITY_PATH (RESOURCES_PATH+std::string("stdPersonalities/"))
#define STD_PERSONALITY_MENU_PATH (MENU_PATH+std::string("personalities"))

#define STD_NAMES_MENU_PATH (MENU_PATH+std::string("names"))

#define STD_MODELS_PATH (RESOURCES_PATH+std::string("CrushDefaults/"))
#define STD_MODELS_MENU_PATH (MENU_PATH+std::string("models"))

#define STD_INTERESTS_PATH (RESOURCES_PATH+std::string("interests/"))

#define STD_INTERESTS_MENU_PATH (MENU_PATH+std::string("interests"))

#define STD_TRAITS_PATH (RESOURCES_PATH+std::string("traits/"))

#define STD_TRAITS_MENU_PATH (MENU_PATH+std::string("traits"))

namespace ResourceParsing{


Inclination parseInclination(std::string& filePath);

Crush* parseCrush(std::string &filePath);

Interest parseInterest(std::string &filePath,std::iostream::pos_type& pos);

optionSet parseMenu(std::string &filePath);

Inclination parseInterestDelta(std::string &filePath);

Inclination parsePersonality(std::string &filePath);

}

#endif
