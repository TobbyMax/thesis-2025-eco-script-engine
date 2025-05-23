/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IdEcoLexicalAnalyzer1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IdEcoLexicalAnalyzer1
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

#ifndef __ID_ECO__LEXICAL_ANALYZER_1_H__
#define __ID_ECO__LEXICAL_ANALYZER_1_H__

#include "IEcoBase1.h"
#include "IEcoLexicalAnalyzer1.h"

/* EcoLexicalAnalyzer1 CID = {7D1E60DA-B7EA-4837-A79D-537781F94437} */
#ifndef __CID_EcoLexicalAnalyzer1
static const UGUID CID_EcoLexicalAnalyzer1 = {0x01, 0x10, {0x7D, 0x1E, 0x60, 0xDA, 0xB7, 0xEA, 0x48, 0x37, 0xA7, 0x9D, 0x53, 0x77, 0x81, 0xF9, 0x44, 0x37} };
#endif /* __CID_EcoLexicalAnalyzer1 */

/* Фабрика компонента для динамической и статической компановки */
#ifdef ECO_DLL
ECO_EXPORT IEcoComponentFactory* ECOCALLMETHOD GetIEcoComponentFactoryPtr();
#elif ECO_LIB
extern IEcoComponentFactory* GetIEcoComponentFactoryPtr_7D1E60DAB7EA4837A79D537781F94437;
#endif

#endif /* __ID_ECO__LEXICAL_ANALYZER_1_H__ */
