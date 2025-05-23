/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   CEcoScanner1Sink
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает реализацию компонента CEcoScanner1Sink
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#ifndef __C_ECO_SCANNER_1_SINK_H__
#define __C_ECO_SCANNER_1_SINK_H__


#include "IEcoLexicalAnalyzer1.h"
#include "IEcoSystem1.h"
#include "IdEcoString1.h"
#include "IEcoLog1.h"
#include "IdEcoMemoryManager1.h"

typedef struct CEcoScanner1Sink {

    /* Таблица функций интерфейса IEcoLexicalAnalyzer1Events */
    IEcoLexicalAnalyzer1EventsVTbl* m_pVTbIEvents;

    /* Счетчик ссылок */
    uint32_t m_cRef;

    /* Интерфейс для работы с памятью */
    IEcoMemoryAllocator1* m_pIMem;

    /* Интерфейс для работы со строкой */
    IEcoString1* m_pIString;

    /* Указатель на интерфейс работы с журналом */
    IEcoLog1* m_pILog;

    /* Данные экземпляра */

} CEcoScanner1Sink, *CEcoScanner1SinkPtr;

/* Создание экземпляра */
int16_t createCEcoScanner1Sink(/* in */ IEcoUnknown* pIUnkSystem, /* in */ IEcoUnknown* pIUnkOuter, /* in */ IEcoLog1* pILog, /* out */ IEcoLexicalAnalyzer1Events** ppIEvents);
/* Удаление */
void deleteCEcoScanner1Sink(/* in */ IEcoLexicalAnalyzer1Events* pIEvents);

#endif /* __C_ECO_SCANNER_1_SINK_H__ */
