/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DBCENUMS_H
#define DBCENUMS_H

#include "ItemPrototype.h"

enum LevelLimit
{
    // Client expected level limitation, like as used in DBC item max levels for "until max player level"
    // use as default max player level, must be fit max level for used client
    // also see MAX_LEVEL and STRONG_MAX_LEVEL define
#define DEFAULT_MAX_LEVEL 90
#define DEFAULT_MAX_SKILL_VALUE 600

    // client supported max level for player/pets/etc. Avoid overflow or client stability affected.
    // also see GT_MAX_LEVEL define
#define MAX_LEVEL    100

    // Server side limitation. Base at used code requirements.
    // also see MAX_LEVEL and GT_MAX_LEVEL define
#define STRONG_MAX_LEVEL 255
};

enum BattlegroundBracketId                                  // bracketId for level ranges
{
    BG_BRACKET_ID_FIRST          = 0,
    BG_BRACKET_ID_LAST           = 16
};

// must be max value in PvPDificulty slot+1
#define MAX_BATTLEGROUND_BRACKETS  17

enum AreaTeams
{
    AREATEAM_NONE  = 0,
    AREATEAM_ALLY  = 2,
    AREATEAM_HORDE = 4,
    AREATEAM_ANY   = AREATEAM_ALLY+AREATEAM_HORDE
};

enum AchievementFaction
{
    ACHIEVEMENT_FACTION_HORDE           = 0,
    ACHIEVEMENT_FACTION_ALLIANCE        = 1,
    ACHIEVEMENT_FACTION_ANY             = -1
};

enum AchievementFlags
{
    ACHIEVEMENT_FLAG_COUNTER                = 0x00000001,    // Just count statistic (never stop and complete)
    ACHIEVEMENT_FLAG_HIDDEN                 = 0x00000002,    // Not sent to client - internal use only
    ACHIEVEMENT_FLAG_PLAY_NO_VISUAL         = 0x00000004,    // Client does not play achievement earned visual
    ACHIEVEMENT_FLAG_SUMM                   = 0x00000008,    // Use summ criteria value from all requirements (and calculate max value)
    ACHIEVEMENT_FLAG_MAX_USED               = 0x00000010,    // Show max criteria (and calculate max value ??)
    ACHIEVEMENT_FLAG_REQ_COUNT              = 0x00000020,    // Use not zero req count (and calculate max value)
    ACHIEVEMENT_FLAG_AVERAGE                = 0x00000040,    // Show as average value (value / time_in_days) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_BAR                    = 0x00000080,    // Show as progress bar (value / max vale) depend from other flag (by def use last criteria value)
    ACHIEVEMENT_FLAG_REALM_FIRST_REACH      = 0x00000100,    //
    ACHIEVEMENT_FLAG_REALM_FIRST_KILL       = 0x00000200,    //
    ACHIEVEMENT_FLAG_UNK3                   = 0x00000400,    // ACHIEVEMENT_FLAG_HIDE_NAME_IN_TIE
    ACHIEVEMENT_FLAG_REALM_FIRST_GUILD      = 0x00000800,    // first guild on realm done something
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_NEWS     = 0x00001000,    // Shows in guild news
    ACHIEVEMENT_FLAG_SHOW_IN_GUILD_HEADER   = 0x00002000,    // Shows in guild news header
    ACHIEVEMENT_FLAG_GUILD                  = 0x00004000,    //
    ACHIEVEMENT_FLAG_SHOW_GUILD_MEMBERS     = 0x00008000,    //
    ACHIEVEMENT_FLAG_SHOW_CRITERIA_MEMBERS  = 0x00010000,    //
    ACHIEVEMENT_FLAG_ACCOUNT                = 0x00020000,    //
    ACHIEVEMENT_FLAG_UNK5                   = 0x00040000,
    ACHIEVEMENT_FLAG_HIDE_ZERO_COUNTER      = 0x00080000,    // statistic is hidden from UI if no criteria value exists
    ACHIEVEMENT_FLAG_TRACKING_FLAG          = 0x00100000,    // hidden tracking flag, sent to client in all cases except completion announcements
};

enum ModifierTreeFlags
{
    MODIFIERTREE_FLAG_UNK                 = 0x00000001,    //
    MODIFIERTREE_FLAG_CONDITION           = 0x00000002,    // Is condition
    MODIFIERTREE_FLAG_MAIN                = 0x00000004,    // Is main and not condition
    MODIFIERTREE_FLAG_PARENT              = 0x00000008,    // Is parent and not condition
};

enum
{
    MAX_CRITERIA_REQUIREMENTS          = 1,
    MAX_ADDITIONAL_CRITERIA_CONDITIONS = 3
};

enum CriteriaCondition
{
    CRITERIA_CONDITION_NONE                 = 0,
    CRITERIA_CONDITION_NO_DEATH             = 1,    // reset progress on death
    CRITERIA_CONDITION_UNK2                 = 2,    // only used in "Complete a daily quest every day for five consecutive days"
    CRITERIA_CONDITION_BG_MAP               = 3,    // requires you to be on specific map, reset at change
    CRITERIA_CONDITION_NO_LOSE              = 4,    // only used in "Win 10 arenas without losing"
    CRITERIA_CONDITION_NOT_LOSE_AURA        = 5,    // reset progress on removed aura
    CRITERIA_CONDITION_UNK8                 = 8,
    CRITERIA_CONDITION_NO_SPELL_HIT         = 9,    // requires the player not to be hit by specific spell
    CRITERIA_CONDITION_NOT_IN_GROUP         = 10,   // requires the player not to be in group
    CRITERIA_CONDITION_NO_LOSE_PET_BATTLE   = 11,   // only used in "Win 10 consecutive pet battles."
    CRITERIA_CONDITION_UNK13                = 13    // unk
};

enum CriteriaAdditionalCondition
{
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_DRUNK_VALUE          = 1,
    CRITERIA_ADDITIONAL_CONDITION_UNK2                        = 2,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_LEVEL                  = 3,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_ENTRY       = 4,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_PLAYER       = 5,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_DEAD         = 6,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_ENEMY        = 7,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_HAS_AURA             = 8,
    CRITERIA_ADDITIONAL_CONDITION_UNK9                        = 9, // NYI current pvp season??
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HAS_AURA             = 10,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MUST_BE_MOUNTED      = 11,
    CRITERIA_ADDITIONAL_CONDITION_UNK12                       = 12,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_MIN            = 14,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_QUALITY_EQUALS         = 15,
    CRITERIA_ADDITIONAL_CONDITION_UNK16                       = 16,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_AREA_OR_ZONE         = 17,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_AREA_OR_ZONE         = 18,
    CRITERIA_ADDITIONAL_CONDITION_ITEM_ENTRY                  = 19,
    CRITERIA_ADDITIONAL_CONDITION_MAP_DIFFICULTY              = 20,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_YIELDS_XP   = 21,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_ARENA_TEAM_SIZE      = 24,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_RACE                 = 25,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_CLASS                = 26,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_RACE                 = 27,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CLASS                = 28,
    CRITERIA_ADDITIONAL_CONDITION_MAX_GROUP_MEMBERS           = 29,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_CREATURE_TYPE        = 30,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_MAP                  = 32,
    CRITERIA_ADDITIONAL_CONDITION_BUILD_VERSION               = 33,
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_LEVEL_IN_SLOT     = 34, // all battlepet level in slot
    CRITERIA_ADDITIONAL_CONDITION_WITHOUT_GROUP               = 35,
    CRITERIA_ADDITIONAL_CONDITION_MIN_PERSONAL_RATING         = 37,
    CRITERIA_ADDITIONAL_CONDITION_TITLE_BIT_INDEX             = 38,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_LEVEL                = 39,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_LEVEL                = 40,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_ZONE                 = 41,
    CRITERIA_ADDITIONAL_CONDITION_SOURCE_NOT_ZONE             = 42,
    CRITERIA_ADDITIONAL_CONDITION_UNK43                       = 43, // NYI
    CRITERIA_ADDITIONAL_CONDITION_UNK44                       = 44, // NYI
    CRITERIA_ADDITIONAL_CONDITION_TARGET_HEALTH_PERCENT_BELOW = 46,
    CRITERIA_ADDITIONAL_CONDITION_UNK55                       = 55,
    CRITERIA_ADDITIONAL_CONDITION_MIN_ACHIEVEMENT_POINTS      = 56,
    CRITERIA_ADDITIONAL_CONDITION_REQUIRES_LFG_GROUP          = 58,
    CRITERIA_ADDITIONAL_CONDITION_BE_THE_LAST_SURVIVOR_5V5    = 60,
    CRITERIA_ADDITIONAL_CONDITION_REQUIRES_GUILD_GROUP        = 61,
    CRITERIA_ADDITIONAL_CONDITION_GUILD_REPUTATION            = 62,
    CRITERIA_ADDITIONAL_CONDITION_RATED_BATTLEGROUND          = 63,
    CRITERIA_ADDITIONAL_CONDITION_PROJECT_RARITY              = 65,
    CRITERIA_ADDITIONAL_CONDITION_PROJECT_RACE                = 66,
    CRITERIA_ADDITIONAL_CONDITION_SPEC_EVENT                  = 67, // While celebrate 10-th wow and etc.
    CRITERIA_ADDITIONAL_CONDITION_DUNGEON_FIFFICULTY          = 68,
    CRITERIA_ADDITIONAL_CONDITION_MIN_LEVEL                   = 69,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MIN_LEVEL            = 70,
    CRITERIA_ADDITIONAL_CONDITION_TARGET_MAX_LEVEL            = 71,
    CRITERIA_ADDITIONAL_CONDITION_UNK73                       = 73, // NYI
    CRITERIA_ADDITIONAL_CONDITION_ACTIVE_SCENARIO             = 74,
    CRITERIA_ADDITIONAL_CONDITION_UNK75                       = 75, // NYI
    CRITERIA_ADDITIONAL_CONDITION_ACHIEV_POINTS               = 76,
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_FEMALY            = 78,
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_HP_LOW_THAT       = 79,
    CRITERIA_ADDITIONAL_CONDITION_COUNT_OF_GUILD_MEMBER_IN_GROUP= 80, // NYI
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_MASTER_PET_TAMER  = 81,
    CRITERIA_ADDITIONAL_CONDITION_UNK82                       = 82, // NYI
    CRITERIA_ADDITIONAL_CONDITION_CHALANGER_RATE              = 83,
    CRITERIA_ADDITIONAL_CONDITION_INCOMPLETE_QUEST            = 84,
    CRITERIA_ADDITIONAL_CONDITION_COMPLETE_ACHIEVEMENT        = 86,
    CRITERIA_ADDITIONAL_CONDITION_NOT_COMPLETE_ACHIEVEMENT    = 87,
    CRITERIA_ADDITIONAL_CONDITION_REPUTATION_UNK              = 88, // NYI reputation???
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_QUALITY           = 89,
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_WIN_IN_PVP        = 90,
    CRITERIA_ADDITIONAL_CONDITION_BATTLEPET_SPECIES           = 91,
    CRITERIA_ADDITIONAL_CONDITION_EXPANSION_LESS              = 92,
    CRITERIA_ADDITIONAL_CONDITION_UNK93                       = 93, // NYI
    CRITERIA_ADDITIONAL_CONDITION_UNK94                       = 94, // NYI
    CRITERIA_ADDITIONAL_CONDITION_REPUTATION                  = 95, // Reputation check
    CRITERIA_ADDITIONAL_CONDITION_ITEM_CLASS_AND_SUBCLASS     = 96,
    CRITERIA_ADDITIONAL_CONDITION_UNK97                       = 97, // NYI may be GO entry???
    CRITERIA_ADDITIONAL_CONDITION_REACH_SKILL_LEVEL           = 99,
    CRITERIA_ADDITIONAL_CONDITION_UNK102                      = 102, // NYI may be zone??
    CRITERIA_ADDITIONAL_CONDITION_NOT_HAVE_ACTIVE_SPELL       = 104,
    CRITERIA_ADDITIONAL_CONDITION_HAS_ITEM_COUNT              = 105,
    CRITERIA_ADDITIONAL_CONDITION_REQ_ADDON                   = 106,
    CRITERIA_ADDITIONAL_CONDITION_START_QUEST                 = 110, // May be completed or in progress?
    CRITERIA_ADDITIONAL_CONDITION_UNK111                      = 111, // NYI may be quest??
    CRITERIA_ADDITIONAL_CONDITION_UNK112                      = 112, // NYI
    CRITERIA_ADDITIONAL_CONDITION_UNK113                      = 113, // NYI
    CRITERIA_ADDITIONAL_CONDITION_ITEM_COUNT                  = 114,
    CRITERIA_ADDITIONAL_CONDITION_UNK116                      = 116, // NYI
    CRITERIA_ADDITIONAL_CONDITION_CURRENCY_COUNT              = 119, // Currency
    CRITERIA_ADDITIONAL_CONDITION_CURRENCY_ON_SEASON          = 121, // Currency on season
    CRITERIA_ADDITIONAL_CONDITION_DEATH_COUNTER               = 122, // Death instance counter
    CRITERIA_ADDITIONAL_CONDITION_UNK123                      = 123, // NYI Bonus Event Weekend
    CRITERIA_ADDITIONAL_CONDITION_UNK124                      = 124, // NYI
    CRITERIA_ADDITIONAL_CONDITION_ARENA_SEASON                = 125, // Arena season check
};

enum AchievementCriteriaFlags
{
    CRITERIA_FLAG_SHOW_PROGRESS_BAR = 0x00000001,         // Show progress as bar
    CRITERIA_FLAG_HIDDEN            = 0x00000002,         // Not show criteria in client
    CRITERIA_FLAG_FAIL_ACHIEVEMENT  = 0x00000004,         // BG related??
    CRITERIA_FLAG_RESET_ON_START    = 0x00000008,         //
    CRITERIA_FLAG_IS_DATE           = 0x00000010,         // not used
    CRITERIA_FLAG_MONEY_COUNTER     = 0x00000020,         // Displays counter as money
    CRITERIA_FLAG_QUEST             = 0x00001000          // For quest
};

enum CriteriaTimedTypes
{
    CRITERIA_TIMED_TYPE_EVENT            = 1,    // Timer is started by internal event with id in timerStartEvent
    CRITERIA_TIMED_TYPE_UNK2             = 2,    // Unknown
    CRITERIA_TIMED_TYPE_SPELL_CASTER     = 5,    // Timer is started by casting a spell with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_SPELL_TARGET     = 6,    // Timer is started by being target of spell with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_CREATURE         = 7,    // Timer is started by killing creature with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_SPELL_TARGET2    = 8,    // Timer is started by being target of spell with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_QUEST            = 9,    // Timer is started by accepting quest with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_CREATURE2        = 10,   // Timer is started by killing creature with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_BATTLEPET        = 11,   // Timer is started by win in battlepet to first lose
    CRITERIA_TIMED_TYPE_ITEM2            = 12,   // Timer is started by using item with entry in timerStartEvent
    CRITERIA_TIMED_TYPE_EVENT2           = 13,   // Timer is started by internal event with id in timerStartEvent
    CRITERIA_TIMED_TYPE_SCENARIO_STAGE   = 14,   // Timer is started by changing stages in a scenario

    CRITERIA_TIMED_TYPE_MAX
};

enum CriteriaTypes
{
    CRITERIA_TYPE_KILL_CREATURE                 = 0,
    CRITERIA_TYPE_WIN_BG                        = 1,
    CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS = 3, // struct { uint32 itemCount; }
    CRITERIA_TYPE_REACH_LEVEL                   = 5,
    CRITERIA_TYPE_REACH_SKILL_LEVEL             = 7,
    CRITERIA_TYPE_COMPLETE_ACHIEVEMENT          = 8,
    CRITERIA_TYPE_COMPLETE_QUEST_COUNT          = 9,
    CRITERIA_TYPE_COMPLETE_DAILY_QUEST_DAILY    = 10, // you have to complete a daily quest x times in a row
    CRITERIA_TYPE_COMPLETE_QUESTS_IN_ZONE       = 11,
    CRITERIA_TYPE_CURRENCY                      = 12,
    CRITERIA_TYPE_DAMAGE_DONE                   = 13,
    CRITERIA_TYPE_COMPLETE_DAILY_QUEST          = 14,
    CRITERIA_TYPE_COMPLETE_BATTLEGROUND         = 15,
    CRITERIA_TYPE_DEATH_AT_MAP                  = 16,
    CRITERIA_TYPE_DEATH                         = 17,
    CRITERIA_TYPE_DEATH_IN_DUNGEON              = 18,
    CRITERIA_TYPE_COMPLETE_RAID                 = 19,
    CRITERIA_TYPE_KILLED_BY_CREATURE            = 20,
    CRITERIA_TYPE_KILLED_BY_PLAYER              = 23,
    CRITERIA_TYPE_FALL_WITHOUT_DYING            = 24,
    CRITERIA_TYPE_DEATHS_FROM                   = 26,
    CRITERIA_TYPE_COMPLETE_QUEST                = 27,
    CRITERIA_TYPE_BE_SPELL_TARGET               = 28,
    CRITERIA_TYPE_CAST_SPELL                    = 29,
    CRITERIA_TYPE_BG_OBJECTIVE_CAPTURE          = 30,
    CRITERIA_TYPE_HONORABLE_KILL_AT_AREA        = 31,
    CRITERIA_TYPE_WIN_ARENA                     = 32,
    CRITERIA_TYPE_PLAY_ARENA                    = 33,
    CRITERIA_TYPE_LEARN_SPELL                   = 34,
    CRITERIA_TYPE_HONORABLE_KILL                = 35,
    CRITERIA_TYPE_OWN_ITEM                      = 36,
    CRITERIA_TYPE_WIN_RATED_ARENA               = 37,
    CRITERIA_TYPE_HIGHEST_TEAM_RATING           = 38,
    CRITERIA_TYPE_HIGHEST_PERSONAL_RATING       = 39,
    CRITERIA_TYPE_LEARN_SKILL_LEVEL             = 40,
    CRITERIA_TYPE_USE_ITEM                      = 41,
    CRITERIA_TYPE_LOOT_ITEM                     = 42,
    CRITERIA_TYPE_EXPLORE_AREA                  = 43,
    CRITERIA_TYPE_OWN_RANK                      = 44,
    CRITERIA_TYPE_BUY_BANK_SLOT                 = 45,
    CRITERIA_TYPE_GAIN_REPUTATION               = 46,
    CRITERIA_TYPE_GAIN_EXALTED_REPUTATION       = 47,
    CRITERIA_TYPE_VISIT_BARBER_SHOP             = 48,
    CRITERIA_TYPE_EQUIP_EPIC_ITEM               = 49,  // TODO: itemlevel is mentioned in text but not present in dbc
    CRITERIA_TYPE_ROLL_NEED_ON_LOOT             = 50,
    CRITERIA_TYPE_ROLL_GREED_ON_LOOT            = 51,
    CRITERIA_TYPE_HK_CLASS                      = 52,
    CRITERIA_TYPE_HK_RACE                       = 53,
    CRITERIA_TYPE_DO_EMOTE                      = 54,
    CRITERIA_TYPE_HEALING_DONE                  = 55,
    CRITERIA_TYPE_GET_KILLING_BLOWS             = 56, // TODO: in some cases map not present, and in some cases need do without die
    CRITERIA_TYPE_EQUIP_ITEM                    = 57,
    CRITERIA_TYPE_MONEY_FROM_VENDORS            = 59,
    CRITERIA_TYPE_GOLD_SPENT_FOR_TALENTS        = 60,
    CRITERIA_TYPE_NUMBER_OF_TALENT_RESETS       = 61,
    CRITERIA_TYPE_MONEY_FROM_QUEST_REWARD       = 62,
    CRITERIA_TYPE_GOLD_SPENT_FOR_TRAVELLING     = 63,
    CRITERIA_TYPE_GOLD_SPENT_AT_BARBER          = 65,
    CRITERIA_TYPE_GOLD_SPENT_FOR_MAIL           = 66,
    CRITERIA_TYPE_LOOT_MONEY                    = 67,
    CRITERIA_TYPE_USE_GAMEOBJECT                = 68,
    CRITERIA_TYPE_BE_SPELL_TARGET2              = 69,
    CRITERIA_TYPE_SPECIAL_PVP_KILL              = 70,
    CRITERIA_TYPE_INSTANSE_MAP_ID               = 71,
    CRITERIA_TYPE_FISH_IN_GAMEOBJECT            = 72,
    CRITERIA_TYPE_SCRIPT_EVENT                  = 73,  // should be thrown by scripts
    CRITERIA_TYPE_EARNED_PVP_TITLE              = 74, // TODO: title id is not mentioned in dbc
    CRITERIA_TYPE_LEARN_SKILLLINE_SPELLS        = 75,
    CRITERIA_TYPE_WIN_DUEL                      = 76,
    CRITERIA_TYPE_LOSE_DUEL                     = 77,
    CRITERIA_TYPE_KILL_CREATURE_TYPE            = 78,  // TODO: creature type (demon, undead etc.) is not stored in dbc
    CRITERIA_TYPE_GOLD_EARNED_BY_AUCTIONS       = 80,
    CRITERIA_TYPE_CREATE_AUCTION                = 82,
    CRITERIA_TYPE_HIGHEST_AUCTION_BID           = 83,
    CRITERIA_TYPE_WON_AUCTIONS                  = 84,
    CRITERIA_TYPE_HIGHEST_AUCTION_SOLD          = 85,
    CRITERIA_TYPE_HIGHEST_GOLD_VALUE_OWNED      = 86,
    CRITERIA_TYPE_GAIN_REVERED_REPUTATION       = 87,
    CRITERIA_TYPE_GAIN_HONORED_REPUTATION       = 88,
    CRITERIA_TYPE_KNOWN_FACTIONS                = 89,
    CRITERIA_TYPE_LOOT_EPIC_ITEM                = 90,
    CRITERIA_TYPE_RECEIVE_EPIC_ITEM             = 91,
    CRITERIA_TYPE_SCRIPT_EVENT_2                = 92,  // should be thrown by scripts
    CRITERIA_TYPE_ROLL_NEED                     = 93,
    CRITERIA_TYPE_ROLL_GREED                    = 94,
    CRITERIA_TYPE_ADD_BATTLE_PET_JOURNAL        = 96,
    CRITERIA_TYPE_HIGHEST_HIT_DEALT             = 101,
    CRITERIA_TYPE_HIGHEST_HIT_RECEIVED          = 102,
    CRITERIA_TYPE_TOTAL_DAMAGE_RECEIVED         = 103,
    CRITERIA_TYPE_HIGHEST_HEAL_CASTED           = 104,
    CRITERIA_TYPE_TOTAL_HEALING_RECEIVED        = 105,
    CRITERIA_TYPE_HIGHEST_HEALING_RECEIVED      = 106,
    CRITERIA_TYPE_QUEST_ABANDONED               = 107,
    CRITERIA_TYPE_FLIGHT_PATHS_TAKEN            = 108,
    CRITERIA_TYPE_LOOT_TYPE                     = 109,
    CRITERIA_TYPE_CAST_SPELL2                   = 110,  // TODO: target entry is missing
    CRITERIA_TYPE_LEARN_SKILL_LINE              = 112,
    CRITERIA_TYPE_EARN_HONORABLE_KILL           = 113,
    CRITERIA_TYPE_ACCEPTED_SUMMONINGS           = 114,
    CRITERIA_TYPE_EARN_ACHIEVEMENT_POINTS       = 115,
    CRITERIA_TYPE_COMPLETED_LFG_DUNGEONS        = 118, // Number of times the player completed an LFG dungeon
    CRITERIA_TYPE_USE_LFD_TO_GROUP_WITH_PLAYERS = 119,
    CRITERIA_TYPE_INITIATED_KICK_IN_LFG         = 120, // Number of times the player kicked someone in LFG, initiating the kick
    CRITERIA_TYPE_VOTED_KICK_IN_LFG             = 121, // Number of times the player kicked someone in LFG, voting, but not initiating
    CRITERIA_TYPE_BEING_KICKED_IN_LFG           = 122, // Number of times the player has been kicked by someone in LFG
    CRITERIA_TYPE_ABANDONED_LFG_DUNGEONS        = 123, // Number of times the player abandoned an LFG dungeon
    CRITERIA_TYPE_SPENT_GOLD_GUILD_REPAIRS      = 124,
    CRITERIA_TYPE_REACH_GUILD_LEVEL             = 125,
    CRITERIA_TYPE_CRAFT_ITEMS_GUILD             = 126,
    CRITERIA_TYPE_CATCH_FROM_POOL               = 127,
    CRITERIA_TYPE_BUY_GUILD_BANK_SLOTS          = 128,
    CRITERIA_TYPE_EARN_GUILD_ACHIEVEMENT_POINTS = 129,
    CRITERIA_TYPE_WIN_RATED_BATTLEGROUND        = 130,
    CRITERIA_TYPE_REACH_RBG_RATING              = 132,
    CRITERIA_TYPE_BUY_GUILD_EMBLEM              = 133,
    CRITERIA_TYPE_COMPLETE_QUESTS_GUILD         = 134,
    CRITERIA_TYPE_HONORABLE_KILLS_GUILD         = 135,
    CRITERIA_TYPE_KILL_CREATURE_TYPE_GUILD      = 136,
    CRITERIA_TYPE_UNK137                        = 137, // Number of times the player joined an LFG dungeon with a tank that leaves early
    CRITERIA_TYPE_COMPLETE_GUILD_DUNGEON_CHALLENGES = 138, //struct { Flag flag; uint32 count; } 1: Guild Dungeon, 2:Guild Challenge, 3:Guild battlefield
    CRITERIA_TYPE_COMPLETE_GUILD_CHALLENGES     = 139, //struct { uint32 count; } Guild Challenge
    CRITERIA_TYPE_UNK140                        = 140, //criteria found but achive not found
    CRITERIA_TYPE_UNK141                        = 141, //criteria found but achive not found
    CRITERIA_TYPE_UNK142                        = 142, //criteria found but achive not found
    CRITERIA_TYPE_UNK143                        = 143, //criteria found but achive not found
    CRITERIA_TYPE_UNK144                        = 144,
    CRITERIA_TYPE_COMPLETED_LFR_DUNGEONS        = 145, // Number of times the player completed an LFR dungeon
    CRITERIA_TYPE_ABANDONED_LFR_DUNGEONS        = 146, // Number of times the player abandoned an LFR dungeon
    CRITERIA_TYPE_INITIATED_KICK_IN_LFR         = 147, // Number of times the player kicked someone in LFR, initiating the kick
    CRITERIA_TYPE_VOTED_KICK_IN_LFR             = 148, // Number of times the player kicked someone in LFR voting, but not initiating
    CRITERIA_TYPE_BEING_KICKED_IN_LFR           = 149, // Number of times the player has been kicked by someone in LFR
    CRITERIA_TYPE_COUNT_OF_LFR_QUEUE_BOOSTS_BY_TANK = 150,
    CRITERIA_TYPE_COMPLETE_SCENARIO_COUNT       = 151,
    CRITERIA_TYPE_COMPLETE_SCENARIO             = 152,
    CRITERIA_TYPE_REACH_SCENARIO_BOSS           = 153,
    CRITERIA_TYPE_UNK154                        = 154, //not found in dbc tree
    CRITERIA_TYPE_OBTAIN_BATTLEPET              = 155,
    CRITERIA_TYPE_COLLECT_BATTLEPET             = 156,
    CRITERIA_TYPE_CAPTURE_PET_IN_BATTLE         = 157,
    CRITERIA_TYPE_BATTLEPET_WIN                 = 158,
    CRITERIA_TYPE_UNK159                        = 159,
    CRITERIA_TYPE_BATTLEPET_LEVEL_UP            = 160,
    CRITERIA_TYPE_CAPTURE_BATTLE_PET_CREDIT     = 161,
    CRITERIA_TYPE_LEVEL_BATTLE_PET_CREDIT       = 162,

    CRITERIA_TYPE_TOTAL
};

enum CriteriaTreeFlags : uint16
{
    CRITERIA_TREE_FLAG_PROGRESS_BAR         = 0x0001,
    CRITERIA_TREE_FLAG_PROGRESS_IS_DATE     = 0x0004,
    CRITERIA_TREE_FLAG_SHOW_CURRENCY_ICON   = 0x0008,
    CRITERIA_TREE_FLAG_ALLIANCE_ONLY        = 0x0200,
    CRITERIA_TREE_FLAG_HORDE_ONLY           = 0x0400,
    CRITERIA_TREE_FLAG_SHOW_REQUIRED_COUNT  = 0x0800
};

enum CriteriaTreeOperator : uint8
{
    CRITERIA_TREE_OPERATOR_SINGLE                   = 0,
    CRITERIA_TREE_OPERATOR_SINGLE_NOT_COMPLETED     = 1,
    CRITERIA_TREE_OPERATOR_ALL                      = 4,
    CRITERIA_TREE_OPERAROR_SUM_CHILDREN             = 5,
    CRITERIA_TREE_OPERATOR_MAX_CHILD                = 6,
    CRITERIA_TREE_OPERATOR_COUNT_DIRECT_CHILDREN    = 7,
    CRITERIA_TREE_OPERATOR_ANY                      = 8,
    CRITERIA_TREE_OPERATOR_SCENARIO                 = 9,
};

enum ArchaeologyBranches
{
    ARCHAEOLOGY_BRANCH_NONE         = 0,
    ARCHAEOLOGY_BRANCH_DWARF        = 1,
    ARCHAEOLOGY_BRANCH_DRAENEI      = 2,
    ARCHAEOLOGY_BRANCH_FOSSIL       = 3,
    ARCHAEOLOGY_BRANCH_NIGHT_ELF    = 4,
    ARCHAEOLOGY_BRANCH_NERUBIAN     = 5,
    ARCHAEOLOGY_BRANCH_ORC          = 6,
    ARCHAEOLOGY_BRANCH_TOLVIR       = 7,
    ARCHAEOLOGY_BRANCH_TROLL        = 8,
    ARCHAEOLOGY_BRANCH_VRYKUL       = 27,
    ARCHAEOLOGY_BRANCH_MANTID       = 29,
    ARCHAEOLOGY_BRANCH_PANDAREN     = 229,
    ARCHAEOLOGY_BRANCH_MOGU         = 231,
    ARCHAEOLOGY_BRANCH_UNUSED       = 315,
};

enum AreaFlags
{
    AREA_FLAG_SNOW                  = 0x00000001,                // snow (only Dun Morogh, Naxxramas, Razorfen Downs and Winterspring)
    AREA_FLAG_UNK1                  = 0x00000002,                // Razorfen Downs, Naxxramas and Acherus: The Ebon Hold (3.3.5a)
    AREA_FLAG_UNK2                  = 0x00000004,                // Only used for areas on map 571 (development before)
    AREA_FLAG_SLAVE_CAPITAL         = 0x00000008,                // city and city subsones
    AREA_FLAG_UNK3                  = 0x00000010,                // can't find common meaning
    AREA_FLAG_SLAVE_CAPITAL2        = 0x00000020,                // slave capital city flag?
    AREA_FLAG_ALLOW_DUELS           = 0x00000040,                // allow to duel here
    AREA_FLAG_ARENA                 = 0x00000080,                // arena, both instanced and world arenas
    AREA_FLAG_CAPITAL               = 0x00000100,                // main capital city flag
    AREA_FLAG_CITY                  = 0x00000200,                // only for one zone named "City" (where it located?)
    AREA_FLAG_OUTLAND               = 0x00000400,                // expansion zones? (only Eye of the Storm not have this flag, but have 0x00004000 flag)
    AREA_FLAG_SANCTUARY             = 0x00000800,                // sanctuary area (PvP disabled)
    AREA_FLAG_NEED_FLY              = 0x00001000,                // Respawn alive at the graveyard without corpse
    AREA_FLAG_UNUSED1               = 0x00002000,                // Unused in 3.3.5a
    AREA_FLAG_OUTLAND2              = 0x00004000,                // expansion zones? (only Circle of Blood Arena not have this flag, but have 0x00000400 flag)
    AREA_FLAG_OUTDOOR_PVP           = 0x00008000,                // pvp objective area? (Death's Door also has this flag although it's no pvp object area)
    AREA_FLAG_ARENA_INSTANCE        = 0x00010000,                // used by instanced arenas only
    AREA_FLAG_UNUSED2               = 0x00020000,                // Unused in 3.3.5a
    AREA_FLAG_CONTESTED_AREA        = 0x00040000,                // On PvP servers these areas are considered contested, even though the zone it is contained in is a Horde/Alliance territory.
    AREA_FLAG_UNK6                  = 0x00080000,                // Valgarde and Acherus: The Ebon Hold
    AREA_FLAG_LOWLEVEL              = 0x00100000,                // used for some starting areas with area_level <= 15
    AREA_FLAG_TOWN                  = 0x00200000,                // small towns with Inn
    AREA_FLAG_REST_ZONE_HORDE       = 0x00400000,                // Warsong Hold, Acherus: The Ebon Hold, New Agamand Inn, Vengeance Landing Inn, Sunreaver Pavilion (Something to do with team?)
    AREA_FLAG_REST_ZONE_ALLIANCE    = 0x00800000,                // Valgarde, Acherus: The Ebon Hold, Westguard Inn, Silver Covenant Pavilion (Something to do with team?)
    AREA_FLAG_WINTERGRASP           = 0x01000000,                // Wintergrasp and it's subzones
    AREA_FLAG_INSIDE                = 0x02000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_OUTSIDE               = 0x04000000,                // used for determinating spell related inside/outside questions in Map::IsOutdoors
    AREA_FLAG_WINTERGRASP_2         = 0x08000000,                // Can Hearth And Resurrect From Area
    AREA_FLAG_NO_FLY_ZONE           = 0x20000000,                // Marks zones where you cannot fly
    AREA_FLAG_UNK9                  = 0x40000000
};

enum DifficultyFlag
{
    DIFFICULTY_FLAG_HEROIC          = 0x01,
    DIFFICULTY_FLAG_DEFAULT         = 0x02,
    DIFFICULTY_FLAG_CAN_SELECT      = 0x04, // Player can select this difficulty in dropdown menu
    DIFFICULTY_FLAG_CHALLENGE_MODE  = 0x8,
};

enum Difficulty
{
    NONE_DIFFICULTY              = 0,                       // entry
    REGULAR_DIFFICULTY           = 1,                       // entry 
    HEROIC_DIFFICULTY            = 2,                       // difficulty_entry_2 new difficulty_entry_1
    MAN10_DIFFICULTY             = 3,                       // entry
    MAN25_DIFFICULTY             = 4,                       // difficulty_entry_4 new difficulty_entry_1
    MAN10_HEROIC_DIFFICULTY      = 5,                       // difficulty_entry_5 new difficulty_entry_2
    MAN25_HEROIC_DIFFICULTY      = 6,                       // difficulty_entry_6 new difficulty_entry_3
    RAID_TOOL_DIFFICULTY         = 7,                       // difficulty_entry_7 new difficulty_entry_4
    CHALLENGE_MODE_DIFFICULTY    = 8,                       // difficulty_entry_8 new difficulty_entry_4
    MAN40_DIFFICULTY             = 9,                       // difficulty_entry_9 new difficulty_entry_4
    HEROIC_SCENARIO_DIFFICULTY   = 11,
    NORMAL_SCENARIO_DIFFICULTY   = 12,
    FLEXIBLE_DIFFICULTY          = 14,
};

#define RAID_DIFFICULTY_MASK_25MAN 4                        // since 25man difficulties are 4 and 6, we can check them like that

#define MAX_DIFFICULTY             FLEXIBLE_DIFFICULTY+1
#define MAX_BOUND                  4

enum ScenarioFlags
{
    SCENARIO_FLAG_CHALLENGE             = 0x1,
    SCENARIO_FLAG_SUPRESS_STAGE_TEXT    = 0x2,
};

enum ScenarioStepFlags
{
    SCENARIO_STEP_FLAG_BONUS_OBJECTIVE  = 0x1,
};

enum SpawnMask
{
    SPAWNMASK_CONTINENT         = (1 << NONE_DIFFICULTY),   // any maps without spawn modes

    SPAWNMASK_DUNGEON_NORMAL    = (1 << REGULAR_DIFFICULTY),
    SPAWNMASK_DUNGEON_HEROIC    = (1 << HEROIC_DIFFICULTY),
    SPAWNMASK_DUNGEON_CHALLENGE = (1 << CHALLENGE_MODE_DIFFICULTY),
    SPAWNMASK_DUNGEON_ALL       = (SPAWNMASK_DUNGEON_NORMAL | SPAWNMASK_DUNGEON_HEROIC | SPAWNMASK_DUNGEON_CHALLENGE),
    
    SPAWNMASK_SCENARIO_NORMAL   = (1 << NORMAL_SCENARIO_DIFFICULTY),
    SPAWNMASK_SCENARIO_HEROIC   = (1 << HEROIC_SCENARIO_DIFFICULTY),
    SPAWNMASK_SCENARIO_ALL      = (SPAWNMASK_SCENARIO_NORMAL | SPAWNMASK_SCENARIO_HEROIC),

    SPAWNMASK_RAID_10MAN_NORMAL = (1 << MAN10_DIFFICULTY),
    SPAWNMASK_RAID_25MAN_NORMAL = (1 << MAN25_DIFFICULTY),
    SPAWNMASK_RAID_40MAN_NORMAL = (1 << MAN40_DIFFICULTY),
    SPAWNMASK_RAID_NORMAL_ALL   = (SPAWNMASK_RAID_10MAN_NORMAL | SPAWNMASK_RAID_25MAN_NORMAL | SPAWNMASK_RAID_40MAN_NORMAL),

    SPAWNMASK_RAID_10MAN_HEROIC = (1 << MAN10_HEROIC_DIFFICULTY),
    SPAWNMASK_RAID_25MAN_HEROIC = (1 << MAN25_HEROIC_DIFFICULTY),
    SPAWNMASK_RAID_HEROIC_ALL   = (SPAWNMASK_RAID_10MAN_HEROIC | SPAWNMASK_RAID_25MAN_HEROIC),

    SPAWNMASK_RAID_RAID_TOOL    = (1 << RAID_TOOL_DIFFICULTY),

    SPAWNMASK_RAID_ALL          = (SPAWNMASK_RAID_NORMAL_ALL | SPAWNMASK_RAID_HEROIC_ALL | SPAWNMASK_RAID_RAID_TOOL)
};

enum FactionTemplateFlags
{
    FACTION_TEMPLATE_FLAG_PVP               = 0x00000800,   // flagged for PvP
    FACTION_TEMPLATE_FLAG_CONTESTED_GUARD   = 0x00001000,   // faction will attack players that were involved in PvP combats
    FACTION_TEMPLATE_FLAG_HOSTILE_BY_DEFAULT= 0x00002000
};

enum FactionMasks
{
    FACTION_MASK_PLAYER   = 1,                              // any player
    FACTION_MASK_ALLIANCE = 2,                              // player or creature from alliance team
    FACTION_MASK_HORDE    = 4,                              // player or creature from horde team
    FACTION_MASK_MONSTER  = 8                               // aggressive creature from monster team
    // if none flags set then non-aggressive creature
};

enum MapTypes                                               // Lua_IsInInstance
{
    MAP_COMMON          = 0,                                // none
    MAP_INSTANCE        = 1,                                // party
    MAP_RAID            = 2,                                // raid
    MAP_BATTLEGROUND    = 3,                                // pvp
    MAP_ARENA           = 4,                                // arena
    MAP_SCENARIO        = 5                                 // scenario
};

enum MapFlags
{
    MAP_FLAG_CAN_CHANGE_DIFFICULTY              = 0x0100,
    MAP_FLAG_POST_BC_RAID_INSTANCE              = 0x8000,
};

enum AbilytyLearnType
{
    ABILITY_LEARNED_ON_GET_PROFESSION_SKILL     = 1,
    ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL  = 2
};

enum ItemEnchantmentType
{
    ITEM_ENCHANTMENT_TYPE_NONE             = 0,
    ITEM_ENCHANTMENT_TYPE_COMBAT_SPELL     = 1,
    ITEM_ENCHANTMENT_TYPE_DAMAGE           = 2,
    ITEM_ENCHANTMENT_TYPE_EQUIP_SPELL      = 3,
    ITEM_ENCHANTMENT_TYPE_RESISTANCE       = 4,
    ITEM_ENCHANTMENT_TYPE_STAT             = 5,
    ITEM_ENCHANTMENT_TYPE_TOTEM            = 6,
    ITEM_ENCHANTMENT_TYPE_USE_SPELL        = 7,
    ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET = 8
};

enum ItemLimitCategoryMode
{
    ITEM_LIMIT_CATEGORY_MODE_HAVE       = 0,                      // limit applied to amount items in inventory/bank
    ITEM_LIMIT_CATEGORY_MODE_EQUIP      = 1                       // limit applied to amount equipped items (including used gems)
};

enum ItemSpecStat
{
    ITEM_SPEC_STAT_INTELLECT        = 0,
    ITEM_SPEC_STAT_AGILITY          = 1,
    ITEM_SPEC_STAT_STRENGTH         = 2,
    ITEM_SPEC_STAT_SPIRIT           = 3,
    ITEM_SPEC_STAT_HIT              = 4,
    ITEM_SPEC_STAT_DODGE            = 5,
    ITEM_SPEC_STAT_PARRY            = 6,
    ITEM_SPEC_STAT_ONE_HANDED_AXE   = 7,
    ITEM_SPEC_STAT_TWO_HANDED_AXE   = 8,
    ITEM_SPEC_STAT_ONE_HANDED_SWORD = 9,
    ITEM_SPEC_STAT_TWO_HANDED_SWORD = 10,
    ITEM_SPEC_STAT_ONE_HANDED_MACE  = 11,
    ITEM_SPEC_STAT_TWO_HANDED_MACE  = 12,
    ITEM_SPEC_STAT_DAGGER           = 13,
    ITEM_SPEC_STAT_FIST_WEAPON      = 14,
    ITEM_SPEC_STAT_GUN              = 15,
    ITEM_SPEC_STAT_BOW              = 16,
    ITEM_SPEC_STAT_CROSSBOW         = 17,
    ITEM_SPEC_STAT_STAFF            = 18,
    ITEM_SPEC_STAT_POLEARM          = 19,
    ITEM_SPEC_STAT_THROWN           = 20,
    ITEM_SPEC_STAT_WAND             = 21,
    ITEM_SPEC_STAT_SHIELD           = 22,
    ITEM_SPEC_STAT_RELIC            = 23,
    ITEM_SPEC_STAT_CRIT             = 24,
    ITEM_SPEC_STAT_HASTE            = 25,
    ITEM_SPEC_STAT_BONUS_ARMOR      = 26,
    ITEM_SPEC_STAT_CLOAK            = 27,

    ITEM_SPEC_STAT_NONE             = 28
};

enum LfgFlags
{
    LFG_FLAG_SEASONAL                            = 0x0004,
    LFG_FLAG_USER_TELEPORT_NOT_ALLOWED           = 0x0800,
    LFG_FLAG_NON_BACKFILLABLE                    = 0x1000,
};

enum LfgSubType
{
    LFG_SUBTYPE_NONE                             = 0,
    LFG_SUBTYPE_DUNGEON                          = 1,
    LFG_SUBTYPE_RAID                             = 2,
    LFG_SUBTYPE_SCENARIO                         = 3,
    LFG_SUBTYPE_FLEX                             = 4,
};

enum LfgType
{
    LFG_TYPE_NONE                                = 0,       // Internal use only
    LFG_TYPE_DUNGEON                             = 1,
    LFG_TYPE_RAID                                = 2,
    LFG_TYPE_QUEST                               = 3,       // not exist in dbc
    LFG_TYPE_ZONE                                = 4,
    LFG_TYPE_HEROIC                              = 5,       // not exist in dbc
    LFG_TYPE_RANDOM                              = 6,
    LFG_TYPE_SCENARIO                            = 7,       // not exist in dbc
};

enum MountFlags
{
    MOUNT_FLAG_CAN_PITCH                = 0x4,                    // client checks MOVEMENTFLAG2_FULL_SPEED_PITCHING
    MOUNT_FLAG_CAN_SWIM                 = 0x8                     // client checks MOVEMENTFLAG_SWIMMING
};

enum TotemCategoryType
{
    TOTEM_CATEGORY_TYPE_KNIFE           = 1,
    TOTEM_CATEGORY_TYPE_TOTEM           = 2,
    TOTEM_CATEGORY_TYPE_ROD             = 3,
    TOTEM_CATEGORY_TYPE_PICK            = 21,
    TOTEM_CATEGORY_TYPE_STONE           = 22,
    TOTEM_CATEGORY_TYPE_HAMMER          = 23,
    TOTEM_CATEGORY_TYPE_SPANNER         = 24
};

// SummonProperties.dbc, col 1
enum SummonPropGroup
{
    SUMMON_PROP_GROUP_UNKNOWN1       = 0,                   // 1160 spells in 3.0.3
    SUMMON_PROP_GROUP_UNKNOWN2       = 1,                   // 861 spells in 3.0.3
    SUMMON_PROP_GROUP_PETS           = 2,                   // 52 spells in 3.0.3, pets mostly
    SUMMON_PROP_GROUP_CONTROLLABLE   = 3,                   // 13 spells in 3.0.3, mostly controllable
    SUMMON_PROP_GROUP_UNKNOWN3       = 4                    // 86 spells in 3.0.3, taxi/mounts
};

// SummonProperties.dbc, col 3
enum SummonPropType
{
    SUMMON_PROP_TYPE_UNKNOWN         = 0,                   // different summons, 1330 spells in 3.0.3
    SUMMON_PROP_TYPE_SUMMON          = 1,                   // generic summons, 49 spells in 3.0.3
    SUMMON_PROP_TYPE_GUARDIAN        = 2,                   // summon guardian, 393 spells in 3.0.3
    SUMMON_PROP_TYPE_ARMY            = 3,                   // summon army, 5 spells in 3.0.3
    SUMMON_PROP_TYPE_TOTEM           = 4,                   // summon totem, 169 spells in 3.0.3
    SUMMON_PROP_TYPE_CRITTER         = 5,                   // critter/minipet, 195 spells in 3.0.3
    SUMMON_PROP_TYPE_DK              = 6,                   // summon DRW/Ghoul, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_BOMB            = 7,                   // summon bot/bomb, 4 spells in 3.0.3
    SUMMON_PROP_TYPE_PHASING         = 8,                   // something todo with DK prequest line, 2 spells in 3.0.3
    SUMMON_PROP_TYPE_SIEGE_VEH       = 9,                   // summon different vehicles, 14 spells in 3.0.3
    SUMMON_PROP_TYPE_DRAKE_VEH       = 10,                  // summon drake (vehicle), 3 spells
    SUMMON_PROP_TYPE_LIGHTWELL       = 11,                  // summon lightwell, 6 spells in 3.0.3
    SUMMON_PROP_TYPE_JEEVES          = 12,                  // summon Jeeves, 1 spell in 3.3.5a
    SUMMON_PROP_TYPE_LASHTAIL        = 13,                  // Lashtail Hatchling, 1 spell in 4.2.2
    SUMMON_PROP_TYPE_GATE            = 14,                  // summon gate, 2 spells in 5.4.1
    SUMMON_PROP_TYPE_BANNER          = 18                   // summon Banner, 3 spell in 5.4.1
};

// SummonProperties.dbc, col 5
enum SummonPropFlags
{
    SUMMON_PROP_FLAG_NONE            = 0x00000000,          // 1342 spells in 3.0.3
    SUMMON_PROP_FLAG_UNK1            = 0x00000001,          // 75 spells in 3.0.3, something unfriendly
    SUMMON_PROP_FLAG_UNK2            = 0x00000002,          // 616 spells in 3.0.3, something friendly
    SUMMON_PROP_FLAG_UNK3            = 0x00000004,          // 22 spells in 3.0.3, no idea...
    SUMMON_PROP_FLAG_UNK4            = 0x00000008,          // 49 spells in 3.0.3, some mounts
    SUMMON_PROP_FLAG_UNK5            = 0x00000010,          // 25 spells in 3.0.3, quest related?
    SUMMON_PROP_FLAG_UNK6            = 0x00000020,          // 0 spells in 3.3.5, unused
    SUMMON_PROP_FLAG_UNK7            = 0x00000040,          // 12 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK8            = 0x00000080,          // 4 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK9            = 0x00000100,          // 51 spells in 3.0.3, no idea, many quest related
    SUMMON_PROP_FLAG_UNK10           = 0x00000200,          // 51 spells in 3.0.3, something defensive
    SUMMON_PROP_FLAG_UNK11           = 0x00000400,          // 3 spells, requires something near?
    SUMMON_PROP_FLAG_UNK12           = 0x00000800,          // 30 spells in 3.0.3, no idea
    SUMMON_PROP_FLAG_UNK13           = 0x00001000,          // Lightwell, Jeeves, Gnomish Alarm-o-bot, Build vehicles(wintergrasp)
    SUMMON_PROP_FLAG_UNK14           = 0x00002000,          // Guides, player follows
    SUMMON_PROP_FLAG_UNK15           = 0x00004000,          // Force of Nature, Shadowfiend, Feral Spirit, Summon Water Elemental
    SUMMON_PROP_FLAG_UNK16           = 0x00008000,          // Light/Dark Bullet, Soul/Fiery Consumption, Twisted Visage, Twilight Whelp. Phase related?
    SUMMON_PROP_FLAG_UNK17           = 0x00010000,
    SUMMON_PROP_FLAG_UNK18           = 0x00020000,
    SUMMON_PROP_FLAG_UNK19           = 0x00040000,
    SUMMON_PROP_FLAG_UNK20           = 0x00080000,
    SUMMON_PROP_FLAG_UNK21           = 0x00100000           // Totems
};

enum VehicleSeatFlags
{
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_ENTER                          = 0x00000001,
    VEHICLE_SEAT_FLAG_HAS_LOWER_ANIM_FOR_RIDE                           = 0x00000002,
    VEHICLE_SEAT_FLAG_UNK1                                              = 0x00000004,
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIM_ON_VOLUNTARY_EXIT   = 0x00000008,
    VEHICLE_SEAT_FLAG_UNK3                                              = 0x00000010,
    VEHICLE_SEAT_FLAG_HIDE_PASSENGER                                    = 0x00000200,           // Passenger is hidden
    VEHICLE_SEAT_FLAG_ALLOW_TURNING                                     = 0x00000400,           // needed for CGCamera__SyncFreeLookFacing
    VEHICLE_SEAT_FLAG_CAN_CONTROL                                       = 0x00000800,           // Lua_UnitInVehicleControlSeat
    VEHICLE_SEAT_FLAG_CAN_CAST_MOUNT_SPELL                              = 0x00001000,           // Can cast spells with SPELL_AURA_MOUNTED from seat (possibly 4.x only, 0 seats on 3.3.5a)
    VEHICLE_SEAT_FLAG_UNCONTROLLED                                      = 0x00002000,           // can override !& VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT
    VEHICLE_SEAT_FLAG_CAN_ATTACK                                        = 0x00004000,           // Can attack, cast spells and use items from vehicle
    VEHICLE_SEAT_FLAG_SHOULD_USE_VEH_SEAT_EXIT_ANIMN_ON_FORCED_EXIT     = 0x00008000,
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_VOLUNTARY_EXIT                  = 0x00040000,
    VEHICLE_SEAT_FLAG_HAS_VEH_EXIT_ANIM_FORCED_EXIT                     = 0x00080000,
    VEHICLE_SEAT_FLAG_REC_HAS_VEHICLE_ENTER_ANIM                        = 0x00400000,
    VEHICLE_SEAT_FLAG_ENABLE_VEHICLE_ZOOM                               = 0x01000000,
    VEHICLE_SEAT_FLAG_CAN_ENTER_OR_EXIT                                 = 0x02000000,           // Lua_CanExitVehicle - can enter and exit at free will
    VEHICLE_SEAT_FLAG_CAN_SWITCH                                        = 0x04000000,           // Lua_CanSwitchVehicleSeats
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_ENTER  = 0x08000000,
    VEHICLE_SEAT_FLAG_HAS_START_WARITING_FOR_VEH_TRANSITION_ANIM_EXIT   = 0x10000000,
    VEHICLE_SEAT_FLAG_CAN_CAST                                          = 0x20000000,           // Lua_UnitHasVehicleUI
    VEHICLE_SEAT_FLAG_UNK2                                              = 0x40000000,           // checked in conjunction with 0x800 in CastSpell2
    VEHICLE_SEAT_FLAG_DISALLOWS_INTERACTION                             = 0x80000000
};

enum VehicleSeatFlagsB
{
    VEHICLE_SEAT_FLAG_B_NONE                     = 0x00000000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED            = 0x00000002,
    VEHICLE_SEAT_FLAG_B_TARGETS_IN_RAIDUI        = 0x00000008,           // Lua_UnitTargetsVehicleInRaidUI
    VEHICLE_SEAT_FLAG_B_EJECTABLE                = 0x00000020,           // ejectable
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_2          = 0x00000040,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_3          = 0x00000100,
    VEHICLE_SEAT_FLAG_B_KEEP_PET                 = 0x00020000,
    VEHICLE_SEAT_FLAG_B_USABLE_FORCED_4          = 0x02000000,
    VEHICLE_SEAT_FLAG_B_CAN_SWITCH               = 0x04000000,
    VEHICLE_SEAT_FLAG_B_VEHICLE_PLAYERFRAME_UI   = 0x80000000            // Lua_UnitHasVehiclePlayerFrameUI - actually checked for flagsb &~ 0x80000000
};

// CurrencyTypes.dbc
enum CurrencyTypes
{
    CURRENCY_NONE                           = 0,
    CURRENCY_TYPE_DALARAN_JEWEL             = 61,  // Jewelcrafting token WoTLK
    CURRENCY_TYPE_EPICUREAN                 = 81,  // Cook token WoTLK
    CURRENCY_TYPE_CHAMPION_SEAL             = 241, // Argent tournament token
    CURRENCY_TYPE_ILLUSTROUS_JEWEL          = 361, // Jewelcrafting token Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_DWARF         = 384, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_TROLL         = 385, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_CONQUEST_POINTS           = 390, // PvP
    CURRENCY_TYPE_TOL_BARAD                 = 391, // Battleground Cataclysm 
    CURRENCY_TYPE_HONOR_POINTS              = 392, // PvP
    CURRENCY_TYPE_ARCHAEOLOGY_FOSSIL        = 393, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_NIGHT_ELF     = 394, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_JUSTICE_POINTS            = 395, // PvE
    CURRENCY_TYPE_VALOR_POINTS              = 396, // PvE
    CURRENCY_TYPE_ARCHAEOLOGY_ORC           = 397, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_DRAENEI       = 398, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_VRYKUL        = 399, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_NERUBIAN      = 400, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_ARCHAEOLOGY_TOLVIR        = 401, // ARCHAEOLOGY Cataclysm
    CURRENCY_TYPE_IRONPAW                   = 402, // Cook token MoP
    CURRENCY_TYPE_WORLD_TREE                = 416, // 4.2 token Molten front
    CURRENCY_TYPE_CONQUEST_META_ARENA       = 483, // PvP
    CURRENCY_TYPE_CONQUEST_META_RATED_BG    = 484, // PvP
    CURRENCY_TYPE_DARKMOON_TICKET           = 515, // Darkmoon fair
    CURRENCY_TYPE_MOTE_OF_DARKNESS          = 614, // 4.3.4 token Dragon soul
    CURRENCY_TYPE_CORRUPTED_ESSENCE         = 615, // 4.3.4 Deathwing token
    CURRENCY_TYPE_ARCHAEOLOGY_PANDAREN      = 676, // ARCHAEOLOGY MoP
    CURRENCY_TYPE_ARCHAEOLOGY_MOGU          = 677, // ARCHAEOLOGY MoP
    CURRENCY_TYPE_CONQUEST_META_RANDOM_BG   = 692, //
    CURRENCY_TYPE_ELDER_CHARM_GOOD_FORTUNE  = 697, // LFR roll chance MoP
    CURRENCY_TYPE_ZEN_JEWEL                 = 698, // Jewelcrafting token MoP NYI
    CURRENCY_TYPE_ARCHAEOLOGY_MANTID        = 754,
};

#define CURRENCY_PRECISION 100.0f

enum CurrencyCategory
{
    CURRENCY_CATEGORY_ARCHAEOLOGY   = 82,
    CURRENCY_CATEGORY_META_CONQUEST = 89,
};

enum CurrencyFlags
{
    CURRENCY_FLAG_TRADEABLE         = 0x0001,
    CURRENCY_FLAG_HAS_PRECISION     = 0x0008,
    CURRENCY_FLAG_HAS_SEASON_COUNT  = 0x0080,
    CURRENCY_FLAG_UNK               = 0x2000,
};

#endif
