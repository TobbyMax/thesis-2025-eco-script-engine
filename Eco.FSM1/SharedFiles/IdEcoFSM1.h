/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoFSM1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoFSM1
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

#ifndef __ID_ECO_FINITE_STATE_MACHINE_1_H__
#define __ID_ECO_FINITE_STATE_MACHINE_1_H__

#include "IEcoBase1.h"
#include "IEcoFSM1.h"

/* EcoFSM1 CID = {5E7C610C-B846-447D-B59A-3C5A2C4F446F} */
#ifndef __CID_EcoFSM1
static const UGUID CID_EcoFSM1 = {0x01, 0x10, {0x5E, 0x7C, 0x61, 0x0C, 0xB8, 0x46, 0x44, 0x7D, 0xB5, 0x9A, 0x3C, 0x5A, 0x2C, 0x4F, 0x44, 0x6F} };
#endif /* __CID_EcoFSM1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_5E7C610CB846447DB59A3C5A2C4F446F;
#endif

#endif /* __ID_ECO_FINITE_STATE_MACHINE_1_H__ */
