/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSE1Lua
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSE1Lua
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

#ifndef __ID_ECOSE1LUA_HPP__
#define __ID_ECOSE1LUA_HPP__

#include "IEcoBase1.hpp"
#include "IEcoSE1Lua.hpp"

/* EcoSE1Lua CID = {A42A420F-C14D-4387-9877-877F8E62028C} */
#ifndef __CID_EcoSE1Lua
static const UGUID CID_EcoSE1Lua = {0x01, 0x10, {0xA4, 0x2A, 0x42, 0x0F, 0xC1, 0x4D, 0x43, 0x87, 0x98, 0x77, 0x87, 0x7F, 0x8E, 0x62, 0x02, 0x8C}};
#endif /* __CID_EcoSE1Lua */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern "C" IEcoComponentFactory* GetIEcoComponentFactoryPtr_A42A420FC14D43879877877F8E62028C;
#endif

#endif /* __ID_ECOSE1LUA_HPP__ */
