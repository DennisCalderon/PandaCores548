/*
* Copyright (C) 2008-2016 UwowCore <http://uwow.biz/>
*/

#include "RedisBuilderMgr.h"
#include <time.h>

RedisBuilderMgr::RedisBuilderMgr()
{
}

RedisBuilderMgr::~RedisBuilderMgr()
{
}

std::string RedisBuilderMgr::BuildString(Json::Value& data)
{
    return Builder.write(data);
}

bool RedisBuilderMgr::LoadFromRedis(const RedisValue* v, Json::Value& data)
{
    if (!v->isOk() || v->isNull() || !v->isString())
    {
        sLog->outInfo(LOG_FILTER_REDIS, "RedisBuilderMgr::DeSerialization data is empty");
        return false;
    }

    bool isReader = Reader.parse(v->toString().c_str(), data);
    if (!isReader)
    {
        sLog->outInfo(LOG_FILTER_REDIS, "RedisBuilderMgr::DeSerialization parce json false");
        return false;
    }

    return true;
}

bool RedisBuilderMgr::LoadFromRedisArray(const RedisValue* v, std::vector<RedisValue>& data)
{
    if (!v->isOk() || v->isNull())
    {
        sLog->outInfo(LOG_FILTER_REDIS, "RedisBuilderMgr::LoadFromRedisArray data is empty");
        return false;
    }

    if (!v->isArray())
    {
        sLog->outInfo(LOG_FILTER_REDIS, "RedisBuilderMgr::LoadFromRedisArray is not array");
        return false;
    }

    data = v->toArray();

    return true;
}

bool RedisBuilderMgr::CheckKey(char* _key)
{
    RedisValue v = RedisDatabase.Execute("EXISTS", _key);
    if (!v.isOk() || v.isNull())
    {
        sLog->outInfo(LOG_FILTER_REDIS, "RedisBuilderMgr::CheckKey data not found %s", _key);
        return false;
    }

    if (!v.toInt())
    {
        sLog->outInfo(LOG_FILTER_REDIS, "RedisBuilderMgr::CheckKey key not exist %s", _key);
        return false;
    }

    return true;
}

void RedisBuilderMgr::InitRedisKey()
{
    queryGuidKey = new char[18];
    petKey = new char[18];
    bracketKey = new char[18];
    aucItemKey = new char[18];
    aucKey = new char[18];
    guildKey = new char[18];
    guildFKey = new char[15];
    guildFMKey = new char[20];
    groupKey = new char[12];
    groupMemberKey = new char[20];
    groupInstanceKey = new char[18];
    challengeKey = new char[18];
    ticketKey = new char[18];
    mailsKey = new char[18];

    sprintf(queryGuidKey, "r{%u}HIGHESTGUIDS", realmID);
    sprintf(petKey, "r{%u}pets", realmID);
    sprintf(bracketKey, "r{%u}bracket", realmID);
    sprintf(aucItemKey, "r{%i}auc{%i}items", realmID, 0);
    sprintf(aucKey, "r{%i}auc", realmID);
    sprintf(guildFKey, "r{%u}finder", realmID);
    sprintf(guildFMKey, "r{%u}findermember", realmID);
    sprintf(groupKey, "r{%i}group", realmID);
    sprintf(groupMemberKey, "r{%i}groupmember", realmID);
    sprintf(groupInstanceKey, "r{%i}instance", realmID);
    sprintf(challengeKey, "r{%i}challenge", realmID);
    sprintf(ticketKey, "r{%i}ticket", realmID);
    sprintf(mailsKey, "r{%i}mails", realmID);
}

void PlayerSave::SaveToDB()
{
    SaveItem();

    SQLTransaction trans = CharacterDatabase.BeginTransaction();

    std::string guid = std::to_string(m_player->GetGUIDLow());
    uint8 index = 0;
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_CHARACTER_JSON);
    stmt->setUInt32(index++, m_player->GetGUIDLow());
    stmt->setUInt32(index++, m_player->GetSession()->GetAccountId());
    stmt->setString(index++, m_player->GetName());
    stmt->setUInt8(index++, m_player->GetSession()->EnumData[guid.c_str()]["slot"].asInt());
    stmt->setUInt8(index++, m_player->getRace());
    stmt->setUInt8(index++, m_player->getClass());
    stmt->setUInt8(index++, m_player->getGender());
    stmt->setUInt8(index++, m_player->getLevel());
    stmt->setUInt32(index++, m_player->GetUInt32Value(PLAYER_XP));
    stmt->setUInt64(index++, m_player->GetMoney());
    stmt->setUInt32(index++, m_player->GetUInt32Value(PLAYER_BYTES));
    stmt->setUInt32(index++, m_player->GetUInt32Value(PLAYER_BYTES_2));
    stmt->setUInt32(index++, m_player->GetUInt32Value(PLAYER_FLAGS));
    stmt->setUInt16(index++, (uint16)m_player->GetMapId());
    stmt->setFloat(index++, finiteAlways(m_player->GetPositionX()));
    stmt->setFloat(index++, finiteAlways(m_player->GetPositionY()));
    stmt->setFloat(index++, finiteAlways(m_player->GetPositionZ()));
    stmt->setUInt32(index++, m_player->m_Played_time[PLAYED_TIME_TOTAL]);
    stmt->setUInt32(index++, m_player->m_Played_time[PLAYED_TIME_LEVEL]);
    stmt->setUInt32(index++, uint32(time(NULL)));
    stmt->setUInt16(index++, (uint16)m_player->GetAtLoginFlag());
    stmt->setUInt16(index++, m_player->getCurrentUpdateZoneID());
    stmt->setUInt32(index++, m_player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
    std::ostringstream ss;
    // cache equipment...
    for (uint32 i = 0; i < EQUIPMENT_SLOT_END * 2; ++i)
        ss << m_player->GetUInt32Value(PLAYER_VISIBLE_ITEM_1_ENTRYID + i) << ' ';

    // ...and bags for enum opcode
    for (uint32 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Item* item = m_player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
            ss << item->GetEntry();
        else
            ss << '0';
        ss << " 0 ";
    }
    stmt->setString(index++, ss.str());
    stmt->setString(index++, sRedisBuilderMgr->BuildString(m_player->PlayerData));
    stmt->setString(index++, sRedisBuilderMgr->BuildString(m_player->PlayerMailData));
    trans->Append(stmt);

    index = 0;
    stmt = CharacterDatabase.GetPreparedStatement(CHAR_REP_ACCOUNT_JSON);
    stmt->setUInt32(index++, m_player->GetSession()->GetAccountId());
    stmt->setString(index++, sRedisBuilderMgr->BuildString(m_player->AccountDatas));
    trans->Append(stmt);

    CharacterDatabase.CommitTransaction(trans);
}

void PlayerSave::SaveItem()
{
    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; i++)
    {
        if (Item* pItem = m_player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            std::string guid = std::to_string(pItem->GetGUIDLow());
            m_player->PlayerData["items"][guid.c_str()] = pItem->ItemData;
        }
    }

    for (uint8 i = INVENTORY_SLOT_BAG_START; i < INVENTORY_SLOT_BAG_END; ++i)
    {
        if (Bag* pBag = m_player->GetBagByPos(i))
        {
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
            {
                if (Item* pItem = m_player->GetItemByPos(i, j))
                {
                    std::string guid = std::to_string(pItem->GetGUIDLow());
                    m_player->PlayerData["items"][guid.c_str()] = pItem->ItemData;
                }
            }
        }
    }

    for (uint8 i = EQUIPMENT_SLOT_START; i < INVENTORY_SLOT_ITEM_END; ++i)
        if (Item* pItem = m_player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            std::string guid = std::to_string(pItem->GetGUIDLow());
            m_player->PlayerData["items"][guid.c_str()] = pItem->ItemData;
        }

    // checking every item from 39 to 74 (including bank bags)
    for (uint8 i = BANK_SLOT_ITEM_START; i < BANK_SLOT_BAG_END; ++i)
        if (Item* pItem = m_player->GetItemByPos(INVENTORY_SLOT_BAG_0, i))
        {
            std::string guid = std::to_string(pItem->GetGUIDLow());
            m_player->PlayerData["items"][guid.c_str()] = pItem->ItemData;
        }

    for (uint8 i = BANK_SLOT_BAG_START; i < BANK_SLOT_BAG_END; ++i)
        if (Bag* pBag = m_player->GetBagByPos(i))
            for (uint32 j = 0; j < pBag->GetBagSize(); ++j)
                if (Item* pItem = pBag->GetItemByPos(j))
                {
                    std::string guid = std::to_string(pItem->GetGUIDLow());
                    m_player->PlayerData["items"][guid.c_str()] = pItem->ItemData;
                }
}