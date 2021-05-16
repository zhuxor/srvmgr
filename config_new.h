#pragma once

#include <stdint.h>
#include "lib\utils.hpp"

extern unsigned long MAX_SKILL;
extern unsigned long MAX_EXP_ON_SKILL;


struct MainCharacterParameters {
	uint8_t Body, Reaction, Mind, Spirit;
};

struct CharacterMagicResists {
	union {
		struct {
			uint8_t Fire, Water, Air, Earth, Astral;
		};
		uint8_t Sphere[5];
	};
};

namespace Config
{
    extern uint32_t ExceptionCount;

    extern uint32_t LogMode;
    extern std::string LogFile;

	extern std::string ChrBase;

    extern uint32_t ServerID;

	extern bool ServerStarted;

    extern std::string CurrentMapName;
    extern std::string CurrentMapTitle;

    extern uint32_t ServerFlags;
    extern bool MapLoaded;
    extern uint32_t ProtocolVersion;

    extern uint32_t MaxPaletteAllowed;

    extern std::string SqlAddress;
    extern uint16_t SqlPort;
    extern std::string SqlLogin;
    extern std::string SqlPassword;
    extern std::string SqlDatabase;

    extern uint32_t ServerCaps;
    extern uint32_t GameMode;

    extern bool Suspended;
    extern uint32_t OriginalTime;
    extern uint32_t MaxPlayers;

	extern std::string ControlDirectory;

	extern bool ExitingCleanly;

    extern double DeathExpMult;
    extern double KilledExpMult;
    extern double PKExpMult;
    extern double RespawnExpMult2;

	extern float InventoryDropProbability;
	extern float WearDropProbability;

	extern MainCharacterParameters WarriorMaleMaxParameters;
	extern MainCharacterParameters WarriorFemaleMaxParameters;
	extern MainCharacterParameters MageMaleMaxParameters;
	extern MainCharacterParameters MageFemaleMaxParameters;

	extern CharacterMagicResists warrior_max_resists;
	extern CharacterMagicResists amazon_max_resists;
	extern CharacterMagicResists mage_max_resists;
	extern CharacterMagicResists witch_max_resists;

	extern uint32_t MinQuestReward;
	extern uint32_t MaxQuestReward;

	extern uint32_t QuestRollInterval;
	extern float mage_pvp_dmg_factor;
	extern float shop_potions_factor;
	extern bool server_rotate_maps;
}

int ReadConfig(const char* filename);