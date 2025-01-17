/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2020 Jerzy Kasenbreg
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 */

#ifndef _USB_DESCRIPTORS_H_
#define _USB_DESCRIPTORS_H_

#define TUD_AUDIO_DESC_FEATURE_UNIT_16_CHANNEL_LEN (6+(16+1)*4)
#define TUD_AUDIO_DESC_FEATURE_UNIT_16_CHANNEL(_unitid, _srcid, _ctrlch0master, _ctrlch1, _ctrlch2, _ctrlch3, _ctrlch4, _ctrlch5, _ctrlch6, _ctrlch7, _ctrlch8, _ctrlch9, _ctrlch10, _ctrlch11, _ctrlch12, _ctrlch13, _ctrlch14, _ctrlch15, _ctrlch16, _stridx) \
    TUD_AUDIO_DESC_FEATURE_UNIT_16_CHANNEL_LEN, TUSB_DESC_CS_INTERFACE, AUDIO_CS_AC_INTERFACE_FEATURE_UNIT, _unitid, _srcid, U32_TO_U8S_LE(_ctrlch0master), U32_TO_U8S_LE(_ctrlch1), U32_TO_U8S_LE(_ctrlch2), U32_TO_U8S_LE(_ctrlch3), U32_TO_U8S_LE(_ctrlch4), U32_TO_U8S_LE(_ctrlch5), U32_TO_U8S_LE(_ctrlch6), U32_TO_U8S_LE(_ctrlch7), U32_TO_U8S_LE(_ctrlch8), U32_TO_U8S_LE(_ctrlch9), U32_TO_U8S_LE(_ctrlch10), U32_TO_U8S_LE(_ctrlch11), U32_TO_U8S_LE(_ctrlch12), U32_TO_U8S_LE(_ctrlch13), U32_TO_U8S_LE(_ctrlch14), U32_TO_U8S_LE(_ctrlch15), U32_TO_U8S_LE(_ctrlch16), _stridx

#define TUD_AUDIO_MIC_16_CH_DESC_LEN (TUD_AUDIO_DESC_IAD_LEN\
  + TUD_AUDIO_DESC_STD_AC_LEN\
  + TUD_AUDIO_DESC_CS_AC_LEN\
  + TUD_AUDIO_DESC_CLK_SRC_LEN\
  + TUD_AUDIO_DESC_INPUT_TERM_LEN\
  + TUD_AUDIO_DESC_OUTPUT_TERM_LEN\
  + TUD_AUDIO_DESC_FEATURE_UNIT_16_CHANNEL_LEN\
  + TUD_AUDIO_DESC_STD_AS_INT_LEN\
  + TUD_AUDIO_DESC_STD_AS_INT_LEN\
  + TUD_AUDIO_DESC_CS_AS_INT_LEN\
  + TUD_AUDIO_DESC_TYPE_I_FORMAT_LEN\
  + TUD_AUDIO_DESC_STD_AS_ISO_EP_LEN\
  + TUD_AUDIO_DESC_CS_AS_ISO_EP_LEN)

#define TUD_AUDIO_MIC_16_CH_DESCRIPTOR(_itfnum, _stridx, _nBytesPerSample, _nBitsUsedPerSample, _epin, _epsize) \
  /* Standard Interface Association Descriptor (IAD) */\
  TUD_AUDIO_DESC_IAD(/*_firstitf*/ _itfnum, /*_nitfs*/ 0x02, /*_stridx*/ 0x00),\
  /* Standard AC Interface Descriptor(4.7.1) */\
  TUD_AUDIO_DESC_STD_AC(/*_itfnum*/ _itfnum, /*_nEPs*/ 0x00, /*_stridx*/ _stridx),\
  /* Class-Specific AC Interface Header Descriptor(4.7.2) */\
  TUD_AUDIO_DESC_CS_AC(/*_bcdADC*/ 0x0200, /*_category*/ AUDIO_FUNC_MICROPHONE, /*_totallen*/ TUD_AUDIO_DESC_CLK_SRC_LEN+TUD_AUDIO_DESC_INPUT_TERM_LEN+TUD_AUDIO_DESC_OUTPUT_TERM_LEN+TUD_AUDIO_DESC_FEATURE_UNIT_16_CHANNEL_LEN, /*_ctrl*/ AUDIO_CS_AS_INTERFACE_CTRL_LATENCY_POS),\
  /* Clock Source Descriptor(4.7.2.1) */\
  TUD_AUDIO_DESC_CLK_SRC(/*_clkid*/ 0x04, /*_attr*/ AUDIO_CLOCK_SOURCE_ATT_INT_PRO_CLK, /*_ctrl*/ (AUDIO_CTRL_RW << AUDIO_CLOCK_SOURCE_CTRL_CLK_FRQ_POS | AUDIO_CTRL_R << AUDIO_CLOCK_SOURCE_CTRL_CLK_VAL_POS), /*_assocTerm*/ 0x01,  /*_stridx*/ 0x00),\
  /* Input Terminal Descriptor(4.7.2.4) */\
  TUD_AUDIO_DESC_INPUT_TERM(/*_termid*/ 0x01, /*_termtype*/ AUDIO_TERM_TYPE_IN_GENERIC_MIC, /*_assocTerm*/ 0x03, /*_clkid*/ 0x04, /*_nchannelslogical*/ 16, /*_channelcfg*/ AUDIO_CHANNEL_CONFIG_NON_PREDEFINED, /*_idxchannelnames*/ 0x00, /*_ctrl*/ AUDIO_CTRL_R << AUDIO_IN_TERM_CTRL_CONNECTOR_POS, /*_stridx*/ 0x00),\
  /* Output Terminal Descriptor(4.7.2.5) */\
  TUD_AUDIO_DESC_OUTPUT_TERM(/*_termid*/ 0x03, /*_termtype*/ AUDIO_TERM_TYPE_USB_STREAMING, /*_assocTerm*/ 0x01, /*_srcid*/ 0x02, /*_clkid*/ 0x04, /*_ctrl*/ 0x0000, /*_stridx*/ 0x00),\
  /* Feature Unit Descriptor(4.7.2.8) */\
  TUD_AUDIO_DESC_FEATURE_UNIT_16_CHANNEL(/*_unitid*/ 0x02, /*_srcid*/ 0x01, /*_ctrlch0master*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch1*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch2*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch3*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch4*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch5*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch6*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch7*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch8*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch9*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch10*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch11*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch12*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch13*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch14*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch15*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_ctrlch16*/ AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_MUTE_POS | AUDIO_CTRL_RW << AUDIO_FEATURE_UNIT_CTRL_VOLUME_POS, /*_stridx*/ 0x00),\
  /* Standard AS Interface Descriptor(4.9.1) */\
  /* Interface 1, Alternate 0 - default alternate setting with 0 bandwidth */\
  TUD_AUDIO_DESC_STD_AS_INT(/*_itfnum*/ (uint8_t)((_itfnum)+1), /*_altset*/ 0x00, /*_nEPs*/ 0x00, /*_stridx*/ 0x00),\
  /* Standard AS Interface Descriptor(4.9.1) */\
  /* Interface 1, Alternate 1 - alternate interface for data streaming */\
  TUD_AUDIO_DESC_STD_AS_INT(/*_itfnum*/ (uint8_t)((_itfnum)+1), /*_altset*/ 0x01, /*_nEPs*/ 0x01, /*_stridx*/ 0x00),\
  /* Class-Specific AS Interface Descriptor(4.9.2) */\
  TUD_AUDIO_DESC_CS_AS_INT(/*_termid*/ 0x03, /*_ctrl*/ AUDIO_CTRL_NONE, /*_formattype*/ AUDIO_FORMAT_TYPE_I, /*_formats*/ AUDIO_DATA_FORMAT_TYPE_I_PCM, /*_nchannelsphysical*/ 16, /*_channelcfg*/ AUDIO_CHANNEL_CONFIG_NON_PREDEFINED, /*_stridx*/ 0x00),\
  /* Type I Format Type Descriptor(2.3.1.6 - Audio Formats) */\
  TUD_AUDIO_DESC_TYPE_I_FORMAT(_nBytesPerSample, _nBitsUsedPerSample),\
  /* Standard AS Isochronous Audio Data Endpoint Descriptor(4.10.1.1) */\
  TUD_AUDIO_DESC_STD_AS_ISO_EP(/*_ep*/ _epin, /*_attr*/ (uint8_t) ((uint8_t)TUSB_XFER_ISOCHRONOUS | (uint8_t)TUSB_ISO_EP_ATT_ASYNCHRONOUS | (uint8_t)TUSB_ISO_EP_ATT_DATA), /*_maxEPsize*/ _epsize, /*_interval*/ 0x01),\
  /* Class-Specific AS Isochronous Audio Data Endpoint Descriptor(4.10.1.2) */\
  TUD_AUDIO_DESC_CS_AS_ISO_EP(/*_attr*/ AUDIO_CS_AS_ISO_DATA_EP_ATT_NON_MAX_PACKETS_OK, /*_ctrl*/ AUDIO_CTRL_NONE, /*_lockdelayunit*/ AUDIO_CS_AS_ISO_DATA_EP_LOCK_DELAY_UNIT_UNDEFINED, /*_lockdelay*/ 0x0000)

#endif
