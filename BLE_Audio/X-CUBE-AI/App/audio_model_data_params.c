/**
  ******************************************************************************
  * @file    audio_model_data_params.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Nov 22 04:59:03 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */

#include "audio_model_data_params.h"


/**  Activations Section  ****************************************************/
ai_handle g_audio_model_activations_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(NULL),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};




/**  Weights Section  ********************************************************/
AI_ALIGNED(32)
const ai_u64 s_audio_model_weights_array_u64[105] = {
  0xa4d20842aef5017fU, 0xabc5171cde15073dU, 0x27df02e507f61714U, 0xdfee1b0dde1d0628U,
  0xe1fc4affe1080419U, 0xd4fe0bf1f0100830U, 0xbe06194aba0a0d34U, 0xc7d71eedce0b0b74U,
  0xeef508df40258810U, 0xf00ff8e93f2f8800U, 0xf0020ddb0d4782fcU, 0xc070ff71401970eU,
  0x1f0618e5f901811aU, 0x12f8e1e8f8428510U, 0xea0e0bda244c8303U, 0x206fcd2542681f9U,
  0x38073b271824e9c5U, 0xea15f50e19e0d08eU, 0xc5d0cdafb2abb881U, 0xfd21fe25593632ebU,
  0xcf9f22f362b09e7U, 0xf0e6dbd7bdd1d593U, 0x150a21e7f600ccaeU, 0x11071235e3078c97U,
  0xcecbbc95b0a981a5U, 0xf6e6ece7dbb099c2U, 0x10744451b38351aU, 0x1847441b552e5850U,
  0x45f10e4d515b5830U, 0x18210e0701290bfcU, 0xf2dcd1d6b0cdcde1U, 0xd3b9b1b9bbad8ac2U,
  0xb81dd73e5ae611c6U, 0xc1036c07f6e87f21U, 0x81ff50227df3be2U, 0xd70ed4eb149bbcf3U,
  0x7fed81310d41917U, 0xfbd91010faf920e1U, 0xc116cd0e34e81310U, 0xd6fd1c2117cf63e8U,
  0xc06949f1c4ccdcbcU, 0x232a49c281ef00aaU, 0xe21e0fbcde4b290aU, 0xa1d27cbe93f3b06U,
  0xea230decf8065f0cU, 0x201d59cbd93310edU, 0xec5455baec1dfac5U, 0xfb5451d49dcddaa0U,
  0x2d9ca18138184efaU, 0xfcc4c7a1142e3ef8U, 0xffcca7b9193211f5U, 0x15e2d1b0330aebfcU,
  0xded2b9c2070b24f2U, 0xf0c2d39ef32a22fbU, 0xe9f6c6b2113435e8U, 0x45afc0a2e36b21e4U,
  0x411b031a0424098cU, 0x12112913191e0481U, 0xf5151512140ff3a6U, 0x18f31b0713f5bfU,
  0xd25260d1c06efd2U, 0xf513ce1afc23f4b7U, 0x3ded13030128fec7U, 0x3c1e362e27f2c09fU,
  0xfffffee7ffffff45U, 0xfffffecafffffe5dU, 0xffffff1b000000a3U, 0x61fffffdfcU,
  0x392d40f6f6e5d4daU, 0x2012f3ee03fe374eU, 0xff12f2cbefd1152cU, 0xeafdd0f8c1dbd547U,
  0xf6e727a21415fec7U, 0xc2e8faf459d430d7U, 0x332039eaeaf1e0d3U, 0x14ea0d03cad7122eU,
  0x31aeee4c4d72719U, 0xf1f696ebebd7b741U, 0x5d6fd1ee6022a9bU, 0xd1fbdb3749eeaec9U,
  0x2c3136d0f3f4c8d3U, 0x6f71809f1dd0e2eU, 0x815f5e7f1c0040dU, 0xa0e9f9faecd4ba1aU,
  0xd4cedbc70500b281U, 0xdacd2ad430f2c7f6U, 0x132640f1fe10e7dfU, 0x80fefeffbe70b10U,
  0xfd16f6e215df040dU, 0xca04c019e2d5a928U, 0xe2dcf10be6f840dfU, 0xace9cefe18cbd0d7U,
  0x1e1b3de0fa17bfd3U, 0xee6f0ebdcd90f29U, 0xe60dffeae5de0914U, 0xccf4f4f7fcdd0310U,
  0xcec5e2ef12c8fad7U, 0xc6d6cad3fae1c2b0U, 0x3337360603f8c8e2U, 0x140f0a0efef8204bU,
  0xda1ffdfacfc01633U, 0xe8e8dc00afcec220U, 0xdbd618bbfada36f4U, 0xc3d8c5f0b5caddbdU,
  0xfffff996U,
};


ai_handle g_audio_model_weights_table[1 + 2] = {
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
  AI_HANDLE_PTR(s_audio_model_weights_array_u64),
  AI_HANDLE_PTR(AI_MAGIC_MARKER),
};

