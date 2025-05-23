/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSE1Lua
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSE1Lua
 * </описание>
 *
 * <ссылка>
 *
 * </ссылка>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __I_ECOSE1LUA_HPP__
#define __I_ECOSE1LUA_HPP__

#include "IEcoBase1.hpp"

/* IEcoSE1Lua IID = {3BBB11F2-75CF-432A-A548-45F3DBFCAAB5} */
#ifndef __IID_IEcoSE1Lua
static const UGUID IID_IEcoSE1Lua = {0x01, 0x10, {0x3B, 0xBB, 0x11, 0xF2, 0x75, 0xCF, 0x43, 0x2A, 0xA5, 0x48, 0x45, 0xF3, 0xDB, 0xFC, 0xAA, 0xB5}};
#endif /* __IID_IEcoSE1Lua */

interface IEcoSE1Lua : public IEcoUnknown {
public:
    /* IEcoSE1Lua */
    virtual int16_t ECOCALLMETHOD MyFunction(/* in */ char_t* Name, /* out */ char_t** CopyName) = 0;

};



#endif /* __I_ECOSE1LUA_HPP__ */
