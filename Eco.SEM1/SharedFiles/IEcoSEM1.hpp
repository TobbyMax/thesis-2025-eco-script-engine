/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   IEcoSEM1
 * </сводка>
 *
 * <описание>
 *   Данный заголовок описывает интерфейс IEcoSEM1
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

#ifndef __I_ECOSEM1_HPP__
#define __I_ECOSEM1_HPP__

#include "IEcoBase1.hpp"

/* IEcoSEM1 IID = {E6E96975-7686-48C3-B075-5143CE324AAC} */
#ifndef __IID_IEcoSEM1
static const UGUID IID_IEcoSEM1 = {0x01, 0x10, {0xE6, 0xE9, 0x69, 0x75, 0x76, 0x86, 0x48, 0xC3, 0xB0, 0x75, 0x51, 0x43, 0xCE, 0x32, 0x4A, 0xAC}};
#endif /* __IID_IEcoSEM1 */

interface IEcoSEM1 : public IEcoUnknown {
public:
    /* IEcoSEM1 */
    virtual int16_t ECOCALLMETHOD MyFunction(/* in */ char_t* Name, /* out */ char_t** CopyName) = 0;

};



#endif /* __I_ECOSEM1_HPP__ */
