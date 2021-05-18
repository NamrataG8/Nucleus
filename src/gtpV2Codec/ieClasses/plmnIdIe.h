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
#ifndef PLMNIDIE_H_
#define PLMNIDIE_H_

#include "manual/gtpV2Ie.h"



class PlmnIdIe: public GtpV2Ie {
public:
    PlmnIdIe();
    virtual ~PlmnIdIe();

    bool encodePlmnIdIe(MsgBuffer &buffer,
                 PlmnIdIeData const &data);
    bool decodePlmnIdIe(MsgBuffer &buffer,
                 PlmnIdIeData &data, Uint16 length);
    void displayPlmnIdIe_v(PlmnIdIeData const &data,
                 Debug &stream);
};

#endif /* PLMNIDIE_H_ */