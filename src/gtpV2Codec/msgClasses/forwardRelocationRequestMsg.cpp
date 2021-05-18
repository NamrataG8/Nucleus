/*
 * Copyright 2019-present Infosys Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/******************************************************************************
 *
 * This is an auto generated file.
 * Please do not edit this file.
 * All edits to be made through template source file
 * <TOP-DIR/scripts/GtpV2StackCodeGen/tts/msgtemplate.cpp.tt>
 ******************************************************************************/ 

#include "forwardRelocationRequestMsg.h"
#include "../ieClasses/manual/gtpV2Ie.h"
#include "../ieClasses/gtpV2IeFactory.h"
#include "../ieClasses/imsiIe.h"
#include "../ieClasses/fTeidIe.h"
#include "../ieClasses/fTeidIe.h"
#include "../ieClasses/fqdnIe.h"
#include "../ieClasses/mmContextIe.h"
#include "../ieClasses/indicationIe.h"
#include "../ieClasses/targetIdentificationIe.h"
#include "../ieClasses/plmnIdIe.h"
#include "../ieClasses/fContainerIe.h"
#include "../ieClasses/scefPdnConnectionIe.h"
#include "../ieClasses/mmeSgsnUeScefPdnConnectionsInForwardRelocationRequest.h"

ForwardRelocationRequestMsg::ForwardRelocationRequestMsg()
{
    msgType = ForwardRelocationRequestMsgType;
    Uint16 mandIe;
    mandIe = FTeidIeType;
    mandIe = (mandIe << 8) | 0; // senderFTeidForControlPlane
    mandatoryIeSet.insert(mandIe);    mandIe = MmContextIeType;
    mandIe = (mandIe << 8) | 0; // mmeSgsnAmfUeMmContext
    mandatoryIeSet.insert(mandIe);
}

ForwardRelocationRequestMsg::~ForwardRelocationRequestMsg()
{

}

bool ForwardRelocationRequestMsg::encodeForwardRelocationRequestMsg(MsgBuffer &buffer,
                        ForwardRelocationRequestMsgData
							const &data)
{
    bool rc = false;
    GtpV2IeHeader header;
    Uint16 startIndex = 0;
    Uint16 endIndex = 0;
    Uint16 length = 0;

    if (data.imsiIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = ImsiIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        ImsiIe imsi=
        dynamic_cast<
        ImsiIe&>(GtpV2IeFactory::getInstance().getIeObject(ImsiIeType));
        rc = imsi.encodeImsiIe(buffer, data.imsi);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: imsi\n");
            return false;
        }
    }

    
    // Encode the Ie Header
    header.ieType = FTeidIeType;
    header.instance = 0;
    header.length = 0; // We will encode the IE first and then update the length
    GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
    startIndex = buffer.getCurrentIndex(); 
    FTeidIe senderFTeidForControlPlane=
    dynamic_cast<
    FTeidIe&>(GtpV2IeFactory::getInstance().getIeObject(FTeidIeType));
    rc = senderFTeidForControlPlane.encodeFTeidIe(buffer, data.senderFTeidForControlPlane);
    endIndex = buffer.getCurrentIndex();
    length = endIndex - startIndex;
    
    // encode the length value now
    buffer.goToIndex(startIndex - 3);
    buffer.writeUint16(length, false);
    buffer.goToIndex(endIndex);

    if (!(rc))
    { 
        errorStream.add((char *)"Failed to encode IE: senderFTeidForControlPlane\n");
        return false;
    }

    if (data.sgwS11S4IpAddressAndTeidForControlPlaneIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = FTeidIeType;
        header.instance = 1;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        FTeidIe sgwS11S4IpAddressAndTeidForControlPlane=
        dynamic_cast<
        FTeidIe&>(GtpV2IeFactory::getInstance().getIeObject(FTeidIeType));
        rc = sgwS11S4IpAddressAndTeidForControlPlane.encodeFTeidIe(buffer, data.sgwS11S4IpAddressAndTeidForControlPlane);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: sgwS11S4IpAddressAndTeidForControlPlane\n");
            return false;
        }
    }

    if (data.sgwNodeNameIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = FqdnIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        FqdnIe sgwNodeName=
        dynamic_cast<
        FqdnIe&>(GtpV2IeFactory::getInstance().getIeObject(FqdnIeType));
        rc = sgwNodeName.encodeFqdnIe(buffer, data.sgwNodeName);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: sgwNodeName\n");
            return false;
        }
    }

    
    // Encode the Ie Header
    header.ieType = MmContextIeType;
    header.instance = 0;
    header.length = 0; // We will encode the IE first and then update the length
    GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
    startIndex = buffer.getCurrentIndex(); 
    MmContextIe mmeSgsnAmfUeMmContext=
    dynamic_cast<
    MmContextIe&>(GtpV2IeFactory::getInstance().getIeObject(MmContextIeType));
    rc = mmeSgsnAmfUeMmContext.encodeMmContextIe(buffer, data.mmeSgsnAmfUeMmContext);
    endIndex = buffer.getCurrentIndex();
    length = endIndex - startIndex;
    
    // encode the length value now
    buffer.goToIndex(startIndex - 3);
    buffer.writeUint16(length, false);
    buffer.goToIndex(endIndex);

    if (!(rc))
    { 
        errorStream.add((char *)"Failed to encode IE: mmeSgsnAmfUeMmContext\n");
        return false;
    }

    if (data.indicationFlagsIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = IndicationIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        IndicationIe indicationFlags=
        dynamic_cast<
        IndicationIe&>(GtpV2IeFactory::getInstance().getIeObject(IndicationIeType));
        rc = indicationFlags.encodeIndicationIe(buffer, data.indicationFlags);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: indicationFlags\n");
            return false;
        }
    }

    if (data.targetIdentificationIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = TargetIdentificationIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        TargetIdentificationIe targetIdentification=
        dynamic_cast<
        TargetIdentificationIe&>(GtpV2IeFactory::getInstance().getIeObject(TargetIdentificationIeType));
        rc = targetIdentification.encodeTargetIdentificationIe(buffer, data.targetIdentification);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: targetIdentification\n");
            return false;
        }
    }

    if (data.selectedPlmnIdIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = PlmnIdIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        PlmnIdIe selectedPlmnId=
        dynamic_cast<
        PlmnIdIe&>(GtpV2IeFactory::getInstance().getIeObject(PlmnIdIeType));
        rc = selectedPlmnId.encodePlmnIdIe(buffer, data.selectedPlmnId);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: selectedPlmnId\n");
            return false;
        }
    }

    if (data.eUtranTransparentContainerIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = FContainerIeType;
        header.instance = 1;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        FContainerIe eUtranTransparentContainer=
        dynamic_cast<
        FContainerIe&>(GtpV2IeFactory::getInstance().getIeObject(FContainerIeType));
        rc = eUtranTransparentContainer.encodeFContainerIe(buffer, data.eUtranTransparentContainer);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: eUtranTransparentContainer\n");
            return false;
        }
    }

    if (data.mmeSgsnUeScefPdnConnectionsIePresent)
    {
        
        // Encode the Ie Header
        header.ieType = ScefPdnConnectionIeType;
        header.instance = 0;
        header.length = 0; // We will encode the IE first and then update the length
        GtpV2Ie::encodeGtpV2IeHeader(buffer, header);
        startIndex = buffer.getCurrentIndex(); 
        ScefPdnConnectionIe mmeSgsnUeScefPdnConnections=
        dynamic_cast<
        ScefPdnConnectionIe&>(GtpV2IeFactory::getInstance().getIeObject(ScefPdnConnectionIeType));
        MmeSgsnUeScefPdnConnectionsInForwardRelocationRequest groupedIeInstance =
        dynamic_cast<
        MmeSgsnUeScefPdnConnectionsInForwardRelocationRequest&>(mmeSgsnUeScefPdnConnections.getGroupedIe(msgType, 0));
        rc = groupedIeInstance.encodeMmeSgsnUeScefPdnConnectionsInForwardRelocationRequest(buffer, data.mmeSgsnUeScefPdnConnections);
        endIndex = buffer.getCurrentIndex();
        length = endIndex - startIndex;
        
        // encode the length value now
        buffer.goToIndex(startIndex - 3);
        buffer.writeUint16(length, false);
        buffer.goToIndex(endIndex);

        if (!(rc))
        { 
            errorStream.add((char *)"Failed to encode IE: mmeSgsnUeScefPdnConnections\n");
            return false;
        }
    }
    return rc;

}

bool ForwardRelocationRequestMsg::decodeForwardRelocationRequestMsg(MsgBuffer &buffer,
 ForwardRelocationRequestMsgData 
 &data, Uint16 length)
{

    bool rc = false;
    GtpV2IeHeader ieHeader;
  
    set<Uint16> mandatoryIeLocalList = mandatoryIeSet;
    while (buffer.lengthLeft() > IE_HEADER_SIZE)
    {
        GtpV2Ie::decodeGtpV2IeHeader(buffer, ieHeader);
        if (ieHeader.length > buffer.lengthLeft())
        {
            // We do not have enough bytes left in the message for this IE
            errorStream.add((char *)"IE Length exceeds beyond message boundary\n");
            errorStream.add((char *)"  Offending IE Type: ");
            errorStream.add(ieHeader.ieType);
            errorStream.add((char *)"\n  Ie Length in Header: ");
            errorStream.add(ieHeader.length);
            errorStream.add((char *)"\n  Bytes left in message: ");
            errorStream.add(buffer.lengthLeft());
            errorStream.endOfLine();
            return false;
        }

        switch (ieHeader.ieType){
     
            case ImsiIeType:
            {
                ImsiIe ieObject =
                dynamic_cast<
                ImsiIe&>(GtpV2IeFactory::getInstance().getIeObject(ImsiIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeImsiIe(buffer, data.imsi, ieHeader.length);

                    data.imsiIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: imsi\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case FTeidIeType:
            {
                FTeidIe ieObject =
                dynamic_cast<
                FTeidIe&>(GtpV2IeFactory::getInstance().getIeObject(FTeidIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeFTeidIe(buffer, data.senderFTeidForControlPlane, ieHeader.length);

                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: senderFTeidForControlPlane\n");
                        return false;
                    }
                }
                else if(ieHeader.instance == 1)
                {
                    rc = ieObject.decodeFTeidIe(buffer, data.sgwS11S4IpAddressAndTeidForControlPlane, ieHeader.length);

                    data.sgwS11S4IpAddressAndTeidForControlPlaneIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: sgwS11S4IpAddressAndTeidForControlPlane\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case FqdnIeType:
            {
                FqdnIe ieObject =
                dynamic_cast<
                FqdnIe&>(GtpV2IeFactory::getInstance().getIeObject(FqdnIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeFqdnIe(buffer, data.sgwNodeName, ieHeader.length);

                    data.sgwNodeNameIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: sgwNodeName\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case MmContextIeType:
            {
                MmContextIe ieObject =
                dynamic_cast<
                MmContextIe&>(GtpV2IeFactory::getInstance().getIeObject(MmContextIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeMmContextIe(buffer, data.mmeSgsnAmfUeMmContext, ieHeader.length);

                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: mmeSgsnAmfUeMmContext\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case IndicationIeType:
            {
                IndicationIe ieObject =
                dynamic_cast<
                IndicationIe&>(GtpV2IeFactory::getInstance().getIeObject(IndicationIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeIndicationIe(buffer, data.indicationFlags, ieHeader.length);

                    data.indicationFlagsIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: indicationFlags\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case TargetIdentificationIeType:
            {
                TargetIdentificationIe ieObject =
                dynamic_cast<
                TargetIdentificationIe&>(GtpV2IeFactory::getInstance().getIeObject(TargetIdentificationIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodeTargetIdentificationIe(buffer, data.targetIdentification, ieHeader.length);

                    data.targetIdentificationIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: targetIdentification\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case PlmnIdIeType:
            {
                PlmnIdIe ieObject =
                dynamic_cast<
                PlmnIdIe&>(GtpV2IeFactory::getInstance().getIeObject(PlmnIdIeType));

                if(ieHeader.instance == 0)
                {
                    rc = ieObject.decodePlmnIdIe(buffer, data.selectedPlmnId, ieHeader.length);

                    data.selectedPlmnIdIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: selectedPlmnId\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case FContainerIeType:
            {
                FContainerIe ieObject =
                dynamic_cast<
                FContainerIe&>(GtpV2IeFactory::getInstance().getIeObject(FContainerIeType));

                if(ieHeader.instance == 1)
                {
                    rc = ieObject.decodeFContainerIe(buffer, data.eUtranTransparentContainer, ieHeader.length);

                    data.eUtranTransparentContainerIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: eUtranTransparentContainer\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }
     
            case ScefPdnConnectionIeType:
            {
                ScefPdnConnectionIe ieObject =
                dynamic_cast<
                ScefPdnConnectionIe&>(GtpV2IeFactory::getInstance().getIeObject(ScefPdnConnectionIeType));

                if(ieHeader.instance == 0)
                {
                    MmeSgsnUeScefPdnConnectionsInForwardRelocationRequest groupedIeInstance =
                    dynamic_cast<
                    MmeSgsnUeScefPdnConnectionsInForwardRelocationRequest&>(ieObject.getGroupedIe(msgType, 0));
                    rc = groupedIeInstance.decodeMmeSgsnUeScefPdnConnectionsInForwardRelocationRequest(buffer, data.mmeSgsnUeScefPdnConnections, ieHeader.length);

                    data.mmeSgsnUeScefPdnConnectionsIePresent = true;
                    if (!(rc))
                    {
                        errorStream.add((char *)"Failed to decode IE: mmeSgsnUeScefPdnConnections\n");
                        return false;
                    }
                }

                else
                {
                    // Unknown IE instance print error
                    errorStream.add((char *)"Unknown IE Type: ");
                    errorStream.add(ieHeader.ieType);
                    errorStream.endOfLine();
                    buffer.skipBytes(ieHeader.length);
                }
                break;
            }

            default:
            {
                // Unknown IE print error
                errorStream.add((char *)"Unknown IE Type: ");
                errorStream.add(ieHeader.ieType);
                errorStream.endOfLine();
                buffer.skipBytes(ieHeader.length);
            }
        }
    }
    return rc; // TODO validations
}

void ForwardRelocationRequestMsg::
displayForwardRelocationRequestMsgData_v(ForwardRelocationRequestMsgData const &data, Debug &stream)
{
    stream.incrIndent();
    stream.add((char *)"ForwardRelocationRequestMsg:");
    stream.endOfLine();
    stream.incrIndent();
        
    
    if (data.imsiIePresent)
    {


        stream.add((char *)"IE - imsi:");
        stream.endOfLine();
        ImsiIe imsi=
        dynamic_cast<
        ImsiIe&>(GtpV2IeFactory::getInstance().getIeObject(ImsiIeType));
        imsi.displayImsiIe_v(data.imsi, stream);

    }
    stream.add((char *)"IE - senderFTeidForControlPlane:");
    stream.endOfLine();
    FTeidIe senderFTeidForControlPlane=
    dynamic_cast<
    FTeidIe&>(GtpV2IeFactory::getInstance().getIeObject(FTeidIeType));
    senderFTeidForControlPlane.displayFTeidIe_v(data.senderFTeidForControlPlane, stream);

    if (data.sgwS11S4IpAddressAndTeidForControlPlaneIePresent)
    {


        stream.add((char *)"IE - sgwS11S4IpAddressAndTeidForControlPlane:");
        stream.endOfLine();
        FTeidIe sgwS11S4IpAddressAndTeidForControlPlane=
        dynamic_cast<
        FTeidIe&>(GtpV2IeFactory::getInstance().getIeObject(FTeidIeType));
        sgwS11S4IpAddressAndTeidForControlPlane.displayFTeidIe_v(data.sgwS11S4IpAddressAndTeidForControlPlane, stream);

    }
    if (data.sgwNodeNameIePresent)
    {


        stream.add((char *)"IE - sgwNodeName:");
        stream.endOfLine();
        FqdnIe sgwNodeName=
        dynamic_cast<
        FqdnIe&>(GtpV2IeFactory::getInstance().getIeObject(FqdnIeType));
        sgwNodeName.displayFqdnIe_v(data.sgwNodeName, stream);

    }
    stream.add((char *)"IE - mmeSgsnAmfUeMmContext:");
    stream.endOfLine();
    MmContextIe mmeSgsnAmfUeMmContext=
    dynamic_cast<
    MmContextIe&>(GtpV2IeFactory::getInstance().getIeObject(MmContextIeType));
    mmeSgsnAmfUeMmContext.displayMmContextIe_v(data.mmeSgsnAmfUeMmContext, stream);

    if (data.indicationFlagsIePresent)
    {


        stream.add((char *)"IE - indicationFlags:");
        stream.endOfLine();
        IndicationIe indicationFlags=
        dynamic_cast<
        IndicationIe&>(GtpV2IeFactory::getInstance().getIeObject(IndicationIeType));
        indicationFlags.displayIndicationIe_v(data.indicationFlags, stream);

    }
    if (data.targetIdentificationIePresent)
    {


        stream.add((char *)"IE - targetIdentification:");
        stream.endOfLine();
        TargetIdentificationIe targetIdentification=
        dynamic_cast<
        TargetIdentificationIe&>(GtpV2IeFactory::getInstance().getIeObject(TargetIdentificationIeType));
        targetIdentification.displayTargetIdentificationIe_v(data.targetIdentification, stream);

    }
    if (data.selectedPlmnIdIePresent)
    {


        stream.add((char *)"IE - selectedPlmnId:");
        stream.endOfLine();
        PlmnIdIe selectedPlmnId=
        dynamic_cast<
        PlmnIdIe&>(GtpV2IeFactory::getInstance().getIeObject(PlmnIdIeType));
        selectedPlmnId.displayPlmnIdIe_v(data.selectedPlmnId, stream);

    }
    if (data.eUtranTransparentContainerIePresent)
    {


        stream.add((char *)"IE - eUtranTransparentContainer:");
        stream.endOfLine();
        FContainerIe eUtranTransparentContainer=
        dynamic_cast<
        FContainerIe&>(GtpV2IeFactory::getInstance().getIeObject(FContainerIeType));
        eUtranTransparentContainer.displayFContainerIe_v(data.eUtranTransparentContainer, stream);

    }
    if (data.mmeSgsnUeScefPdnConnectionsIePresent)
    {


        stream.add((char *)"IE - mmeSgsnUeScefPdnConnections:");
        stream.endOfLine();
        ScefPdnConnectionIe mmeSgsnUeScefPdnConnections=
        dynamic_cast<
        ScefPdnConnectionIe&>(GtpV2IeFactory::getInstance().getIeObject(ScefPdnConnectionIeType));
        MmeSgsnUeScefPdnConnectionsInForwardRelocationRequest groupedIeInstance =
        dynamic_cast<
        MmeSgsnUeScefPdnConnectionsInForwardRelocationRequest&>(mmeSgsnUeScefPdnConnections.getGroupedIe(msgType, 0));
        groupedIeInstance.displayMmeSgsnUeScefPdnConnectionsInForwardRelocationRequestData_v(data.mmeSgsnUeScefPdnConnections, stream);
    }

    stream.decrIndent();
    stream.decrIndent();
}
