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
#ifndef FCONTAINERIE_H_
#define FCONTAINERIE_H_

#include "manual/gtpV2Ie.h"



class FContainerIe: public GtpV2Ie {
public:
    FContainerIe();
    virtual ~FContainerIe();

    bool encodeFContainerIe(MsgBuffer &buffer,
                 FContainerIeData const &data);
    bool decodeFContainerIe(MsgBuffer &buffer,
                 FContainerIeData &data, Uint16 length);
    void displayFContainerIe_v(FContainerIeData const &data,
                 Debug &stream);
};

#endif /* FCONTAINERIE_H_ */
