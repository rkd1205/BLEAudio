/**
  ******************************************************************************
  * @file    audio_model.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Nov 22 04:59:03 2023
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  ******************************************************************************
  */


#include "audio_model.h"
#include "audio_model_data.h"

#include "ai_platform.h"
#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_audio_model
 
#undef AI_AUDIO_MODEL_MODEL_SIGNATURE
#define AI_AUDIO_MODEL_MODEL_SIGNATURE     "1c680d67f792f2590465c80798b55474"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Nov 22 04:59:03 2023"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_AUDIO_MODEL_N_BATCHES
#define AI_AUDIO_MODEL_N_BATCHES         (1)

static ai_ptr g_audio_model_activations_map[1] = AI_C_ARRAY_INIT;
static ai_ptr g_audio_model_weights_map[1] = AI_C_ARRAY_INIT;



/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input_10_0_conversion_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 15996, AI_STATIC)
/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  upsample_0_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)
/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  upsample_0_0_conversion_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)
/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1360, AI_STATIC)
/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)
/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 208, AI_STATIC)
/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1, AI_STATIC)
/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  nl_5_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 1, AI_STATIC)
/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 208, AI_STATIC)
/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_scratch0_array, AI_ARRAY_FORMAT_S16,
  NULL, NULL, 288, AI_STATIC)
/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)
/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)
/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 288, AI_STATIC)
/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  dense_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1, AI_STATIC)
/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  serving_default_input_10_output_array, AI_ARRAY_FORMAT_S8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 15996, AI_STATIC)
/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(upsample_0_0_conversion_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4076593220233917f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04815874248743057f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch1_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04815874248743057f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_4_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.056375812739133835f),
    AI_PACK_INTQ_ZP(10)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_5_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_scratch2_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04815874248743057f),
    AI_PACK_INTQ_ZP(-9)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0021804687567055225f, 0.005142941139638424f, 0.004969118162989616f, 0.0038962301332503557f, 0.0024173432029783726f, 0.003903968958184123f, 0.003465225687250495f, 0.004672384820878506f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_4_weights_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0077103241346776485f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_input_10_output_array_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4076593220233917f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input_10_0_conversion_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 129, 124), AI_STRIDE_INIT(4, 4, 4, 4, 516),
  1, &serving_default_input_10_0_conversion_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  upsample_0_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 32, 32), AI_STRIDE_INIT(4, 4, 4, 4, 128),
  1, &upsample_0_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  upsample_0_0_conversion_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 32, 32), AI_STRIDE_INIT(4, 1, 1, 1, 32),
  1, &upsample_0_0_conversion_output_array, &upsample_0_0_conversion_output_array_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 1360, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1360, 1360),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 6, 6), AI_STRIDE_INIT(4, 1, 1, 8, 48),
  1, &conv2d_1_output_array, &conv2d_1_output_array_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output0, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 288, 1, 1), AI_STRIDE_INIT(4, 1, 1, 288, 288),
  1, &conv2d_1_output_array, &conv2d_1_output_array_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch1, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 13, 2), AI_STRIDE_INIT(4, 1, 1, 8, 104),
  1, &conv2d_1_scratch1_array, &conv2d_1_scratch1_array_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &dense_4_output_array, &dense_4_output_array_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  nl_5_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1, 1),
  1, &nl_5_output_array, &nl_5_output_array_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch2, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 13, 2), AI_STRIDE_INIT(4, 1, 1, 8, 104),
  1, &conv2d_1_scratch2_array, &conv2d_1_scratch2_array_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_scratch0, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 288, 1, 1), AI_STRIDE_INIT(4, 2, 2, 576, 576),
  1, &dense_4_scratch0_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 8, 8), AI_STRIDE_INIT(4, 1, 1, 8, 64),
  1, &conv2d_1_weights_array, &conv2d_1_weights_array_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_weights, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 288, 1, 1, 1), AI_STRIDE_INIT(4, 1, 288, 288, 288),
  1, &dense_4_weights_array, &dense_4_weights_array_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  dense_4_bias, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 1, 1, 1), AI_STRIDE_INIT(4, 4, 4, 4, 4),
  1, &dense_4_bias_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_input_10_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 129, 124), AI_STRIDE_INIT(4, 1, 1, 1, 129),
  1, &serving_default_input_10_output_array, &serving_default_input_10_output_array_intq)



/**  Layer declarations section  **********************************************/



AI_STATIC_CONST ai_i8 nl_5_nl_params_data[] = { -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -128, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -127, -126, -126, -126, -126, -126, -126, -126, -126, -126, -126, -125, -125, -125, -125, -125, -125, -124, -124, -124, -124, -123, -123, -123, -123, -122, -122, -122, -121, -121, -120, -120, -120, -119, -119, -118, -118, -117, -116, -116, -115, -114, -114, -113, -112, -111, -110, -109, -108, -107, -106, -105, -104, -102, -101, -100, -98, -97, -95, -94, -92, -90, -88, -86, -84, -82, -80, -78, -75, -73, -71, -68, -65, -63, -60, -57, -54, -51, -48, -45, -42, -38, -35, -32, -28, -25, -21, -18, -14, -11, -7, -4, 0, 4, 7, 11, 14, 18, 21, 25, 28, 32, 35, 38, 42, 45, 48, 51, 54, 57, 60, 63, 65, 68, 71, 73, 75, 78, 80, 82, 84, 86, 88, 90, 92, 94, 95, 97, 98, 100, 101, 102, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 114, 115, 116, 116, 117, 118, 118, 119, 119, 120, 120, 120, 121, 121, 122, 122, 122, 123, 123, 123, 123, 124, 124, 124, 124, 125, 125, 125, 125, 125, 125, 126, 126, 126, 126, 126, 126, 126, 126, 126, 126, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127, 127 };
AI_ARRAY_OBJ_DECLARE(
    nl_5_nl_params, AI_ARRAY_FORMAT_S8,
    nl_5_nl_params_data, nl_5_nl_params_data, 256, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_5_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_5_layer, 5,
  NL_TYPE, 0x0, NULL,
  nl, forward_nl_integer,
  &nl_5_chain,
  NULL, &nl_5_layer, AI_STATIC, 
  .nl_params = &nl_5_nl_params, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output0),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_4_weights, &dense_4_bias),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  dense_4_layer, 4,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_4_chain,
  NULL, &nl_5_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_i8 conv2d_1_nl_params_data[] = { -9 };
AI_ARRAY_OBJ_DECLARE(
    conv2d_1_nl_params, AI_ARRAY_FORMAT_S8,
    conv2d_1_nl_params_data, conv2d_1_nl_params_data, 1, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &upsample_0_0_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_scratch0, &conv2d_1_scratch1, &conv2d_1_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 2,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_sssa8_ch_nl_pool,
  &conv2d_1_chain,
  NULL, &dense_4_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = &conv2d_1_nl_params, 
  .nl_func = nl_func_relu_array_integer, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(2, 2), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_mp_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  upsample_0_0_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &upsample_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &upsample_0_0_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  upsample_0_0_conversion_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &upsample_0_0_conversion_chain,
  NULL, &conv2d_1_layer, AI_STATIC, 
)


AI_STATIC_CONST ai_float upsample_0_scales_data[] = { 0.25806451612903225, 0.24806201550387597, 1.0, 1 };
AI_ARRAY_OBJ_DECLARE(
    upsample_0_scales, AI_ARRAY_FORMAT_FLOAT,
    upsample_0_scales_data, upsample_0_scales_data, 4, AI_STATIC_CONST)
AI_TENSOR_CHAIN_OBJ_DECLARE(
  upsample_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input_10_0_conversion_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &upsample_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  upsample_0_layer, 0,
  UPSAMPLE_TYPE, 0x0, NULL,
  upsample, forward_upsample,
  &upsample_0_chain,
  NULL, &upsample_0_0_conversion_layer, AI_STATIC, 
  .scales = &upsample_0_scales, 
  .center = false, 
  .mode = AI_UPSAMPLE_NEAREST, 
  .nearest_mode = AI_ROUND_FLOOR, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  serving_default_input_10_0_conversion_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_input_10_0_conversion_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  serving_default_input_10_0_conversion_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &serving_default_input_10_0_conversion_chain,
  NULL, &upsample_0_layer, AI_STATIC, 
)


#if (AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 836, 1, 1),
    836, NULL, NULL),
  AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
    AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 79980, 1, 1),
    79980, NULL, NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUDIO_MODEL_IN_NUM, &serving_default_input_10_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUDIO_MODEL_OUT_NUM, &nl_5_output),
  &serving_default_input_10_0_conversion_layer, 0, NULL)

#else

AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 836, 1, 1),
      836, NULL, NULL)
  ),
  AI_BUFFER_ARRAY_OBJ_INIT_STATIC(
  	AI_FLAG_NONE, 1,
    AI_BUFFER_INIT(AI_FLAG_NONE,  AI_BUFFER_FORMAT_U8,
      AI_BUFFER_SHAPE_INIT(AI_SHAPE_BCWH, 4, 1, 79980, 1, 1),
      79980, NULL, NULL)
  ),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUDIO_MODEL_IN_NUM, &serving_default_input_10_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_AUDIO_MODEL_OUT_NUM, &nl_5_output),
  &serving_default_input_10_0_conversion_layer, 0, NULL)

#endif	/*(AI_TOOLS_API_VERSION < AI_TOOLS_API_VERSION_1_5)*/


/******************************************************************************/
AI_DECLARE_STATIC
ai_bool audio_model_configure_activations(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_activations_map(g_audio_model_activations_map, 1, params)) {
    /* Updating activations (byte) offsets */
    
    serving_default_input_10_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 0);
    serving_default_input_10_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 0);
    
    serving_default_input_10_0_conversion_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 15996);
    serving_default_input_10_0_conversion_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 15996);
    
    upsample_0_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 0);
    upsample_0_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 0);
    
    upsample_0_0_conversion_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 4096);
    upsample_0_0_conversion_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 4096);
    
    conv2d_1_scratch0_array.data = AI_PTR(g_audio_model_activations_map[0] + 0);
    conv2d_1_scratch0_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 0);
    
    conv2d_1_scratch1_array.data = AI_PTR(g_audio_model_activations_map[0] + 1360);
    conv2d_1_scratch1_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 1360);
    
    conv2d_1_scratch2_array.data = AI_PTR(g_audio_model_activations_map[0] + 1568);
    conv2d_1_scratch2_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 1568);
    
    conv2d_1_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 1776);
    conv2d_1_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 1776);
    
    dense_4_scratch0_array.data = AI_PTR(g_audio_model_activations_map[0] + 0);
    dense_4_scratch0_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 0);
    
    dense_4_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 576);
    dense_4_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 576);
    
    nl_5_output_array.data = AI_PTR(g_audio_model_activations_map[0] + 0);
    nl_5_output_array.data_start = AI_PTR(g_audio_model_activations_map[0] + 0);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_ACTIVATIONS);
  return false;
}



/******************************************************************************/
AI_DECLARE_STATIC
ai_bool audio_model_configure_weights(
  ai_network* net_ctx, const ai_network_params* params)
{
  AI_ASSERT(net_ctx)

  if (ai_platform_get_weights_map(g_audio_model_weights_map, 1, params)) {
    /* Updating weights (byte) offsets */
    
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(g_audio_model_weights_map[0] + 0);
    conv2d_1_weights_array.data_start = AI_PTR(g_audio_model_weights_map[0] + 0);
    
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(g_audio_model_weights_map[0] + 512);
    conv2d_1_bias_array.data_start = AI_PTR(g_audio_model_weights_map[0] + 512);
    
    dense_4_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_4_weights_array.data = AI_PTR(g_audio_model_weights_map[0] + 544);
    dense_4_weights_array.data_start = AI_PTR(g_audio_model_weights_map[0] + 544);
    
    dense_4_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_4_bias_array.data = AI_PTR(g_audio_model_weights_map[0] + 832);
    dense_4_bias_array.data_start = AI_PTR(g_audio_model_weights_map[0] + 832);
    
    return true;
  }
  AI_ERROR_TRAP(net_ctx, INIT_FAILED, NETWORK_WEIGHTS);
  return false;
}


/**  PUBLIC APIs SECTION  *****************************************************/


AI_DEPRECATED
AI_API_ENTRY
ai_bool ai_audio_model_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_AUDIO_MODEL_MODEL_NAME,
      .model_signature   = AI_AUDIO_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 123370,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .params            = AI_STRUCT_INIT,
      .activations       = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}


AI_API_ENTRY
ai_bool ai_audio_model_get_report(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if (report && net_ctx)
  {
    ai_network_report r = {
      .model_name        = AI_AUDIO_MODEL_MODEL_NAME,
      .model_signature   = AI_AUDIO_MODEL_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 123370,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .map_signature     = AI_MAGIC_SIGNATURE,
      .map_weights       = AI_STRUCT_INIT,
      .map_activations   = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }
  return false;
}

AI_API_ENTRY
ai_error ai_audio_model_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_audio_model_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_error ai_audio_model_create_and_init(
  ai_handle* network, const ai_handle activations[], const ai_handle weights[])
{
    ai_error err;
    ai_network_params params;

    err = ai_audio_model_create(network, AI_AUDIO_MODEL_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE)
        return err;
    if (ai_audio_model_data_params_get(&params) != true) {
        err = ai_audio_model_get_error(*network);
        return err;
    }
#if defined(AI_AUDIO_MODEL_DATA_ACTIVATIONS_COUNT)
    if (activations) {
        /* set the addresses of the activations buffers */
        for (int idx=0;idx<params.map_activations.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_activations, idx, activations[idx]);
    }
#endif
#if defined(AI_AUDIO_MODEL_DATA_WEIGHTS_COUNT)
    if (weights) {
        /* set the addresses of the weight buffers */
        for (int idx=0;idx<params.map_weights.size;idx++)
            AI_BUFFER_ARRAY_ITEM_SET_ADDRESS(&params.map_weights, idx, weights[idx]);
    }
#endif
    if (ai_audio_model_init(*network, &params) != true) {
        err = ai_audio_model_get_error(*network);
    }
    return err;
}

AI_API_ENTRY
ai_buffer* ai_audio_model_inputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_inputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_buffer* ai_audio_model_outputs_get(ai_handle network, ai_u16 *n_buffer)
{
  if (network == AI_HANDLE_NULL) {
    network = (ai_handle)&AI_NET_OBJ_INSTANCE;
    ((ai_network *)network)->magic = AI_MAGIC_CONTEXT_TOKEN;
  }
  return ai_platform_outputs_get(network, n_buffer);
}

AI_API_ENTRY
ai_handle ai_audio_model_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_audio_model_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if (!net_ctx) return false;

  ai_bool ok = true;
  ok &= audio_model_configure_weights(net_ctx, params);
  ok &= audio_model_configure_activations(net_ctx, params);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_audio_model_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_audio_model_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_AUDIO_MODEL_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

