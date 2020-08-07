/*
 * Copyright (c) 2020, Infosys Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */
 /******************************************************************************
 *
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/GtpV2StackCodeGen/tts/ietemplate.h.tt>
 ******************************************************************************/
#ifndef CAUSEIE_H_
#define CAUSEIE_H_

#include "manual/gtpV2Ie.h"



class CauseIe: public GtpV2Ie {
public:
    CauseIe();
    virtual ~CauseIe();

    bool encodeCauseIe(MsgBuffer &buffer,
                 CauseIeData const &data);
    bool decodeCauseIe(MsgBuffer &buffer,
                 CauseIeData &data, Uint16 length);
    void displayCauseIe_v(CauseIeData const &data,
                 Debug &stream);
};

#endif /* CAUSEIE_H_ */
