/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoSEM1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoSEM1
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

#ifndef __ID_ECOSEM1_HPP__
#define __ID_ECOSEM1_HPP__

#include "IEcoBase1.hpp"
#include "IEcoSEM1.hpp"

/* EcoSEM1 CID = {9BC2C181-9992-43A3-8E45-C2BC67CDDD73} */
#ifndef __CID_EcoSEM1
static const UGUID CID_EcoSEM1 = {0x01, 0x10, {0x9B, 0xC2, 0xC1, 0x81, 0x99, 0x92, 0x43, 0xA3, 0x8E, 0x45, 0xC2, 0xBC, 0x67, 0xCD, 0xDD, 0x73}};
#endif /* __CID_EcoSEM1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern "C" IEcoComponentFactory* GetIEcoComponentFactoryPtr_9BC2C181999243A38E45C2BC67CDDD73;
#endif

#endif /* __ID_ECOSEM1_HPP__ */
