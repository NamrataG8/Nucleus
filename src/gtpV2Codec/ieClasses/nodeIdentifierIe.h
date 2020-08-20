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
#ifndef NODEIDENTIFIERIE_H_
#define NODEIDENTIFIERIE_H_

#include "manual/gtpV2Ie.h"



class NodeIdentifierIe: public GtpV2Ie {
public:
    NodeIdentifierIe();
    virtual ~NodeIdentifierIe();

    bool encodeNodeIdentifierIe(MsgBuffer &buffer,
                 NodeIdentifierIeData const &data);
    bool decodeNodeIdentifierIe(MsgBuffer &buffer,
                 NodeIdentifierIeData &data, Uint16 length);
    void displayNodeIdentifierIe_v(NodeIdentifierIeData const &data,
                 Debug &stream);
};

#endif /* NODEIDENTIFIERIE_H_ */
